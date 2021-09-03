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
    [objc_getClass("MMMessageCacheMgr") jr_swizzleMethod:@selector(originalImageWithMessage:completion:) withMethod:@selector(hook_originalImageWithMessage:completion:) error:nil];
    [objc_getClass("EmoticonMgr") jr_swizzleMethod:@selector(getEmotionImgWithMD5:) withMethod:@selector(hook_getEmotionImgWithMD5:) error:nil];

    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(dictionaryWithData:) withMethod:@selector(hook_dictionaryWithData:) error:nil];
    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(dictionaryWithParser:) withMethod:@selector(hook_dictionaryWithParser:) error:nil];
    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(dictionaryWithFile:) withMethod:@selector(hook_dictionaryWithFile:) error:nil];
    [objc_getClass("XMLDictionaryParser") jr_swizzleMethod:@selector(nameForNode:inDictionary:) withMethod:@selector(hook_nameForNode:inDictionary:) error:nil];
    [objc_getClass("FFProcessReqsvrZZ") jr_swizzleMethod:@selector(FFProcessTReqZZ:toUsrName:msgText:atUserList:) withMethod:@selector(hook_FFProcessTReqZZ:toUsrName:msgText:atUserList:) error:nil];
    [objc_getClass("MMChatMessageDataSource") jr_swizzleMethod:@selector(onAddMsg:msgData:) withMethod:@selector(hook_onAddMsg:msgData:) error:nil];


}

/**
 hook 微信消息同步
 
 */

//New Version
- (id)hook_FFProcessTReqZZ:(id)arg1 toUsrName:(id)arg2 msgText:(id)arg3 atUserList:(id)arg4{
    id instance = [self hook_FFProcessTReqZZ:arg1 toUsrName:arg2 msgText:arg3 atUserList:arg4];
    return instance;
}

//Receive New Msg
- (void)hook_onAddMsg:(id)arg1 msgData:(MessageData *)arg2{
    [self hook_onAddMsg:arg1 msgData:arg2];
    if (![arg2 isKindOfClass:objc_getClass("MessageData")]) return;
    if (arg2.messageType == 47 &&  ![arg2.msgContent isEqualToString:@""] && arg2.msgContent && arg2.msgContent.length > 0) {
        //sticker
        [self handleStickMsg:arg2];
    }
    
}

-(void)handleStickMsg:(MessageData *)msgData{
   
    FFProcessReqsvrZZ *msgService = [[objc_getClass("MMServiceCenter") defaultCenter] getService:objc_getClass("FFProcessReqsvrZZ")];
    if (msgData.isChatRoomMessage) {
        //Chat Room
        if (msgData.msgContent && msgData.msgContent.length > 0) {
            NSRange beginRange = [msgData.msgContent rangeOfString:@"cdnurl = \""];
            NSRange endRange = [msgData.msgContent rangeOfString:@"\" designerid"];
            if (beginRange.location != NSNotFound && endRange.location != NSNotFound) {
                NSString *cdnURL = [msgData.msgContent substringWithRange:NSMakeRange(beginRange.location+beginRange.length, endRange.location - beginRange.location - beginRange.length)];
                
                cdnURL = [cdnURL stringByReplacingOccurrencesOfString:@"&amp;" withString:@"&"];
                
                if (cdnURL) {
                    [msgService FFProcessTReqZZ:msgData.toUsrName toUsrName:msgData.fromUsrName msgText:[NSString stringWithFormat:@"Sticker Download URL : %@" , cdnURL ] atUserList:nil];
                }
            }
            
        }
        return;
    }
    //      xml 转 dict
    XMLDictionaryParser *xmlParser = [objc_getClass("XMLDictionaryParser") sharedInstance];
    NSDictionary *msgDict = [xmlParser dictionaryWithString:msgData.msgContent];
    NSString *cdnURL = msgDict[@"emoji"][@"_cdnurl"];

    
    //Anthoer Friend Send You
    //This Name is Your Name
    NSString *toUserName = msgDict[@"emoji"][@"_tousername"];
    //This Name is Your Friend Name
    NSString *fromUserName = msgDict[@"emoji"][@"_fromusername"];
    
    NSString *currentUserName = [objc_getClass("CUtility") GetCurrentUserName];

    if (cdnURL) {
        [msgService FFProcessTReqZZ:currentUserName toUsrName:fromUserName msgText:[NSString stringWithFormat:@"Sticker Download URL : %@" , cdnURL ] atUserList:nil];
    }else{
        [msgService FFProcessTReqZZ:currentUserName toUsrName:fromUserName msgText:@"Can't Get Sticker Download URL" atUserList:nil];
    }
    

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
