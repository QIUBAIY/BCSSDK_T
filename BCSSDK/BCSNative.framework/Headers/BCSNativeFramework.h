//
//  BCSNative.h
//  BCSNative
//
//  Created by dshy1234 on 9/21/15.
//  Copyright (c) 2015 redcdn. All rights reserved.
//

#import <UIKit/UIKit.h>
//! Project version number for BCSNative.
FOUNDATION_EXPORT double BCSNativeVersionNumber;

//! Project version string for BCSNative.
FOUNDATION_EXPORT const unsigned char BCSNativeVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <BCSNative/PublicHeader.h>
#import <BCSNative/ConferenceSDK.h>
#import <BCSNative/ConferenceListener.h>
#import <BCSNative/Constants.h>
#import <BCSNative/BCSNative.h>
#import <BCSNative/BCSNative.h>
#import <BCSNative/CNCameraInfo.h>
#import <BCSNative/CNSpeakerInfo.h>

#import <BCSNative/CustomLog.h>
#import <BCSNative/DDLegacyMacros.h>
#import <BCSNative/DDFileLogger.h>
#import <BCSNative/DDLog.h>
#import <BCSNative/DDTTYLogger.h>
#import <BCSNative/MTFormatter.h>
#import <BCSNative/KeyEventWrite.h>
#import <BCSNative/KeyEventWriteConstant.h>
#import <BCSNative/Constant.h>
#import <BCSNative/ButelOpenSDK.h>
#import <BCSNative/LogManager.h>
#import <BCSNative/ButelOpenSDKConst.h>
#import <BCSNative/MeetingInfo.h>

#import <BCSNative/MeetingItem.h>

#import <BCSNative/CheckMeetingPwd.h>



#import <BCSNative/MeetingInfo.h>

#import <BCSNative/ConstConfig.h>
//#import <BCSNative/GetNowMeetings.h>

#import <BCSNative/UsersSearchMod.h>


#import <BCSNative/ModifyMeetingInviters.h>
#import <BCSNative/ChatMessageInfo.h>
//#import <BCSNative/GCDAsyncUdpSocket.h>

#import <BCSNative/Constant.h>
#import <BCSNative/MeetingInfoItem.h>


#import <BCSNative/KeyEventWrite.h>
#import <BCSNative/AuthenticateInfo.h>

#import <BCSNative/CMCMDCacheInfo.h>
#import <BCSNative/BTVideoParamInfo.h>
#import <BCSNative/CNQosInfoModel.h>
//#import <BCSNative/CaptionAndThemeInfo.h>
//#import <BCSNative/MTFormatter.h>
//#import <BCSNative/CaptionAndThemeInfo.h>
#import <BCSNative/CaptionAndThemeInfo.h>




#ifdef DEBUG
static const DDLogLevel ddLogLevel = LOG_LEVEL_VERBOSE;
#else
static const DDLogLevel ddLogLevel = LOG_LEVEL_VERBOSE;
#endif


// 极会议使用的时候，不要定义BUTELMEETING
#define BUTELMEETING




#define LogWriterD CustomLogV

// 判断是否为ios8
#define IOS8 ([[[UIDevice currentDevice]systemVersion] floatValue] >= 8.0)

// 判断是否为ios7
#define IOS7 ([[[UIDevice currentDevice]systemVersion] floatValue] >= 7.0)

// 判断IOS版本是否为6及以上
#define IOS6 ([[[UIDevice currentDevice]systemVersion] floatValue] >= 6.0)

// 判断IOS版本是否为[6.0, 7.0)
#define IOS6E ([[[UIDevice currentDevice]systemVersion] floatValue] >= 6.0 && [[[UIDevice currentDevice]systemVersion] floatValue] < 7.0)
/// 屏宽
#define UISCREENWIDTH  ([UIScreen mainScreen].bounds.size.width)
/// 屏高
#define UISCREENHEIGHT  ([UIScreen mainScreen].bounds.size.height)

typedef NS_ENUM(NSUInteger, EventCode) {
    EventCodeQuitByButel                     = 1001,  //可视端主动调用退出接口
    EventCodeQuitByInvalidToken              = 1002,  //会议过程中token失效
    EventCodeQuitByPhone                     = 1003,  //会议过程中收到用户来电
    EventCodeQuitByMeeting                   = 1004,  //会议室用户点击返回按钮
    EventCodeQuitByNetwork                   = 1005,  //会议过程中出现网络异常
    EventCodeQuitByMeetingLocked             = 1006,  //会议已锁定
    EventCodeQuitByBaseLibrary               = 1007,  //基础库异常
    EventCodeQuitByMeetingEnded              = 1008,  //会议已结束
    EventCodeQuitByMobileNetworkNotAllowed   = 1009,  //不允许使用移动网络进行会议
    EventCodeQuitBySMSInvited                = 1010,  //点击短信邀请退出会议
    EventCodeQuitByOtherError                = 1099,  //会议过程中出现其它异常
    EventCodeJoinMeeting                     = 1100,  //加入会议
    EventCodeMeetingIdInvalite               = 1101, // 加入会议失败，会议号无效
    EventCodeNetError                        = 1102, //网络差会议号查询失败
    EventCodeMeetingNotStart                 =  1103,// 会议尚未开始
    EventCodeAlarmStart                      = 1200,  //开始振铃
    EventCodeAlarmEndByCancel                = 1201,  //点击忽略按钮结束振铃
    EventCodeAlarmEndByTimeOut               = 1202,  //未执行任何操作振铃结束（此情况下可视端根据需求需要进行通知栏提示）
    EventCodeAlarmEndByJoinMeeting           = 1203,  //点击加入按钮结束振铃
    EventCodeAlarmCache                      = 1204,  // 振铃命令缓存
    EventCodeAlarmEndByApplicationEnterBackGround = 1205, // 应用切换到后台，取消振铃
    EventCodeButelInviteFromeMeetingRoom     = 1300,  //会议室内发起邀请
    EventCodeButelInvalidToken               = 1400,  //操作过程中出现token失效

    EventCodeButelKeyEventMeetingMenu                = 1601,  // 点击会议主菜单
    EventCodeButelKeyEventSpeak                      = 1602,  // 发言操作
    EventCodeButelKeyEventCancelSpeak                = 1603,  // 取消发言
    EventCodeButelKeyEventParticipants               = 1604,  // 参会方
    EventCodeButelKeyEventInviteToMeetting           = 1605,  // 邀请参会
    EventCodeButelKeyEventGiveMicSuccess             = 1606,  // 传麦成功
    EventCodeButelKeyEventAddParticipantsSucess      = 1607,  // 参会方添加至联系人
    EventCodeButelKeyEventInviteByAccount            = 1608,  // 视讯号邀请
    EventCodeButelKeyEventInviteByList               = 1609,  // 邀请列表邀请
    EventCodeButelKeyEventMeettingLock               = 1610,  // 会议加锁
    EventCodeButelKeyEventMeettingUnLock             = 1611,  // 会议解锁
    EventCodeButelKeyEventSwitchWindow               = 1612,  // 切换窗口
    EventCodeButelKeyEventQuitMeeting                = 1613,  // 退出会议
    EventCodeButelKeyEventChangeCamera               = 1614,  // 切换摄像头
    EventCodeButelKeyEventJoinMeeting                = 1615,  // 加入会议
    EventCodeButelKeyEventQuiteMeetingByHost =  1616 // 被主持人请出会议
};

typedef NS_ENUM(NSInteger, JMeetingSDKReturnCode) {
    JMeetingSDKReturnCodeOK = 0,
    JMeetingSDKReturnCodeNoInit = -1,
    JMeetingSDKReturnCodeInProcessing = -2,
    JMeetingSDKReturnCodeParameterIsNotcomplete = -3,
    JMeetingSDKReturnCodeOtherError = -999,

};


