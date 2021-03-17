//
//  NSObject+hook.m
//  WechatMacMessageRobotFramework
//
//  Created by Sylar on 2021/3/16.
//

#import "NSObject+hook.h"
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import "JRSwizzle.h"
#import <objc/runtime.h>
#import "WeChatHeader.h"
#import "WXDownloadManager.h"
#import "NSImage+GIFHelper.h"
@implementation NSObject (hook)
+ (void)hookWeChat{
    [objc_getClass("MessageService") jr_swizzleMethod:@selector(FFImgToOnFavInfoInfoVCZZ:isFirstSync:) withMethod:@selector(hook_OnSyncBatchAddMsgs:isFirstSync:) error:nil];
    [objc_getClass("MessageService") jr_swizzleMethod:@selector(SendImgMessage:toUsrName:thumbImgData:midImgData:imgData:imgInfo:) withMethod:@selector(hook_SendImgMessage:toUsrName:thumbImgData:midImgData:imgData:imgInfo:) error:nil];
    [objc_getClass("MessageService") jr_swizzleMethod:@selector(SendTextMessage:toUsrName:msgText:atUserList:) withMethod:@selector(hook_SendTextMessage:toUsrName:msgText:atUserList:) error:nil];
    [objc_getClass("MessageService") jr_swizzleMethod:@selector(notifyNewMsgNotificationOnMainThread:msgData:) withMethod:@selector(hook_notifyNewMsgNotificationOnMainThread:msgData:) error:nil];
    [objc_getClass("MMMessageCacheMgr") jr_swizzleMethod:@selector(originalImageWithMessage:completion:) withMethod:@selector(hook_originalImageWithMessage:completion:) error:nil];
    [objc_getClass("EmoticonMgr") jr_swizzleMethod:@selector(getEmotionImgWithMD5:) withMethod:@selector(hook_getEmotionImgWithMD5:) error:nil];

    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(dictionaryWithData:) withMethod:@selector(hook_dictionaryWithData:) error:nil];
    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(dictionaryWithParser:) withMethod:@selector(hook_dictionaryWithParser:) error:nil];
    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(dictionaryWithFile:) withMethod:@selector(hook_dictionaryWithFile:) error:nil];
    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(nameForNode:inDictionary:) withMethod:@selector(hook_nameForNode:inDictionary:) error:nil];

}

/**
 hook 微信消息同步
 
 */
- (void)hook_OnSyncBatchAddMsgs:(NSArray *)msgs isFirstSync:(BOOL)arg2 {
    [self hook_OnSyncBatchAddMsgs:msgs isFirstSync:arg2];
    [msgs enumerateObjectsUsingBlock:^(AddMsg *addMsg, NSUInteger idx, BOOL * _Nonnull stop) {
        NSDate *now = [NSDate date];
        NSTimeInterval nowSecond = now.timeIntervalSince1970;
        if (nowSecond - addMsg.createTime > 180) {      // 若是3分钟前的消息，则不进行自动回复与远程控制。
            return;
        }
        if (addMsg.msgType == 47) {
            //Sticker
        }
        
    }];
    
}



//Receive New Msg
-(void)hook_notifyNewMsgNotificationOnMainThread:(id)arg1 msgData:(MessageData *)arg2{
    [self hook_notifyNewMsgNotificationOnMainThread:arg1 msgData:arg2];
    if (![arg2 isKindOfClass:objc_getClass("MessageData")]) return;
    if (arg2.messageType == 47 &&  ![arg2.msgContent isEqualToString:@""] && arg2.msgContent && arg2.msgContent.length > 0) {
        //sticker
        [self handleStickMsg:arg2];
    }
    
}

-(void)handleStickMsg:(MessageData *)msgData{
   
    MessageService *msgService = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("MessageService")];
    if (msgData.isChatRoomMessage) {
        //Chat Room
        if (msgData.msgContent && msgData.msgContent.length > 0) {
            NSError *error;
            NSString *pattern = @"cdnurl = \"http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?";
            NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:pattern options:NSRegularExpressionCaseInsensitive error:&error];
            NSArray<NSTextCheckingResult *> *result = [regex matchesInString:msgData.msgContent options:0 range:NSMakeRange(0, msgData.msgContent.length)];
                if (result) {
                    for (int i = 0; i<result.count; i++) {
                        NSTextCheckingResult *res = result[i];
                        NSString *cdnURLStr =  [msgData.msgContent substringWithRange:res.range];
                        cdnURLStr = [cdnURLStr stringByReplacingOccurrencesOfString:@"cdnurl = \"" withString:@""];
                        [msgService SendTextMessage:msgData.toUsrName toUsrName:msgData.fromUsrName msgText:[NSString stringWithFormat:@"Sticker Download URL : %@" , cdnURLStr ] atUserList:nil];
                    }
                }
        }
        return;
    }
    //      xml 转 dict
    XMLDictionaryParser *xmlParser = [objc_getClass("XMLDictionaryParser") sharedInstance];
    NSDictionary *msgDict = [xmlParser dictionaryWithString:msgData.msgContent];
    MMMessageCacheMgr *mgr = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("MMMessageCacheMgr")];
    NSString *cdnURL = msgDict[@"emoji"][@"_cdnurl"];
    NSString *thumbURL = msgDict[@"emoji"][@"_thumburl"];
    NSString *md5 = msgDict[@"emoji"][@"_md5"];
    CGFloat height = [msgDict[@"emoji"][@"_height"] floatValue];
    CGFloat width = [msgDict[@"emoji"][@"_width"] floatValue];
    
    //Anthoer Friend Send You
    //This Name is Your Name
    NSString *toUserName = msgDict[@"emoji"][@"_tousername"];
    //This Name is Your Friend Name
    NSString *fromUserName = msgDict[@"emoji"][@"_fromusername"];
    
    NSString *currentUserName = [objc_getClass("CUtility") GetCurrentUserName];

    if (cdnURL) {
        [msgService SendTextMessage:currentUserName toUsrName:fromUserName msgText:[NSString stringWithFormat:@"Sticker Download URL : %@" , cdnURL ] atUserList:nil];
    }else{
        [msgService SendTextMessage:currentUserName toUsrName:fromUserName msgText:@"Can't Get Sticker Download URL" atUserList:nil];
    }
    
//_productid system not nil

}

- (void)hook_originalImageWithMessage:(id)arg1 completion:(id)arg2{
    [self hook_originalImageWithMessage:arg1 completion:arg2];
}

-(id)hook_getEmotionImgWithMD5:(id)arg1{
    id obj = [self hook_getEmotionImgWithMD5:arg1];
    return obj;
}

-(id)hook_SendImgMessage:(id)arg1 toUsrName:(id)arg2 thumbImgData:(id)arg3 midImgData:(id)arg4 imgData:(id)arg5 imgInfo:(id)arg6{
    id obj = [self hook_SendImgMessage:arg1 toUsrName:arg2 thumbImgData:arg3 midImgData:arg4 imgData:arg5 imgInfo:arg6];
    return obj;
}

- (id)hook_SendTextMessage:(id)arg1 toUsrName:(id)arg2 msgText:(id)arg3 atUserList:(id)arg4{
    id obj = [self hook_SendTextMessage:arg1 toUsrName:arg2 msgText:arg3 atUserList:arg4];
    return obj;
}


- (id)hook_dictionaryWithData:(id)arg1{
    id obj = [self hook_dictionaryWithData:arg1];
    return obj;
}
- (id)hook_dictionaryWithParser:(id)arg1{
    id obj = [self hook_dictionaryWithParser:arg1];
    return obj;
}
- (id)hook_dictionaryWithFile:(id)arg1{
    id obj = [self hook_dictionaryWithFile:arg1];
    return obj;
}
- (id)hook_nameForNode:(id)arg1 inDictionary:(id)arg2{
    id obj = [self hook_nameForNode:arg1 inDictionary:arg2];
    return obj;
}
@end
