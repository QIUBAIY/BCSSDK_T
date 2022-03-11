//
//  BCSNative.h
//  BCSNative
//
//  Created by Setoge on 2020/3/13.
//  Copyright © 2020 Bulet. All rights reserved.
//  BCSNative事件的管理类 使用接口都在这里


#import <Foundation/Foundation.h>
#import <BCSNative/ConferenceListener.h>
#import <BCSNative/Constants.h>
#import <BCSNative/ConferenceSDK.h>
#import <BCSNative/CNCameraInfo.h>
#import <BCSNative/CNSpeakerInfo.h>
#import <BCSNative/AudioRecordParam.h>

#import <BCSNative/BCSMarkInfo.h>
#import <BCSNative/BCSNativeFramework.h>
#import <BCSNative/HTTPDNSConfig.h>
#import <BCSNative/CMCMDCacheInfo.h>
#import <BCSNative/BTVideoParamInfo.h>
#import "CurMeetingInfo.h"
#import <UIKit/UIKit.h>
#import "Constants.h"
#import "ConferenceListener.h"
#import <BCSNative/ProxyManager.h>
#import <BCSNative/ConferenceAPIParam.h>
#import <BCSNative/ConferenceSDKDelegate.h>
#import "MeetingInfoItem.h"
NS_ASSUME_NONNULL_BEGIN


@interface ConferenceSDK : NSObject

@property (nonatomic,weak) id <ConferenceSDKDelegate> conferenceSDKDelegate;

/// 数据分享页面
@property (nonatomic,strong) UIView *docView;

/// 自己视频窗口的预览窗口
@property (nonatomic,strong) UIView *selfSurfaceView;
/// 退出会议的监听对象
@property (nonatomic, copy, nullable) void(^ExitMeetingBlock)(void);

/// 绘制触摸屏幕回调
@property (nonatomic, copy) void(^StartDrawTouchActionBlock)(void);



#pragma mark - SDK生命周期


/***
     * 初始化
     * @param initParam 初始化参数
     * @param initListener 初始化结果异步返回
     * @return 0 成功 其他 失败
     */
- (int)init:(ConferenceInitParam *)param
     onInit:(InitListener *)onInitListener;


/**
 *添加回调函数
 *@param listener ConferenceListenerd对象
 */
- (void)addConferenceListener:(ConferenceListener *)listener;

/**
 *移除回调函数
 *@param listener ConferenceListenerd对象
 *
 */
- (void)removeConferenceListener:(ConferenceListener *)listener;

/**
 *添加其他事件监听者
 *@param listener ConferenceListenerd对象
 *
 */
- (void)addOthersConferenceEventsListener:(ConferenceListener *)listener;

/**
 *移除其他事件回调函数
 *@param listener ConferenceListenerd对象
 *
 */
- (void)removeOthersConferenceEventsListener:(ConferenceListener *)listener;

/**
 *释放SDK
 */
- (void)destroy;

/**
     * 添加会议代理
     *
     * @param type  代理类型
     * @param proxy 代理对象
     * @return 0：操作成功 非0 ：操作 失败
     */

-(int)addMeetingProxy:(MeetingProxy)proxy proxyType:(MEETING_PROXY_TYPE)type;










#pragma mark - 会议

/**
 * 加入会议
 *
 * @param meetingID           会议号
 * @param meetingPwd          会议密码
 * @param nickName            昵称
 * @param onJoinMeeting 加入会议监听回调
 * @return 同步返回操作结果，加入会议是否成功将通过 JoinMeetingListener 异步返回
 * <p>
 * 0：操作成功
 * <p>
 * !=0：操作 失败
 */
- (int)joinMeeting:(NSString *)meetingID
          nickName:(NSString*)nickName
     meetingPwd:(NSString*)meetingPwd onJoinMeeting:(JoinMeetingListener *)onJoinMeeting;

/**
 *用户退出会议
 */
- (void)exitMeeting;

#pragma mark - 会议设置
/**
 *设置会议视频模式  1 超清1080p;2 高清720p;3 清晰vga ;  4 流畅qvga； 参照：{Constants.h  VIDEOMODEL} 仅对 调用 {joinMeeting} 接口之前有效
 *
 *@param videoMode 会议模式
 *
 */
- (void)setVideoMode:(VIDEOMODEL) videoMode;

/**
 *设置加会时摄像头打开或关闭 ；仅对 调用 {joinMeeting} 接口之前有效
 *@param isOpenCamera YES 打开 ；NO 关闭； 设置摄像头默认状态 默认不开启摄像头
 *
 */
- (void)setOpenCamera:(BOOL) isOpenCamera;

/**
 *是否自动发言 ；仅对 调用 {joinMeeting} 接口之前有效
 *@param autoSpeak YES  自动发言（默认； 进入会议，如果有空闲mic，且会议模式是自由模式，服务器将允许其发言;NO   不发言；进入会议，服务器不会自动让其发言
 *
 */
- (void)setAutoSpeak:(BOOL)autoSpeak ;

/**
 *设置发言自动麦克风
 *@param isOpenMic YES 打开 ；NO 关闭； 设置mic默认状态 默认开启mic
 *
 */
- (void)setOpenMic:(BOOL) isOpenMic;
/**
 * 设置水印信息
 * @param markInfo 水印信息
 * @return 0 设置成功 其他 设置失败
 */
- (int)setMarkInfo:(BCSMarkInfo *)markInfo;

/**
 * 设置远端视频画面渲染方式
 *
 * @param displayMode 0:保持原始比例留黑边  -1:拉伸铺满全屏  -2:保持原始比例，不留黑边，进行缩放裁剪
 * @return 0 设置成功 其他 设置失败
 */

-(int)setRemoteVideoDisplayMode:(int) displayMode;


/**
 *设置会议视频模式  1 超清1080p;2 高清720p;3 清晰vga ;  4 流畅qvga； 参照：{Constants.h  VIDEOMODEL}；仅对 调用 {joinMeeting} 接口之前有效
 *@param videoMode 会议模式
 *@param accountID 订阅视图的视讯号
 *
 */
- (void)setConferenceSDKVideoMode:(VIDEOMODEL)videoMode accountID:(NSString *)accountID;

/**
 * 设置自定义编码参数
 *@param videoParam BTVideoParam 见数据结构
 */
- (int)setSDKVideoEncParam:(BTVideoParamInfo*) videoParam;
/**
 * 设置窗口视频流是大流还是小流
 * @param HDModel YES 是高清 NO 是默认的
 */
- (void)setConferVideoSteramState:(BOOL)HDModel;
/**
 * 设置窗口视频流是大流还是小流
 * @param HDModel YES 是高清 NO 是默认的
 * @param accountID 视讯号
 */
- (void)setVideoSteramHighModel:(BOOL)HDModel  accountID:(NSString *)accountID;
 /**
* 设置窗口视频流为中流
* @param accountID 视讯号
*/
- (void)setVideoSteramMidModelAccountID:(NSString *)accountID;
/**
 * 增加设置音频过滤参数
 * @param waitTime 音频音量持续低于音量下限,停止发送音频
 * @param min 音量下限
 * @param max 音量上限,一旦音量高于max,立即发送音频
 * @return  0：成功; 其他：失败
 */
- (int)setAudioFilterParam:(int) waitTime min:(int)min max:(int)max;

/**
 *传入oem语言包字典参数
 */
- (void)setKeyValueOEMContant:(NSDictionary *)OEMDic;

/**
 * 设置区域简码，例如中国为CN（使用HttpDNS的情况下需要调用）
 *
 * @param aCode 区域简码
 */
- (void)setHttpDNSAreaCode:(NSString *)aCode;


/**
 * 设置音频录制参数
 *
 * @param audioRecordParam 音频录制参数
 *                         该接口需要在开启录制前设置
 * @return 0 设置成功 其他 设置失败
 */
-(int)setAudioRecordParam:(AudioRecordParam *) audioRecordParam;

/**
 * 设置是否录制本地音频
 *
 * @param recordLocalAudioData true 录制本地音频
 *                             false 取消录制本地音频
 *                             设置后，音频数据通过异步回调OnReceiveAudioData返回
 * @return 0 设置成功 其他 设置失败
 */
-(int)setRecordLocalAudioData:(BOOL) recordLocalAudioData;

/**
 *设置镜像模式
 *@param isMirrorModel      YES：镜像模式   ; NO：镜像模式 默认非镜像模式
 *@param accountID            视讯号
 *@return 0 成功 其他 失败
 *
 */
- (int)setMirrorMode:(BOOL)isMirrorModel accountID:(NSString*)accountID;


/**
 * 设置App应用日志的路径 (在初始化ConferenceSDK之前调用)
 * @param logPath  App应用日志的路径
 */

- (void)setAppLogPath:(NSString * _Nonnull )logPath;

/**
  *设置GroupID(屏幕共享)
  * @param groupid    主程序GroupID
  *
*/
- (int )setGroupID:(NSString * _Nonnull ) groupid;

/// 添加设置网络代理
/// @param type 0:http 1:socks
/// @param proxyIP ip地址
/// @param proxyPort 端口
- (int )addNetPlaneProxyType:(int )type proxyIP:(NSString * _Nonnull)proxyIP proxyPort:(NSString * _Nonnull)proxyPort;

#pragma mark - 主持人操作
/**
 * 主持人修改会议模式，当前只有主持模式、自由模式
 * 仅有主持人拥有操作权限
 *
 * @param meetingMode                    会议模式 {MEETINGMODE}
 * @param listener 操作结果回调MasterChangeMeetingModeListener
 * @return 0: 操作成功发出，操作结果需要等待MasterChangeMeetingModeListener 回调返回
 * 其他: 操作失败
 */
- (int)masterChangeMeetingMode:(MEETINGMODE)meetingMode
            modeChangeListener:(MasterChangeMeetingModeListener *)listener ;


/**
 * 主持人指定发言，只有主持人拥有操作权限
 *
 * @param beSpeakedID                 发言者视讯号
 * @param speakerID                       被替换的发言者视讯号，如果为""，表示由服务器决定空闲mic进行发言
 * @param listener 操作结果回调 listener
 * @return
 * 0: 操作成功，操作结果将通过 MasterSetUserStartSpeakListener 异步返回
 * <0: 操作失败
 */
- (int)masterSetUserStartSpeak:(NSString*)beSpeakedID
                     speakerID:(NSString *)speakerID
        userStartSpeakListener:(MasterSetUserStartSpeakListener *)listener;


/**
 * 主持人指定参会方取消发言;备注：仅有主持人拥有操作权限
 *@param speakedID 被指定取消发言者账户ID
 *@param listener 主持指定停止参会方发言的回调对象
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)masterSetUserStopSpeak:(NSString*)speakedID
        userStopSpeakListener:(MasterSetUserStopSpeakListener *)listener;


/**
 * 主持人踢人功能，触发服务器将该参会方请出会议室，其他参会方会收到被踢者退出会议的通知
 *
 * @param beKickedUserID         被请出会议室参会方id
 * @param listener               操作结果回调listener
 * @return <p>
 * 0: 操作成功，操作结果将通过 MasterKickUserListener 异步返回
 * <p>
 * <0: 操作失败
 */
- (int)masterKickUser:(NSString *)beKickedUserID
     kickUserListener:(MasterKickUserListener *)listener;


/**
 * 主持人权限移交
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param newMasterID                    新主持人视讯号
 * @param masterTransferMasterIdListener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterTransferMasterIdListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterTransferMasterID:(NSString *)newMasterID
     transferMasterIDListener:(MasterTransferMasterIdListener *)listener;


/**
 * 主持人申请结束会议请求命令
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param listener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterAskForEndMeetingListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterAskForEndMeeting:(MasterAskForEndMeetingListener *)listener;


/**
 * 主持人修改会议聊天状态状态
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param isChat                         1代表开启，0代表关闭
 * @param listener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterChangeChatStateListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterAskForChat:(BOOL)isChat
           chatListener:(MasterAskForChatListener *)listener;



/**
 * 主持人操作参会方摄像头请求命令
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param beSpeakedID                 指定用户操作（beOperateUserId为""：会议中除主持人的全体用户）
 * @param type                            操作类型 1.打开2.关闭
 * @param masterOperateUserCameraListener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterOperateUserCameraListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterOperateUserCamera:(int)type
                   beSpeakedID:(NSString*)beSpeakedID
                      listener:(MasterOperateUserMediaListener *)listener;

/**
 * 主持人操作参会方麦克风请求命令
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param beSpeakedID              指定用户操作（beOperateUserId为""：会议中除主持人的全体用户）
 * @param type                         操作类型 1.打开2.关闭
 * @param listener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterOperateUserMicListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterOperateUserMic:(int)type
                beSpeakedID:(NSString*)beSpeakedID
                   listener:(MasterOperateUserMediaListener *)listener;

/**
 * 主持人操作参会方文档请求命令
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param beSpeakedID              指定用户操作（beOperateUserId为""：会议中除主持人的全体用户）
 * @param type                         操作类型 1.打开2.关闭
 * @param listener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterOperateUserDocListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterOperateUserDoc:(int)type
                beSpeakedID:(NSString*)beSpeakedID
                   listener:(MasterOperateUserMediaListener *)listener;

/**
 *主持人设置主讲人/取消主讲人
 *@param type 1：设置主讲人，2：取消主讲人
 *@param presenter 被指定为主讲人的视讯号，为空时，取消主讲人
 *@param listener 操作结果回调listener对象
 *
 *@return 0表示调用成功，<0表示调用失败
 */
- (int)masterOperatePresenter:(int)type
                  bePresenter:(NSString*)presenter
                     listener:(MasterOperatePresenterListener *)listener;

/**
 * 会议加解锁，只有主持人有权限操作：1代表加锁，0代表无锁
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param lock                           1代表加锁，0代表无锁
 * @param listener 操作结果回调listener
 * @return 0: 操作成功发出，操作结果需要等待MasterChangeMeetingLockStateListener 回调返回
 * 其他: 操作失败
 */
- (int)masterLockMeeting:(int)lock
                listener:(MasterLockMeetingListener *)listener;


/**
 * 主持人清除参会方举手状态
 * <p>
 * 仅有主持人拥有操作权限
 *
 * @param beOperateUserId               被操作者视讯号，支持传空，表示所有
 * @param listener     操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 MasterSetUserDownHandListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)masterSetUserDownHand:(NSString *)beOperateUserId listener:(MasterSetUserDownHandListener*)listener;


/** 设置全体静音状态
 * @param mute  0：关闭   1：开启
 * @param unmuteable   0：不允许  1：允许
 * @return 0成功；其他失败
 */
- (int)masterSetMute:(int)mute unmuteable:(int)unmuteable;

/// 是否允许用户自动解除静音
/// @param unmuteable   0：不允许  1：允许；0: 允许参会方在静音状态自己打开麦克风；1: 不允许参会方在静音状态下自己打开麦克风
/// @return 0成功；其他失败
- (int)masterSetUnmuteable:(int)unmuteable;

/**
 * 获取是否允许打开麦克风
 *
 * @return 是否允许打开麦克风 0：不允许  1：允许
 */
- (BOOL)getAllowOpenMicFlag;











#pragma mark - 普通参会方操作
/**
 *申请发言
 *@param listener 操作结果回调对象
 *@param speaker  被抢占人的视讯号 传空则不抢占
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)askForSpeak:(AskForSpeakListener *)listener BeSpeaker:(NSString *)speaker ;


/**
 *申请停止发言
 *@param listener 操作结果回调对象
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)askForStopSpeak:(AskForStopSpeakListener *)listener;


/**
 * 申请打开摄像头
 *
 * @param listener 操作结果回调listener
 * @return <p>
 * 0: 操作成功发出，操作结果需要等待 AskForOpenCameraListener 回调返回
 * <p>
 * !=0 : 操作失败
 */
- (int)askForOpenCamera:(AskForOpenCameraListener *)listener;


/**
 * 申请关闭摄像头
 *
 * @param listener 操作结果回调listener
 * @return <p>
 * =0: 操作成功发出，操作结果需要等待 AskForCloseCameraListener 回调返回
 * <p>
 * !=0: 操作失败
 */
- (int)askForCloseCamera:(AskForCloseCameraListener *)listener;


/**
 *切换摄像头
 */
- (void)askForSwitchCamera;


/**
 *申请打开麦克风
 *@param listener 操作结果回调对象
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)askForOpenMic:(AskForOpenMicListener *)listener;


/**
 * 关闭本地麦克风
 *
 * @param askForCloseMicListener 操作回调接口
 * @return 0： 操作成功 其他 失败
 */
- (int)askForCloseMic:(AskForCloseMicListener *)listener;


/**
 *申请打开扬声器
 *@param listener 操作结果回调
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)askForOpenLoudspeaker:(AskForOpenLoudspeakerListener *)listener;


/**
 *申请关闭扬声器
 *@param listener 操作结果回调
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)askForCloseLoudspeaker:(AskForCloseLoudspeakerListener *)listener;


/**
 * 会议内发消息
 *
 * @param chatType   聊天类型
 *                   ChatType.PUBLIC_MSG 公众消息
 *                   ChatType.PRIVATE_MSG 私聊消息
 * @param content    消息内容
 * @param receiver   私聊消息接收者视讯号
 * @param atUserList 公众消息@者视讯号
 * @return 0 同步返回成功，其他失败
 */
- (int)sendMeetingChatMessage:(CHATTYPE)chatType
                      content:(NSString*)content
                     receiver:(NSString*)receiver
                   atUserList:(NSArray*)atUserList;

/**
 * 设置本地窗口锁定 / 取消本地窗口锁定
 *@param lock YES 本地窗口锁定; NO 取消本地窗口锁定
 *@param listener 监听回调
 *
 */
- (void)lockLocalWindow:(BOOL)lock
           lockWindowID:(NSString *)speakerID
               listener:(LocalWindowLockStatusListener *)listener;

/**
 *申请举手发言
 *@param listener 操作结果回调
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)askForRaiseHand:(UserAskForRaiseHandListener *)listener;

/**
 * 举手/手放下
 * <p>
 * 只有普通参会方才有操作权限
 * @param raised YES举手 /NO手放下
 * @param listener 操作结果回调listener
 * @return <p>
 * = 0: 操作成功，操作结果将通过 UserAskForRaiseHandListener 异步返回
 * <p>
 * < 0: 操作失败
 */
- (int)raiseHandOperite:(BOOL)raised  listener:(UserAskForRaiseHandListener*)listener;



/**
 *发送追踪命令的接口
 *@param destAccountId  被追踪方的视讯号
 */
-(int)connectMeetingRoom:(NSString *)destAccountId listener:(ConnectMeetingRoomListener*)listener;


/**
 *发送自定义消息接口
 *@param destAccountId  目标方的视讯号
 *@param msgData  消息内容（Json格式字符串）
 */
- (int)sendCustomMsg:(NSString *)msgData destAccountId:(NSString *)destAccountId listener:(SendCustomMsgListener*)listener;


/**
 *发送获取PTZ摄像头信息命令
 *@param dstAccountId       被控端视讯号
 *@param listener  异步回调
 *@return 0 成功 其他 失败
 *异步结果通过 PtzInfoListener返回
 */
-(int)sendGetPtzInfoRequest:(NSString *)dstAccountId listener: (PtzInfoListener*)listener;

/**
 *发送PTZ摄像头控制命令
 *@param ctrType 控制类型 见YunTaiControlType定义
 *@param dstAccountId 被控端视讯号
 *@return 0 成功 其他 失败ƒ
 *异步结果通过 CameraCtrlRespListener返回
 */
-(int)sendCameraCtrlCtrType:(YunTaiControlType )ctrType param:(NSString* _Nullable )param dstAccountId:(NSString *)dstAccountId listener: (CameraCtrlRespListener*)listener;

/// 订阅混音音频流
/// @return  0：成功; 其他：失败
- (int)subscribeAudioMIX;


/**
 * 手动上传日志
 * @param userId          用户视讯号
 * @param logPath         需要上传的日志的路径
 * @param logSerVerUrl    日志上传服务器地址
 */

//public void mandatoryUploadLog(String userId, String logPath, String logSerVerUrl)

-(void)mandatoryUploadLog:(NSString * _Nonnull )userId logPath:(NSString * _Nonnull)logPath logSerurl:(NSString * _Nonnull)logSerVerUrl;



#pragma mark - 画面操作

/**
 * 开始本地渲染：开启本地的自预览摄像头画面或者文档共享画面
 *
 * @param mediaType   人像画面或文档共享画面 {MediaType}
 * @param surfaceView 显示窗口
 * @return <p>
 * 0: 成功
 * <p>
 * !=0: 失败
 */
- (int)startLocalVideo:(MEDIATYPE)mediaType
           surfaceView:(UIView *)surfaceView;


/**
 * 停止本地渲染：停止本地的自预览或者文档共享视频
 *
 * @param mediaType 人像视频或者文档视频 {MEDIATYPE}
 * @return <p>
 * 0: 成功
 * <p>
 * !=0: 失败
 */
- (int)stopLocalVideo:(MEDIATYPE)mediaType;


/**
 *开始渲染远端窗口
 *@param mediaType 人像画面或文档共享画面 参照：{Constants.h MEDIATYPE}
 *@param accountID 发言者视讯号
 *@param surfaceView 渲染的窗口句柄
 *
 *@return 0表示调用成功，<0表示调用失败
 */
- (int)startRemoteVideo:(MEDIATYPE)mediaType
              accountID:(NSString *)accountID
            surfaceView:(UIView *)surfaceView ;


/**
 *停止远端渲染
 *@param mediaType 人像画面或文档共享画面 参照：{Constants.h MEDIATYPE}
 *@param accountID 发言者视讯号
 *
 *@return 0表示调用成功，<0表示调用失败
 */
- (int)stopRemoteVideo:(MEDIATYPE)mediaType
             accountID:(NSString *)accountID;


/**
 * 暂停远端视频渲染（窗口不在视线范围后调用）
 *
 * @param accountID 暂定订阅的目标发言者视讯号
 * @param mediaType 暂停订阅的流类型文档视频或者人像视频{MediaType}
 * @return <p>
 * 0: 成功
 * <p>
 * !=0: 失败
 */
- (int)pauseSubscribe:(MEDIATYPE)mediaType
            accountID:(NSString *)accountID;


/**
 * 订阅/恢复订阅 视频流
 *@param mediaType 人像画面或文档共享画面 参照：{Constants.h MEDIATYPE}
 *@param accountID 视讯号
 *@param mediaView 窗口视图
 *@param displayType  : 订阅视频流模式(DISPLAY_MODEL_TYPE)
                       SMALL_WND = 1,//小流
                       MIDDLE_WND,//中流
                       BIG_WND,// 大流
 *@return 0表示调用成功，<0表示调用失败
 */
- (int)resumeSubscribe:(MEDIATYPE)mediaType
             accountID:(NSString *)accountID
             mediaView:(UIView *)mediaView
             displayType:(DISPLAY_MODEL_TYPE )displayType;


/**
 *取消订阅视频流
 *@param mediaType mediaType 人像画面或文档共享画面 参照：{Constants.h MEDIATYPE}
 *@param accountID 视讯号
 */
- (int)conferenceUnSubscribe:(MEDIATYPE)mediaType accountID:(NSString *)accountID;


/**
 *设置收大流的视讯号
 *@param list 设置为大流的视讯号list
 *
 */
- (void)setBigStream:(NSArray *)list;


/**
     * 拍照
     *
     * @param seqNum    异步接口调用序号，要求前后的调用不能重复，
     *                  与回调中的seqNum对应
     * @param butelNum  需要拍照方的视讯号
     * @param mediaType 媒体类型 1：视频  2：文档
     * @param picPath   拍照存储路径及文件名 path/1.jepg
     *                  异步结果通过void (^OnTakePicture)(long result,int seqN, NSString *picPath)返回
     */
- (int )takePicture:(int) seqNum
           butelNum:(int)butelNum mediaType:(int)mediaType picPath:(NSString*)picPath;


#pragma mark - 共享
/**
 *开启/关闭 白板共享
 * @param share YES 开启 NO 关闭
 */
- (int)whiteBoardShare:(BOOL)share  listener:(WhiteBoardShareListener*)listener;

/**
 * 开启/关闭 屏幕
 *
 * @param share                  YES：开启共享 NO：关闭共享
 * @param listener               申请共享异步回调
 * @return int 0 成功 其他失败
 */

- (int)askForStartScreenSharing:(BOOL)share  listener:(AskForStartScreenSharingListener*)listener;
/**
 *初始化图元模块  如果在刚加入会议的时候 有白板的情况下调用
 */
- (void)initMediaGeometryManager;

#pragma mark - 共享标注

/**
 *开始数据分享控制模块加载
 *@param surfaceView 显示窗口
 *@param userID 开启数据分享的用户ID
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)startDataShare:(UIView *)surfaceView
          shareUserID:(NSString *)userID;
/**
 *开始辅数据分享控制模块加载
 *@param surfaceView 显示窗口
 *@param userID 开启数据分享的用户ID
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)startFuDataShare:(UIView *)surfaceView shareUserID:(NSString *)userID;

/**
 *停止数据分享
 *@param userID 停止数据分享的用户ID
 *
 *@return 0 同步返回成功，其他失败
 */
- (int)stopDataShare:(NSString *)userID;

/**
 * 开始标注
 *
 * @return 0 成功 其他 失败
 */
- (int)startDraw;

/**
 * 取消标注
 *
 * @return 0 成功 其他 失败
 */
- (int)stopDraw;

/**
 * 设置画笔参数
 *
 * @param sel      画笔类型
 * @param color    画笔颜色
 * @param penwidth 画笔粗细
 * @return 0 成功 其他 失败
 */
- (int)operateSelect:(DRAWOPERATETYPE)sel
               color:(int)color
            penWidth:(int)penWidth;

/**
 * 判断用户视频流是否支持标注
 * @param userID 用户账号
 * @param streamtype 流id：
 *     ResourceID_Video_Camera  100
 *     ResourceID_Video_DOC     300
 *     ResourceID_Audio_MIC     200
 * @return  YES：允许; NO：不允许
 */
- (BOOL)getStreamEnableDrawState:(NSString *)userID streamtype:(int )streamtype;

/**
 * 获取视频流分辨率信息
 *
 * @param accountId 视讯号
 * @param mediaType 媒体类型MEDIATYPE_VIDEO：视频  MEDIATYPE_DOC_VIDEO：文档
 * @return 视频信息
 */
-(MediaStreamInfo *)getVideoInfo:(NSString *)accountID  mediaType:(MEDIATYPE) mediaType;







#pragma mark - 查询接口

/**
 *获取主持人视讯号
 *
 *@return 主持人视讯号
 */
- (NSString *)getMasterAccountID;

/**
 *获取主持名称
 *
 *@return 主持人名称
 */
- (NSString *)getMasterName;

/**
 * 获取会议模式，当前模式分为主持模式和自由模式
 *
 * @return <p>
 * 1: 自由模式
 * 2：主持模式
 */
- (int)getMeetingMode;

/**
 *获取会议最大发言方数
 *
 *@return 最大发言方数
 */
- (int)getMeetingMaxSpeakerNum;

/**
 *获取会议当前发言方数
 *
 *@return 会议当前发言方数
 */
- (int)getCurrentSpeakerNum ;

/**
 *获取所有发言者信息列表
 *
 *@return 所有发言者信息列表
 */
- (NSMutableArray<CNSpeakerInfo *> *)getSpeakers ;

/**
 * 通过视讯号查询发言者
 *
 * @param accountId 视讯号
 * @return <p>
 * null: 如果该视讯号没有发言
 * <p>
 * CNSpeakerInfo: 该视讯号对应的发言者
 * @see SpeakerInfo
 */
- (CNSpeakerInfo *)getSpeakerInfoByID:(NSString *)speakerID;

/**
 *根据视讯号查询参会方信息
 *@param speakerID 参会方者的视讯号
 *
 *@return 参会方信息
 */
- (CNSpeakerInfo *)getSpeakerInfoFromParticipantList:(NSString *)speakerID;

/**
 *获取参会方列表
 *@param listener 操作结果回调
 *
 *@return 参会方列表数组
 */
- (NSArray<CNSpeakerInfo *> *)getParticipantList:(GetParticipantListListener *)listener;


/**
 * 会议模块是否初始化成功，YES成功，NO 失败
 */
- (BOOL)getConferenceSDKInited;


/**
 * 当前扬声器是否打开
 *
 * @return true：打开  false：关闭
 */
-(BOOL )isLoudSpeakerOpen;


/**
 * 获取当前主讲人
 *
 * @return 主讲人视讯号
 */
- (NSString *)getPresenterID;

/**
 *获取会议锁定状态
 *
 *@return YES  已加锁；NO没加锁
 */
- (BOOL)getMeetingLockStauts;

/**
 * 获取本地锁定人
 *
 * @return 本地锁定人视讯号
 */
- (NSString *)getLockWindowID;

/**
 * 获取共享人视讯号
 *
 * @return 共享人视讯号
 */
-(NSString *)getSharViewUserID;

/**
 *获取QOS信息
 *@param isAdapt 是否自动获取
 *
 *@return QOS信息
 */
- (NSDictionary *)getQosInfoWithIsAdapt:(Boolean)isAdapt;

/**
 *新增Qos服务器信息
 *
 *@return QOS服务器信息
 */
- (NSArray *)getServiceArr;

/**
 *获取当前会议信息
 *
 *@return 当前会议信息（本地记录信息）
 */
- (CurMeetingInfo *)getCurrentMeetingInfo;

/**
 *会议的mpu模式
 *
 *@return YES：mpu平等模式; NO：没有mpu
 */
- (BOOL)getMPUMode;

/**
 *查找某个视讯号当前是否在互动状态
 *
 *@param accountID 视讯号
 *
 *@return  YES：互动; NO：未互动
 */
- (BOOL)isInterActive:(NSString* )accountID;

/**
 获取qos信息
 */
- (NSString *)getQosStr;

/**
 * 查询用户举手状态
 * @param userID 用户账号
 * @return  YES：举手; NO：放下手/未举手
 */
- (BOOL)getUserHandStauts:(NSString *)userID;


/**
 *获取会议内全体静音设置状态
 *@return  YES：全体静音; NO：没静音
 * */
- (BOOL)getMeetingMuteStatus;


/**
 * 获取会议内设置的字幕信息（如果主持人没设置，返回的信息为null）
 *
 * @return CaptionAndThemeInfo 字幕信息
 */
- (CaptionAndThemeInfo *)getMeetingCaptionInfo;


/**
 * 获取会议内设置的主题信息（如果主持人没设置，返回的信息为null）
 *
 * @return CaptionAndThemeInfo 主题信息
 */
- (CaptionAndThemeInfo *)getMeetingThemeInfo;


/**
 *获取 信令接收端口
 */
- (int)getSDKUDPLocalPoart;


/**
 *网络是否可用 YES 可用；NO 不可用
*/
- (BOOL)networkIsReachable;

/**
 *获取会议ID
*/
- (NSString *)getMeetingID;

/**
 *获取当前语言包
*/
- (NSDictionary *)getOEMDic;

/**
     * 获取当前正在说话人列表
     * @return 说话人列表
     */
-(NSArray *)getCurrentSpeakingList;

/**
     *当前用户是否正在发言（正在说话）
     * @return ture:正在说话 false：当前没说话
     */
-(BOOL )isUserSpeaking:(NSString*) accountID;


/**
     * 获取录制本地音频的开关状态
     *
     * @return true：正在录制本地音频  false：没有录制本地音频
     */
-(BOOL )getRecordLocalAudioState;

/**
     * 获取当前使用摄像头类型
     *
     * @return 摄像头类型 BCSCameraType:
     *                    CAMERA_FRONT = 1,//文字水印
     *                    CAMERA_BACK,    //后置
     *                    CAMERA_UNKNOW    //未知
 */
-(BCSCameraType )getCurrentCameraType;










#pragma mark - 异常操作上报
/**
 *异常操作上报
 *@param action          异常事件名称，最好使用中文
 *@param type            异常事件类型
 *@param descriptions   异常事件描述
 *
 */
- (void)reportAbnormalInfoAction:(NSString *_Nullable)action type:(NSString *_Nullable)type descriptions:(NSString *_Nullable)descriptions;










#pragma mark - delegate方法

/**
 * 获取当前会议基本信息（通过vms平台）
 * @param meetingId 会议号
 * @return 当前会议信息
 */
-(void)getMeetingInfo:(NSString *)meetingId Success:(void(^)(MeetingInfoItem *meetingInfo))success
                              failure:(void(^)(int code,NSString* message))failure;


/**
 * 获取会议分享地址
 *
 * @param meetingId 会议id
 */
-(void)getMeetingShareUrlWithMeetingId:(NSString *)meetingId Success:(void (^)(NSString* shareUrl))success failure:(void(^)(int code,NSString* message))failure;


/**
 *设置会议密码
 *@param password 会议密码
 *@param succeed 成功的回调
 *@param failed 失败的回调
 *
 *@return 0成功，其他失败
 *@note 如果接口调用者不是主持人，则无法重置；重置密码不需要原密码，也不需要该会议有密码。
 */
//设置会议密码
-(void)setMeetingPassword:(NSString *)password Success:(void (^)(NSString* password))success
                              failure:(void(^)(int code,NSString* message))failure;


@end

NS_ASSUME_NONNULL_END
