//
//  BTVideoParamInfo.h
//  BCSNative
//
//  Created by ButelMac on 2020/11/26.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 视频参数
@interface BTVideoParamInfo : NSObject
/*
 编码模式：
 0.自定义(选择自定义编码参数有效）
 1.FHD:1080p
 2.HD:720p
 3.VGA:360p
 4.QVGA:180p
 5.UHD:4k
 */
@property(nonatomic,assign)BTVideoEncodingMode encMode;
/// 编码码率
@property(nonatomic,assign)int encBitrate;
/// 编码帧率
@property(nonatomic,assign)int encFps;
/// 编码宽
@property(nonatomic,assign)int encWidht;
/// 编码高
@property(nonatomic,assign)int encHeight;
/*
 接收视频模式：
 0.自适应（默认值，SDK内部动态调整）
 1.高清，接收大流
 2.标清，接收小流
 */
@property(nonatomic,assign)BTVideoReceivedMode recvMode;

@end

NS_ASSUME_NONNULL_END
