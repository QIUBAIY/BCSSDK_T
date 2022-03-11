//
//  MeetingInfoItem.h
//  JustMeeting
//
//  Created by dutingfu on 16/1/23.
//  Copyright © 2016年 青牛软件. All rights reserved.
//

#import "BCSPostBaseDataAdaptor.h"

@interface AttendeesItem : NSObject

@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *nube;

@end

@interface MeetingInfoItem : NSObject
@property (nonatomic, copy) NSString *meetingid;//会议编号
@property (nonatomic, copy) NSString *name;//会议名称
@property (nonatomic, assign) int meetingtype;//会议类型；1:即时会议，2:预约会议
@property (nonatomic, assign) int meetingmode;//会议模式；1.自由模式; 2.主持人模式;
@property (nonatomic, copy) NSString *starttime;//会议开始时间，格式为：yyyy-MM-dd HH:mm:ss；
@property (nonatomic, copy) NSString *endtime;//会议结束时间，格式为：yyyy-MM-dd HH:mm:ss；
@property (nonatomic, copy) NSString *password;//密码
@property (nonatomic, copy) NSString *managenube;//主持人视讯号
@property (nonatomic, assign) BOOL isrecord;//是否开启会议录制
@property (nonatomic, assign) BOOL usepassword;//是否开启会议密码
@property (nonatomic, assign) BOOL usenotify;//是否发送短信通知
@property (nonatomic, copy) NSArray<AttendeesItem *> *attendees;//参会方列表
@property (nonatomic, copy) NSDictionary *meetingstatus;//会议状态
/*
 recording [boolean]    是    是否正在录制
 living [boolean]    是    是否正在直播
 inmeeting [boolean]    是    是否正在会议中
 */

@end


