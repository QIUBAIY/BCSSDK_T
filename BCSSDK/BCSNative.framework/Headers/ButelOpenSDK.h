//
//  ButelOpenSDK.h
//  UdpEchoClient
//
//  Created by dshy1234 on 15/4/22.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Constant.h"
#import "ButelOpenSDKConst.h"
#import "CurMeetingInfo.h"
#import "ScreenShareControl.h"
#import "MeetingSpeakerInfo.h"
#import "CameraInfo.h"
#import "MediaGeometryManager.h"
#import "BTVideoParamInfo.h"

typedef void (^ButelOpenSDKNotifyListener)(int notifyType, id object);
typedef void (^ButelOpenSDKOperationListenerSuc)(id object);
typedef void (^ButelOpenSDKOperationListenerFailed)(id object);

typedef void (^WhiteBoardOperation)(id cmd,int streamid,int type);
///CPU 进程枚举值
typedef enum {
    CpuStatus_OtherOverLoad, /// 其他进程cpu高
    CpuStatus_SelfOverLoad   /// 自己CPU高
}ButelOpenSDK_CpuStatus;
///自适应状态的枚举值
typedef enum {
    UNKNOWN_Adapte_State = -1,
    OPEN_Adapte_State,			///打开自适应
    CLOSE_Adapte_State///关闭自适应
} Adater_State;
/// 网络状态的枚举值
typedef enum {
    Net_Status_Normal, /// 网络好
    Net_Status_Bad,  /// 网络差
    Net_Status_VeryBad /// 网络极差
}ButelOpenSDK_NET_STATUS;
///是否打开自适应视频
typedef enum {
    AdapterVideo_Open,///打开自适应视频
    AdapterVideo_Close///关闭自适应视频
}AdapterVideo_OP;
/// 文字聊天的类型
typedef enum {
    Private_Chat=1, /// 私聊
    Public_Chat,/// 公众
}ButelOpenSDK_ChatType;


@interface AdapterVideoInfo : NSObject

/// 数据流ID
@property(nonatomic,assign)int streamID;

/// 自适应视频状态
@property(nonatomic,assign)AdapterVideo_OP adapterop;
@end

/// AdapterEventDelegate代理回调
@protocol AdapterEventDelegate <NSObject>

/// CPU状态回调
/// @param cupstatus CPU状态
- (void)onCpuStatusChange:(ButelOpenSDK_CpuStatus)cupstatus;

/// 网络状态回调
/// @param netstatus 网络状态
- (void)onNetStatusChange:(ButelOpenSDK_NET_STATUS)netstatus;

/// 自适应打开关闭视频
/// @param info 打开关闭视频回调
- (void)onAdapterOpenOrCloseVideo:(AdapterVideoInfo *)info;

/// 音量回调分贝
/// @param volume 音量分贝
/// @param streamID 数据流ID
- (void)onAdapterMicVolume:(double)volume streamID:(int)streamID;

/// 网络质量的回调
/// @param accountID 视讯号
/// @param netStatus 网络状态
/// @param resID 资源ID
- (void)onNewNetStatusChangeWithAccountID:(NSString *)accountID  m_netStatus:(int) netStatus  isRemote:(BOOL)isRemote;

/// 订阅完成之后 语音激励的回调
/// @param accountID 视讯号
/// @param isDoc 是否是数据分享
- (void)onContantStreamIDCompleteWithAccountID:(NSString *)accountID  stateISDoc:(int)isDoc;

/// 语音激励回调
/// @param accountID 被激励对象的视讯号
- (void)onVoiceIncentiveCallbackWith:(NSString *)accountID;

/// 语音激励回调（所有人）
/// @param accountID 被激励对象的视讯号
- (void)onVoiceIncentiveCallbackWithAccounts:(NSArray *)accounts;

/// 语音信息回调（所有人）
/// @param accountID 被激励对象的视讯号
- (void)onAudioRawFrameCallbackWith:(NSString *)accountID data:(char *)data datalen:(int)datalen samplerate:(int)samplerate channels:(int)channels bitspersample:(int)bitspersample;

/// 截屏异步回调通知
/// @param accountID 被激励对象的视讯号
///  * @param result  拍照结果，0 成功，>0 失败，1：拍照失败，2：未通话
///  * @param seqN  与TakePicture返回的seqNum对应
///  * @param picPath 拍照存储路径及文件名，如：path/1.jepg*
- (void)onTakePictureCallbackWith:(NSString *)picPath  result:(int)result;

/// 插件上屏幕共享打开关闭的通知
/// @param state 1 打开，0关闭
/// @param streamID
- (void)onScreenSharStateChange:(int)state StreamID:(int)streamID;
@end

@interface ButelOpenSDK : NSObject <ScreenShareControlDelegate>

/// 是否是超级管理员
@property (nonatomic, strong) NSString *monitorSign;

/// 前置摄像头数据
@property(nonatomic,strong)CameraInfo * frontCameara;

/// 后置摄像头数据
///
@property(nonatomic,strong)CameraInfo * backCamera;
///
///  扬声器状态 1：打开 2：关闭
@property(nonatomic,assign)int loudSpeakerStatus;
///
/// 摄像头的状态，yes ,表示前置，false 表示后置
@property(nonatomic,assign) BOOL isFrontCamera;
///
/// 底层回调协议
@property(nonatomic,weak)id <AdapterEventDelegate> adapterDelegate;
///
/// 0 视频会议，1 语音会议
@property(nonatomic,assign) BOOL meetingType;
// 参会方列表
@property (nonatomic,strong) NSMutableArray *participantListArray;

///
/// 设置信令层监听对象
/// @param listener 监听对象
-(void)setButelNotifyListener:(ButelOpenSDKNotifyListener)listener;
///
/// 初始化ButelOpenSDK对象
/// @param accountId 视讯号
/// @param accountName 昵称
/// @param meetingId 会议号
/// @param rcUrl 初始化时RCURL
/// @param token 鉴权token
/// @param listener 监听对象
- (instancetype)initWith:(NSString *)accountId
             accountName:(NSString *)accountName
               meetingId:(int) meetingId
                   rcUrl:(NSString *)rcUrl
                   token:(NSString *)token
                   appkey:(NSString *)appkey
                   group:(NSString *)group
          notifyListener:(ButelOpenSDKNotifyListener)listener;


/// 退出会议
///
/// @return 0 成功；！=0 失败
- (int)exitMeeting;


/// 获取参会方列表
/// @param succeed 成功的回调
/// @param failed 失败的回调
///
/// @return 0 成功；！=0 失败
- (int)getParticipatorList:(ButelOpenSDKOperationListenerSuc)succeed
                    failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 申请停止发言
/// @param succeed 成功的回调
/// @param failed 失败的回调
///
/// @return 0 成功；！=0 失败
- (int)askForStopSpeak:(ButelOpenSDKOperationListenerSuc)succeed
                failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 申请发言
/// @param speakerUserId 申请发言发言的视讯号
/// @param succeed 成功的回调
/// @param failed 失败的回调
///
/// @return 0 成功；！=0 失败
- (int)askForSpeak:(NSString *)speakerUserId
           succeed:(ButelOpenSDKOperationListenerSuc)succeed
            failed:(ButelOpenSDKOperationListenerFailed)failed;


/// 加解锁会议
/// @param lockInfo  1 加锁；0解锁
/// @param succeed 成功的回调
/// @param failed 失败的回调
///
/// @return 0 成功；！=0 失败
- (int)lockMeeting:(int) lockInfo
           succeed:(ButelOpenSDKOperationListenerSuc)succeed
            failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 传麦
/// @param beSpeakedUserId 将麦传递给谁
/// @param succeed       成功的回调
/// @param failed         失败的回调
///
/// @return 0 成功；！=0 失败
- (int)giveMic:(NSString *)beSpeakedUserId
       succeed:(ButelOpenSDKOperationListenerSuc)succeed
        failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 加入会议
/// @param token 鉴权的token
/// @param meetingId 会议号
/// @param adminId 管理员视讯号
/// @param isAutoSpeak 是否自动发言；YES 自动发言；NO不自动发言
/// @param succeed 成功的回调
/// @param failed 失败的回调
///
/// @return 0 成功；！=0 失败
- (int)joinMeeting:(NSString *)token
         meetingID:(NSString *) meetingId
           adminId:(NSString *)adminId
       isAutoSpeak:(int)isAutoSpeak
           succeed:(ButelOpenSDKOperationListenerSuc)succeed
            failed:(ButelOpenSDKOperationListenerFailed)failed;
///
/// 释放接口
- (void)BOSRelease;

/// 获取会议信息接口
///
/// @return 会议信息
- (CurMeetingInfo *)getCurMeetingInfo;

/// 获取发言者信息接口
///
/// @return 获取发言者列表
- (NSArray *)getSpeakers;

/// 获取qos
/// @param isAdapt 是否自动获取
///
/// @return QOS信息
- (NSString *)getQosInfoWithIsAdapt:(Boolean)isAdapt;

/// 远端关闭摄像头
/// @param meidaType 媒体类型
/// @param accountID 视讯号
- (void)RemoteSpeakerCloseVideo:(int)meidaType accountID:(NSString *)accountID;

/// 远端开启摄像头
/// @param meidaType 媒体类型
/// @param accountID 视讯号
- (void)RemoteSpeakerOpenVideo:(int)meidaType accountID:(NSString *)accountID;

/// 主持人改变会议模式
/// @param mode 1为自由模式；2为主持人模式。
/// @param succeed 成功Block
/// @param failed 失败Block
///
/// @return 0表示接口请求成功，-2表示在指定发言模式下没有主持人权限操作。-1表示除权限之外的操作错误
- (int)switchMeetingMode:(int)mode
                 succeed:(ButelOpenSDKOperationListenerSuc)succeed
                  failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 主持人指定发言
/// @param beSpeakedUserId 被指定发言者账户ID
/// @param speakerUserId 发言者账号ID. 如果发言者账号不为空，则抢占该发言者；如果发言者账号为空，则视是否有空闲指标来决定是否发言
/// @param succeed 成功Block
/// @param failed 失败Block
///
/// @return 0表示接口请求成功，-2表示在指定发言模式下没有主持人权限操作。-1表示除权限之外的操作错误
- (int)assignUserStartSpeak:(NSString *)beSpeakedUserId
              speakerUserId:(NSString *)speakerUserId
                    succeed:(ButelOpenSDKOperationListenerSuc)succeed
                     failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 主持人取消指定发言
/// @param beSpeakedUserId 用户id
/// @param succeed  成功Block
/// @param failed   失败Block
///
/// @return 0表示接口请求成功，-2表示在指定发言模式下没有主持人权限操作。-1表示除权限之外的操作错误
- (int)assignUserStopSpeak:(NSString *)beSpeakedUserId
                   succeed:(ButelOpenSDKOperationListenerSuc)succeed
                    failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 用户举手请求发言
/// @param succeed  成功Block
/// @param failed   失败Block
///
/// @return 0表示调用成功，<0表示调用失败
- (int)requestForSpeak:(ButelOpenSDKOperationListenerSuc)succeed
                failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 指定主持人
/// @param speakerUserId 被指定者视讯号
/// @param succeed 成功Block
/// @param failed 失败Block
///
/// @return 0表示调用成功，<0表示调用失败
- (int)assignKeyNoteSpeaker:(NSString *)speakerUserId
                    succeed:(ButelOpenSDKOperationListenerSuc)succeed
                     failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 关闭摄像头
/// @param succed 成功Block
/// @param faile 失败Block
///
/// @return 0表示调用成功，<0表示调用失败
- (int)askForCloseCamera:(ButelOpenSDKOperationListenerSuc)succed
                    faile:(ButelOpenSDKOperationListenerFailed)faile;

/// 打开摄像头
/// @param succed 成功Block
/// @param faile 失败Block
///
/// @return 0表示调用成功，<0表示调用失败
- (int)askForOpenCamera:(ButelOpenSDKOperationListenerSuc)succed
                   faile:(ButelOpenSDKOperationListenerFailed)faile;

/// 打开mic
/// @param succed 成功Block
/// @param faile 失败Block
///
/// @return 0表示调用成功，<0表示调用失败
- (int)openMicphone:(ButelOpenSDKOperationListenerSuc)succed
               faile:(ButelOpenSDKOperationListenerFailed)faile;

/// 打开mic
/// @param succed 成功Block
/// @param faile 失败Block
///
/// @return 0表示调用成功，<0表示调用失败
- (int)closeMicphone:(ButelOpenSDKOperationListenerSuc)succed
                faile:(ButelOpenSDKOperationListenerFailed)faile;


/// 继续订阅
/// @param resourceID 资源ID
/// @param accountID 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)continueSubscribe:(int)resourceID accountID:(NSString *)accountID;

/// 继续订阅
/// @param resourceID 资源ID
/// @param accountID 视讯号
/// @param isVideoModel 是否是高清模式
///
/// @return 0表示调用成功，<0表示调用失败
- (int)continueSubscribe:(int)resourceID accountID:(NSString *)accountID isVideoModel:(BOOL)isVideoModel; 

/// 暂停订阅
/// @param resourceID 资源ID
/// @param accountID 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)pauseSubscribe:(int)resourceID accountID:(NSString *)accountID;

/// 开始订阅
/// @param streamInfo 数据流信息
/// @param account 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)subsribe:(MediaStreamInfo *)streamInfo account:(NSString *)account;

/// 取消订阅
/// @param resourceID 资源ID
/// @param accountID 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)unSubcribe:(int)resourceID accountID:(NSString *)accountID;

/// 开始渲染本地窗口
/// @param resourceID 资源ID
/// @param accountID 视讯号
/// @param rendView 渲染的窗口句柄
///
/// @return 0表示调用成功，<0表示调用失败
- (int)startLocalVideo:(int)resourceID accountID:(NSString *)accountID rendView:(UIView *)rendView;

/**
     * 设置远端视频画面渲染方式
     *
     * @param displayMode 0:保持原始比例留黑边  -1:拉伸铺满全屏  -2:保持原始比例，不留黑边，进行缩放裁剪
     * @return 0 设置成功 其他 设置失败
     */

-(int)setRemoteVideoDisplayMode:(int) displayMode;

/// 开始渲染远端窗口
/// @param resourceID 流类型
/// @param accountID 视讯号
/// @param rendView 渲染的窗口句柄
/// @param isdoc 是否是数据分享
///
/// @return 0表示调用成功，<0表示调用失败
- (int)startRemoteVideo:(int)resourceID accountID:(NSString *)accountID rendView:(UIView *)rendView isdoc:(BOOL) isdoc;

/// 停止远端渲染
/// @param resourceID 流类型
/// @param accountID 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)stopRemoteVideo:(int)resourceID accountID:(NSString *)accountID;

/// 停止本地渲染
/// @param meidaType 媒体类型
/// @param accountID 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)stopLocalVideo:(int)meidaType accountID:(NSString *)accountID;

/// 切换摄像头
/// @param streamID 数据流ID
///
/// @return 0表示调用成功，<0表示调用失败
-(int)switchCamera:(int)streamID;

/// 发布mic数据流
/// @param resourceID 资源ID
///
/// @return 0表示调用成功，<0表示调用失败
-(int)publishMic:(int) resourceID ;

/// 发布视频流
/// @param resourceID 资源ID
///
/// @return 0表示调用成功，<0表示调用失败
-(int)publisCamera:(int)resourceID;

/// 取消发布数据流
/// @param streamid 数据流ID
///
/// @return 0表示调用成功，<0表示调用失败
-(int)unpublisStream:(int)streamid;

/// 获取发布端口
///
/// @return 0表示调用成功，<0表示调用失败
- (int)getPublishPort;

/// 根据resourceId 获取流信息
/// @param resourceId 资源ID
/// @param accountID 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)getStreamIDInfo:(int)resourceId accountID:(NSString *)accountID;

/// 获取资源ID
/// @param type 数据类型
/// @param account 视讯号
///
/// @return 0表示调用成功，<0表示调用失败
- (int)getResorceIdByType:(SpeakerMediaType)type account:account;

/// 根据视讯号获取发言者
/// @param accountID 视讯号
///
/// @return 获取发言者信息
- (CNSpeakerInfo *)getSpeakerInfoWithAccountID:(NSString *)accountID;

/// 根据视讯号和资源ID获取数据流信息
/// @param resourceId 资源ID
/// @param accountID 视讯号
///
/// @return 数据流信息
- (MediaStreamInfo *)getSteamInfo:(int)resourceId accountID:(NSString *)accountID;

/// 设置摄像头信息
/// @param position 摄像头的类型
/// @param info 摄像头信息
- (void)setCameraParam:(NSInteger)position info:(CameraInfo *)info;


/// 打开或关闭扬声器
/// @param type YES 打开，NO 关闭
///
/// @return 0表示调用成功，<0表示调用失败
- (int)OperateSpeakerState:(BOOL)type;
///
/// 销毁timer
- (void)destoryTimer;
///
/// 通知sdk cpu 使用状态更新
- (void)notifySdkCpuInfoUpdate;

/// 设置自适应开关
/// @param state 自适应状态
- (void)setAdateState:(Adater_State)state;

/// 发布数据流
/// @param type 数据流类型；0 发布视频，音频，1 只发布音频流， 3 主持模式下无论是否全体静音 都发布视频，音频
- (void)publisStream:(NSUInteger)type;

/// 获取图源管理模块
///
/// @return 图源管理模块
- (MediaGeometryManager *)getGeometryManager;

/// 获取图源链路ID
/// @param streamid 视频流ID
///
/// @return  成功返回链路id；失败返回 <=0
- (int)GetMediaFrameWorkStreamID:(int)streamid;
///
/// 反初始化图源模块
- (void)unInitGeometryManager;
///
/// 初始化图源模块
- (void)initMediaGeometryManager;

/// 是否打开高清模式
/// @param isOpen 1 打开高清模式；0 不打开高清模式
- (void)SetMRDisplayMode:(int)isOpen;

/// 设置收大流的视讯号
/// @param list 设置为大流的视讯号list
- (void)setBigStream:(NSArray *)list;

/// 转授主持人  备注：仅有主持人拥有操作权限
/// @param userid 新主持人视讯号
/// @param succed 成功回调
/// @param faile 失败的回调
- (void)host_JurisdictionChange:(NSString *)userid
                        succeed:(ButelOpenSDKOperationListenerSuc)succed
                          faile:(ButelOpenSDKOperationListenerFailed)faile;

/// 主持人将参会方请出会议
/// 备注：仅有主持人拥有操作权限
///
/// @param userid 被请出会议方的视讯号
/// @param token token
/// @param succed 成功的回调
/// @param faile 失败的回调
- (void)hostKitOutPaticipiant:(NSString *)userid
                        token:(NSString *)token
                      succeed:(ButelOpenSDKOperationListenerSuc)succed
                        faile:(ButelOpenSDKOperationListenerFailed)faile;

/// 主持人申请结束会议
/// @param succed 成功的回调
/// @param faile 失败的回调
- (void)hostEndMeeting:(ButelOpenSDKOperationListenerSuc)succed
                 faile:(ButelOpenSDKOperationListenerFailed)faile;

/// 主持人 开启或关闭会议中文字聊天功能
/// @param openOrClose YES 开启； NO 关闭
/// @param succeed 成功的回调
/// @param failed 失败的回调
- (void)hostOpenOrCloseMessage:(BOOL)openOrClose
                       succeed:(ButelOpenSDKOperationListenerSuc)succeed
                        failed:(ButelOpenSDKOperationListenerFailed)failed;

/// 会议中发送文字聊天信息
/// @param chatType 聊天类型 私聊或公众
/// @param content 信息内容
/// @param receiver 接收者视讯号 私聊时接受者视讯号，公众时为空
/// @param atUserArr @某些联系人视讯号数组
- (void)sendChatMessageWithChatType:(ButelOpenSDK_ChatType)chatType
                            Content:(NSString*)content
                           Receiver:(NSString*)receiver
                            AtUsers:(NSArray*)atUserArr;

/** 支持代理服务器*/

/// 设置上传映射relayIPMap
/// @param relayIPMap 映射地址
- (void)setUpConvertRelayIPMap:(NSString*)relayIPMap;
/**地址域名映射*/
- (void)setConvertRelayIPMap:(NSString*)relayIPMap;
- (void)setSTPProxyListInfo:(NSString *)proxyStr;
- (void)setHOSTProxyListInfo:(NSString *)proxyStr;

/// 设置下载映射relayIPMap
/// @param relayIPMap 映射地址
- (void)setDownConvertRelayIPMap:(NSString*)relayIPMap;

/// 设置映射地址
/// @param recverIPMap 映射地址
- (void)setConvertRecverIPMap:(NSString*)recverIPMap;

/// 更新IP映射列表
/// @param IPPortMap IP映射列表
- (void)setMeetingUpdateIPPortMap:(NSString*)IPPortMap;

/// 获取支持的最大的发言人数
///
/// @return 最大的发言人数
- (int)getMaxSpeakerNumber;


/**设置统一路由*/
- (void)MediaPlaySDKSetGatewayRc:(NSArray <NSString*> * ) gwrc_urls  netid:(int )netid;

#pragma mark - Setoge: ---------2020.7.21 新增方法

/// 主持人操作参会方的摄像头和麦克风打开或关闭
/// @param BeUserID 不为空时，被操作的参会方视讯号；为空时，操作全部参会方
/// @param operateType 1 打开；2关闭
/// @param mediaType 1视频；2音频；3文档
///
/// @return 0表示调用成功，<0表示调用失败
- (int)hostSetSpeakerCamearOrMicWithBeUserID:(NSString *)BeUserID operateType:(int)operateType mediaType:(int)mediaType;

/// 获取会议内主讲人
///
/// @return 会议内主讲人
- (int)getMeetingSpeakerAccountID;

/// 设置当前主讲人
/// @param account 当前主讲人视讯号
//- (int)hostSetMeetingSpeakerAccountID:(NSString *)account;

#pragma mark - Setoge: ---------2020.8.13-- 设置订阅视频的模式
/// 设置订阅视频的模式
/// @param model 视频模式 1，高清 ；2流畅
/// @param streamID 数据流id
- (void)setVideoModel:(int)model videoStreamID:(int)streamID;
#pragma mark - Setoge: ---------2020.8.17-获取未互动的参会方信息

/// 更加视讯号获取发言者信息
/// @param accountID 视讯号
///
/// @return 发言者信息
- (CNSpeakerInfo *)getMPUSpeakerInfoWithAccountID:(NSString *)accountID;

/// 获取未互动的参会方数组
///
/// @return 获取未互动参会方数组
- (NSMutableArray *)getMPUSpeakerInfo;

/// 获取qos信息
///
/// @return QOS信息
- (NSString *) getQosStr;

#pragma mark - MZF: --------- 全发言实现的方法
/// 举手操作
/// @param raised 举手的状态；YES 举手；NO 放下手
- (int)raiseHandOperite:(BOOL)raised ;

/// 订阅混音音频流
- (int)subscribeAudioMIX;

/// 增加设置音频过滤参数
/// @param waitTime 音频音量持续低于音量下限,停止发送音频
/// @param min 音量下限
/// @param max 音量上限,一旦音量高于max,立即发送音频
- (int)setAudioFilterParam:(int) waitTime min:(int)min max:(int)max;



/// 主持人清除参会方举手状态
/// @param beOperateUserId 被操作者视讯号，支持传空，表示所有
- (int)hostSetUserDownHand:(NSString *)beOperateUserId;


/// 设置全体静音状态
/// @param mute  0：关闭   1：开启
/// @param unmuteable   0：不允许  1：允许
/// @return 0成功；其他失败
- (int)hostSetMute:(int)mute unmuteable:(int)unmuteable;

/// 是否允许用户自动取消静音
/// @param unmuteable   0：不允许  1：允许
/// @return 0成功；其他失败
- (int)hostSetUnmuteable:(int)unmuteable;

/// 是否允许用户自动取消静音
/// @param unmuteable   0：不允许  1：允许
- (int)newhostSetUnmuteable:(int)unmuteable ;

/// 设置自定义编码参数
/// @param videoParam BTVideoParam 见数据结构
- (int)setVideoEncParam:(BTVideoParamInfo*) videoParam;

/// 设置或取消主讲人
/// @param presenter 设置主讲的视讯号；为空时取消设置主讲人
- (int)hostSetPresenter:(NSString *)presenter;
///获取 信令接收端口
- (int)getOpenSDKUDPLocalPoart ;

///开启/关闭白板共享
/// @param share YES 开启 NO 关闭

- (int)startWhiteBoardShare:(BOOL)share  succeed:(ButelOpenSDKOperationListenerSuc)succeed
                     failed:(ButelOpenSDKOperationListenerFailed)failed;;
///开启/关闭屏幕共享
/// @param share YES 开启 NO 关闭

- (int)askForStartScreenSharing:(BOOL)share  succeed:(ButelOpenSDKOperationListenerSuc)succeed
                         failed:(ButelOpenSDKOperationListenerFailed)failed;
///推送白板流
- (int)pushWhiteBoardStream;


/// @param ctrlType 控制类型 见YunTaiControlType定义
/// @param dstAccountId 被控端视讯号
/// @return 0 成功 其他 失败

-(int)sendCameraCtrlCtrType:(NSString *)ctrType dstAccountId:(NSString *)dstAccountId;

-(int)sendGetPtzInfoRequest:(NSString *)dstAccountId;


/// 发布轮询视频流
/// @param resultBlock 发布视频流的结果code -1 发布失败 0 发布成功 streamID
-(void)stratRenderpollingVideo:(int)bitrate resultBlock:(void (^)(long Code,int streamID))resultBlock;
/// 被轮询开始的结果回应
/// @param status 被轮询开始的结果
/// @param targetID 主持人的视讯号
- (void)butelRoundRobinResult:(int)status targetID:(NSString*)targetID;
/// 解析主题字幕数据
-(CaptionAndThemeInfo *)getCaptionAndThemeInfoWithCMDKey:(NSString *)cmdKey value:(NSString*)cmdValue;


/**
    * 拍照
    *
    * @param seqNum  异步接口调用序号，要求前后的调用不能重复，
与回调中的seqNum对应
    * @ param butelNum  需要拍照方的视讯号
    * @ param picPath    拍照存储路径及文件名 path/1.jepg
    * 异步结果通过 void (^OnTakePicture)(long result,int seqN, NSString *picPath)返回
    */
- (void)butelTakePicture:(int) seqNum mediaType:(int)mediaType butelNum:(int)butelNum picPath :(NSString*)picPath onTakePicture:(void (^)(long result,int seqN, NSString *picPath))onTake;


/**
 *设置镜像模式
 *@param isMirrorModel      YES：镜像模式   ; NO：镜像模式 默认非镜像模式
 *@param streamID                  流ID
 *
 */
- (int)setMirrorMode:(BOOL)isMirrorModel streamID:(int)streamID;
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



+(NSString *)transformateIPMap:(NSString *)mapping;




 /**
   *设置水印
   * @param markInfo     水印信息
   * @param streamID     流ID
   * @return 0 设置成功 其他 设置失败
   *
*/
- (int)updateMarkInfo:(BCSMarkInfo *)markInfo streamID:(int)streamID;
/**
  *设置GroupID(屏幕共享)
  * @param groupid    主程序GroupID
  *
*/
- (void)setGroupID:(NSString * _Nonnull ) groupid;
/**
     * 获取当前使用摄像头类型
     *
     * @return 摄像头类型
     * CAMERA_FRONT:前置
     * CAMERA_BACK:后置
     * CAMERA_UVC:UVC摄像头
     * CAMERA_UNKNOW:未知
     */
-(int )getCurrentCameraType;
@end
