//
//  JJhomeIOT.h
//  JJhomeIOTSDK
//
//  Created by 王爽 on 2018/9/4.
//  Copyright © 2018年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"
#import "CameraItem.h"

@protocol JJhomeIOTDelegate <NSObject>
@optional
/**搜索到设备回调*/
- (void)jjhomeSearchedDeviceWithDict:(nullable NSDictionary *)dict;


@end


@interface JJhomeIOT : NSObject
@property (nonatomic, weak, nullable) id <JJhomeIOTDelegate> delegate;
@property(nonatomic,strong)NSString * _Nullable kAppid;

typedef void(^SuccessBlock)(id _Nullable obj);
typedef void(^FailureBlock)(id _Nullable obj);

+ (JJhomeIOT *_Nonnull)shareJJhomeIOT;

// 初始化，在程序入口处调用
- (void)initIOT;

//  程序推到后台调用
- (void)enterBackground;

// 程序回到前台调用
- (void)enterForeground;

// pragma mark - 搜索设备
- (void)searchDevie;

/*获取设备P2P服务器信息
 无需登录，面向无用户模式
 @param devices 设备ID,若是多少ID用逗号分隔
 */
- (void)getP2PInfoWithDevices:(nonnull NSString *)devices success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/*注册新用户(无需验证码校验)(暂时弃用)
 *  @param username 用户名（手机号、邮箱）
 *  @param userpass 密码
 *  @param usertype 用户类型 （@"phone_no"或@"email"）
 *  @param appId    app唯一ID （由平台分配）
 *  @param successBlock  请求成功回调
 *  @param failureBlock  请求失败回调
 */
- (void)registerWithUsername:(nonnull NSString *)username andWithUserPass:(nonnull NSString *)userpass andWithUsertype:(nonnull NSString *)usertype andWithAppId:(nonnull NSString *)appId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/*注册新用户(需验证码校验)
 *  @param username 用户名（手机号、邮箱）
 *  @param userpass 密码
 *  @param usertype 用户类型 （@"phone_no"或@"email"）
 *  @param appId    app唯一ID （由平台分配）
 *  @param verificationCode    验证码 （由平台分配）
 *  @param successBlock  请求成功回调
 *  @param failureBlock  请求失败回调
 */

- (void)registerWithUsername:(nonnull NSString *)username andWithUserPass:(nonnull NSString *)userpass andWithUsertype:(nonnull NSString *)usertype andWithAppId:(nonnull NSString *)appId verificationCode:(nonnull NSString *)verificationCode success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/*发送验证码 (已弃用)
 *  @param userName 用户名（手机号、邮箱）
 *  @param userType 用户类型 （@"phone_no"或@"email"）
 *  @param appId    app唯一ID （由平台分配）
 *  @param verificationCode (自己生成的6位数字）
 *  @param successBlock  请求成功回调
 *  @param failureBlock  请求失败回调
 */
- (void)sendVerificationCodeWithUserName:(nonnull NSString *)userName userType:(nonnull NSString *)userType verificationCode:(nonnull NSString *)verificationCode appId:(nonnull NSString *)appId success:(nonnull SuccessBlock)successBlock failure:(nonnull FailureBlock)failureBlock DEPRECATED_MSG_ATTRIBUTE("Please use [[JJhomeIOT shareJJhomeIOT]  getVerificationCodeWithUserName:]");

/*获取验证码
 *  @param userName 用户名（手机号、邮箱）
 *  @param userType 用户类型 （"phone_no":手机用户  "email":电子邮箱用户）
 *  @param appId    app唯一ID （由平台分配）
 *  @param task_type    事务类型 （1:注册用户 2:重置密码）
 *  @param successBlock  请求成功回调
 *  @param failureBlock  请求失败回调
 */
- (void)getVerificationCodeWithUserName:(nonnull NSString *)userName userType:(nonnull NSString *)userType taskType:(NSInteger)taskType appId:(nonnull NSString *)appId success:(nonnull SuccessBlock)successBlock failure:(nonnull FailureBlock)failureBlock;

/*登陆
 *  @param username 用户名（手机号、邮箱）
 *  @param userpass 密码
 *  @param usertype 用户类型 （@"phone_no"或@"email"）
 *  @param appId    app唯一ID （由平台分配）
 *  @param successBlock  请求成功回调
 *  @param failureBlock  请求失败回调
 */
- (void)loginWithUsername:(nonnull NSString *)username andWithUserpass:(nonnull NSString *)userpass andWithUsertype:(nonnull NSString *)usertype andWithAppId:(nonnull NSString *)appId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/*修改用户密码（需先登录）
 *  @param oldPasswd 旧密码
 *  @param newPasswd  新密码
 */
- (void)modifyUserPassWithOldPasswd:(nonnull NSString *)oldPasswd newPasswd:(nonnull NSString *)newPasswd success:(nonnull SuccessBlock)successBlock failure:(nonnull FailureBlock)failureBlock;

/*重置用户密码
 *  @param userName 用户名
 *  @param veriCode 校验码
 *  @param newPasswd  新密码
 *  @param appId    app唯一ID （由平台分配）
 */
- (void)resetUserPassWithUserName:(nonnull NSString *)userName veriCode:(nonnull NSString *)veriCode newPasswd:(nonnull NSString *)newPasswd appId:(nonnull NSString *)appId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

//  获取设备列表（需要先登录）
- (void)getDeviceListSuccessBlock:(nullable SuccessBlock)successBlock failureBlock:(nullable FailureBlock )failureBlock;

// 声波添加-初始化
- (void)acousticInit;

// 声波添加-声波发送
- (void)acousticSendRandom:(nonnull NSString *)random wifiName:(nonnull NSString *)wifiName wifiPasswd:(nonnull NSString *)wifiPasswd userId:(nonnull NSString *)userId successBlock:(nullable SuccessBlock)successBlock;

//   声波添加-结束（发送完成后需结束）
- (void)acousticEnd;

// 检查声波添加是否成功（需要先登录）
- (void)acousticAddCheckWithRandom:(nonnull NSString *)random success:(nonnull SuccessBlock)successBlock failure:(nonnull FailureBlock)failureBlock;



/* 添加设备（需要先登录）
 *  @param deviceId   设备ID
 *  @param deviceName 设备名称
 *  @param devicePasswd 设备密码
 *  @param deviceType 自定义设备类型 ：（例如，公版JJhome为“0”-IPC “1”-门铃 “2”-低功耗IPC）
*  @param security YES：添加前检测设备ID是否合法及是否已被其他用户添加，NO：不检查 强制添加
 */
- (void)addDeviceWithDeviceId:(nonnull NSString *)deviceId deviceName:(nonnull NSString *)deviceName devicePasswd:(nonnull NSString *)devicePasswd deviceType:(nonnull NSString*)deviceType security:(BOOL)security success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/*删除设备
 *  @param deviceId   设备ID
 *  @param isShareDevice 是否分享的设备
 */
- (void)deleteDeviceWithDeviceId:(nonnull NSString *)deviceId isShareDevice:(BOOL)isShareDevice success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/*修改设备名称或者密码，如果是修改设备密码，需要在【- (void)deviceChangePswordSuccess:(CameraItem *)item】回调函数中调用
 *  @param psword   修改后的密码
 *  @param name     修改后的名称
 */
- (void)rewriteDeviceWithDeviceId:(nonnull NSString *)deviceId psword:(nullable NSString *)psword orDeviceName:(nullable NSString *)name  success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

 /* 分享设备（需要先登录）
 *  @param deviceId                被分享的设备ID
 *  @param sharedUserName 被分享人的username
 *  @param sharedUserType   被分享人的类型 “email”、“phone_no”
 *  @param refName                备注名
 *  @param appId    app唯一ID （由平台分配）
 */
- (void)shareDeviceWithDeviceId:(nonnull NSString *)deviceId sharedUserName:(nonnull NSString *)sharedUserName sharedUserType:(nonnull NSString *)sharedUserType refName:(nonnull NSString *)refName appId:(nonnull NSString *)appId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;


/*取消分享设备（需要先登录）
 *  @param deviceId         被取消分享的设备ID
 *  @param sharedUserId 被分享人的userId
 */
- (void)unShareDeviceWithDeviceId:(nonnull NSString *)deviceId sharedUserId:(nonnull NSString *)sharedUserId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;


 /*分享的用户列表（需要先登录）
 *  @param deviceId         被取消分享的设备ID
 */
- (void)shareUserListWithDeviceId:(nonnull NSString *)deviceId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 获取设备事件列表（需要先登录） 2022.11.18更新
 *  @param cameraItem  设备Item
 *  @param dateString  筛选日期字符串(eg:2020-05-05),不筛选传nil
 *  @param type  筛选事件类型,1:访客 2:电量低 3:移动侦测 4:人体感应 5:声音侦测 6:防拆报警 10:人形检测,不筛选传0
 *  @param pageNO  页号
 *  @param pageSize  条/页
 *  @param timeZone  新增参数手机当前时区; 例如东八区 8，西八区 -8
 */
- (void)getEventListWithDevice:(CameraItem *_Nullable)cameraItem dateString:(NSString *_Nullable)dateString eventType:(int)type pageNo:(NSInteger)pageNO pageSize:(NSInteger)pageSize timeZone:(NSInteger)timeZone success:(SuccessBlock _Nullable )successBlock failure:(FailureBlock _Nullable )failureBlock;

/*  获取设备有事件的日期数组及设备所拥有的报警类型数组（需要先登录） 2022.11.18更新
*  @param cameraItem     设备Item
    类型,1:访客 2:电量低 3:移动侦测 4:人体感应 5:声音侦测 6:防拆报警 10:人形检测
 *  @param timeZone  新增参数手机当前时区; 例如东八区 8，西八区 -8
*/
- (void)getEventListDateAndTypeInfo:(CameraItem *_Nullable)cameraItem timeZone:(NSInteger)timeZone success:(SuccessBlock _Nullable )successBlock failure:(FailureBlock _Nullable)failureBlock;
/*  删除设备事件列表（需要先登录） 2022.11.18更新
 *  @param cameraItem     设备Item
 *  @param times  需要删除的时间（格式：2018:09:10 12:12:32）逗号隔开，全部删除设为空
 *  @param timeZone  新增参数手机当前时区; 例如东八区 8，西八区 -8
 */
- (void)deleteEventWithDevice:(CameraItem * _Nullable)cameraItem andTimes:(NSString * _Nullable)times timeZone:(NSInteger)timeZone success:(SuccessBlock _Nullable)successBlock failure:(FailureBlock _Nullable)failureBlock;



#pragma mark - 云存储部分
/* 产品套餐查询
 * @param type 套餐类型，海康机器人填“2”
 * @param pageNo 默认第一页
 */
- (void)cloudServiceProductListWithAppId:(nonnull NSString *)appId type:(NSInteger)type pageNo:(NSInteger)pageNo currency:(NSInteger)currency success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 提交订单 (需要先登录）
 * @param appId
 * @param productId  产品套餐id
 * @param devicdId   要开通服务的设备id
 */
- (void)cloudServiceOrderSubmitWithAppId:(nonnull NSString *)appId productId:(NSInteger)productId deviceId:(nonnull NSString *)devicdId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 订单微信支付-返回APP调起微信支付所需参数 (需要先登录）
 * @param appId
 * @param orderId  订单id
 */
- (void)cloudServiceWeixinPayWithAppId:(nonnull NSString *)appId orderId:(nonnull NSString *)orderId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 订单支付宝支付-返回APP调起支付宝支付所需参数 (需要先登录）
 * @param appId
 * @param orderId  订单id
successBlock返回支付宝支付所需已签名好参数,
 可直接调支付宝支付api:- (void)payOrder:(NSString *)orderStr fromScheme:(NSString *)schemeStr
  callback:(CompletionBlock)completionBlock 请求支付
 */
- (void)cloudServiceAliPayWithAppId:(nonnull NSString *)appId orderId:(nonnull NSString *)orderId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 订单paypal支付-返回APP调起微信支付所需参数 (需要先登录）
 * @param appId
 * @param orderId  订单id
   @param Environment  环境,0开发 1生产
 */
- (void)cloudServicePayPalWithAppId:(nonnull NSString *)appId orderId:(nonnull NSString *)orderId andEnvironment:(int)Environment success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 查询某个订单 (需要先登录）
 * @param appId
 * @param orderId  订单id
 */
- (void)cloudServiceOrderQueryWithAppId:(nonnull NSString *)appId orderId:(nonnull NSString *)orderId  success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 查询所有订单 (需要先登录）
 * @param appId
 * @param pageNo 默认第一页
 */
- (void)cloudServiceOrderQueryWithAppId:(nonnull NSString *)appId pageNo:(NSInteger)pageNo success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 查询PayPal订单 (需要先登录）
 * @param appId
 * @param payment_id
 */
- (void)cloudServiceOrderQueryWithAppId:(nonnull NSString *)appId payment_id:(nonnull NSString *)payment_id  environment:(NSInteger)environment success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 查询设备云存储服务开通情况 (需要先登录）
 * @param deviceId 查询的设备
 */
- (void)cloudServiceDeviceQueryWithDeviceId:(nonnull NSString *)deviceId success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 查询有云存储记录的日期 (需要先登录）
 * @param deviceId 查询的设备
 * @param timeZone 手机时区
 * @param startTime UTC开始时间 格式：“2019-08-30 02:33:42”
 * @param endTime UTC结束时间 格式：“2019-08-30 02:33:42”
 */
- (void)cloudStorageCalendarQueryWithDeviceId:(nonnull NSString *)deviceId timeZone:(NSInteger)timeZone startTime:(nullable NSString *)startTime endTime:(nullable NSString *)endTime success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;

/* 查询云存储记录 (需要先登录）
 * @param deviceId 查询的设备
 * @param pageNo 第几页
 * @param pageSize 每页返回的纪录
 * @param startTime UTC开始时间 格式：“2019-08-30 02:33:42”
 * @param endTime UTC结束时间 格式：“2019-08-30 02:33:42”
 */
- (void)cloudStorageQueryWithDeviceId:(nonnull NSString *)deviceId pageNo:(NSInteger)pageNo pageSize:(NSInteger)pageSize startTime:(nullable NSString *)startTime endTime:(nullable NSString *)endTime success:(nullable SuccessBlock)successBlock failure:(nullable FailureBlock)failureBlock;


@end
