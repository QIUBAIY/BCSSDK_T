//
//  AudioRecordParam.h
//  BCSNative
//
//  Created by 杨礼正 on 2021/12/9.
//  Copyright © 2021 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AudioRecordParam : NSObject
// 采样率
@property(nonatomic,assign) int sampleRate;
// 声道数
@property(nonatomic,assign) int  channels;

@end

NS_ASSUME_NONNULL_END
