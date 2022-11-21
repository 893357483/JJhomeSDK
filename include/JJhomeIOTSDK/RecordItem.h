//
//  RecordAudio.h
//  AuvilinkBell
//
//  Created by 王爽 on 15/9/16.
//  Copyright (c) 2015年 王爽. All rights reserved.
//
//  手机麦克风录音，传输到设备

#import <Foundation/Foundation.h>




@interface RecordItem : NSObject
@property (nonatomic, assign) unsigned long int session;
@property (nonatomic, assign) unsigned short speakBufferSize;
@property (nonatomic, assign) int encodeType;
@property (nonatomic, assign) int isHalfDuplex;
- (void)startRecordWithClient:(unsigned long int)client andWithChannel:(unsigned long int)channel andWithStreamID:(unsigned long int)streamID andWithUserID:(unsigned long int)userID;
- (void)stopRecord;
@end
