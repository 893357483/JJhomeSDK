//
//  JJPushServer.h
//  JJhomeIOTSDK
//
//  Created by 徐健 on 2018/11/1.
//  Copyright © 2018年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CameraItem.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    CMD_100 = 100,  // 设备列表的第一个设备，推送服务器会先删除其他数据再添加
    CMD_101,             // 设备列表其他设备
    CMD_102,             // 设备列表为空时清除推送服务器设备
    CMD_103,             // 分享设备,发送通知消息
    CMD_104,             // 取消分享设备,发送通知消息
    CMD_105,             // 设备强制添加，删除已经绑定的设备,并发送通知消息
    CMD_106,             // 退出登录
    CMD_107,             // 解除绑定，删库
    CMD_109 = 109,        // 绑定微信openid
    CMD_112 = 112,       //绑定设备名称
} PushCmd;

@protocol JJPushDelegate <NSObject>
@optional
- (void)jjPushServerSendSuccessWithDeviceId:(NSString *)deviceId userId:(NSString *)userId pushCmd:(NSInteger)pushCmd;
- (void)jjPushServerSendFailureWithDeviceId:(NSString *)deviceId userId:(NSString *)userId pushCmd:(NSInteger)pushCmd errInfo:(NSString *)errInfo;
- (void)jjPushServerSendSuccessWithIP:(NSString *)ip port:(NSInteger)port pushCmd:(NSInteger)pushCmd;
- (void)jjPushServerSendFailureWithIP:(NSString *)ip port:(NSInteger)port pushCmd:(NSInteger)pushCmd errInfo:(NSString *)errInfo;

@end

@interface JJPushServer : NSObject
@property (nonatomic, weak) id <JJPushDelegate> delegate;
+ (JJPushServer *)shareJJPush;

// 设备列表为空时绑定用户，并清空推送服务器设备 102
/*
 *  @param serverIp 用户登录时返回的推送服务器IP
*  @param port 用户登录时返回的推送服务器端口
 *  @param userId 用户ID
 *  @param deviceToken  注册的推送的token
 *  @param pushId  APPd推送ID，平台分配
 */
- (void)clearDevicesFromServerIp:(NSString *)serverIp port:(NSInteger)port userId:(NSString *)userId deviceToken:(NSData *)deviceToken pushId:(NSInteger)pushId;

// 绑定所有设备  100、101
/*
 *  @param deviceList 设备列表
 *  @param userId 用户ID
 *  @param deviceToken  注册的推送的token
 *  @param pushId  APPd推送ID，平台分配
 */
- (void)bindDeviceList:(NSArray<CameraItem *> *)deviceList userId:(NSString *)userId deviceToken:(NSData *)deviceToken pushId:(NSInteger)pushId;


// 解绑所有设备 106
- (void)unBindAllDeviceWithUserId:(NSString *)userId deviceToken:(NSData *)deviceToken pushId:(NSInteger)pushId;

// 发送分享设备通知  103
/*
 *  @param cameraItem 分享的设备
 *  @param userId 被分享用户ID
 *  @param ip 被分享用户推送服务器IP
 *  @param port   被分享用户推送服务器端口
 *  @param deviceToken  注册的推送的token
 *  @param pushId  APPd推送ID，平台分配
 */
- (void)shareDevice:(CameraItem *)cameraItem toUserId:(NSString *)userId userPushServerIp:(NSString *)ip userPushServerPort:(NSInteger)port  deviceToken:(NSData *)deviceToken pushId:(NSInteger)pushId;

// 发送取消分享设备通知,并解除绑定  104
/*
 *  @param cameraItem 取消分享的设备
 *  @param userId 被分享用户ID
 *  @param ip 被分享用户推送服务器IP
 *  @param port   被分享用户推送服务器端口
 *  @param deviceToken  注册的推送的token
 *  @param pushId  APPd推送ID，平台分配
 */
- (void)unShareDevice:(CameraItem *)cameraItem toUserId:(NSString *)userId userPushServerIp:(NSString *)ip userPushServerPort:(NSInteger)port  deviceToken:(NSData *)deviceToken pushId:(NSInteger)pushId;


//  解除绑定（删除设备）107
- (void)unBindDevice:(CameraItem *)cameraItem userId:(NSString *)userId deviceToken:(NSData *)deviceToken pushId:(NSInteger)pushId;

// 解除绑定，并通知用户（强制添加已被添加的设备时调用）105
/*
 *  @param cameraItem 添加的设备
 *  @param oldUserId 设备当前绑定的用户ID
 */
- (void)addDevice:(CameraItem *)cameraItem fromOldUserId:(NSString *)oldUserId;
@end

NS_ASSUME_NONNULL_END
