//
//  KeyEventWriteConstant.h
//  JustMeeting
//
//  Created by dutingfu on 15/8/5.
//  Copyright (c) 2015年 青牛软件. All rights reserved.
//

#ifndef JustMeeting_KeyEventWriteConstant_h
#define JustMeeting_KeyEventWriteConstant_h
#define OK 1
#define Fail 0
// 1 启动
#define GET_NPS_INFO @"100001" // 获取nps信息
// 4 启动SDK依赖
#define BOOT_HOSTAGENT @"100008" // 启动hostagent
#define BOOT_DETECT_LINK @"100009" // 启动短连接检测
// 5 鉴权【张小龙】
#define  LOGIN_INFO @"100010" // 登录接口
#define  IDENTIFY_INFO @"100073" // 鉴权信息
#define  BIND_TOKEN @"100011" // 绑定token
#define  MODITY_USERMESSAGE @"100012" // 修改用户信息

// 6注册
#define  GET_NUBE @"100014"  // 获取视讯号
#define  SEND_CHECKCODE @"100015" // 发送验证码
#define  ACTIVE_INFO @"100016" //  100016 激活

// 7声音检测
#define VOICE_CHECK @"100017" // 声音检测

// 8 主页
#define GET_INVITE_MEETINGLIST @"100018" //获取会议邀请列表

// 9 预约
#define  RESERVE_MEETING @"100019" // 100019 预约会议
#define CREATE_MEETING_RESERVE @"100020" //100020 创建会议
// 10 会议列表
#define  GET_MEETINGLIST @"100021" //  100021 获取会议列表
#define  CHECK_MEETINGNUM_INVALID @"100022" // 查询会议号是否合法
// 11 召开会议【张莉】
#define  KSTART_MEETING @"100023"//  100023 召开会议
// 12 邀请会议
#define CROSS_BG_INVITE_ATTENDMEETING @"100024" // 通过后台接口邀请参会【
#define CROSS_HOSTAGENT_INVITE_ATTENDMEETING @"100025" //  100025 通过HostAgent邀请参会
// 13 通讯录
#define CREATE_MEETING_CONTACT  @"100037" // 召开会议
#define CROSS_BG_INVITE_ATTENGMEETING @"100038" // 通过后台接口邀请参会
#define DELETE_CONTACT_FROMDB @"100039" // 从数据库删除联系人
#define UPLOAD_DATA_TO_CONTACTSERVER @"100040" // 上传数据到个人通讯录服务器
#define DOWNLAOD_DATA_FROM_CONTACTSERVER @"100041" // 从个人通讯录服务器下载数据
#define SYNC_CONTACTS_INFO_MOBILE @"100042" // 同步联系人信息
// 14 会控
#define ADD_MEETING_BY_NUBE @"100045" // 加入会议
#define DEAL_981_EVENT @"100046" // 处理-981
#define GET_PARTICIPANTS @"100047" // 获取参会方
#define SPEARING @"100048" // 发言
#define CANCEL_SPEARING @"100049" // 取消发言
#define GIVE_MAIC @"100050" // 传麦
#define INVITE_IN_MEETINGROOM @"100051" //  邀请
#define LOCK_UNLOCK_IN_MEETINGROOM @"100052" // 加锁/解锁
#define DEAL_STARTSPEAKING @"100053" //  处理开始发言
#define DEAL_STAOPSPEAKING @"100054" // 处理停止发言
#define INIT_MEETING_AGENT @"100055" //  初始化会控agent
#define INIT_MEDIAPLAY @"100056" // 初始化Mediaplay
#define INIT_SCREENSHARE @"100057" //   初始化屏幕分享
#define UNINSTALL_MEDIA_MODEL @"100058" // 卸载视频模块
#define UNINSTALL_SCREEN_SHARE @"100059" // 卸载屏幕分享
#define UNINSTALL_MEETINGCONTROL @"100060" // 卸载会控
#define START_SCREENSHARE @"100061" // 开始屏幕分享
#define STOP_SCREENSHARE @"100062" // 停止屏幕分享
#define START_PREVIEW @"100063" // 开启预览
#define STOP_PREVIEW @"100064"  // 停止预览
#define START_CAMERA @"100065"  //  打开摄像头
#define STOP_CAMERA  @"100066"  // 关闭摄像头
#define PUSHFRAME_EXCEPTION_STATE @"100067" // PushFrame异常状态
#define STARTVIEW @"100068" // startView
#define STOPVIEW  @"100069"  // stopView
#define STARTSPEAK @"100070" // STARTSPEAK
#define STOPSPEAK @"100071"  // stopSpeak
#define RESTARTSPEAK @"100072" // restartSpeak

#define KEY_LOGIN_AUTHEN_INFO @"KEY_LOGIN_AUTHEN_INFO"

#endif
