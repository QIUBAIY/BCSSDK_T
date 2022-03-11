//
//  ScreenShareControl.h
//  JustMeeting
//
//  Created by dshy1234 on 3/8/16.
//  Copyright © 2016 青牛软件. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol ScreenShareControlDelegate <NSObject>
/**
 *  申请开始分享
 *
 *  @return ：0，成功。<0,失败的错误码
 */
- (int)applyForStart;

/**
 *  申请停止分享
 *
 *  @return ：0，成功。<0,失败的错误码
 */
- (int)applyForStop;

- (int)frameData:(unsigned char *)data datalen:(unsigned int)datalen;

- (int)start:(int)height width:(int)width bitrate:(int)bitrate filmformat:(int)filmformat;

- (int)stop;

- (int)setName:(NSString *)name;

@end

@interface ScreenShareControl : NSObject
@property (weak) id<ScreenShareControlDelegate> controlDelegate;
@property(nonatomic) int publishport;
/**
 *  申请开始分享回应
 *
 *  @param nresult 0,申请连接成功
	<0 ,会控返回的申请连接失败错误码。
	1,UI 忙，拒绝连接。
	2，UI未发言，拒绝连接
	3, 发送申请连接请求发送失败（发送失败或是接受响应的错误码是失败）
	4，UI超时未回应。
 *
 *  @return 0：成功 其他：失败
 */
- (int)applyStartResponse:(int)nresult;

/**
 *  初始化接口
 *
 *  @param accountID      视讯号
 *  @param logFilePath    日志文件路径
 *  @param configFilePath 配置文件路径
 *  @param delegate       delegate
 *
 *  @return instancetype
 */
- (instancetype)initWithID:(NSString *)accountID
               logFilePath:(NSString *)logFilePath
            configFilePath:(NSString *)configFilePath
                  delegate:(id<ScreenShareControlDelegate>)delegate;


/**
 *  通知停止分享
 *
 *  @param nresult 停止原因id
 *  @param desp    描述信息，如：某某人抢占了屏幕分享
    1,文档共享被抢占 ，desp:json串.{"accountId":"123","userName":"testName"}
	2,本地发言停止 ，desp 可空
	3,本地退会，
	4,服务器超时
	其他错误码待扩展
 *
 *  @return 0：成功 其他：失败
 */
- (int)noticeForceStopSharing:(int)nresult desp:(NSString *)desp;

/**
 *  设置发言状态
 *
 *  @param isSpeaking YES：发言 NO停止发言
 */
- (void)setSpeak:(bool)isSpeaking;

- (void)SSCRelease;

//agent call UI
- (int)AgentCB_Start:(int)height secWidth:(int)width bitrate:(int)bitrate filmformat:(int)filmformat;
- (int)AgentCB_Stop;
- (int)AgentCB_FrameData:(unsigned char *)data secLen:(unsigned int)datalen;
- (int)AgentCB_SetName:(char * )name secLen:(unsigned int)namelen;


/*
 返回值：0，成功。<0,失败的错误码
 （pc版本中 ，UI 会进行本地命令按钮状态管理）
 */
- (int)AgentCB_ApplyForStart;
- (int)AgentCB_ApplyForStop;

/*
 pc版本使用，在agent 等待开始分享响应超时的时候，通知UI 自己不再等，以允许UI的本地操作按钮可用
 */
- (int)AgentCB_WaitStartTimeOut;
@end
