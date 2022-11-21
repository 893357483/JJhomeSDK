//
//  DeviceTool.h
//  AuvilinkBell
//
//  Created by 王爽 on 15/7/20.
//  Copyright (c) 2015年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DeviceTool : NSObject
/**
 *  获取手机当前ssid
 */
+ (NSString *) getDeviceSSID;
/**
 *  打开手电筒
 */
+ (void)turnOnLed:(BOOL)update;
/**
 *  关闭手电筒
 */
+ (void)turnOffLed:(BOOL)update;

+ (NSString *) localWiFiIPAddress;

+ (NSString *)getCurrentLanguage;

+ (NSString *)getIPAddress:(BOOL)preferIPv4;

@end
