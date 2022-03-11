//
//  ConferenceSDKAgent.h
//  ConferenceSDK
//
//  Created by Setoge on 2020/3/28.
//  Copyright © 2020 taojunfeng. All rights reserved.
//  ConferenceSDK带UI的管理类

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//会议的显示模式
typedef enum {
    CONFERENCEPAGEMODE_COMMON = 1,// 普通模式
    CONFERENCEPAGEMODE_VOICESTIMULATION = 2,//语音激励模式
    CONFERENCEPAGEMODE_GALLERY = 3,//画廊模式
    CONFERENCEPAGEMODE_GALLERY_VOICESTIMULATION = 4,//语音激励模式+画廊模式
    
} CONFERENCEPAGEMODE;

@class ConferenceSDK;
@interface ConferenceSDKAgent : NSObject
typedef void (^onSendMsg)(NSInteger ret ,NSString * _Nonnull meetingID,NSString * _Nullable msg);
/// BCSNative事件的管理类
@property (strong, nonatomic) ConferenceSDK *  _Nullable conferenceSDK;
/// 会议室页面模式
@property (nonatomic,assign) CONFERENCEPAGEMODE pageMode;

+ (ConferenceSDKAgent *_Nonnull)shareManager;

#pragma mark - SDK生命周期
/**
 * 初始化接口
 * @param param     初始化参数
 * @param onInitListener 初始化结果异步返回
 * @return 0 成功 其他 失败
 * @return 0 成功 其他 失败
 */
- (int)init:(ConferenceInitParam *_Nonnull)param
     onInit:(InitListener *_Nullable)onInitListener;

/**
     * 加入会议
     * @param nickName            昵称
     * @param meetingID           会议号
     * @param passWord           会议密码没有传""
     * @param onJoinMeeting    加入会议监听回调
     * @param viewController     会议室控制器
     * @return  同步返回操作结果
     *                0：操作成功
     *                !=0：操作 失败
     */
- (int)joinMeeting:(NSString *_Nonnull)meetingID
           nickName:(NSString*_Nonnull)nickName
         meetingPwd:(NSString*_Nonnull)passWord
     viewController:(UIViewController *_Nonnull)viewController
      onJoinMeeting:(JoinMeetingListener *_Nullable)onJoinMeeting;

/**
 退出会议
*/
- (void)exitMeeting;

/**
 释放相关资源
 */
- (void)destorySDK;







#pragma mark - 会议设置
/**
     * 添加会议代理
     *
     * @param type  代理类型
     * @param proxy 代理对象
     * @return 0：操作成功 非0 ：操作 失败
     */
-(int)addMeetingProxy:(MeetingProxy _Nonnull )proxy proxyType:(MEETING_PROXY_TYPE )type;

/**
     * 添加ConferenceSDKDelegate
     *
     * @param conferenceSDKDelegate  Delegate
     * @return 0：操作成功 非0 ：操作 失败
     */
-(int)setConferenceSDKDelegate:(id<ConferenceSDKDelegate>_Nonnull)conferenceSDKDelegate;

/**加会时候的默认设置属性 麦克风和摄像头 0 是打开 1是关闭
  *@param cameraType 摄像头属性 0 是打开 1是关闭
  *@param micType  麦克风属性 0 是打开 1是关闭
 */
- (void)setMeetingCamerState:(int)cameraType micState:(int)micType;

/**
 *设置窗口视频流是大流还是小流
 *@param HDModel YES 是高清 NO 是默认的
 */
- (void)setJMeetingVideoSteramState:(BOOL)HDModel;

/**加会时候的默认设置属性
  *@param MirrState 镜像 1 镜像。0非镜像
 */
- (void)setMirrorState:(BOOL)MirrState;

/**
 * 设置自定义编码参数
 *@param videoParam BTVideoParam 见数据结构
 */
- (int)setSDKVideoEncParam:(BTVideoParamInfo * _Nullable) videoParam;

/**
 * qos浮层框显示控制
 * @param isShow isShow
 */
- (void)qosInfoViewShow:(BOOL)isShow;

/**设置区域简码，例如中国为CN（使用HttpDNS的情况下需要调用_Nonnull）
  *@param aCode 区域简码
  */
- (void)setHttpDNSAreaCode:(NSString *_Nonnull)aCode;

/**
 *  设置语言包
 * @param OEMDic 语言包
 */
- (void)setKeyValueOEMContant:(NSDictionary * _Nonnull)OEMDic;


/**
 *  设置是否支持横竖屏
 * @param open YES： 支持;   NO： 不支持
 */
- (void)screenSwitchOpen:(BOOL)open;



#pragma mark - 获取会议信息
/**
 *  获取会议ID
 */
- (NSString * _Nonnull)getMeetingID;

/**
 * 获取qos信息
 */
- (NSString * _Nullable)getQosStr;

/**
 *  获取 信令接收端口
 */
- (int)getUDPLocalPoart;

/**
 *  会议模块是否初始化成功，YES成功，NO 失败
 */
- (BOOL)getConferenceSDKInited;

/**
 *  获取当前镜像状态
 */
- (BOOL)currentsetMirrorState;

/**
 *  获取当前是否支持横竖屏
 */
- (BOOL)currentScreenSwitchState;




#pragma mark - 会议交互
/**
 *  发送追踪命令的接口
 */
- (void)connectMeetingRoom:(NSString * _Nonnull)accountID  onSend:(onSendMsg _Nullable )onSendMsg;

/**异常事件上传
  *@param action 事件名称 例如: 登陆
  *@param type  事件类型 例如:error
  *param descriptions 事件描述
 */
- (void)reportAbnormalEventInfoAction:(NSString *_Nullable)action type:(NSString *_Nullable)type descriptions:(NSString *_Nullable)descriptions;

/// 添加设置网络代理
/// @param type 0:http 1:socks
/// @param proxyIP ip地址
/// @param proxyPort 端口
- (int )addNetPlaneProxyType:(int )type proxyIP:(NSString * _Nonnull)proxyIP proxyPort:(NSString * _Nonnull)proxyPort;

@end


