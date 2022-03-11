//
//  MeetingInfo.h
//  AFNetworking iOS Example
//
//  Created by dshy1234 on 5/13/15.
//  Copyright (c) 2015 Gowalla. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MeetingInfo : NSObject
@property(strong, nonatomic) NSString * meetingId;
@property(strong, nonatomic) NSString * adminPhoneId;
//会议创建者id
@property (nonatomic, copy) NSString *creatorId;
- (instancetype)initWithInfo:(MeetingInfo *)info;
@end
