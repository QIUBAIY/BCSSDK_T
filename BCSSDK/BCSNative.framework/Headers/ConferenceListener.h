//
//  ConferenceListener.h
//  BCSNative
//
//  Created by Setoge on 2020/3/13.
//  Copyright © 2020 Bulet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNChatMessageInfo.h"
#import "CaptionAndThemeInfo.h"
#import "Constants.h"
NS_ASSUME_NONNULL_BEGIN

///收到其他用户事件的回调对象
@interface ConferenceListener : NSObject

/// 获取设备是否拥有使用状态
///
/// @param deviceType 设备类型 1，摄像头；2，麦克风
/// @param status  yes 可以使用；no不能使用
@property (copy, nonatomic)  void (^ CNDeviceAuthority)(int deviceType, BOOL status);
 
/// 会议室成员加入通知（会议中有人加会时调用）
///
/// @param accountID 参会者视讯号
/// @param accountName 参会名称
@property (copy, nonatomic)  void (^ OnUserJoin)(NSString * accountID, NSString * accountName);


/// 会议室成员退出通知
///
/// @param accountID 发言者视讯号
@property (copy, nonatomic)  void (^ OnUserLeave)(NSString * accountID, NSString *accountName);

/// 发言者打开Mic通知
///
/// @param accountID 发言者视讯号
@property (copy, nonatomic)  void (^ OnUserOpenMic)(NSString * accountID);


/// 发言者关闭Mic通知
///
/// @param accountID 发言者视讯号
@property (copy, nonatomic)  void (^ OnUserCloseMic)(NSString * accountID);

/// 发言者打开摄像头通知 (主持人指定发言)
///
/// @param accountID 发言者视讯号
@property (copy, nonatomic)  void (^ OnUserOpenCamera)(NSString * accountID);

/// 发言者关闭摄像头通知
///
/// @param accountID 发言者视讯号
@property (copy, nonatomic)  void (^ OnUserCloseCamera)(NSString * accountID);

/// 发言者打开共享通知 （创建发言者窗口视图）
///
/// @param accountID 视讯号
/// @param accountName 参会名称
/// @param shareType 共享类型
@property (copy, nonatomic)  void (^ OnUserOpenShare)(NSString * accountID, NSString * accountName, int shareType);

/// 发言者关闭共享通知
///
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnUserCloseShare)(NSString * accountID);

/// 发言者打开辅数据源通知 （创建发言者窗口视图）
///
/// @param accountID 视讯号
/// @param accountName 参会名称
/// @param shareType 共享类型
@property (copy, nonatomic)  void (^ OnUserFuOpenShare)(NSString * accountID, NSString * accountName);

/// 发言者关闭辅数据源通知
///
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnUserCloseFuShare)(NSString * accountID);

/// 发言者打开扬声器的通知
///
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnOpenLoudspeaker)(NSString * accountID);

/// 发言者关闭扬声器通知
///
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnCloseLoudspeaker)(NSString * accountID);

/// 用户开始发言通知
///
/// @param accountID 视讯号
/// @param accountName 参会名称
@property (copy, nonatomic)  void (^ OnStartSpeak)(NSString * accountID, NSString * accountName);

/// 用户停止发言通知
///
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnStopSpeak)(NSString * accountID);

/// 解散会议通知
@property (copy, nonatomic)  void (^ OnMeetingFinish)(void);

/// 会议被中断通知
@property (copy, nonatomic)  void (^ OnMeetingBreak)(void);

/// 会议重连通知
@property (copy, nonatomic)  void (^ OnMeetingRestore)(void);

/// 会议异常通知
///
/// @param errorNum 异常错误码
@property (copy, nonatomic)  void (^ OnMeetingException)(int errorNum);

/// 会议模式（主持、自由模式）改变通知
///
/// @param mode 当前会议模式
@property (copy, nonatomic)  void (^ OnMeetingModeChange)(MEETINGMODE mode);

/// 参会方举手发言通知
///
/// @param accountID 视讯号
/// @param accountName 参会名称
@property (copy, nonatomic)  void (^ OnUserRaiseHand)(NSString * accountID, NSString * accountName);

/// 网络状态回调
/// @param state  当前网络状态
@property (copy, nonatomic)  void (^ OnNetworkStateChange)(int state);

/**
     * 用户网络状态改变回调
     *
     * @param accountId   视讯号
     * @param isRemote    true 远端差   false 本地差
     * @param netState    网络状态 0正常，1糟糕
     */

@property (copy, nonatomic)  void (^ OnUserNetStateChange)(NSString * accountID, int netState, BOOL isRemote);

///
/// 视频流继续订阅完成的回调
/// @param accountID 回调的视讯号
/// @param isDoc          1屏幕分享者，2普通发言者
@property (copy, nonatomic)  void (^ ContantStreamIDComplete)(NSString * accountID, int isDoc);

///
/// 语音激励的回调
/// @param accountID 回调的视讯号
@property (copy, nonatomic)  void (^ VoiceIncentiveChange)(NSString * accountID);

///
/// 发言者音量回调
/// @param level 当前音量
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnSpeakerVolumeChange)(int level ,NSString * accountID);

///
/// 自适应打开关闭视频
/// @param adapterop 自适应打开关闭视频 0 打开； 1 关闭
/// @param accountID 视讯号
@property (copy, nonatomic)  void (^ OnAdapterChange)(int adapterop ,NSString * accountID);

//被抢占发言的回调
@property (copy, nonatomic)  void (^ OnBeSpeaker)(void);

///
/// 在控制器内获取加会成功的回调
@property (copy, nonatomic)  void (^ OnJoinMeetingSuccess)(void);

///
/// 会议内消息开关状态改变
/// @param state  1 打开 0 关闭
@property (copy, nonatomic)  void (^ OnMeetingChatStateChange)(int state);

///
/// 会议内收到其他参会方消息
/// @param chatMessageInfo  消息内容
@property (copy, nonatomic)  void (^ OnReceiveMeetingChatMessage)(CNChatMessageInfo * chatMessageInfo);


///  主持人变更
///  @param newMasterId 新主持人视讯号
///  @param newMasterName 新主持人昵称
@property (copy, nonatomic)  void (^ OnMasterIdChanged)(NSString * newMasterId ,NSString * newMasterName);

/// 主持人操作用户麦克风、扬声器、摄像头
///  @param deviceType 设备类型 1：麦克风 2：扬声器 3：摄像头
///  @param operateType 操作类型 1：打开 2：关闭
@property (copy, nonatomic)  void (^ OnMasterChangeUserMediaState)(int deviceType ,int operateType);


/**
     * 收到音频数据回调
     *
     * @param accountID     音频数据对应的视讯号
     * @param data          音频数据
     * @param sampleRate    采样率
     * @param channels      声道数
     * @param bitsPerSample 码率
     */
@property (copy, nonatomic)  void (^ OnReceiveAudioData)(NSString *accountID, char * data, int sampleRate ,int channels,int bitsPerSample,int datalen);

///收到自己被踢出通知
@property (nonatomic,copy) void (^ OnKickOut)(void);

/// 创建发言者视图 并调用渲染接口去渲染视图(加会时，会议中有其参会方时创建其他参会方窗口)
///
/// @param doc YES,是分享视图，NO 普通视图
/// @param accountID 参会者视讯号 (通过判断 accountID是否与自己的账号一致，区别调用的接口)
/// @param accountName 参会名称
@property (copy, nonatomic)  void (^ OnCreateSpeakersWindow)(BOOL doc, NSString * accountID, NSString * accountName);

#pragma mark - Setoge: ---------2020.7.20 新增方法
/// 参会方操作事件的回调
///
/// @param operationType 操作类型
/// @param beOperateUserId 参会者视讯号 被操作者视讯号，支持传空，表示所有
/// @param resultCode 0：成功，!=0：失败
/// @param msg 失败原因
@property (copy, nonatomic)  void (^ OnLocalOperationBlock)(USEROPERATIONTYPE operationType ,NSString * beOperateUserId , int resultCode, NSString * msg);

///会议内主讲人发生变化， userId  主讲人视讯号，为空表示没有
@property (copy, nonatomic)  void (^ onPresenterChanged)( NSString * accountID);

///刷新ui移除所有的窗口
@property (copy, nonatomic)  void (^ OnUploadRemoveUI)(void);
/// 刷新 UI
@property (copy, nonatomic)  void (^ OnRefreshUI)(void);


/// 是否允许打开麦克风状态变化通知
/// @param state  YES：允许操作麦克风；NO：不允许
@property (copy, nonatomic)  void (^ OnAllowOpenMicStateChange)(BOOL state);

/// 参会方举手状态发生变化通知
/// @param accountID  状态变化着视讯号，若为空，表示所有参会方
/// @param state  YES 举手；NO 放下手
@property (copy, nonatomic)  void (^ OnUserHandStateChange)(NSString * accountID,BOOL state);

/// 全体静音状态变化通知
/// @param delFlag  0：状态改变；1：删除状态(保持现有状态)
/// @param ismute  YES：全体静音；NO：取消全体静音
/// @param unmuteable 是否允许用户自动取消静音 YES：允许；NO：不允许
@property (copy, nonatomic)  void (^ OnMeetingMuteStateChange)(int delFlag, BOOL ismute,BOOL unmuteable, int cmdId);

/// 广播缓存命令回调
/// @param broadcastCacheArray  广播缓存命令数组
@property (copy, nonatomic)  void (^ OnBroadcastCacheBlock)( NSMutableArray * broadcastCacheArray);

/// 发言者状态批量改变
/// @param reasonCode 1:批量更新为发言者
/// @param batchSpeakersArray 批量发言者数组
@property (copy, nonatomic)  void (^ OnSpeakersStateBatchChange)(int reasonCode ,NSMutableArray * batchSpeakersArray);

/// 主持人将要轮询你
@property (copy, nonatomic)  void (^ OnMasterWillStarPolling)(void);

/// 主持人开始轮询你
@property (copy, nonatomic)  void (^ OnMasterStarPolling)(void);

/// 主持人结束轮询你
@property (copy, nonatomic)  void (^ OnMasterStopPolling)(void);

///主持人设置主题字幕
///@param displayType caption 主题 theme 字幕
///@param captionAndThemeStyle 内容
@property (copy, nonatomic) void (^OnSetMeetingThemeAndCaption)(NSString * displayType,CaptionAndThemeInfo* captionAndThemeStyle);


///收到自定义消息通知
///@param orgAccountId 发送者视讯号
///@param msgData 消息内容
@property (copy, nonatomic) void (^OnReceiveCustomMsg)(NSString * orgAccountId,NSString* msgData);

/// 本地发布视频流成功
///@param accountId 发布者视讯号
///@param isFrontCamera 是否是前置摄相头
@property (nonatomic,strong) void (^OnVideoStreamPushListener)(NSString * accountId,BOOL isFrontCamera);

/**
 * 拍照完成结果回调
 *
 * @param result  拍照结果，0 成功，>0 失败，1：拍照失败，2：未通话
 * @param seqN  与TakePicture返回的seqNum对应
 * @param picPath 拍照存储路径及文件名，如：path/1.jepg*
 */
@property (nonatomic,strong) void (^OnTakePicture)(long result,int seqN, NSString *picPath);

/**
 * 订阅混音流成功回调
 *
 */
@property (nonatomic,strong) void (^OnSubscribeAudioSuccess)(void);
@end

/******************************************************************************/

/// 打开或者关闭麦克的结果回调
@interface OpenOrCloseMeetingMic : NSObject
@property (copy, nonatomic) void (^onSuccess)(int code, NSString *msg);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 打开或者关闭摄像头的结果回调
@interface OpenOrCloseMeetingCamera : NSObject
@property (copy, nonatomic) void (^onSuccess)(int code, NSString *msg);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/******************************************************************************/

/// 会议SDK初始化的监听回调对象
@interface OnGetNowMeetings : NSObject
@property (copy, nonatomic) void (^onSuccess)(int valueCode, NSArray * meetingList);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);

@end

/// 会议SDK初始化的监听回调对象
@interface InitListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(NSString *nubeNumber);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 创建会议的的监听回调对象
@interface CreateMeetingListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(NSString *meetingID);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 加入会议的监听回调对象
@interface JoinMeetingListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人改变会议模式的监听回调对象
@interface MasterChangeMeetingModeListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(MEETINGMODE model);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人指定参会方发言的监听回调对象
@interface MasterSetUserStartSpeakListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人指定停止参会方发言的监听回调对象
@interface MasterSetUserStopSpeakListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人请出参会方的监听回调对象
@interface MasterKickUserListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人移交权限的监听回调对象
@interface MasterTransferMasterIdListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人解散会议的监听回调对象
@interface MasterAskForEndMeetingListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请发言的监听回调对象
@interface AskForSpeakListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请停止发言的监听回调对象
@interface AskForStopSpeakListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请打开摄像头的监听回调对象
@interface AskForOpenCameraListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请关闭摄像头的监听回调对象
@interface AskForCloseCameraListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请打开mic的监听回调对象
@interface AskForOpenMicListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请关闭mic的监听回调对象
@interface AskForCloseMicListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请打开扬声器的监听回调对象
@interface AskForOpenLoudspeakerListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户申请关闭扬声器的监听回调对象
@interface AskForCloseLoudspeakerListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户举手发言的监听回调对象
@interface UserAskForRaiseHandListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 用户获取参会方列表的监听回调对象
@interface GetParticipantListListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(NSArray *infoList);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 主持人打开或关闭聊天功能的监听回调对象
@interface MasterAskForChatListener : NSObject
/// status 1打开聊天功能；0关闭聊天功能
@property (copy, nonatomic) void (^onSuccess)(int status);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end


@interface MasterUserMediaStateListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end


@interface MasterSetUserDownHandListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

@interface WhiteBoardShareListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

@interface AskForStartScreenSharingListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

@interface ConnectMeetingRoomListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(NSString *accountId,NSString *meetingId);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *accountId,NSString *msg);
@end
#pragma mark - Setoge: ---------2020.7.20 新增方法
/// 主持人操作方法
/*
4.7 主持人操作打开/关闭摄像头    masterOperateUserCamera    beOperateUserId    被操作者视讯号，支持传空，表示所有
        type    1：打开，2：关闭
4.8 主持人操作打开/关闭麦克风    masterOperateUserMic    beOperateUserId    被操作者视讯号，支持传空，表示所有
        type    1：打开，2：关闭
4.9 主持人操作打开/关闭文档    masterOperateUserDoc    beOperateUserId    被操作者视讯号，支持传空，表示所有
        type    1：打开，2：关闭
4.10 主持人设置主讲人    masterSetPresenter    presenter    主讲人
4.11 主持人取消主讲人    masterCancelPresenter    N/A

*/
#pragma mark - 主持人操作参会方媒体控件的监听回调对象 摄像头、麦克风、文档
/// 主持人操作参会方媒体控件的监听回调对象
@interface MasterOperateUserMediaListener : NSObject
///mediaType 1视频；2音频；3文档； type    1：打开，2：关闭； beOperateUserId    被操作者视讯号，支持传空，表示所有;
@property (copy, nonatomic) void (^onSuccess)(int mediaType,int type,NSString *beOperateUserId);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

#pragma mark - 主持人设置主讲人/取消主讲人
/// 主持人指定参会方打开mic的监听回调对象
@interface MasterOperatePresenterListener : NSObject
///presenter    主讲人; type    1：设置主讲人，2：取消主讲人
@property (copy, nonatomic) void (^onSuccess)(int type,NSString *presenter);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end
#pragma mark - 主持人加锁/解锁会议

@interface MasterLockMeetingListener : NSObject
/// type    1：加锁，2：解锁
@property (copy, nonatomic) void (^onSuccess)(int type);
@property (copy, nonatomic) void (^onFailed)(int type,int code, NSString *msg);
@end
#pragma mark - Setoge: ---------2020.7.20 新增方法

/// 发送透传自定义消息
@interface SendCustomMsgListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end

/// 设置本地窗口锁定/取消本地窗口锁定
@interface LocalWindowLockStatusListener : NSObject
///accountID    本地窗口视讯号; type    1：设置本地窗口锁定，2：取消本地窗口锁定
@property (copy, nonatomic) void (^onSuccess)(int type,NSString *accountID);
@property (copy, nonatomic) void (^onFailed)(int code, NSString *msg);
@end
///云台摄像头控制回调
@interface CameraCtrlRespListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(void);
@property (copy, nonatomic) void (^onFailed)(int code,NSString *msg);
@end

///云台摄像头信息获取回调
@interface PtzInfoListener : NSObject
@property (copy, nonatomic) void (^onSuccess)(NSArray * info);
@property (copy, nonatomic) void (^onFailed)(int code,NSString *msg);
@end

NS_ASSUME_NONNULL_END
