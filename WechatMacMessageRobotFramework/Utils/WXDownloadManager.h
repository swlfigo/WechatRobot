//
//  WXDownloadManager.h
//  WechatMacMessageRobotFramework
//
//  Created by sylar on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import <Appkit/Appkit.h>
#import "WeChatHeader.h"
NS_ASSUME_NONNULL_BEGIN

@interface WXDownloadModel : NSObject

@property(nonatomic,strong)NSData *oriImageData;
@property(nonatomic,strong)NSData *thumbImageData;
@property(nonatomic,assign)CGSize oriImageSize;
@property(nonatomic,assign)CGSize thumbImageSize;

@end

@interface WXDownloadManager : NSObject
+(instancetype) shareInstance;

-(void)downloadStickerMsgData:(MessageData *)msgData success:(void(^)(WXDownloadModel *downloadModel))successHandler;

@end

NS_ASSUME_NONNULL_END
