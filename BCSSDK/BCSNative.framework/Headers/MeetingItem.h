//
//  MeetingItem.h
//  BCSNative
//
//  Created by huxinwen65 on 2020/7/9.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MeetingItem : NSObject

//会议id
@property (copy, nonatomic) NSNumber *    meetingId;
//会议创建者id
@property (copy, nonatomic)NSString *    creatorId;
//会议创建者name
@property (copy, nonatomic)NSString *    creatorName;
//会议创建时间(采用UTC时间，与1970年1月1日的时间差，单位s)
@property (assign, nonatomic)long    createTime;
@property (assign, nonatomic)long    expectStarttime;
@property (assign, nonatomic)long    expectEndtime;
// 预约会议新增字段
// 会议类型 字段 即时会议    1  预约会议    2
@property(assign,nonatomic)   NSInteger  meetingType;
// 主题
@property(copy,nonatomic)     NSString * topic;
// 是否有会议密码，0：无，1：有
@property(assign,nonatomic) int hasMeetingPwd;
// 会议主持人，当前即会议创建者
@property(copy,nonatomic) NSString * meetingHost;

@end

NS_ASSUME_NONNULL_END
