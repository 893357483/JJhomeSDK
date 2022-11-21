//
//  CStreamItem.h
//  Auvilink
//
//  Created by 王爽 on 15/6/11.
//  Copyright (c) 2015年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface YUVModel : NSObject

@property (nonatomic, assign) unsigned char *yuvData;
@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;

@end

@interface AudioModel : NSObject
@property (nonatomic, assign) unsigned char *audioData;
@property (nonatomic, assign) int length;
@property (nonatomic, assign) double time;
@end

@interface VideoModel:NSObject
@property (nonatomic, assign) unsigned char *videoData;
@property (nonatomic, assign) int length;
@property (nonatomic, assign) double time;
@end


@class CStreamItem;
@protocol CStreamItemDelegate <NSObject>
@optional
// 码率、总流量回调
- (void)cStreamItem:(CStreamItem *)item getFlowRate:(int)rate andWithTotalRate:(CGFloat)totalRate;
// 第一帧回调
- (void)cStreamItemGotFirstVideoFrame:(CStreamItem *)item;
// 视频回调
- (void)cStreamItem:(CStreamItem *)item getVideoData:(YUVModel *)yuvModel;
// 音频回调
- (int)cStreamItem:(CStreamItem *)item getAudioData:(AudioModel *)audioModel;
// 音视频回放时间信息回调
- (void)cStreamItem:(CStreamItem *)item getYear:(int)year month:(int)month day:(int)day hour:(int)hour minute:(int)minute second:(int)second milliscond:(int)milliscond;
@end


typedef void (^ImageBlock) (UIImage *displayImage);
typedef void(^YUVDataBlock)(YUVModel *model);
typedef void(^AudioDataBlock)(AudioModel *model);
@interface CStreamItem : NSObject

@property (nonatomic, assign) unsigned long int mReader;
@property (nonatomic, assign) unsigned long int audioReader;
@property (nonatomic, assign) unsigned long int mClient;
@property (nonatomic, assign) unsigned long int mSession;
@property (nonatomic, assign) unsigned long int mAudioSession;
@property (nonatomic, assign) BOOL mWaitForIFrame;
@property (nonatomic, assign) unsigned long int  mFrameDecoder;
@property (nonatomic, weak) id <CStreamItemDelegate> delegate;
@property (nonatomic, assign) BOOL gotFirstVideoFrame;
@property (nonatomic, assign) unsigned short bufferSize;
@property (nonatomic, strong) NSMutableArray *videoCacheArray;
@property (nonatomic, strong) NSMutableArray *mp4VideoCacheArray;
@property (nonatomic, strong) NSMutableArray *audioCacheArray;
@property (nonatomic, strong) NSMutableArray *mp4AudioCacheArray;
@property (nonatomic, assign) int m_bWaitForIFrame;
@property (nonatomic, assign) BOOL noDisplay;
@property (nonatomic, assign) BOOL noPlayAudio;
@property (nonatomic, assign) BOOL noPlayHistoryVideo;
@property (nonatomic, assign) BOOL mp4Recording;
@property (nonatomic, assign) BOOL iFrame;

/**
 *  打开音视频实时预览
 *
 *  @param nChannel  默认0
 *  @param nstreamID 默认0
 */
- (void)startPlayWithChannel:(int)nChannel andStreamID:(int)nStreamID;

/**
 *  打开音视频回放
 *
 *  @param nChannel  默认0
 *  @param nstreamID 默认0
 */
- (void)startPlayBackWithChannel:(int)nChannel andWithStreamID:(int)nStreamID;

/**
 *  停止音视频
 */
- (void)stop;

/**
 *  截屏
 */
- (UIImage *)screenCaptureWithVideoModel:(YUVModel *)model;

// 设置亮度
- (void)setVideoLightness:(CGFloat)offset;


/**
 *  视频录制（mp4）
 *
 *  @param width 视频宽度
 *  @param height   视频高
 *  @param frameRate 帧率
 *  @param filePath 文件保存路径
 */
- (void)startMP4VideoRecordWithWidth:(int)width andWithHeight:(int)height andFramerate:(int)frameRate andWithFilePath:(nullable NSString *)filePath;

/**
 *  停止视频录制（mp4）
 */
- (void)stopMP4VideoRecord;
@end
