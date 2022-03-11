//
//  CheckMeetingPwd.h
//  DataCenter
//
//  Created by dutingfu on 16/9/1.
//  Copyright © 2016年 dutingfu. All rights reserved.
//

#import "BCSPostBaseDataAdaptor.h"

@interface CheckMeetingPwd : BCSPostBaseDataAdaptor

/// 设置会议和检查密码
/// @param token 鉴权token
/// @param meetingId 会议号
/// @param meetingPwd 会议室密码
/// @param succeed 成功的回调
/// @param failed 失败的回调
/// @return 0 成功；其他失败
- (int)CheckMeetingPwdWithToken:(NSString *)token
                      meetingId:(int)meetingId
                     meetingPwd:(NSString *)meetingPwd
                        succeed:(void (^)(id resData))succeed
                         failed:(void (^)(long errorCode, NSString *des))failed;


/// 设置会议和检查密码
/// @param meetingId 会议号
/// @param meetingPwd 会议室密码
/// @param succeed 成功的回调
/// @param failed 失败的回调
/// @return 0 成功；其他失败
- (int)CheckMeetingPwdMeetingId:(int)meetingId
                     meetingPwd:(NSString *)meetingPwd
                        succeed:(void (^)(id resData))succeed
                         failed:(void (^)(long errorCode, NSString *des))failed;
@end
