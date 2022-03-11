//
//  ModifyMeetingInviters.h
//  DataCenter
//
//  Created by dshy1234 on 5/17/15.
//  Copyright (c) 2015 redcdn. All rights reserved.
//

#import "BCSPostBaseDataAdaptor.h"

@interface ModifyMeetingInviters : BCSPostBaseDataAdaptor
- (int)modifymeetingInviter:(NSString *)token
                  meetingId:(int)meetingId
               invotedUsers:(NSArray *)invotedUsers
              invotedPhones:(NSArray *)invotedPhones
                        app:(NSString *)app
                    succeed:(void (^)(id resData))succeed
                     failed:(void (^)(long errorCode, NSString *des))failed;
/*
 smsType 1：即时会议 2 预约会议 不传默认为即时会议
 */
- (int)sendMeettingInviteMSG:(NSString *)token
                  meetingId:(int)meetingId
               invotedUsers:(NSArray *)invotedUsers
              invotedPhones:(NSArray *)invotedPhones
                        app:(NSString *)app
                        smsType:(int)smsType
                    succeed:(void (^)(id resData))succeed
                     failed:(void (^)(long errorCode, NSString *des))failed;
@end
