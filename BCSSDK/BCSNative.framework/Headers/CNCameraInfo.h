//
//  CNCameraInfo.h
//  JMeetingFramework
//
//  Created by dutingfu on 2017/4/25.
//  Copyright © 2017年 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CNCameraInfo : NSObject

/// 摄像头采集宽度
@property(nonatomic,assign) int width;

/// 摄像头采集高度
@property(nonatomic,assign) int height;

/// 摄像头采集码率
@property(nonatomic,assign) int bitrate;

/// 摄像头帧率
@property(nonatomic,assign) int fps;

@end
