//
//  NSImage+GIFHelper.h
//  WechatMacMessageRobotFramework
//
//  Created by sylar on 2021/3/16.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSImage (GIFHelper)
- (BOOL)isGifImage;
- (BOOL)saveAnimatedGIFToFile:(NSString*)filepath;
@end

NS_ASSUME_NONNULL_END
