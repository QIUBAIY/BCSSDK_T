//
//  GetMeetingInfo.h
//  DataCenter
//
//  Created by dshy1234 on 5/17/15.
//  Copyright (c) 2015 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GetMeetingInfo : NSObject
@property(assign, nonatomic)   int meetingId;
@property(strong, nonatomic)  NSString *phoneId;
@property(strong, nonatomic)  NSString *creatorName;
@property(strong, nonatomic)  NSString *createTime;
@property(strong, nonatomic)  NSString * expectStarttime;
@property(assign,nonatomic)   NSInteger  meetingType;
@property(copy,nonatomic)     NSString * topic;
// 兼容JMeetingSdk 添加的 creatorId
@property(copy,nonatomic)   NSString *	creatorId;
@property(assign, nonatomic)   int count;
@property(assign,nonatomic) int hasMeetingPwd;
@property(copy,nonatomic) NSString * meetingHost;
@property(copy,nonatomic) NSString * expectEndtime;

- (instancetype)initWithInfo:(GetMeetingInfo *)info;

@end
