//
//  ButelOpenSDKConst.h
//  UdpEchoClient
//
//  Created by dshy1234 on 15/4/22.
//
//

#import <Foundation/Foundation.h>

//会控命令中的字段名
static NSString * CMD_ID = @"cmdID";
static NSString * Inner_CMD_ID = @"innerCmdID";

static NSString * CMD_TOKEN = @"token";
static NSString * USER_ID = @"userId";
static NSString * ACOUNT_ID = @"acountId";
static NSString * ACCOUNT_ID = @"accountId";
static NSString * CMD_MEETING_ID = @"meetingId";
static NSString * CMD_STATUS = @"status";
static NSString * MIC_ID = @"micId";
static NSString * MEETING_PRESENCE_ID = @"meetingPresenceId";
static NSString * SPEAKER_ACCOUNT_ID = @"speakerAccountId";
static NSString * SHOW_MODE = @"showMode";
static NSString * PARTNER_LIST = @"partnerList";
static NSString * PARTICIPATORS = @"paticipators";
static NSString * ROLE = @"role";
static NSString * MEETING_STATE = @"meetingState";
static NSString * USER_NAME = @"userName";
static NSString * SPEAKER_STATUS = @"loudSpeakerStatus";
static NSString * MEETING_NAME = @"meetingName";
static NSString * MIC1SPEAKER_ACCOUNT_ID = @"Mic1SpeakerAccoutId";
static NSString * MIC2SPEAKER_ACCOUNT_ID = @"Mic2SpeakerAccoutId";
static NSString * AUDIENCE = @"audience";
static NSString * MEMBER_STATUS = @"memberStatus";
static NSString * PATICIPATORS = @"paticipators";
static NSString * MIC_1_USERNAME = @"Mic1UserName";
static NSString * MIC_2_USERNAME = @"Mic2UserName";
static NSString * EXIT_MODE = @"exitMode";
static NSString * SERVER_STATUS = @"serverStatus";
static NSString * MIC_1_USERID = @"Mic1UserID";
static NSString * MIC_2_USERID = @"Mic2UserID";
static NSString * LOCK_INFO = @"lockInfo";
static NSString * CMD_FLAG = @"cmdFlag";
static NSString * ORIG_USER_NAME = @"origUserName";

static NSString * MIC1_CAM_STAUS = @"Mic1CamStaus";
static NSString * MIC2_CAM_STAUS = @"Mic2CamStaus";
static NSString * OPERATOR_ID = @"operatorId";

static NSString * MASTER_ID = @"masterId";
static NSString * USER_TYPE = @"userType";
static NSString * MEETING_STYLE = @"meetingStyle";
static NSString * MASTER_NAME = @"masterName";
static NSString * LIVE_STATUS = @"liveStatus";
static NSString * CHAT_STATUS = @"ChatStatus";
static NSString * SPEAKERS = @"speakers";
static NSString * CAM_STAUS = @"camStaus";
static NSString * SPEAKER_TYPE = @"speakerType";
static NSString * SCREEN_SHARE_INFO = @"screenShareInfo";
static NSString * STREAMS = @"streams";
static NSString * RESULTS = @"results";
static NSString * OPERATETYPE = @"operateType";

//客户端被轮询需要判断的字段
static NSString * DPMSG = @"DPMSG";//即将被轮询
static NSString * TOASTMSG = @"TOASTMSG";//即将被轮询

//客户端追踪设备
//static NSString * TIMESTAMP = @"timestamp";//时间戳
static NSString * TRACEMODE = @"tracemode";
static NSString * RSPCODE = @"rspcode";
static NSString * RSPMSG = @"rspmsg";



//会控命令错误码
const static int SUCCESS = 0;
const static int TOKEN_TIME_OUT = -900;
const static int INVALID_MEETING_ID = -901;
const static int INVALID_ACCOUNT_ID = -902;
const static int MEETING_NOT_START = -903;
const static int PARTICIPANT_FULL = -904;
const static int INVALID_MIC_ID = -905;
const static int ALREADY_JOINED_MEETING = -906;
const static int MEETING_STOP = -907;
const static int AUTHORITY_WRONG = -908;
const static int ACCOUNT_IN_OTHER_MEETING = -909;
const static int INVALID_SPEAKER_ID = -910;
const static int MEETING_ALREADY_START = -911;
const static int INVALID_CMD = -912;
const static int PARAMS_WRONG = -913;
const static int MEETING_FINISHED = -914;
const static int MEETING_CONTEXT_INIT_FAILED = -915;
const static int ACCOUNT_CONTEXT_NOT_EXIST = -916;
const static int MANAGER_NOT_EXIST = -917;
const static int USER_LOG_OUT_OR_NOT_LOGIN = -918;
const static int JSON_CONTROL_FAILED = -919;
const static int MEMORY_ALLOCATE_FAILED = -920;
const static int IS_LEAVING = -921;
const static int IS_SPEAKING = -922;
const static int LOCAL_NET_WRONG = -980;
const static int SERVER_WRONG = -981;
const static int MC_TIME_OUT = -982;
const static int OTHER_EXCEPTION = -999;
const static int MANAGER_JOIN_MEETING_ERROR = -923;
const static int TOPO_WRONG = -932;
const static int LOCK_OR_UNLOCK_MEETING_FAILED = -934;
const static int MEETING_LOCKED = -935;
const static int MEETING_NOT_CREATED = -987;
typedef enum {
    MOCode_NULL = 0,
    MOCode_INIT_MEDIAPLAY_SDK,
    MOCode_MIC_1_SPEAK,
    MOCode_MIC_2_SPEAK,
    MOCode_MIC_1_STOP_SPEAK,
    MOCode_MIC_2_STOP_SPEAK,
    MOCode_RELEASE,
} ButelOpenSDKMediaOperationCode;

typedef enum {
    MCOCode_NULL = 0,
    MCOCode_JOIN_MEETING,
    MCOCode_RE_JOIN_MEETING,
    MCOCode_GET_PARTICIPATOR_LIST,
    MCOCode_ASK_FOR_SPEAK,
    MCOCode_ASK_FOR_STOP_SPEAK,
    MCOCode_GIVE_MIC,
    MCOCode_LOCK_MEETING,
    MCOCode_EXIT_MEETING,
    
} ButelOpenSDKMeetingControlOperationCode;

typedef enum {
    MeetingState_NOT_START = 1,
    MeetingState_RUNNING,
    MeetingState_STOPPED,
} MeetingState;


typedef enum {
    MemberStatus_SPEAKING = 1,
    MemberStatus_LISTENING,
} MemberStatus;


typedef enum {
    SDK_NOT_JOIN_MEETING = 0,
    SDK_JOIN_MEETING_SUC,
    SDK_JOIN_MEETING_FAIL,
    SDK_MIC_1_SPEAK_SUC,
    SDK_MIC_1_SPEAK_FAIL,
    SDK_MIC_2_SPEAK_SUC,
    SDK_MIC_2_SPEAK_FAIL,
    SDK_REPORT_STATUS_SUC,
    SDK_REPORT_STATUS_FAIL,
    SDK_START_MEETING_SUC,
    SDK_START_MEETING_FAIL,
    SDK_MIC_1_STOP_SPEAK_SUC,
    SDK_MIC_1_STOP_SPEAK_FAIL,
    SDK_MIC_2_STOP_SPEAK_SUC,
    SDK_MIC_2_STOP_SPEAK_FAIL,
    SDK_RELEASE_SUC,
    SDK_RELEASE_FAIL,
    SDK_BE_GRABED,
    SDK_EXCEPTION,
    SDK_MEETING_STOPPED,
    SDK_EXIT_MEETING_SUC,
    SDK_EXIT_MEETING_FAIL,
} ButelOpenSDKStatusCode;

/// 信令命令枚举值
typedef enum {
    JOIN_MEETING                = 7001,
    JOIN_MEETING_RESP           = 7002,
    EXIT_MEETING                = 7003,
    EXIT_MEETING_RESP           = 7004,
    BE_GRABED                   = 7005,
    EXCEPTION                   = 7006,
    REPORT_STATUS               = 8001,
    REPORT_STATUS_RESP          = 8002,
    ASK_FOR_SPEAK               = 8007,
    ASK_FOR_SPEAK_RESP          = 8008,
    
//    START_MEETING               = 8015,
    START_SPEAK                 = 8019,
    NOTIFY_SPEAKER_STREAM_UPDATE = 8133,
    STOP_SPEAK                  = 8021,
    SPEAKER_ON_LINE             = 8025,
    SPEAKER_OFF_LINE            = 8027,
    ASK_FOR_STOP_SPEAK          = 8031,
    ASK_FOR_STOP_SPEAK_RESP     = 8032,
    
    GET_PARTICIPATORS           = 4013,/// 9013
    GET_PARTICIPATORS_RESP      = 4014,/// 9014
    PERSON_JOIN_MEETING         = 9015,
    PERSON_EXIT_MEETING         = 9017,
    PERSON_ASK_FOR_SPEAK        = 9019,
    NOTIFY_UPDATE_STATUS        = 9029,
    
    GIVE_MIC                    = 8035,
    GIVE_MIC_RESP               = 8036,
    
    LOCK_MEETING                = 8037,
    LOCK_MEETING_RESP           = 8038,
    
    NOTIFY_LOCK_INFO            = 8039,
    
    START_INTERPOSE             = 8071,
    START_INTERPOSE_RESP        = 8072,
    
    NOTIFY_START_INTERPOSE      = 8073,
    
    END_INTERPOSE               = 8075,
    END_INTERPOSE_RESP          = 8076,
    
    NOTIFY_END_INTERPOSE        = 8077,
    
    CLOSE_CAMERA                = 8081,
    CLOSE_CAMERA_RESP           = 8082,
    NOTIFY_CLOSE_CAMERA         = 8083,
    
    // 主持人模式
    COMPERE_MODE_CHANGE         = 8085,
    COMPERE_MODE_CHANGE_RESP    = 8086,
    NOTIFY_COMPERE_MODE_CHANGE  = 8087,
    ASSIGN_START_SPEAK          = 8089,
    ASSIGN_START_SPEAK_RESP     = 8090,
    ASSIGN_STOP_SPEAK           = 8091,
    ASSIGN_STOP_SPEAK_RESP      = 8092,
    REQUEST_SPEAK               = 8093,
    REQUEST_SPEAK_RESP          = 8094,
    NOTIFY_REQUEST_SPEAK        = 8095,
    
    //直播
    ASK_LIVE                    = 8097,
    ASK_LIVE_RESP               = 8098,
    NOTIFY_START_LIVE           = 8099,
    
    //多方会议
    APPLY_START                 = 8101,
    APPLY_START_RESP            = 8102,
    NOTIFY_APPLY_START_OTHER    = 8103,
    NOTIFY_APPLY_START_SELF     = 8104,
    APPLY_STOP                  = 8105,
    APPLY_STOP_RESP             = 8106,
    NOTIFY_APPLY_STOP_OTHER     = 8107,
    NOTIFY_APPLY_STOP_SELF      = 8108,
    ASSIGN_KEYNOTE              = 8111,
    ASSIGN_KEYNOTE_RESP         = 8112,
    NOTIFY_KEYNOTE_VALID        = 8113,
    NOTIFY_KEYNOTE_INVALID      = 8115,
    PUBLISH_STREAM              = 8117,
    PUBLISH_STREAM_RESP         = 8118,
    NOTIFY_PUBLISH_STREAM       = 8119,
    SEND_POSITION               = 100,
    UPDATE_STREAM_INFO          = 8131,
    UPDATE_STREAM_INFO_RES      = 8132,
    HOST_KITOUT_Meeting_REQ     = 8121,
    HOST_KITOUT_Meeting_RES     = 8122,
    
    FUOPEN_SHARE_START_OTHER     = 8152,
    FUCLOSE_SHARE_START_OTHER     = 8156,

    NOTITY_FORCE_QUITEMEETING   = 8123,
    HOST_ORDER_ONE_OPERATION_SPEAKER = 8135,
    HOST_ORDER_ONE_OPERATION_SPEAKER_RESPONSE = 8136,
    NOTIFY_PERSON_UPDATE_SPEAKER_STATE = 8137,
    USER_OPERATION_SPEAKER = 8139,
    USER_OPERATION_SPEAKER_RESPONSE = 8140,
    NOTIFY_OTHER_USER_SPEAKER_STATE_CHANGE = 8141,
    HOST_ORDER_ONE_CHANGE_MEDIA_STATE = 8143,
    HOST_ORDER_ONE_CHANGE_MEDIA_STATE_RESPONSE = 8144,
    NOTIFY_PERSON_UPDATE_MEDIA_STATE = 8145,
    NOTIFY_HOST_START_RECORDER = 8243,
    NOTIFY_HOST_STOP_RECORDER = 8247,
    PACAGE_CMD = 3014,
    HOST_JurisdictionChange_RESPONSE = 8249,
    NOTIFY_HOST_JurisdictionChange = 8250,
    NOTIFY_JurisdictionChange = 8251,
    HOST_END_MEETING_RES = 8030,
    /// 结束会议的信令
    NOTIFY_HOST_END_MEETING = 8555,
    HOST_KITOUT_RESPONSE = 8122,
    USER_OPERATE_MESSGAE = 8237,//主持人开启或关闭会议中文字聊天功能
    USER_OPERATE_MESSGAE_RESPONSE = 8238,//主持人开启或关闭会议中文字聊天功能 回应
    HOST_MESSGAESTATUS_CHANGED = 8239,//服务器通知其他参会方会议文字聊天状态发生改变
    USER_SEND_OR_RECEIVE_MESSAGE = 8052,//发送或收到一对多的文字聊天信息
    USER_RECEIVE_MESSAGE_SINGLE = 101,//因为已经有100的命令，为了区分构造101的假命令 100的命令时一对一的文字聊天信息
//    HOST_CHANGED_CAPTION_OR_THEME = 10002,///主持人端修改 字幕 或 主题 或当前的主讲人 设置后客户端收到的信令
//    USER_GET_CAPTION_OR_THEME = 10003,///获取当前的会议主题 和 字幕的设置
//    USER_GET_CAPTION_OR_THEME_RESPONSE = 10004,///获取当前的会议主题 和 字幕的设置回应

//    USER_GET_MEETINGSPEAKER_USER = 10001,//获取当前的主讲人
    //PTZ摄像头控制命令回调
    USER_SET_PTZ_RESPONSE = 10005,
    //PTZ摄像头信息回调
    USER_SET_PTZINFO_RESPONSE = 10006,
    HOST_INTERACTIVESTATE = 8203,//服务器通知某用户互动状态生效或失效
    
    /// 会议基础信息同步命令
    ASYNC_MEETINGINFO = 20001,
    /// 会议用户列表同步命令
    ASYNC_PARTICIPANTLISTINFO = 20003,
    /// 会议发言者同步命令
    ASYNC_SPEAKERLISTINFO = 20005,
    /// 会议资源同步命令
    ASYNC_RESOURCELISTINFO = 20012,
    /// MPU同步（本次不调整，教育中使用）
    MPU_STREAM_UPDATE_RESP_CMD = 20013,
    
//    20020 用户业务信息同步命令
    ASYNC_SPEAKER_BUSINESS = 20020,
    
    /// 全量会议信息同步命令 包含以上所有会议同步命令
    ASYNC_ALLMEETINGINFO = 30001,
    
    /// 用户举手请求命令
    USER_ASK_RAISES_HAND = 8191,
    /// 用户举手请求回应命令
    USER_ASK_RAISES_HAND_RESPONSE = 8192,
    /// 服务器转发用户举手命令
    HOST_USER_RAISES_HAND = 8193,
    /// 主持人清除所有人某项业务状态的命令
    MASTER_USER_DOWN_HAND = 8194,
    /// 主持人清除所有人某项业务状态请求回应命令
    MASTER_USER_DOWN_HAND_RESPONSE = 8195,
    /// 服务器转发主持人清除所有人举手状态
    HOST_MASTER_USER_DOWN_HAND = 8196,
    
    ///添加/修改缓存命令
    USER_AAD_DEL_CACHE_COMMAND = 10001,
    
    /// 广播缓存命令
    HOST_BROADCAST_CACHE_COMMAND = 10002,
    
    
    /// 终端获取缓存命令
    USER_GET_BROADCAST_CACHE_COMMAND = 10003,
    
    /// 终端获取缓存命令回应
    HOST_GET_BROADCAST_CACHE_RESPONSE = 10004,
    
    /// 批量设置信令 添加/修改缓存命令
    USER_BATCH_SEETING_BROADCAST_COMMAND = 11001,
    
    /// 批量设置信令 添加/修改缓存命令广播/回应
    USER_BATCH_SEETING_BROADCAST_COMMAND_RESPONSE = 11002,
    
    /// 终端获取缓存命令(批量)
    USER_GET_BATCH_BROADCAST_CACHE_COMMAND = 11003,
    
    /// 终端获取缓存命令回应(批量)
    HOST_GET_BATCH_BROADCAST_CACHE_RESPONSE = 11004,
    //RoundRobin 开始或结束轮询命令 10007
    RECEIVED_HOST_ROUNDROBIN = 10007,
    //收到即将被轮询100时自定义命令数字,弹出提示语
    RECEIVED_HOST_BE_POLLE = 9901,
    //追踪
    USER_TRACE = 30003,
    RECEIVED_USER_TRACE = 30004,
    USER_CUSTOM_MSG = 60001


} CmdId;

typedef enum {
    MODE_NO_SPEAKER = 0,
    MODE_MIC_1_ORDER_ALONE,
    MODE_MIC_2_ORDER_ALONE,
    MODE_MIC_1_ALONE,
    MODE_MIC_2_ALONE,
    MODE_MIC_1_BIG,
    MODE_MIC_2_BIG,
    MODE_EQUAL_SIZE,
} ModeStatusCode;



typedef enum {
    NotifyType_PERSON_JOIN_MEETING = 0,
    NotifyType_PERSON_EXIT_MEETING ,
    NotifyType_PERSON_ASK_FOR_SPEAK ,
    NotifyType_REMOTE_MEDIAPLAY_SERVICE_DISCONNECTED,
    NotifyType_REMOTE_MEDIAPLAY_SERVICE_CONNECTED,
    NotifyType_MEETING_STOPPED,
    NotifyType_BE_GRABED,
    NotifyType_EXCEPTION ,
    NotifyType_START_MEETING_SUC,
    NotifyType_START_MEETING_FAIL,
    NotifyType_MIC_1_SPEAK_SUC,
    NotifyType_MIC_1_SPEAK_FAIL,
    NotifyType_MIC_1_STOP_SPEAK_SUC,
    NotifyType_MIC_1_STOP_SPEAK_FAIL,
    NotifyType_MIC_2_SPEAK_SUC,
    NotifyType_MIC_2_SPEAK_FAIL,
    NotifyType_MIC_2_STOP_SPEAK_SUC,
    NotifyType_MIC_2_STOP_SPEAK_FAIL,
    NotifyType_RELEASE_SUC,
    NotifyType_START_SPEAK,
    NotifyType_STOP_SPEAK,
    NotifyType_TIME_OUT,
    NotifyType_MEETING_CONTEXT_INIT_FAILED,
    NotifyType_CHANGE_MODE,
    NotifyType_OTHER_EXCEPTION,
    NotifyType_ACCOUNT_CONTEXT_NOT_EXIST,
    NotifyType_MANAGER_NOT_EXIST,
    NotifyType_SERVER_WRONG,
    NotifyType_HANDLE_EXCEPTION_SUC ,
    NotifyType_HANDLE_EXCEPTION_FAIL ,
    NotifyType_MEETING_FINISHED ,
    NotifyType_SPEAKER_ON_LINE,
    NotifyType_SPEAKER_OFF_LINE,
    NotifyType_TOPO_WRONG,
    NotifyType_MEETING_CONTROL_AGENT_INIT_FAIL,
    NotifyType_ALREADY_JOINED_MEETING,
    NotifyType_TOKEN_TIME_OUT,
    NotifyType_UPLOAD_UI,
    NotifyType_INVALID_MEETING_ID,
    NotifyType_INVALID_ACCOUNT_ID,
    NotifyType_PARTICIPANT_FULL,
    NotifyType_MEETING_STOP,
    NotifyType_MEETING_NOT_START,
    NotifyType_NOTIFY_LOCK_INFO,
    NotifyType_MEETING_LOCKED,
    NotifyType_INIT_COMPLETE,
    NotifyType_START_INTERPOSE,
    NotifyType_END_INTERPOSE,
    NotifyType_NOTIFY_START_INTERPOSE,
    NotifyType_NOTIFY_END_INTERPOSE,
    NotifyType_NOTIFY_CLOSE_CAMERA,
    NotifyType_NOTIFY_COMPERE_MODE_CHANGE,
    NotifyType_NOTIFY_REQUEST_SPEAK,
    NotifyType_NOTIFY_START_LIVE,
    NotifyType_NOTIFY_APPLY_START_OTHER,
    NotifyType_NOTIFY_APPLY_START_SELF,
    NotifyType_FUSHARE_NOTIFY_APPLY_START_OTHER,
    NotifyType_FUSHARE_NOTIFY_APPLY_STOP_OTHER,
    NotifyType_NOTIFY_APPLY_STOP_OTHER,
    NotifyType_NOTIFY_APPLY_STOP_SELF,
    NotifyType_PUBLISH_DOC_STREAM_RESP,
    NotifyType_PUBLISH_Camera_STREAM_RESP,
    NotifyType_PUBLISH_DOC_STREAM,
    NotifyType_SET_DOC_NAME,
    NotifyType_NOTIFY_KEYNOTE_VALID,
    NotifyType_NOTIFY_KEYNOTE_INVALID,
    NotifyType_NOTIFY_PUBLISH_STREAM,
    NotifyType_NOTIFY_STREAM_UPDATE,
    NotifyType_NOTIFY_FORCE_QUITEMEETING,
    // 服务器通知用户需要更改扬声器状态
    NotifyType_NOTIFY_USER_SPEAKER_STATE_CHANGE,
    //  服务器通知某人的扬声器状态改变
    NotifyType_OTHER_SPEAKER_STATE_CHANGE,
    NotifyType_HOST_CHANGE_MEDIA_STATE_CHANGE,
    NotifyType_HOST_START_RECORDER,
    NotifyType_HOST_STOP_RECORDER,
    NotifyType_HOST_Change_Jurisdiction,
    NotifyType_HOST_END_MEETING,
    NotifyType_USER_OPERATE_MESSAGE,//主持人开启或关闭文字聊天功能的回应 8238
    NotifyType_HOST_OPERATE_MESSAGE,//服务器通知其他参会方会议文字聊天状态发生改变 8239
    NotifyType_HOST_UPATE_CHAT_MESSAGEUI,//收到消息更新聊天页面的UI
    NotifyType_HOST_UPATE_CAPTIONORTHEME,//收到主题和字幕更新UI

    NotifyType_HOST_UPATE_SPEAKERUSER,//收到主讲人改变的UI或者获取主讲人的回调
    
    
    /// 用户举手请求回应命令
    NotifyType_USER_ASK_RAISES_HAND_RESPONSE,
    /// 主持人清除所有人某项业务状态请求回应命令
    NotifyType_MASTER_USER_DOWN_HAND_RESPONSE,
    
    
    // 是否允许打开麦克风状态变化通知 OnAllowOpenMicStateChange
    NotifyType_HOST_USER_ALLOW_OPENMMIC_STATE_CHANGE,
    // 参会方举手状态发生变化通知 OnUserHandStateChange
    NotifyType_HOST_USER_HAND_STATE_CHANGE,
    /// 服务器转发主持人清除所有人举手状态
    NotifyType_HOST_MASTER_USER_DOWN_HAND,
    /// 广播缓存命令
    NotifyType_HOST_BROADCAST_CACHE_COMMAND,
    /// 加会成功后返回的缓存信令通知
    NotifyType_JOINMEETING_CACHE_COMMAND,
    /// 批量设置信令 添加/修改缓存命令广播/回应
    NotifyType_USER_BATCH_SEETING_BROADCAST_COMMAND_RESPONSE,
    
    ///  会议资源同步命令通知
    NotifyType_HOST_ASYNC_RESOURCE,
    /// 同步会议各种用户列表
    NotifyType_HOST_ASYNC_MEETINGUSERSINFO,
    
    NotifyType_RECEIVED_HOST_BE_POLLE,//收到即将被轮询的通知
    NotifyType_RECEIVED_HOST_ROUNDROBIN,//收到开始/结束轮询的通知
    NotifyType_USER_SET_PTZ_RESPONSE,//云台控制回应
    NotifyType_USER_SET_PTZINFO_RESPONSE,//获取云台摄像头信息回应
    NotifyType_SUB_SCRIBEAUDIOMIX//订阅混音流成功
    
} NotifyType;

typedef enum {
    MCRCode_SUCCESS = 0,
    MCRCode_NOT_INIT,
    MCRCode_REPEATED_CALL,
    MCRCode_IN_PENDING,
    MCRCode_Cache
} MeetingControlReturnCode;

typedef enum {
    MCStatus_NOT_INIT = 0,
    MCStatus_INITED ,
    MCStatus_JOIN_MEETING,
    MCStatus_EXCEPTION,
} MeetingControlStatus;

typedef enum {
    MCOperation_NULL = 0,
    MCOperation_JOIN_MEETING,
    MCOperation_GET_PARTICIPATOR_LIST,
    MCOperation_ASK_FOR_SPEAK,
    MCOperation_ASK_FOR_STOP_SPEAK,
    MCOperation_LOCK_MEETING,
    MCOperation_GIVE_MIC,
    MCOperation_EXIT_MEETING,
    MCOperation_START_INSTRUMENT,
    MCOperation_END_INSTRUMENT,
    MCOperation_END_CAMERA,
    MCOperation_COMPERE_MODE_CHANGE,
    MCOperation_ASSIGN_START_SPEAK,
    MCOperation_ASSIGN_STOP_SPEAK,
    MCOperation_REQUEST_SPEAK,
    MCOperation_ASK_LIVE,
    MCOperation_APPLY_START,
    MCOperation_APPLY_STOP,
    MCOperation_ASSIGN_KEYNOTE,
    MCOperation_PUBLISH_STREAM,
    // 主持人操作用户扬声器
    MCOperation_ORDER_ONE_SPEAKS,
    // 用户操作扬声器
    MCOperation_USER_OPERATE_SPEAKS,
    MCOperation_HOST_JurisdictionChange,
    MCOperation_HOST_KITOUT,
    MCOperation_HOST_ENDMEETING,
    MCOperation_MESSAGE_OPERATE,///主持人开启或关闭消息功能的操作
    MCOperation_USER_OPERATE_THEMEORCAPRION,///获取会议的主题和字幕的操作

    MCOperation_USER_OPERATE_GETMEETINGSOEAKER,//获取当前主讲人的操作
    MCOperation_USER_OPERATE_SETMEETINGSOEAKER,//设置当前主讲人的操作
    
    MCOperation_USER_OPERATE_GetPtzInfo,//获取PTZ摄像头信息
    MCOperation_USER_OPERATE_PtzCtrl,//发送PTZ控制
} MeetingControlOperation;

typedef enum {
    INIT_CREATVIEW = 9,
    INIT_SUC = 10,
    INIT_FAILURE = 11,
    MIC_1_SPEAK_SUC = 12,
    MIC_1_SPEAK_FAILURE = 13,
    MIC_1_STOP_SPEAK_SUC = 14,
    MIC_1_STOP_SPEAK_FAILURE = 15,
    MIC_2_SPEAK_SUC = 16,
    MIC_2_SPEAK_FAILURE = 17,
    MIC_2_STOP_SPEAK_SUC = 18,
    MIC_2_STOP_SPEAK_FAILURE = 19,
//    RELEASE_SUC = 20,
//    RELEASE_FAILURE = 21
} MediaPlaySDKReturnCode;

typedef enum {
    NOT_INIT = 0,
    MEDIAPLAY_INIT = 1,
    MIC_1_SPEAK = 2,
    MIC_2_SPEAK = 3,
    RELEASE = 4,
}MediaStatusCode;

typedef enum {
    Operation_NULL = 0,
    Operation_LEISURE,
    Operation_INIT,
    Operation_MIC_1_SPEAK,
    Operation_MIC_2_SPEAK,
    Operation_MIC_1_STOP_SPEAK,
    Operation_MIC_2_STOP_SPEAK,
    Operation_RELEASE,
}OperationCode;

typedef NS_ENUM(NSInteger, SSApplyStartResponseCode) {
    SSApplyStartResponseCode_OK                   = 0,
    SSApplyStartResponseCode_UIBusy,
    SSApplyStartResponseCode_NotSpeak,
};

typedef NS_ENUM(NSInteger, SSForceStopSharingCode) {
    SSForceStopSharingCode_OK                   = 0,
    SSForceStopSharingCode_Seized,
    SSForceStopSharingCode_StopSpeak,
    SSForceStopSharingCode_ExitMeeting,
    SSForceStopSharingCode_TimeOut,
    SSForceStopSharingCode_Other,
    
};

typedef NS_ENUM(NSUInteger,YunTaiControlType){
    ZOOMIN = 1,
    ZOOMOUT,
    FOCUSIN,
    FOCUSOUT,
    AUTOFOCUS,
    GOHOME,
    MOVELEFT_START,
    MOVELEFT_STOP,
    MOVERIGHT_START,
    MOVERIGHT_STOP,
    MOVEUP_START,
    MOVEUP_STOP,
    MOVEDOWN_START,
    MOVEDOWN_STOP,
    MOVE_STOP,
    SETPRESET,
    GOTOPRESET,
    DELETEPRESET,
    SETPRESETNAME,
    SETMIRROR,
    SWITCHCAMRA
};

@interface ButelOpenSDKConst : NSObject
+ (NSString *)getDescriptionOfStatusCode:(int)statusCode;
+ (NSString *)YunTaiControlTypeString:(YunTaiControlType)status;
@end
