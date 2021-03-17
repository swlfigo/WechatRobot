//
//  WXDownloadManager.m
//  WechatMacMessageRobotFramework
//
//  Created by sylar on 2021/3/16.
//

#import "WXDownloadManager.h"
#import <AFNetworking/AFNetworking.h>
#import <objc/runtime.h>
@implementation WXDownloadModel
@end

@interface WXDownloadManager()<NSURLSessionDelegate>
@property(nonatomic,strong)NSOperationQueue *msgQueue;
@end

@implementation WXDownloadManager{
    
}
static WXDownloadManager* _instance = nil;
+(instancetype) shareInstance{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[super allocWithZone:NULL] init];
    }) ;
    return _instance;
}

+(id) allocWithZone:(struct _NSZone *)zone{
    return [WXDownloadManager shareInstance];
}

-(id) copyWithZone:(struct _NSZone *)zone{
    return [WXDownloadManager shareInstance];
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _msgQueue = [NSOperationQueue new];
        _msgQueue.maxConcurrentOperationCount = 6;
        _msgQueue.name = @"com.wxRobot.queue";
    }
    return self;
}

- (void)downloadStickerMsgData:(MessageData *)msgData success:(void (^)(WXDownloadModel * _Nonnull))successHandler{
    //      xml 转 dict
    XMLDictionaryParser *xmlParser = [objc_getClass("XMLDictionaryParser") sharedInstance];
    NSDictionary *msgDict = [xmlParser dictionaryWithString:msgData.msgContent];
    MMMessageCacheMgr *mgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("MMMessageCacheMgr")];
    NSString *cdnURL = msgDict[@"emoji"][@"_cdnurl"];
    NSString *thumbURL = msgDict[@"emoji"][@"_thumburl"];
    NSString *md5 = msgDict[@"emoji"][@"_md5"];
    CGFloat height = [msgDict[@"emoji"][@"_height"] floatValue];
    CGFloat width = [msgDict[@"emoji"][@"_width"] floatValue];
    
    __block WXDownloadModel *downloadModel = [[WXDownloadModel alloc]init];
    
    EmoticonMgr *emotionMgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("EmoticonMgr")];
    __block NSData *thumbImageData = nil;
    __block NSData *oriImageData = nil;
    __block NSError *thumbDownloadError = nil;
    __block NSError *oriDownloadError = nil;
    
    NSBlockOperation *thumbOp = [NSBlockOperation blockOperationWithBlock:^{
        dispatch_semaphore_t sema = dispatch_semaphore_create(0);
        AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
        manager.responseSerializer = [AFHTTPResponseSerializer serializer];
        [manager GET:thumbURL parameters:nil headers:nil progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {

            thumbImageData = responseObject;
            
            dispatch_semaphore_signal(sema);
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            dispatch_semaphore_signal(sema);
            thumbDownloadError = error;
        }];
        dispatch_wait(sema, DISPATCH_TIME_FOREVER);
    }];
    
    NSBlockOperation *oriOp = [NSBlockOperation blockOperationWithBlock:^{
        dispatch_semaphore_t sema = dispatch_semaphore_create(0);
        AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
        manager.responseSerializer = [AFHTTPResponseSerializer serializer];
        [manager GET:cdnURL parameters:nil headers:nil progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            
            oriImageData = responseObject;
            
            dispatch_semaphore_signal(sema);
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            dispatch_semaphore_signal(sema);
            oriDownloadError = error;
        }];
        dispatch_wait(sema, DISPATCH_TIME_FOREVER);
    }];
    
    
    NSBlockOperation *finalOp = [NSBlockOperation blockOperationWithBlock:^{
        
        if (oriImageData && thumbImageData && successHandler) {
            downloadModel.oriImageData = oriImageData;
            downloadModel.thumbImageData = thumbImageData;
            NSImage *tmpImage = [[NSImage alloc]initWithData:thumbImageData];
            downloadModel.oriImageSize = NSMakeSize(tmpImage.size.width, tmpImage.size.height);
            downloadModel.thumbImageSize = NSMakeSize(width, height);
            successHandler(downloadModel);
        }
        
    }];
    
    [finalOp addDependency:oriOp];
    [finalOp addDependency:thumbOp];
    [_msgQueue addOperation:oriOp];
    [_msgQueue addOperation:thumbOp];
    [_msgQueue addOperation:finalOp];
}
@end
