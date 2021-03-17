//
//  NSImage+GIFHelper.m
//  WechatMacMessageRobotFramework
//
//  Created by sylar on 2021/3/16.
//

#import "NSImage+GIFHelper.h"

@implementation NSImage (GIFHelper)
- (BOOL)isGifImage
{
  @try {
        NSArray * reps = [self representations];
        for (NSImageRep * rep in reps)
        {
            if ([rep isKindOfClass:[NSBitmapImageRep class]] == YES)
            {
                NSBitmapImageRep * bitmapRep = (NSBitmapImageRep *)rep;
                int numFrame = [[bitmapRep valueForProperty:NSImageFrameCount] intValue];
                return numFrame > 1;
            }
        }
    }@catch (NSException * e) {
    }
    @finally {
    }
    return NO;
}

- (BOOL)saveAnimatedGIFToFile:(NSString*)filepath
{
    //(NSBitmapImageRep *firstFrame, NSBitmapImageRep *secondFrame,
    // NSString *animatedGIFPath)
    
    // options to set the delay on each frame of 2 seconds
    //
    // options to turn on looping for the GIF
    
    @try {
        NSArray * reps = [self representations];
        for (NSImageRep * rep in reps)
        {
            if ([rep isKindOfClass:[NSBitmapImageRep class]] == YES)
            {
                NSBitmapImageRep * bitmapRep = (NSBitmapImageRep *)rep;
                int numFrame = [[bitmapRep valueForProperty:NSImageFrameCount] intValue];
                if (numFrame == 0){
                    NSData *data = [bitmapRep representationUsingType:NSGIFFileType properties: nil];
                    return [data writeToFile:filepath atomically:NO];
                }
                
                // set the place to save the GIF to
#if  __has_feature(objc_arc)
                CGImageDestinationRef animatedGIF = CGImageDestinationCreateWithURL((__bridge CFURLRef) [NSURL fileURLWithPath:filepath],
                                                                                    kUTTypeGIF,
                                                                                    numFrame,
                                                                                    NULL
                                                                                    );
#else
                CGImageDestinationRef animatedGIF = CGImageDestinationCreateWithURL((CFURLRef) [NSURL fileURLWithPath:filepath],
                                                                                    kUTTypeGIF,
                                                                                    numFrame,
                                                                                    NULL
                                                                                    );
#endif
                
                CGBitmapInfo bitmapInfo = kCGBitmapByteOrderDefault | kCGImageAlphaPremultipliedLast; //kCGImageAlphaNoneSkipFirst
                
                CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
                int bitsPerComponent = 8;
                
                for (int i = 0; i < numFrame; ++i)
                {
                    [bitmapRep setProperty:NSImageCurrentFrame withValue:@(i)];
                    
                    CGDataProviderRef frameProvider = CGDataProviderCreateWithData(NULL,
                                                                                   [bitmapRep bitmapData],
                                                                                   [bitmapRep bytesPerRow] * [bitmapRep pixelsHigh],
                                                                                   NULL
                                                                                   );
                    
                    CGImageRef cgFrame = CGImageCreate ([bitmapRep pixelsWide],
                                                        [bitmapRep pixelsHigh],
                                                        bitsPerComponent,
                                                        [bitmapRep bitsPerPixel],
                                                        [bitmapRep bytesPerRow],
                                                        colorSpaceRef,
                                                        bitmapInfo,
                                                        frameProvider,
                                                        NULL,
                                                        NO,
                                                        kCGRenderingIntentDefault
                                                        );
                    
                    if (cgFrame) {
                        
                        float duration = [[bitmapRep valueForProperty:NSImageCurrentFrameDuration] floatValue];
                        /*
                         NSDictionary *frameProperties = [NSDictionary dictionaryWithObject:
                         [NSDictionary dictionaryWithObject:[NSNumber numberWithFloat:duration]
                         forKey:(NSString *)kCGImagePropertyGIFDelayTime]
                         forKey:(NSString *)kCGImagePropertyGIFDictionary];
                         */
                        
                        NSDictionary *frameProperties = @{ (NSString *)kCGImagePropertyGIFDictionary: @{ (NSString *)kCGImagePropertyGIFDelayTime : @(duration) } };
                        
#if  __has_feature(objc_arc)
                        CGImageDestinationAddImage(animatedGIF, cgFrame, (__bridge CFDictionaryRef)frameProperties);
#else
                        CGImageDestinationAddImage(animatedGIF, cgFrame, (CFDictionaryRef)frameProperties);
#endif
                        CGImageRelease(cgFrame);
                    }
                    
                    CGDataProviderRelease(frameProvider);
                    
                }
                
                CGColorSpaceRelease(colorSpaceRef);
                
                /*
                 NSDictionary *gifProperties = [NSDictionary dictionaryWithObject:[NSDictionary dictionaryWithObject:[NSNumber numberWithInt:0]
                 forKey:(NSString *) kCGImagePropertyGIFLoopCount]
                 forKey:(NSString *) kCGImagePropertyGIFDictionary];
                 */
                
                NSDictionary *gifProperties = @{ (NSString *)kCGImagePropertyGIFDictionary: @{ (NSString *)kCGImagePropertyGIFLoopCount : @0 } };
                
                
#if  __has_feature(objc_arc)
                CGImageDestinationSetProperties(animatedGIF, (__bridge CFDictionaryRef) gifProperties);
#else
                CGImageDestinationSetProperties(animatedGIF, (CFDictionaryRef) gifProperties);
#endif
                
                CGImageDestinationFinalize(animatedGIF);
                CFRelease(animatedGIF);
                
            }
        }
        
        return YES;
    }
    @catch (NSException * e) {
        NSLog(@"save gif e=%@",e);
        return NO;
    }
    @finally {
    }
}
@end
