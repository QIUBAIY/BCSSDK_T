//
//  Constant.h
//  JustMeeting
//
//  Created by yusy  on 15/5/28.
//  Copyright (c) 2015年 青牛软件. All rights reserved.
//



#define BINDTOKEN_PARAM_NAME        @"未命名"
#define PROD_ID                     @"prod002"
#define kSectionSelectorViewTopSpace     30
#define kSectionSelectorViewBottomSpace  -50
#define kSectionSelectorViewTopSpace_iphone6(P)     60
#define kSectionSelectorViewBottomSpace_iphone6(P)  -100
#define kSectionSelectorWidth            17
#define KSectionCallOutViewWidth         60

#define service_vip_desc        @"VIP用户"
#define service_normal_desc     @"免费用户"

// 友盟统计所使用的常量------------------------------------------

// 一、	注册登录
//1 桌面启动
#define kCount_LoginFromDesk @"1001"
//2 引导页注册
#define kCount_RegistInGuidePage @"1002"
//3.	引导页登陆成功，进入首页      // 已经完成
#define kCount_LoginFromGuidePage @"1003"


// 二、	首页操作
// 4.	首页点击召开,成功进入会议室。
#define kCount_Holdmeetting_InMainPage @"1004"
// 5.	首页页点击加入，进入加入会议界面
#define kCount_Joinmeetting_InManinPage @"1005"
// 6.	首页点击联系人，进入联系人界面
#define kCount_GetContact_InMainPage @"1006"
// 7.	首页点击头像，进入“我”界面
#define kCount_Click_Me @"1007"

// 三、	会控操作
// 8.	点击发言按钮
#define kCount_MeettingControl_speak @"1008"
// 9.	点击参会方按钮
#define kCount_MeettingControl_joinMetting @"1009"
// 10.	点击邀请参会按钮
#define kCount_MeettingControl_invite @"1010"
// 11.	点击切换摄像头按钮
#define kCount_MeettingControl_changeCamera @"1011"
// 12.	点击取消发言
#define kCount_MeettingControl_cancel @"1012"
// 13.	选择参会人员，传麦成功
#define kCount_MeettingControl_giveMic @"1013"
// 14.	参会方添加至联系人
#define kCount_MeettingControl_addToContact @"1014"
// 15.	视讯号邀请
#define kCount_MeettingControl_inviteByAcount @"1015"
// 16.	已有联系人列表邀请
#define kCount_MeettingControl_inviteContact @"1016"
// 17.	会议加锁
#define kCount_MeettingControl_lock @"1017"
// 18.	会议解锁
#define kCount_MeettingControl_unlock @"1018"
// 19.	切换窗口
#define kCount_MeettingControl_changeWindow @"1019"

// 四、	加入会议
// 20.	会议号加入会议
#define kCount_JoinMeettingByAcoount @"1020"
// 21.	邀请链接加入会议
#define kCount_JoinMeettingByLink @"1021"
// 22.	短信邀请进入会议
#define kCount_JoinMeettingByMessage @"1022"

// 五、	联系人
// 23.	联系人界面点击“发起多人会议”按钮
#define kCount_HoldMeetting_callMultiContact @"1023"
// 24.	名片页中点击“视频会议”
#define kCount_HoldMeetting_byClick_myCard @"1024"
// 25.	手机号/视讯号添加联系人
#define kCount_AddContactByAccountOrPhonenumber @"1025"
// 26.	选择联系人发起多人会议
#define kCount_ChoiseContacts_joinMeeting  @"1026"


// 27.	进入通讯录推荐界面。
#define kCount_Go_Contact_Recomment @"1027"
// 28.  点击插话按钮 ()
#define kCount_CLICK_INTERPOSE @"1028"
// 29.  点击说完了按钮
#define kCount_CLICK_INTERPOSE_END @"1029"
// 30.  点击“开启_关闭视频”按钮
#define kCount_CLICK_OPEN_CLOS @"1030"
// 31   点击“关闭摄像头”按钮(CLICK_CLOSE_CAMERA)
#define kCount_CLICK_CLOSE_CAMERA @"1031"
// 32   开关切换“自由模式”
#define kCount_CHANGE_TO_FREE_MODEL @"1032"
// 33   开关切换“主讲模式”
#define kCount_CHANGE_TO_MAIN_MODEL @"1033"
// 34   会控面板点击“指定发言”按钮
#define kCount_CLICK_DESIGNATED_SPEECH @"1034"
// 35   指定发言列表，指定参会方发言，点击“发言”
#define kCount_DESIGNATED_SPEEC_BY_LIST @"1035"
// 36   指定发言列表，取消参会方发言，点击“取消发言”按钮
#define kCount_CANCEL_DESIGNATED_SPEEC_BY_LIST @"1036"
// 37   会控面板点击“直播”按钮
#define kCount_CLICK_DIRECTSEEDING @"1037"
// 38   直播弹框中点击“开启直播”按钮
#define kCount_CLICK_OPEN_DIRECTSEEDING @"1038"
// 39   直播点击“微信好友”
#define kCount_DIRECTSEEDING_CLICK_WECHAT @"1039"
// 40   直播点击“朋友圈”
#define kCount_DIRECTSEEDING_CLICK_FRIEND @"1040"
// 41   直播点击“短信”
#define kCount_DIRECTSEEDING_CLICK_MESSAGE @"1041"
// 42   直播点击“复制链接”
#define kCount_DIRECTSEEDING_CLICK_COPY  @"1042"
// 43   参会方会控面板点击“举手”按钮
#define kCount_PARTICIP_RANSEHAND @"1043"
// 44   首页点击“预订会议室”按钮
#define kCount_ORDING_MEETINGROOM @"1044"
// 45   预约会议室界面点击“预约”按钮
#define kCount_APPOINT_MEETING @"1045"
// 46   预约成功界面点击 “微信好友”按钮
#define kCount_APPOINT_SUCESS_WECHAT @"1046"
// 47   预约成功界面点击 “朋友圈”按钮
#define kCount_APPOINT_SUCESS_FRIEND @"1047"
// 48   预约成功界面点击 “复制链接”按钮
#define kCount_APPOINT_SUCESS_COPY @"1048"



#define SMALLWINDOWSHEIGHT (UISCREENWIDTH > UISCREENHEIGHT? 80:150)//80
#define SMALLWINDOWSWIDTH (UISCREENWIDTH > UISCREENHEIGHT? 150:80)//80

#define SPEAKERSLIMIT 9 //测试数据 为2   线上需要数据 9
#define IPHONE_X \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})
/// 是否是 IiPad
#define ISIPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

// 保存纳贝账号
#define KEY_NUBE_NUMBER         @"KEY_NUBE_NUMBER"

// 日志上传
#define KEY_LOGUPLOAD_SERVERIP          @"KEY_LOGUPLOAD_SERVERIP"
#define KEY_LOGUPLOAD_SERVERPORT        @"KEY_LOGUPLOAD_SERVERPORT"
// 保存RCURL
#define KEY_RC_URL                      @"KEY_RC_URL"
// 保存帮助页面URL
#define KEY_HELP_URL                    @"KEY_HELP_URL"



// 公共参数
static NSString *COMMON = @"X1MeetingCommon";
static NSString *COMMON_QOS = @"X86MeetingRelayCfg";
static NSString *COMMON_RC_URL = @"RC_URL"; // STP 地址
static NSString *COMMON_MS_URL = @"vmsServerUrl";//@"MS_URL"; // 会议接口地址
static NSString *COMMON_SLAVE_MS_URL = @"SLAVE_MS_URL"; //第二个会议接口地址
static NSString *COMMON_EUC_URL = @"EUC_URL"; // 企业用户中心地址
static NSString *COMMON_PUC_URL = @"PUC_URL"; // 个人用户中心地址
static NSString *COMMON_Persion_Contact_URL = @"Persion_Contact_URL";  // 个人通讯录地址
static NSString *COMMON_Persion_Head_Upload_URL = @"Head_Upload_URL";  // 头像上传服务器地址
static NSString *COMMON_PASS_URL = @"PASS_URL";  // 头像上传服务器地址
static NSString *IOS_MD_CONGIG = @"IOS_MD_Config";


// 应用升级
static NSString *APP_UPDATE = @"X1MeetingAppUpdate";
static NSString *APP_UPDATE_ServerUrl = @"ServerUrl";
static NSString *APP_UPDATE_ProjectName = @"ProjectName";
static NSString *APP_UPDATE_CheckInterval = @"CheckInterval";
static NSString *APP_UPDATE_DeviceType = @"DeviceType";

// 流媒体
static NSString *MediaPlay = @"X1MeetingMediaPlay";
static NSString *MediaPlay_Jfec_in = @"Jfec_in";
static NSString *MediaPlay_Jfec_out = @"Jfec_out";

// 帮助
static NSString *HELP = @"JMeetingHelp";
static NSString *HELP_URL = @"Mobile_Help_Url";

// 推荐中使用的应用下载地址
static NSString *HELP_DOWNLOAD_LINK = @"Mobile_Download_Link";

// 日志上传
static NSString *LogUpload = @"JustMeetingLogUpload";
static NSString *LogUpload_serverIp = @"ServerIP";
static NSString *LogUpload_serverPort = @"ServerPort";
static NSString *LogRecvServerUrl = @"LogRecvServerUrl";
/** 支持代理服务器*/
static NSString *StpUrlMap = @"StpUrlMap";
static NSString *RecverIPMap = @"RecverIPMap";
static NSString *HostIpMap = @"HostIpMap";
static NSString *RelayUrlMap = @"RelayUrlMap";
static NSString *HttpIpMap = @"HttpIpMap";
static NSString *HttpDNS = @"HttpDNS";
static NSString *BootParams = @"BootParams";
static NSString *DomainMapping = @"domainMapping";
static NSString *ReportServeURL = @"ReportServeURL";//盒端管理地址
static NSString *UnifiedRC = @"UnifiedRC";//盒端管理地址



/// 请求会议参数的设备号和串号
//#define DEVESMODEL @"MobileMeeting"
//#define SERIALNUMBER @"GDDXX1000100001"

/// 红云会议SDK
#define DEVESMODEL @"Mobile_jmeeting"
#define SERIALNUMBER @"GDDXX1144500045"

#pragma mark - 会控命令错误码
//const static int SUCCESS = 0;//成功

#define ResourceID_Video_Camera  100
#define ResourceID_Video_DOC     300
#define ResourceID_Audio_MIC     200

#define HYLogPath [NSString stringWithFormat:@"%@%@",NSHomeDirectory(),@"/Library/Log"]
#define HYConfigPath [NSString stringWithFormat:@"%@%@",NSHomeDirectory(),@"/Library/Config"]

// block中弱引用self
#define WEAKSELF typeof(self) __weak weakSelf = self;



typedef NS_ENUM(NSUInteger, JMeetingSDKState) {
    JMeetingSDKStateNoInit,
    JMeetingSDKStateIniting,
    JMeetingSDKStateInited,
    JMeetingSDKStateCreateMeeting,
    JMeetingSDKStateGetNowMeeting,
    JMeetingSDKStateJoiningMeeting,
};



typedef NS_ENUM(NSUInteger, MeetingRoomToAgentCode) {
    MeetingRoomToAgentCodeQuitMeeting,                //退出会议;
    MeetingRoomToAgentCodeIsUserIDExist,              //查询视讯号是否存在;
    MeetingRoomToAgentCodeInviteToMeeting,            //邀请参会;
    MeetingRoomToAgentCodeAddFriend,                  //添加联系人;
    MeetingRoomToAgentCodeGetContactList,             //获取联系人列表;
    MeetingRoomToAgentCodeUMKeyEvent,                 // 友盟关键事件
    MeetingRoomToAgentShareWithThirdPart,                // 微信分享
    MeetingRoomToAgentInviteByWechat,                    // 微信邀请
    MeetingRoomToAgentCodeForceQuitMeeting ,              // 被踢出会议
    MeetingRoomToAgentCodeOtherQuitMeeting, // 某人退出会议
    MeetingRoomToAgentCodeOtherJoinMeeting // 其他人加入会议

};

typedef NS_ENUM(NSUInteger, HostToAgentCode) {
    HostToAgentCodeCodeInComingCallEnd,               //外呼结束;
};
typedef NS_ENUM(NSInteger,MeetingInterfaceCode){   // 会议接口错误码
    MeetingInterfaceCodeSystemError = -999, // 系统错误
    MeetingInterfaceCodeJsonError   = -900, // json格式错误
    MeetingInterfaceCodeParamIsNull = -901,// 参数为空
    MeetingInterfaceCodeTokenIsNotexsit = -902,// token不存在
    MeetingInterfaceCodeTokenInvalite = -903, // token 过期
    MeetingInterfaceCodeInvaliteMeetingID = -906, // 无效的会议号
    MeetingInterfaceCodeServiceIsNull = -909, // service参数为空
    MeetingInterfaceCodeServiceError = -910, // service参数不正确
};

// 分享的类型
typedef NS_ENUM(NSInteger, ShareTypeThrid) {
    ShareTypeThridWeixin          = 0,
    ShareTypeThridPengYouQuan     = 1,
    ShareTypeThridSMS             = 2,
    ShareTypeThridLinkCopy        = 3,

};

typedef NS_OPTIONS(NSUInteger, MeetingControlMediaType) {
    MeetingControlMediaTypeNone            = 0,
    MeetingControlMediaTypeVideoCamera     = 1 << 0,
    MeetingControlMediaTypeMicVideoAudio   = 1 << 1,
    MeetingControlMediaTypeVideoDoc        = 1 << 2,
    MeetingControlMediaTypeAudioDoc        = 1 << 3,
};

#define ResourceID_Video_Camera  100
#define ResourceID_Video_DOC     300
#define ResourceID_Audio_MIC     200

typedef NS_ENUM(NSInteger, SpeakerMediaType) {
    SpeakerMediaType_Video_Camera     = 0,
    SpeakerMediaType_Audio_Mic,
    SpeakerMediaType_Video_Doc,
    SpeakerMediaType_Audio_Doc
};

typedef NS_ENUM(int, MeetingSpeakerType) {
    MeetingSpeakerType_KeyNote     = 1,
    MeetingSpeakerType_Normal      = 2,
};

///编码模式：
typedef NS_ENUM(int, BTVideoEncodingMode) {
    ///0.自定义(选择自定义编码参数有效）
    BTVEncodingMode_Default = 0,
    ///1.FHD:1080p
    BTVEncodingMode_FHD,
    ///2.HD:720p
    BTVEncodingMode_HD,
    ///3.VGA:360p
    BTVEncodingMode_VGA,
    ///4.QVGA:180p
    BTVEncodingMode_QVGA,
    ///5.UHD:4k
    BTVEncodingMode_UHD,
};
///    接收视频模式 received
typedef NS_ENUM(int, BTVideoReceivedMode) {

///    0.自适应（默认值，SDK内部动态调整）
    BTVideoReceivedMode_Default = 0,
///    1.高清，接收大流 HD
    BTVideoReceivedMode_HD,
///    2.标清，接收小流 FLV
    BTVideoReceivedMode_FLV,
};


