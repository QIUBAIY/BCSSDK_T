//
//  CMCMDCacheInfo.h
//  BCSNative
//
//  Created by ButelMac on 2020/11/24.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CMCMDCacheInfo : NSObject

/// 类型为String 业务细分命令，相同的命令缓存覆盖更新
@property (nonatomic,copy) NSString *cmdKey;
/// 类型为String，为终端转发的实际内容
@property (nonatomic,copy) NSString *cmdValue;
/// int值，1代表需要删除服务器内存中对应的cmdKey，该值为1时，可以不携带cmdValue
@property (nonatomic,assign) int delFlag;

/// stp 服务器会自动添加 time，用于排序
@property (nonatomic,assign) int time;

@end

NS_ASSUME_NONNULL_END
