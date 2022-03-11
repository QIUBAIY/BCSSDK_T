//
//  CurMeetingInfo.h
//  UdpEchoClient
//
//  Created by dshy1234 on 15/4/22.
//
//

#import <Foundation/Foundation.h>
#import "ButelOpenSDKConst.h"

@interface CurMeetingInfo : NSObject

/******** 关闭摄像头 ********/
//@property (assign,nonatomic)BOOL isCloseCamera;
/// 是否是自适应模式 YES 自适应模式，NO 不是自适应模式
//@property (assign,nonatomic)BOOL isAudioMode;

/******** 模式变化相关 ********/
//@property (assign,nonatomic)ModeStatusCode mode;
//@property (assign,nonatomic)ModeStatusCode userMode;

/******** 当前参会者信息 ********/
@property (assign,nonatomic)int meetingId;
@property (strong,nonatomic)NSString *adminId;
@property (strong,nonatomic)NSString *accountId;
@property (strong,nonatomic)NSString *accountName;
@property (strong,nonatomic)NSString *accountToken;
@property (assign,nonatomic)int memberStatus;
//@property (assign,nonatomic)int micId;
@property (assign,nonatomic)int intentLockInfo;
@property (assign,nonatomic)int actionLocked;

@property (strong,nonatomic)NSString *masterId;
@property (assign,nonatomic)int userType; //参会用户类型，1为普通用户；2为主持人用户。
@property (assign,nonatomic)int meetingStyle; //会议模式，1为自由模式；2为主持人模式。
@property (assign,nonatomic)int actionMeetingStyle;
@property (strong,nonatomic)NSString *masterName;
@property (assign,nonatomic)int liveStatus; //直播状态，1代表直播会议，2代表普通会议。
@property (assign,nonatomic)int ChatStatus;//1消息打开0关闭
@property (strong,nonatomic)NSString *actionKeyNoteSpeacker; //将要指定的主讲人
/// 发言者总数
@property (assign,nonatomic)int sTotalNum;
/// 参会方总数
@property (assign,nonatomic)int pTotalNum;

/******** 文档分享数据 ********/
@property (assign,nonatomic)int width;
@property (assign,nonatomic)int height;
@property (assign,nonatomic)int vedioRate;
@property (assign,nonatomic)int mediaType;



/******** 当前会议发言者信息 ********/
//@property (strong,nonatomic)NSString *mic1UserId;
//@property (strong,nonatomic)NSString *mic2UserId;
//@property (strong,nonatomic)NSString *mic1UserName;
//@property (strong,nonatomic)NSString *mic2UserName;

@property (strong,nonatomic)NSMutableArray *speakerInfos;

/******** 是否在处理981 ********/
@property (assign,nonatomic)BOOL isDealWith981;
@property (assign,nonatomic)int exceptionRetryTime;

/// 最大发言方数
@property (nonatomic,assign) int speakersNum;

/// 当前混音流id
@property (nonatomic,assign) int scribeAudioStreamID;

- (NSArray *)getSpeakers;
/*
 返回发言者信息数组
 */
- (NSMutableArray *)getMeetingSpeakers;

#pragma mark - Setoge: -2020.8.13-添加是否支持MPU
/// 会议的mpu模式 类型int 0：没有mpu 1：mpu平等模式
@property (nonatomic,assign) int mpuMode;
#pragma mark - Setoge: -2020.8.14-mpu未互动的发言者
@property (strong,nonatomic)NSMutableArray *mpuSpeakerInfos;
/// 设置全体静音状态，  0：关闭静音   1：开启静音 默认 0
@property (nonatomic,assign) int muteStatus;
/// 是否允许用户自动取消静音， 0：不允许用户自动取消静音  1：允许用户自动取消静音 默认 1
@property (nonatomic,assign) int unmuteable;
///// 释放会议信息资源
//- (void)destroyMeetingInfo;
@property (nonatomic,strong) CaptionAndThemeInfo *captionInfo;
@property (nonatomic,strong) CaptionAndThemeInfo *themeInfo;
@end
