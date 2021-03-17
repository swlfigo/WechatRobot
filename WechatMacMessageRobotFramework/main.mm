//
//  main.m
//  WechatMacMessageRobotFramework
//
//  Created by Sylar on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import "NSObject+hook.h"

static void __attribute__((constructor)) initialize(void) {
    [NSObject hookWeChat];
}

