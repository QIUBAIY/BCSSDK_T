//
//  Constants.h
//  BCSNative
//
//  Created by Setoge on 2020/3/13.
//  Copyright © 2020 Bulet. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

/// 鉴权登录时需要的参数配置
#define IMEI @"imei"
#define PRODUCTID @"all"
//#define DEVICETYPE @"C-me"
#define APPTYPE @"mobile"
#define DEVICETYPE @"Mobile_jmeeting"
/// 上传日志的通知
#define SDK_LOG_UPLOADLOGACTION @"UPLOADLOGACTION"

//同步错误码
const static int RES_OK = 0 ;//成功
const static int ERR_FAILED = -99 ;//通用失败错误码
const static int ERR_NOT_INIT = -1 ;//未初始化
const static int ERR_PARAM_INVALID = -2 ;//参数错误
const static int ERR_REINIT = -3 ;//重复初始化
const static int ERR_REFUSED = -4;//当前状态无法操作（如摄像头已打开，操作打开摄像头；当前已是发言状态，操作）
const static int ERR_HTTP_IN_USE = -5 ;// Http接口调用中
const static int ERR_STP_IN_USE = -6 ;//信令接口调用中
const static int ERR_NO_PERMISSION = -7;//当前无操作权限（非主持人）
const static int ERR_MAX_SPEAKER_NUM = -8;//当前会议已达到最大发言人数，无法发言或指定发言
const static int ERR_MASTER_MODE = -9;//主持人模式，无法进行操作
const static int ERR_CACCHCHE = -10;//缓存
#pragma mark - Setoge: --------- 同步状态新增
const static int ERR_REINITING = -10 ;//初始化中
const static int ERR_RECREATING = -11 ;//会议创建中
const static int ERR_REJOINING = -12 ;//加入会议中
const static int ERR_INMEETING = -13 ;//会议中
const static int ERR_SPEAKERING = -14 ;//发言中，已发言
const static int ERR_NOSPEAKERING = -15 ;//未发言
const static int ERR_DATA_STREAM = -16;//没有对应流信息
const static int ERR_STATUS_LOUDSPEAKER = -17;//扬声器状态和操作目标一致
//异步错误码
const static int ERR_ASYNC_FAILED = -2000 ; //通用异步失败错误码
const static int ERR_HTTP_TIMEOUT = -2001 ; //Http请求网络异常，请求失败
const static int ERR_GET_NPS_FAILED = -2002 ; //Nps 配置获取失败
const static int ERR_ACCOUNT_NOT_EXIST = -2003 ; //登录失败，账号不存在
const static int ERR_AUTH_FAILED = -2004  ;//登录失败，账号密码校验错误
const static int ERR_TOKEN_INVALID = -2005  ;//token失效
const static int ERR_MEETINGID_INVALID = -2010 ;//会议号不存在
const static int ERR_MEETING_END = -2011 ;//会议已结束
const static int ERR_MEETING_LOCKED = -2012 ;//会议已加锁
const static int ERR_MEETING_PASSWORDERROR = -2013 ;//会议密码错误
const static int ERR_MEETING_HTTPDNSERROR = -2014 ;//HTTPDNS参数获取失败
const static int ERR_MEETING_AUTHEORZIERROR = -2015 ;//统一认证失败
const static int ERR_MEETING_JOINGED = -2016 ;//已在会议中
const static int ERR_MEETING_AUTHEORZIERRORADDRESS = -2017 ;//统一认证，签名串过期
const static int ERR_STP_TIMEOUT = -2050; //信令请求网络异常，请求失败
const static int ERR_CAMERA_EXCEPTION = -2051; //摄像头异常
const static int ERR_MIC_EXCEPTION = -2052; //麦克风异常
const static int ERR_OFFLINE_EXCEPTION = -2053 ;//被迫下线
const static int ERR_BE_KICK_OFF_EXCEPTION = -2054 ;//被请出会议室
#pragma mark - Setoge: --------- 新增错误码
const static int ERR_REJOIN_MEETING_SUCCESS = -2055; // 会议重连成功
const static int ERR_REJOIN_MEETING_FAIL = -2056; // 会议重连失败
const static int ERR_MEETING_OTHER_EXCEPTION = -2057; //会议过程中出现其他异常
const static int ERR_MEETING_CPU_OVERLOAD = -2058; //会议过程中cpu过载
const static int ERR_MEETING_WBPUSH_FAIL = -2059; //申请发布白板流失败
const static int ERR_MEETING_WBCLOSE_FAIL = -2060;//关闭白板流失败
const static int ERR_MEETING_POLLING_RF_FAIL = -2061; //追踪设备，对方拒绝
const static int ERR_MEETING_POLLING_NM_FAIL = -2062;//追踪设备，二维码过期
const static int ERR_MEETING_POLLING_NS_FAIL = -2063; //追踪设备，不支持
const static int ERR_MEETING_POLLING_OT_FAIL = -2064;//追踪设备，其他

const static int ERR_MEETING_PTZ_MASTER_FAIL = -2065;//仅主持人可控制
const static int ERR_MEETING_PTZ_ALL_FAIL = -2066;//禁止被控制

const static int ERR_NetPlane_UNOPEN = -2067;//不支持平面探测
const static int ERR_NetPlane_GETNETIDFAIL = -2068;//平面探测获取ID失败
///会议的模式
typedef enum {
    MEETINGMODE_FREE_MODE = 1,//自由模式
    MEETINGMODE_MASTER_MODE,//主持模式
} MEETINGMODE;

///媒体的类型
typedef enum {
    MEDIATYPE_VIDEO = 0,//视频类型
    MEDIATYPE_DOC_VIDEO,//数据分享类型
    MEDIATYPE_VIDEO_AUDIO_MIC,// 视频类型的mic
    MEDIATYPE_DOC_VIDEO_AUDIO_MIC,//数据分享类型mic
    MEDIATYPE_FUDOC_VIDEO_AUDIO_MIC
} MEDIATYPE;

///订阅视频流模式
typedef enum {
    BIG_WND= 1,//大流
    SMALL_WND,// 小流
    MIDDLE_WND,//中流
} DISPLAY_MODEL_TYPE;


///水印类型
typedef enum {
    TextMark = 1,//文字水印
    TimeMark,    //时间水印
    PicMark      //图片水印
}BCSMarkType;

///水印类型
typedef enum {
    CAMERA_FRONT = 1,//文字水印
    CAMERA_BACK,    //后置
    CAMERA_UNKNOW    //未知
}BCSCameraType;

/**<绘制标注的类型 */
typedef enum {
    DRAWOPERATETYPE_drawline,           /**< 画线 带箭头 */
    DRAWOPERATETYPE_drawcurve,          // 画曲线
    DRAWOPERATETYPE_drawrect,           // 画矩形
    DRAWOPERATETYPE_drawellips,         // 画椭圆
    DRAWOPERATETYPE_eraseRect,          // 擦除矩形区域
    DRAWOPERATETYPE_select,             // 选中一条线(移动、删除、释放)
    DRAWOPERATETYPE_clearBoard,         // 清屏
    DRAWOPERATETYPE_editText,           // 编辑文字
    DRAWOPERATETYPE_error_pic,          //
    DRAWOPERATETYPE_correct_pic,        //
    DRAWOPERATETYPE_share_pic,          //
    DRAWOPERATETYPE_plus_pic,           //
    DRAWOPERATETYPE_flag_pic,           //
    DRAWOPERATETYPE_star_pic,           //
    DRAWOPERATETYPE_thumbtack_pic,      //
    DRAWOPERATETYPE_single_brush,
    DRAWOPERATETYPE_multi_brush,
    DRAWOPERATETYPE_rectin_triangle,
    DRAWOPERATETYPE_lineSegment,        // 画线段
    DRAWOPERATETYPE_laserPen,           // 激光笔
    DRAWOPERATETYPE_eraserTool,         // 橡皮擦
} DRAWOPERATETYPE;

#pragma mark - 会议的视频模式
///1 超清1080p;2 高清720p; 3 清晰vga ;  4 流畅 qvga；
typedef enum {
    VIDEOMODEL_SD_MODE = 1,//超清模式 1080p
    VIDEOMODEL_HD_MODE = 2,//高清模式 720p
    VIDEOMODEL_FOCUS_MODE = 3,//清晰模式  vga
    VIDEOMODEL_FLUENCY_MODE = 4,//流畅模式 qvga

} VIDEOMODEL;//会议的视频模式


#pragma mark - 文字聊天的类型
typedef enum {
    CHATTYPE_PRIVATE=1, // 私聊
    CHATTYPE_PUBLIC,// 公众
}CHATTYPE;//文字聊天的类型
#pragma mark - 用户操作的类型
typedef enum {
    USEROPERATIONTYPE_Camera_Open=1, // 摄像头打开
    USEROPERATIONTYPE_Camera_Close,// 摄像头关闭

    USEROPERATIONTYPE_MIC_Open,// 麦克风打开
    USEROPERATIONTYPE_MIC_Close,// 麦克风关闭

    USEROPERATIONTYPE_Loudspeaker_Open,// 扬声器打开
    USEROPERATIONTYPE_Loudspeaker_Close,// 扬声器关闭

    USEROPERATIONTYPE_Speak,// 发言
    USEROPERATIONTYPE_UnSpeak,// 取消发言

    USEROPERATIONTYPE_RaiseHands ,// 举手发言

    USEROPERATIONTYPE_Appoint_Camera_Open,// 指定操作某用户摄像头打开
    USEROPERATIONTYPE_Appoint_Camera_Close,// 指定操作某用户摄像头关闭

    USEROPERATIONTYPE_Appoint_MIC_Open,// 指定操作某用户麦克风打开
    USEROPERATIONTYPE_Appoint_MIC_Close,// 指定操作某用户麦克风关闭

    USEROPERATIONTYPE_Appoint_Speaking,// 指定操作某用户发言
    USEROPERATIONTYPE_Appoint_UnSpeaking,// 指定操作某用户取消发言

    USEROPERATIONTYPE_Appoint_Master,// 指定操作某用户为主持人 主持人权限移交

    USEROPERATIONTYPE_Appoint_Speaker,// 指定某用户为主讲人
    USEROPERATIONTYPE_Appoint_UnSpeaker,// 指定取消某用户为主讲人

    USEROPERATIONTYPE_Appoint_Quit,// 指定操作某用户退出会议

    USEROPERATIONTYPE_Silence,// 全部静音
    USEROPERATIONTYPE_UnSilence,// 解除全部静音

    USEROPERATIONTYPE_Encryption,// 会议加密
    USEROPERATIONTYPE_UnEncryption,// 会议解密

    USEROPERATIONTYPE_Lock,// 会议加锁
    USEROPERATIONTYPE_UnLock,// 会议解锁

    USEROPERATIONTYPE_Lock_Window,// 视频窗口锁定
    USEROPERATIONTYPE_UnLock_Window,// 视频窗口取消锁定

    USEROPERATIONTYPE_Share_Doc_Open, // 手机数据分享开启
    USEROPERATIONTYPE_Share_Doc_Close, // 手机数据分享关闭

    USEROPERATIONTYPE_Change_Mode,// 切换会议模式
    USEROPERATIONTYPE_Change_Camera,// 切换摄像头
    USEROPERATIONTYPE_EndMeeting, // 结束会议

    USEROPERATIONTYPE_CHAT_Open,// 聊天功能打开
    USEROPERATIONTYPE_CHAT_Close,// 聊天功能关闭
}USEROPERATIONTYPE;//用户操作的类型

/*
 发言者类型（使用枚举，避免后续需要扩展邀请嘉宾等特殊身份，默认1）
 1: 发言者
 2: 旁观者
 */
#pragma mark - 发言者类型（使用枚举，避免后续需要扩展邀请嘉宾等特殊身份，默认1）
typedef enum {
    CNSPEAKERTYPE_SPERAKER = 1, // 私聊
    CNSPEAKERTYPE_bystander = 2,// 公众
}CNSPEAKERTYPE;//文字聊天的类型

#endif /* Constconfig_h */

