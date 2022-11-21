//
//  XJOpenALHelper.h
//  JJhomeIOTSDK
//
//  Created by 徐健 on 2018/10/19.
//  Copyright © 2018年 王爽. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenAL/al.h>
#import <OpenAL/alc.h>

NS_ASSUME_NONNULL_BEGIN

@interface XJOpenALHelper : NSObject
//初始化openAL
- (BOOL)startPlayer :(int)sampleRate;

//不用时先调用清除, 再销毁对象
- (void)stopPlayer;

//添加音频数据到队列内
- (bool)sendData:(unsigned char *)data size:(UInt32)size aec:(bool)isAec;

//设置音量
- (void)setVolum:(float)volum;

- (int)getBuffer;

- (void)cleanBuffers;
@end

NS_ASSUME_NONNULL_END
