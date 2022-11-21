//
//  CommonTool.h
//  AuvilinkBell
//
//  Created by 王爽 on 15/8/12.
//  Copyright (c) 2015年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface CommonTool : NSObject
//16进制转字符串
+ (NSString *)stringFromHexString:(NSString *)hexString;
//字符串转16进制
+ (NSString *)hexStringFromString:(NSString *)string;
//生成6位随机数
+ (NSString *)getSixRandomNumber;
//生成8位随机数
+ (NSString *)getEightRandomNumber;
//获得屏幕图像
+ (UIImage *)imageFromView: (UIView *) theView;
//获得某个范围内的屏幕图像
+ (UIImage *)imageFromView: (UIView *) theView   atFrame:(CGRect)r;
//yuv数据转成image
+ (UIImage *)convertYUVDataToImageWithYUVData:(unsigned char *)yuvData andWithWidth:(int)width andWithHeight:(int)height;
+ (UIImage *)convertPixBufferToImageWithBuffer:(CVPixelBufferRef)pixelBuffer;

//获取当前屏幕显示的viewcontroller
+ (UIViewController *)getCurrentVC;
//获取推送数据
+ (NSData *)getpushDataWithCMD:(int)cmd andDeviceId:(NSString *)devId andUserId:(NSString *)userId andDeviceToken:(NSData *)deviceToken andPushId:(int)pushId;
+ (NSData *)getpushDataWithCMD:(int)cmd andWithUserId:(NSString *)userId andWithDeviceId:(NSString *)devId;
+ (NSData *)getpushDataWithCMD:(int)cmd andDeviceToken:(NSData *)deviceToken andUserId:(NSString *)userId;
+ (NSData *)getpushDataWithCMD:(int)cmd andDeviceId:(NSString *)devId andDeviceName:(NSString *)deviceName;

unsigned int CheckSum(char *addr, int count);


/**
 *常规ImageView
 */
+ (UIImageView *)createCommonImageViewWithX:(float)x Y:(float)y Widht:(float)width Height:(float)height BgImage:(NSString *)bgImage;

+ (UIButton *)buttonWithX:(float)x Y:(float)y Width:(float)width Height:(float)height Image:(NSString *)image BgImage:(NSString *)bgImage Target:(id)target action:(SEL)selector;
/**
 *常规Button
 */
+ (UIButton *)createCommonButtonWithX:(float)x Y:(float)y Width:(float)width Height:(float)height Image:(NSString *)image BgImage:(NSString *)bgImage Title:(NSString *)text TitleColor:(UIColor *)color;
/**
 *常规Label
 */
+ (UILabel *)createCommonLabelWithX:(float)x Y:(float)y Widht:(float)width Height:(float)height Text:(NSString *)text Font:(int)font TextColor:(UIColor *)color;

// 获取MP4第一帧
+ (UIImage*) thumbnailImageForVideo:(NSURL *)videoURL atTime:(NSTimeInterval)time;

+ (BOOL)isChinese;

/*
 根据指定输入字符串输出二维码图片
 random:参照 声波添加-声波发送流程的random
 wifiname:WiFi名称
 wifipsd:WiFi密码
 userid:用户id
 return: 一张给设备识别的二维码
 */
+ (UIImage *)getQRCodeImageWithRandom:(NSString *)random wifiName:(NSString *)wifiname wifiPsd:(NSString *)wifiPsd andUserId:(NSString *)userid;
@end
