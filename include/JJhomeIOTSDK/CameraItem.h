//
//  CameraItem.h
//  Auvilink
//
//  Created by 王爽 on 15/6/10.
//  Copyright (c) 2015年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OptionModel.h"
#import "CStreamItem.h"
#import "RecordItem.h"

@class CameraItem;
@class CameraInfoModel;

@protocol CameraItemDelegate <NSObject>
@optional
// 登录成功回调
- (void)cameraItemLoginSuccess:(CameraItem *_Nullable)item;
// 在线回调
- (void)succeedOnLine:(CameraItem *_Nullable)item;
// 离线回调
- (void)offLine:(CameraItem *_Nullable)item;
// 密码错误回调
- (void)pswordError:(CameraItem *_Nullable)item;
// 修改密码成功回调
- (void)cameraItemChangedPsword:(CameraItem *_Nullable)cameraItem;
// 开始回放回调
- (void)cameraItemStartPlayback:(CameraItem *_Nullable)cameraItem;
// 停止回放回调
- (void)cameraItemStopPlayback:(CameraItem *_Nullable)cameraItem;
// 无SD卡回调
- (void)cameraItemNoSDCard:(CameraItem *_Nullable)cameraItem;
// 获取历史视频文件回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getHistoryVideoFiles:(NSArray *_Nullable)fileArray;
// 获取设备信息回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getCameraInfo:(CameraInfoModel *_Nullable)model;
// 获取时设备区信息回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getTimeZone:(NSString *_Nullable)timeZone;
// 获取设备分辨率回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getVideoResolution:(ResolutionModel *_Nullable)model;
// 获取设备录像模式回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getRecordMode:(NSString *_Nullable)mode;
// 获取人体感应试模式回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getBodyInfo:(BodyInfoModel *_Nullable)model;
// 获取移动侦测模式回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getMotionInfo:(MotionInfoModel *_Nullable)model;
// 获取声音测试模式回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getBabyVoiceInfo:(MotionInfoModel *_Nullable)model;
// 获取镜像模式回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getMirrorhand:(unsigned char) mirrorhand andFlip:(unsigned char)flip;
// 检查更新回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem needUpdate:(int)update;
// 获取指示灯颜色回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getLedColor:(char)ledColor;
// 获取指示灯开关回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getLedSwitch:(MotionInfoModel *_Nullable)model;
// 更新回调
- (void)cameraItemUpdate:(CameraItem *_Nullable)cameraItem;
// 获取更新进度回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getUpdateProcess:(int)updateProcess;
// 配置时区成功回调
- (void)cameraItemSetTimeZoneSuccess:(CameraItem *_Nullable)cameraItem;
// 配置时间成功回调
- (void)cameraItemSetTimeSuccess:(CameraItem *_Nullable)cameraItem;
// 配置WIFI成功回调
- (void)cameraItemConfigWifiSuccess:(CameraItem *_Nullable)cameraItem;
// 配置分辨率成功回调
- (void)cameraItemSetVideoResolutionSuccess:(CameraItem *_Nullable)cameraItem;
// 配置录像模式成功回调
- (void)cameraItemSetRecordingModeSuccess:(CameraItem *_Nullable)cameraItem;
// 配置人体感应模式成功回调
- (void)cameraItemSetIRSuccess:(CameraItem *_Nullable)cameraItem;
// 配置移动侦测成功回调
- (void)cameraItemSetMotionDetectionSuccess:(CameraItem *_Nullable)cameraItem;
// 配置声音侦测成功回调
- (void)cameraItemSetBabyVoiceInfoSuccess:(CameraItem *_Nullable)cameraItem;
// 配置指示灯颜色成功回调
- (void)cameraItemSetLedColorSuccess:(CameraItem *_Nullable)cameraItem;
// 配置指示灯开关成功回调
- (void)cameraItemSetLedSwitchSuccess:(CameraItem *_Nullable)cameraItem;
// 配置镜像模式成功回调
- (void)cameraItemSetMirrorhandFlipSuccess:(CameraItem *_Nullable)cameraItem;
// 配置成功回调
- (void)cameraItemSetVideoStreamInfoSuccess:(CameraItem *_Nullable)cameraItem;
// 获取在线观看人数回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getUserCount:(short)userCount andMaxUserCount:(short)maxUserCount;
// 获取鱼眼参数回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getCoordinateModel:(CoordinateModel *_Nullable)model;
// 获取门铃锁状态回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getDoorLockStatus:(char)doorLockStatus;
// 设置门铃锁状态回调
- (void)cameraItemSetDoorLockStatusSuccess:(CameraItem *_Nullable)cameraItem;
// 获取云存储服务开关回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getRtmpServiceStatus:(unsigned short)status;
// 设置云存储服务开关回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem setRtmpServiceSuccess:(int)success;
// 获取SD开有录像的日期回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getMonthRecordSuccess:(NSArray *_Nullable)dayArray year:(NSInteger)year month:(NSInteger)month;
// 获取设备提示语回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getLanguageBack:(int)result;
// 设置设备提示语回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem setLanguageBack:(int)result;
// 获取设备振动报警回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getShakeAlarmBack:(int)result;
// 设置设备振动报警回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem setShakeAlarmBack:(int)result;
// 获取设备报警声音回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getPlayAlarmVoiceBack:(int)result;
// 设置重启设备成功回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getRestartBack:(int)result;
// 设置复位设备成功回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getResetBack:(int)result;
// 获取32宫格设置回调
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getMotionRegionInfo:(MotionRegionInfoModel *_Nullable)model;
// 设置32宫格成功回调
- (void)cameraItemSetMotionRegionSuccess:(CameraItem *_Nullable)cameraItem;


/// 获取Wi-Fi信号强度成功
/// - Parameters:
///   - cameraItem: 设备
///   - value: 信号强度值，需要-100，绝对值越小信号越强
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getWifiRssiSuccess:(int)value;

/** 设置失败回调
 CmdId:
 2009:设置分辨率
 2015:设置密码
 2019:设置时区
 2021:设置时间
 2027:设置录像模式
 2031:设置移动侦测
 2035:设置人体感应
 2081:声音侦测
 2099:提示灯开关
 2168:设置移动侦测时段
 2137:设置录像储存方式
 2176:设置声光报警
 2180:设置pir报警时间间隔
 2200:Wi-Fi信号强度
 */
- (void)cameraItemSetConfigFailure:(CameraItem *_Nullable)cameraItem withCmdId:(NSInteger)CmdID;

//2020.4.9新增
// 获取移动侦测设置时段
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getMotionScheduleInfo:(MotionScheduleInfoModel *_Nullable)model;
// 设置移动侦测时段成功
- (void)cameraItemSetMotionScheduleSuccess:(CameraItem *_Nullable)cameraItem;

// 获取录像储存方式
//0,closed; 1,local storage; 2,cloud storage
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getStorageModeStatus:(int)status;
// 设置录像储存方式成功
- (void)cameraItemSetStorageModeSuccess:(CameraItem *_Nullable)cameraItem;

//获取声光报警回调
//status:0.关闭 1.只闪灯 2.只喇叭报警 3.闪灯加喇叭
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getVoiceLightBack:(int)status;
// 设置声光报警成功
- (void)cameraItemSetVoiceLightSuccess:(CameraItem *_Nullable)cameraItem;

//获取pir报警时间间隔回调
//3-600秒
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getPirAlarmTimeIntervalBack:(int)interval;
// 设置pir报警时间间隔成功
- (void)cameraItemSetPirAlarmTimeIntervalSuccess:(CameraItem *_Nullable)cameraItem;

//获取lvst ledmode回调 0自动模式(默认)，1触发模式，2开灯，3关灯。
- (void)cameraItem:(CameraItem *_Nullable)cameraItem getLvstLedModeBack:(int)status;
// 设置lvst led set成功
- (void)cameraItemSetLvstLedModeSuccess:(CameraItem *_Nullable)cameraItem;

/**
 //-1    密码错误
 // 0    搜索中
 // 1    搜索成功
 // 2    正在穿透
 // 3    穿透成功
 // 4    正在转发
 // 5    转发成功
 //10    登录成功/在线
 */
- (void)cameraItemConnectStatus:(int)statusCode;
@end

/**历史视频模型*/
@interface HistoryVideoItem : NSObject
@property (nonatomic, strong, nullable) NSDate  *beginDate;
@property (nonatomic, strong, nullable) NSDate  *endDate;
@property (nonatomic, strong, nullable) NSArray *filehandleArray;
@end

@interface CameraItem : NSObject

typedef void(^SuccessBlock)(id _Nullable obj);
typedef void(^FailureBlock)(id _Nullable obj);

@property (nonatomic, assign)  unsigned long int mReader;
@property (nonatomic, assign) unsigned long int csItemReader;
@property (nonatomic, assign) unsigned long int audioReader;

@property (nonatomic, assign) unsigned long int mClient;
@property (nonatomic, assign) unsigned long int mSession;
@property (nonatomic, assign) unsigned long int mSearchSession;
@property (nonatomic, assign) BOOL firstOnLine;
@property (nonatomic, weak) id <CameraItemDelegate> _Nullable delegate;
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable cameraId;
@property (nonatomic, copy) NSString * _Nullable psword;
@property (nonatomic, copy) NSString * _Nullable username;
@property (nonatomic, copy) NSString * _Nullable type;// 设备类型（后台服务器中），1：门铃，0：IPC，2：低功耗IPC
@property (nonatomic, assign) int deviceType; // 设备类型（设备返回），0：未知设备，1：门铃，2：IPC，3：低功耗IPC
@property (nonatomic, assign) BOOL shared;
@property (nonatomic, assign) BOOL connecting;
@property (nonatomic, assign) BOOL playing;
@property (nonatomic, assign) int alertCount;
@property (nonatomic, strong) CStreamItem * _Nullable csItem;
@property (nonatomic, strong) RecordItem * _Nullable recordItem;
@property (nonatomic, strong) NSData * _Nullable lastImageData;
@property (nonatomic, assign) BOOL pswordError;
@property (nonatomic, copy) NSString * _Nullable cameraIp;
@property (nonatomic, assign) short userCount;
@property (nonatomic, assign) short maxUserCount;

@property (nonatomic, copy) NSString * _Nullable p2pServerIp;
@property (nonatomic, assign) int p2pServerPort;
@property (nonatomic, assign) BOOL onLine;
@property (nonatomic, assign) BOOL isLogin;
@property (nonatomic, copy) NSString * _Nullable isp;
@property (nonnull, copy) NSString *pushserver_ip;
@property (nonatomic, assign) int push_port;
@property (nonatomic, strong) CoordinateModel * _Nullable coordinateModel;
@property (nonatomic, assign) int connectStatus; // 连接状态: 1、正在穿透 2、穿透成功 3、正在转发 4、转发成功
@property (nonatomic, assign) BOOL rtmpService; // 0:关闭， 1:打开

// 能力级 0:否 1:是
@property (nonatomic, assign) int isSupportFisheye; // 是否支持鱼眼
@property (nonatomic, assign) int isSupportHeadRock; // 是否摇头机
@property (nonatomic, assign) int isSupportMirrorFlip; // 是否支持镜像
@property (nonatomic, assign) int isSupportLowRate; // 是否支持低码率
@property (nonatomic, assign) int isHDX; // 是否半双工
@property (nonatomic, assign) int ledSwitch; // 状态指示灯开关功能
@property (nonatomic, assign) int canSetResolution; // 分辨率是否可调
@property (nonatomic, assign) int isAbleCloudStorage; // 是否支持云存储
@property (nonatomic, assign) int canSetLanguage; // 提示语
@property (nonatomic, assign) int canShakeAlarm; // 振动报警
@property (nonatomic, assign) int canBodyInduction; // 人体感应
@property (nonatomic, assign) int canMotionDetection; // 移动侦测
@property (nonatomic, assign) int canVoiceDetection; // 声音侦测
@property (nonatomic, assign) int canFormatSDCard; // 格式化SD卡
@property (nonatomic, assign) int canSyncTime; // 时间同步
@property (nonatomic, assign) int canSyncTimeZone; // 时区同步
@property (nonatomic, assign) int canUpgrade; // 固件升级
@property (nonatomic, assign) int isCanRestart; // 是否支持重启设备
@property (nonatomic, assign) int isCanReset; // 是否支持复位设备
@property (nonatomic, assign) int canMotionDetectionRegion; // 是否支持32宫格
//2020.4.9新增
@property (nonatomic, assign) int canMotionschedule; // 是否支持设置人体感应时间段
//2020.7.1
@property (nonatomic, assign) int canVoiceLight; // 是否支持设置声光报警
//2020.7.2
@property (nonatomic, assign) int canPirAlarmTimeInterval; // 是否支持Pir报警时间间隔
//22.11.18
@property (nonatomic, assign) int canGetWifiRssi;//是否支持获取Wi-Fi信号强度

// 连接设备
- (void)connectCameraItem:(CameraItem *_Nullable)item;

// 唤醒设备
- (void)wakeUpDevice;

// 断开设备
- (void)logoutCameraItem:(CameraItem *_Nullable)item;

// 重新设备
- (void)reconnectCameraItem:(CameraItem *_Nullable)item;

/**
 *  配置到WiFi
 *
 *  @param SSID   想要配置到的WiFi的名称
 *  @param password WiFi密码
 */
- (void)configWiFiWithSSID:(nonnull NSString *)SSID Password:(nonnull NSString*)password;

/**
 *  修改设备密码
 *
 *  @param oldPassword 原密码
 *  @param newPassword 修改后的密码
 */
- (void)modifyPasswordWithOldPassword:(nonnull NSString *)oldPassword newPassword:(nonnull NSString*)newPassword;


/**
 *  获取设备当前分辨率
 */
- (void)getVideoResolution;

/**
 *  设置视频分辨率
 *
 *  @param videoResolutionLevel 视频分辨率等级 0：标清 1：高清 2：流畅
 */
- (void)setVideoResolution:(int)videoResolutionLevel;

/**
 *  获取设备信息
 */
- (void)getDeviceInfo;

/**
 *  获取设备当前录像模式
 */
- (void)getRecordMode;

/**
 *  设置录像模式
 *
 *  @param recordModeLevel 录像模式等级 0：禁用 1：报警录像 2：全时录像
 */
- (void)setRecordMode:(int)recordModeLevel;

/**
 *  获取设备当前人体感应灵敏度
 */
- (void)getBodyReactionLevel;

/**
 *  设置人体感应灵敏度
 *
 *  @param level 人体感应灵敏度等级 0：禁用 1：低（30s） 2：中（20s）3：高（30s）
 */
- (void)setBodyReactionLevel:(int)level;

/**
 *  获取设备当前移动侦测灵敏度
 */
- (void)getMotionDetectionLevel;

/**
 *  设置移动侦测灵敏度
 *
 *  @param level 移动侦测等级 0：禁用 1：低 2：中 3：高 4：最高
 */
- (void)setMotionDetectionLevel:(int)level;

/**
 *  获取设备当前声音侦测灵敏度
 */
- (void)getVoiceDetectionLevel;

/**
 *  设置声音侦测灵敏度
 *
 *  @param level  50~120的值
 */
- (void)setVoiceDetectionLevel:(int)level;

/**
 *  获取设备当前时区
 */
- (void)getDeviceTimeZone;

/**
 *  设备时区与手机时区同步
 */
- (void)syncIPhoneTimeZoneToDevice;

/**
 *  设备时间与手机时间同步
 */
- (void)syncIPhoneTimeToDevice;
/**
 *  自定义设备时区与手机时区同步
 */
- (void)syncIPhoneTimeZoneToDeviceWithTimeZone:(NSTimeZone *_Nullable)timeZone;

/**
 *  自定义设备时间与手机时间同步
 */
- (void)syncIPhoneTimeToDeviceWithYear:(int)year month:(int)month day:(int)day hour:(int)hour minute:(int)minute second:(int)second;

/**
 *  设备格式SD卡
 */
- (void)formatSDCard;

/**
 *  获取LED灯开关
 */
- (void)getLedSwitchStatus;

/**
 *  设置LED灯开关
 * @param status 0:关 1:开
 */
- (void)setLedSwitchStatus:(int)status;

/**
 *  判断是否有固件更新
 */
- (void)ifFirmwareUpgrade;

/**
 *  固件更新
 */
- (void)firmwareUpgrade;

/**
 *  获取画面翻转状态
 */
- (void)getMirrorhandFlipStatus;

/**
 *  设置画面翻转
 *  先获取翻转状态在回调中设置!mirror、!flip
 */
- (void)setMirrorhand:(unsigned char)mirror andFlip:(unsigned char)flip;

/**
 *  摇头机方向控制
 *
 *  @param direction 摇头方向
 */
- (void)controlRequestWithDirection:(UISwipeGestureRecognizerDirection)direction;

/**
 *  获取从某月第一天开始后三十一天内有历史视频的日期
 *
 *  @param date 某月第一天
 */
- (void)requestHistoryVideoDayFromDate:(nullable NSDate *)date;

/**
 *  获取某天历史视频列表
 *
 *  @param date 获取哪一天的历史视频
 */
- (void)requestHistoryVideoFileWithDate:(nullable NSDate *)date;

/**
 *  开始播放历史视频方法1
 *
 *  @param item 根据FileItem对象
 */
- (void)startPlayHistoryVideoWithFileItem:(nonnull FileItem *)item inFileArray:(nonnull NSArray *)fileArray;

/**
 *  开始播放历史视频方法2
 *
 *  @param date 根据NSDate对象
 */
- (void)startPlayHistoryVideoWithDate:(nonnull NSDate *)date inFileArray:(nonnull NSArray *)fileArray;

/**
 *  暂停播放历史视频
 */
- (void)pausePlayHistoryVideo;

/**
 *  获取振动报警开关
 */
- (void)getShakeAlarmStatus;

/**
 *  设置振动报警开关
 * @param status 0:关 1:开
 */
- (void)setShakeAlarmStatus:(int)status;

/**
 *  获取设备语言
 */
- (void)getLanguage;

/**
 *  设置设备语言
 * @param language 0:中文 1:英文
 */
- (void)setLanguage:(int)language;

/**
 *  设置云存储开关
 * @param status 0:关闭 1:打开
 */
- (void)setCloudServiceStatus:(unsigned short)status;

/**
 *  查询云存储开关
 */
- (void)getCloudServiceStatus;

/**
*  播放警报声音 playAlarmVoice
*/
- (void)playAlarmVoice;

/**
 * 重启设备
 */
- (void)setRestartDevice;

/**
 * 复位设备
*/
- (void)setResetDevice;
/**
 * 获取32宫格设置
*/
- (void)motionDetectionRegionRequst;

/**
 *  设置32宫格 (MotionRegionInfoModel参数说明详见OptionModel类说明)
*/
- (void)configMotionRegion:(MotionRegionInfoModel *_Nullable)model;

//2020.4.9新增
//获取移动侦测设置时段
- (void)motionScheduleRequst;
//设置移动侦测时段
- (void)configMotionSchedule:(MotionScheduleInfoModel *_Nullable)model;

//获取录像存储方式
-(void)getStorageModeRequest;

//设置录像储存方式
//0,closed; 1,local storage; 2,cloud storage
-(void)setStorageMode:(int)storage;

//获取声光报警设置
-(void)getVoiceLightStatusRequest;

//设置声光报警
//0.关闭 1.只闪灯 2.只喇叭报警 3.闪灯加喇叭
-(void)setVoiceLightStatus:(int)status;

//获取pir报警间隔设置
-(void)getPirAlarmTimeIntervalRequest;

//设置pir报警间隔(单位:秒)
//1-600秒
-(void)setPirAlarmTimeInterval:(int)interval;

//获取LvstLedMode设置
-(void)getLvstLedModeRequest;

//设置LvstLedMode  0自动模式(默认)，1触发模式，2开灯，3关灯。
-(void)setLvstLedMode:(int)status;

//设置透传协议(data长度64)
-(void)setTransmissionWithData:(char *_Nullable)data;

/// 获取Wi-Fi信号强度
- (void)getWifiRssiReques;

- (void)sendCMDWithCMD:(int)cmd andRequest:(int)requestID andData:(char *_Nullable)data andLenth:(int)lenth;

@end

