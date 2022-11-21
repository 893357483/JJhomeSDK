//
//  OptionModel.h
//  AuvilinkBell
//
//  Created by 王爽 on 15/7/24.
//  Copyright (c) 2015年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface ResolutionModel : NSObject
@property (nonatomic, assign) unsigned short channel;
@property (nonatomic, assign) unsigned short resolution;
@property (nonatomic, assign) unsigned short frameRate;
@property (nonatomic, assign) unsigned short reserve;
@end

@interface BodyInfoModel : NSObject
@property (nonatomic, assign) int channel;
@property (nonatomic, copy) NSString *sensitivity;

@end

@interface MotionInfoModel : NSObject
@property (nonatomic, assign) int channel;
@property (nonatomic, copy) NSString *sensitivity;
@end

@interface CoordinateModel : NSObject
@property (nonatomic, assign) unsigned short channel;
@property (nonatomic, assign) unsigned short type;
@property (nonatomic, assign) unsigned short x;
@property (nonatomic, assign) unsigned short y;
@property (nonatomic, assign) unsigned short radius;
@end

@interface CameraInfoModel : NSObject
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *version;
@property (nonatomic, copy) NSString *manufacture;
@property (nonatomic, copy) NSString *totalSpace;
@property (nonatomic, copy) NSString *freeSpace;
@property (nonatomic, copy) NSString *remainBattery;
@end

@interface FileItem : NSObject
@property (nonatomic, assign) CGFloat  beginSeconds;
@property (nonatomic, assign) CGFloat  endSeconds;
@property (nonatomic, strong) NSArray *filehandleArray;
@property (nonatomic, assign) int beginYear;
@property (nonatomic, assign) int beginMonth;
@property (nonatomic, assign) int beginDay;
@property (nonatomic, assign) int beginHour;
@property (nonatomic, assign) int beginMinute;
@property (nonatomic, assign) int beginSecond;
@property (nonatomic, assign) int beginMilliSeconds;
@property (nonatomic, assign) int endYear;
@property (nonatomic, assign) int endMonth;
@property (nonatomic, assign) int endDay;
@property (nonatomic, assign) int endHour;
@property (nonatomic, assign) int endMinute;
@property (nonatomic, assign) int endSecond;
@property (nonatomic, assign) int endMilliSeconds;
@property (nonatomic, assign) int fileType;//2019-11.30新增
@end

//32宫格区域监测模型
@interface MotionRegionInfoModel : NSObject
@property (nonatomic, copy) NSString *enable;//是否打开检测
@property (nonatomic, copy) NSString *lines;//行
@property (nonatomic, copy) NSString *colunms;//列
//检测灵敏度--相当于:触发区域数/选中区域数(框选的区域里满足多少个就触发检测level就填几)
@property (nonatomic, copy) NSString *level;

/*
 当前格子为选中区域时为1,未选中为0,如:
 0 0 0 0 0 1 1 1   它的32宫格区域如图显示    ⬜️⬜️⬜️⬜️⬜️⬛️⬛️⬛️
 1 0 1 0 0 0 0 0 ----------------------->⬛️⬜️⬛️⬜️⬜️⬜️⬜️⬜️
 0 0 0 0 0 0 0 0 ----------------------->⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️
 0 0 0 0 0 0 1 1                         ⬜️⬜️⬜️⬜️⬜️⬜️⬛️⬛️
 
 motionDataArray里的结构则为:@[@"0",@"0",@"0",@"0",@"0",@"1",@"1",@"1",@"1",@"0",@"1",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"0",@"1",@"1"];
 **/
@property (nonatomic, copy) NSArray *motionDataArray;


@end
@interface MotionScheduleInfoModel : NSObject

@property (nonatomic, strong) NSMutableArray *motionSchedule1;//[0]:switch,[1]:start_hour,[2]:start minute,[3]:end_hour,[4]:end_minute,[5~11]:sunday~saturday,打开为1,关闭为0, 12-15还未用到自动补0
@property (nonatomic, strong) NSMutableArray *motionSchedule2;
@property (nonatomic, strong) NSMutableArray *motionSchedule3;
@end
@interface OptionModel : NSObject

@end
