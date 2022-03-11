//
//  QueryMeetingInfo.h
//  JustMeeting
//
//  Created by dutingfu on 16/1/23.
//  Copyright © 2016年 青牛软件. All rights reserved.
//

#import "BCSPostBaseDataAdaptor.h"

@interface QueryMeetingInfo : BCSPostBaseDataAdaptor
- (NSInteger)GetMeetingInfo:(NSInteger)meetingID succeed:(void (^)(id))succeed failed:(void (^)(long, NSString *))failed;
- (NSInteger)GetMeetingInfoWithToken:(NSString *)token meetingID:(NSInteger)meetingID succeed:(void (^)(id))succeed failed:(void (^)(long, NSString *))failed;
@end
