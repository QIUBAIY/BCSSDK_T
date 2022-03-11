#ifndef MEDIAFRAMEWORKDEF_H
#define MEDIAFRAMEWORKDEF_H

#ifdef _WIN32
#ifdef MEDIAFRAMEWORK_EXPORT
#define MEDIAFRAMEWORKAPI __declspec(dllexport)
#else
#define MEDIAFRAMEWORKAPI __declspec(dllimport)
#endif
#else
#define MEDIAFRAMEWORKAPI
#endif

#include <stdint.h>

// head type define version 0.0.2

typedef enum _AVFrameType
{
    FRAME_TYPE_UNKNOWN = -1,
    FRAME_TYPE_SPS,
    FRAME_TYPE_PPS,
    FRAME_TYPE_I,
    FRAME_TYPE_P,
    FRAME_TYPE_I_MOUSE,    //I关键帧
    FRAME_TYPE_MOUSE,
    FRAME_TYPE_KPI,
    FRAME_TYPE_KP
}AVFrameType;

typedef struct _AVTypeStruct
{
    AVFrameType avFrameType;
}AVTypeStruct;

typedef enum _FrameworkEvent
{
    EVENT_REQUEST_IDR = 0,
    EVENT_RECORD_DONE,
    EVENT_JSON_MSG,
}FrameworkEvent;

typedef struct _RequestIDREventData
{
    int streamID;
}RequestIDREventData;

typedef struct _RecordDoneEventData
{
    char key[256];
    char **filename;
    int filecount;
}RecordDoneEventData;

typedef struct _JsonMsgEventData
{
    int streamId;
    char *msg;
}JsonMsgEventData;

typedef void (*FrameSend)(int streamid, char *pFrame, int frameLen);
typedef void (*FrameSendType)(int streamid, char *pFrame, int frameLen, AVTypeStruct avstruct);
typedef void (*DeviceLostCallBack)(int streamid, char *description, int need_restart);
typedef void (*MediaFrameworkStateReport)(int state, char *description);
typedef void (*AudioCapTestDataCallback)(char *pFrame, int frameLen);
typedef void (*AudioRenderPlayFinishCallback)(int errcode, char* description, void* ctx);
typedef void (*RawMediaFrameCallback)(int streamid, char *pFrame, int width, int height);
typedef void (*AudioDBCallback)(int streamid, int channels, double left, double right);
typedef void (*FrameworkEventCallback)(FrameworkEvent event, void *data);

typedef struct _MediaFrameworkSetting
{
    char                       configPath[256];           ///<配置文件路径
    char                       logPath[256];              ///<日志输出路径
    char					   rkPath[256];				  ///<硬编解码库路径
    MediaFrameworkStateReport  reportFun;                 ///<媒体框架状态汇报函数
}MediaFrameworkSetting;

#define MAX_LIVE_NUM 2

typedef struct _LiveParam
{
    char    url[MAX_LIVE_NUM][256];          ///<直播流地址，最多支持MAX_LIVE_NUM路直播
    char    filepath[256];                   ///<录制文件路径
    int     width;                           ///<直播画面宽度
    int     height;                          ///<直播画面高度
    int     vBitrate;                        ///<直播视频码率
    int     samplerate;                      ///<采样率
    int     channels;                        ///<声道数
    int     bitspersample;                   ///<采样精度
    int     aBitrate;                        ///<直播音频码率
    int     isLive;                          ///<是否直播
    int     isRecord;                        ///<是否录制
}LiveParam;

typedef struct _VideoStreamInfo
{
    int 	xPos;              ///<视频在画布上的x坐标
    int 	yPos;              ///<视频在画布上的y坐标
    int 	width;             ///<视频在画布上的宽
    int 	height;            ///<视频在画布上的高
    int 	streamID;          ///<链路ID
}VideoStreamInfo;

typedef struct _AudioStreamInfo
{
    int 	samplerate;         ///<采样率
    int 	channels;           ///<声道数
    int 	bitspersample;      ///<采样精度
    int 	streamID;           ///<链路ID
}AudioStreamInfo;

typedef enum _StreamType
{
    STREAM_TYPE_VIDEO_SEND,         ///<视频发送链路
    STREAM_TYPE_VIDEO_RECV,         ///<视频接收链路
    STREAM_TYPE_AUDIO_SEND,         ///<音频发送链路
    STREAM_TYPE_AUDIO_RECV,         ///<音频接收链路
    STREAM_TYPE_LIVE,               ///<直播录制链路
    STREAM_TYPE_CMD_SEND,           ///<命令发送链路
    STREAM_TYPE_CMD_RECV,           ///<命令接收链路
    STREAM_TYPE_VIDEO_SENDMR,
    STREAM_TYPE_WHITEBOARD_SEND,
    STREAM_TYPE_WHITEBOARD_RECV,
    STREAM_TYPE_VIRTUALLAYER_SEND,
    STREAM_TYPE_VIRTUALLAYER_RECV,
    STREAM_TYPE_SHARE_AUDIO_SEND,    //给SMSDK占位用的
    STREAM_TYPE_VIDEO_SEND_MS,            //人像多流
    STREAM_TYPE_VIRTUALLAYER_SEND_MS    //数据和桌面共享多流
}StreamType;

typedef enum _SourceType
{
    SOURCE_TYPE_UNKNOWN = -1,
    SOURCE_TYPE_DEVICE,         ///<设备源
    SOURCE_TYPE_FILE,           ///<文件源
    SOURCE_TYPE_NET,            ///<网络源
    SOURCE_TYPE_CALLBACK        ///<回调源
}SourceType;

typedef struct _StreamSource
{
    SourceType type;
    char *source;
    int sourceLen;
    int isPrecise;              ///<当源类型是设备时，此参数表示是否对使用的参数做精确匹配
}StreamSource;

typedef enum _VideoColorSpace
{
    COLORSPACE_I420,
    COLORSPACE_YV12,
    COLORSPACE_NV12,
    COLORSPACE_YUY2,
    COLORSPACE_YUYV,
    COLORSPACE_RGB,
    COLORSPACE_MJPG
}VideoColorSpace;

typedef struct _VideoCapParam
{
    int     aspx;
    int     aspy;
    int 	width;              ///<宽
    int 	height;             ///<高
    int 	fps;                ///<帧率
    VideoColorSpace colorSpace; ///<颜色空间(ios not using)
}VideoCapParam;

typedef enum _VideoCodecType
{
    VIDEO_CODEC_TYPE_SOFT,      ///<软编
    VIDEO_CODEC_TYPE_HARD       ///<硬编
}VideoCodecType;

typedef enum _VideoCodecID
{
    VIDEO_CODEC_ID_UNKNOWN = -1,
    VIDEO_CODEC_ID_H264,           ///<H264编解码
    VIDEO_CODEC_ID_VP8,             ///<VP8编解码
    VIDEO_CODEC_ID_HEVC,
    VIDEO_CODEC_ID_H264_KP,
    VIDEO_CODEC_ID_H264SVC
}VideoCodecID;

typedef enum _VideoCodecLevel
{
    CODEC_LEVEL_LOW,
    CODEC_LEVEL_MEDIUM,
    CODEC_LEVEL_HIGH
}VideoCodecLevel;

typedef struct _VideoEncParam
{
    int 				width;         ///<宽
    int 				height;        ///<高
    int 				fps;           ///<帧率
    int 				bitrate;       ///<码率
    VideoCodecLevel 	level;         ///<编码级别
    VideoCodecID 		codecID;       ///<编码器ID
    VideoCodecType      codecType;     ///<编码器类型
}VideoEncParam;

typedef struct _AudioCapParam
{
    int 	samplerate;        ///<采样率
    int 	channels;          ///<声道数
    int 	bitspersample;     ///<采样精度
}AudioCapParam;

typedef enum _AudioCodecID
{
    AUDIO_CODEC_UNKNOWN = -1,
    AUDIO_CODEC_ALAW,          ///<711 alaw
    AUDIO_CODEC_ULAW,          ///<711 ulaw
    AUDIO_CODEC_SPEEX,         ///<speex
    AUDIO_CODEC_OPUS,           ///<opus
    AUDIO_CODEC_AAC
}AudioCodecID;

typedef struct _AudioEncParam
{
    int 			samplerate;       ///<采样率
    int 			channels;         ///<声道数
    int 			bitspersample;    ///<采样精度
    int 			bitrate;          ///<码率
    AudioCodecID 	codecID;          ///<编码器ID
}AudioEncParam;

typedef enum _PictureType
{
    PIC_TYPE_JPG,
    PIC_TYPE_BMP,
    PIC_TYPE_PNG
}PictureType;

typedef struct _VideoSize
{
    int width;
    int height;
}VideoSize;

typedef struct _VideoFormat
{
    VideoColorSpace colorspace;
    VideoSize size[32];
    int fps[32];
    int sizeCount;
    int fpsCount;
}VideoFormat;

typedef struct _VideoDeviceInfo
{
    char name[256];
    VideoFormat format[16];
    int formatCount;
}VideoDeviceInfo;

/*
 码流状态
 */
typedef enum _StreamState
{
    STREAM_IDLE = 0,
    STREAM_RUNNING,
}StreamState;

typedef struct _MRVideoEncParam
{
    int width;            //宽
    int height;        //高
    int fps;                //帧率
    int bitRate;        //码率
    StreamState state;        //    码流状态
    VideoCodecLevel     level;         ///<编码级别
    VideoCodecID         codecID;       ///<编码器ID
    VideoCodecType      codecType;     ///<编码器类型
}MRVideoEncParam;

typedef struct _MRStreamParam
{
    SourceType sourceType;
    char *source;                                    //摄像头名称
    int sourceLen;                                    //成像头名称长度
    VideoCapParam *camParam;            //采集参数
    MRVideoEncParam *encSDParam;        //小码率流编码参数
    MRVideoEncParam *encHDParam;        //高码率流编码参数
    void *displayWindow;                        //预览窗口
    int aspx;                                            //渲染模式（等比例渲染或者强制比例渲染）
    int aspy;
    FrameSendType frmSDSendType;
    FrameSendType frmHDSendType;
}MRStreamParam;

typedef struct _MRStreamParamEx : public MRStreamParam
{
    void *capHwnd;  //如果source是"DesktopCaptureEx"，则表明要采集的窗口句柄
}MRStreamParamEx;

// in ios , FrameSendType not support . must use FrameSend !!!!
typedef struct _StreamParam
{
    SourceType sourceType;
    char *source;
    int sourceLen;
    union
    {
        struct
        {
            VideoCapParam *capParam;
            VideoEncParam *encParam;
            void *displayWindow;
            int aspx;
            int aspy;
            FrameSend frmSend;
            FrameSendType frmSendType;
        }vsParam;
        
        struct
        {
            void *displayWindow;
            int aspx;
            int aspy;
        }vrParam;
        
        struct
        {
            AudioCapParam *capParam;
            AudioEncParam *encParam;
            FrameSend frmSend;
            FrameSendType frmSendType;
            int isMix;
        }asParam;
        
        struct  
        {
            int isMix;
            char device[256];
        }arParam;
        
        struct  
        {
            LiveParam *param;
        }lvParam;
        
        struct  
        {
            FrameSend frmSend;
            FrameSendType frmSendType;
        }csParam;
        
        struct
        {
            MRStreamParamEx *param;
        }virtualLayerSendParam;
        
        struct
        {
            void *displayWindow;
            int aspx;
            int aspy;
        }virtualLayerRecvParam;
        
        struct
        {
            void *wbHwnd;
        }whiteBoardSendParam;
        
        struct
        {
            void *wbHwnd;
        }whiteBoardRecvParam;
        
    }param;
}StreamParam;

typedef enum _FrameType
{
    FRAME_TYPE_YUV,
    FRAME_TYPE_H264,
    FRAME_TYPE_RTP
}FrameType;

typedef enum _SourceState
{
    STREAM_STATE_START,
    SOURCE_STATE_REMOVED,
    SOURCE_STATE_ADDED,
    SOURCE_STATE_CHANGED
}SourceState;

typedef enum _ScreenStyle
{
    SCREEN_STYLE_NORMAL,
    SCREEN_STYLE_MAX
}ScreenStyle;

typedef struct _SourceStatePacket
{
    int mSourceId;
    SourceState state;
}SourceStatePacket;

typedef void (*LayoutStateCallBack)(int streamid, SourceStatePacket* packet, int count);
typedef void (*ScreenStyleCallBack)(int streamid, ScreenStyle style);

typedef enum
{
    DEF_PIC_NO_DATA,                //接收画面未收到数据时的默认图片
    DEF_PIC_LOCAL_NETWORK_POOR,        //本地网络不好关闭视频时的图片
    DEF_PIC_REMOTE_NETWORK_POOR        //对方网络不好关闭视频时的图片
}DefaultPicture;

typedef enum _StopRecvReason
{
    STOP_FOR_LOCAL_BANDWIDTH_LIMIT,
    STOP_FOR_REMOTE_BANDWIDTH_LIMIT
}StopRecvReason;


// SVC


typedef struct _SVCData
{
    int streamID;
    FrameType type;
    char * pFrame;
    int frameLen;
    AVTypeStruct acstruct;
    unsigned char * pSvcExt;
    int SvcExtLen;
}SVCData;

typedef void (*FrameSendEx)(SVCData * pSVCData);

/////////////////////multi stream相关////////////////////
typedef enum{
    MEDIA_TYPE_VIDEO = 0,
    MEDIA_TYPE_AUDIO = 1
}MediaType;

typedef struct{
    int numLayers;
    int layerID;
    int offset;
    int frameID;
}SVCFrameInfo;

typedef struct{
    char *pData;
    int dataLen;
    AVFrameType frameType;
    SVCFrameInfo *svcinfo;
}VideoEncodedFrame;

typedef enum{
    MS_CALLBACK_TYPE_VIDEOENCODEDFRAME = 0 //对应VideoEncodedFrame
}MultiStreamCallbackType;

typedef void (*MultiStreamFrameCallback)(int streamid, int subid, MultiStreamCallbackType type, void *pData);

typedef struct{
    int subid;
    int bitrate;
    StreamState state;
    VideoCodecID codecID;
    VideoCodecType codecType;
    MultiStreamFrameCallback callBack;
}SubStreamParam;

typedef struct{
    char *cameraName;            //内存由调用者分配
    int cameraNameLen;             //设置参数时表示cameraName字符串长度；获取参数时表示cameraName最大存储长度，返回时会填写cameraName字符串长度
    StreamType type;             //只支持STREAM_TYPE_VIDEO_SEND_MS(人像多流), STREAM_TYPE_VIRTUALLAYER_SEND_MS(数据和桌面共享多流)
    void *displayWindow;
    SubStreamParam *params;         //内存由调用者分配
    int count;                     //params的个数
    int actualCount;             //获取参数时用，表示填入params中的实际个数，小于等于count
}MultiStreamVideoParam;

typedef enum{
    DS_MODE_BALANCE = 0,
    DS_MODE_QUALITY = 1,
    DS_MODE_SPEED = 2
}DataShareMode;

typedef struct{
    int subid;
    int encfps;
    int bitrate;
    int width;
    int height;
    StreamState state;
    char codecName[128];
}SubStreamQos;

typedef struct{
    int streamid;
    int capfps;
    SubStreamQos *subQos;    //调用者负责分配空间
    int count;                //subQos数量
    int actualCount;        //实际填入的subQos数量，小于等于count
}MultiStreamQos;

//////////////////////new qos/////////////////////////

typedef struct QosBase_ {
    StreamType type;
}QosBase;

typedef struct AudioSendQos_ : QosBase{
    int sampleRate;
    int bitsPerSample;
    int channels;
    char codec[32];
    int bitRate;
    int echoTail;
}AudioSendQos;

//typedef struct AudioRecvQos_ : QosBase{
//    int sampleRate;
//    int bitsPerSample;
//    int channels;
//    char codec[32];
//    int bitRate;
//    int emptyPacketRemove;
//    int audioDiscardTimes;
//    int emptyPacketInsert;
//    int oneEmptypacket;
//    int twoEmptyPackets;
//    int threeEmptyPackets;
//    int fourToTenEmptyPackets;
//    int moreThanTenEmptyPackets;
//    int emptyPacketRate;
//}AudioRecvQos;

typedef struct VideoSendQos_ : QosBase{
    int captureFps;
    int encodeFps;
    int width;
    int height;
    char codec[32];
    int bitRate;
}VideoSendQos;

typedef struct VideoRecvQos_ : QosBase{
    int decodeFps;
    int renderFps;
    int width;
    int height;
    char codec[32];
    int bitRate;
}VideoRecvQos;

typedef struct VirtualLayerRecvQos_ : VideoRecvQos{
    
}VirtualLayerRecvQos;

typedef struct{
    char *encoded;            //编码数据
    int encoded_len;        //编码数据长度
    int flag;                //流切换标志，在流切换的第一帧，设置标志位为1，其他情况设置为0
    unsigned short seq;        //帧序号
    int64_t recv_time;        //接收到完整帧的系统时间
    uint32_t *sync_ids;        //当前被选出来的正在说话的用户的同步id，视频传NULL即可
    int syncid_count;        //当前被选出来的正在说话的用户个数，视频传0即可
    uint32_t sync_id;        //当前媒体数据对应的用户的同步id
}MediaPacket;

typedef struct{
    char *encoded;
    int encoded_len;
    int volume;
}AudioEncodedFrame;

typedef void (*AudioEncodedFrameCallback)(int streamID, AudioEncodedFrame *frame);

typedef void (*CurrentSpeakerCallback)(uint32_t *speakers, int speaker_count);

typedef struct{
    uint32_t syncid;    //同步id，如果当前接收的是混音流，同步id会填成0
    int bitrate;
    int samplerate;
    int bitsPerSample;
    int channels;
    char codec[16];
}SingleAudioStreamQos;

typedef struct AudioRecvQos_ : QosBase{
    int streamID;
    SingleAudioStreamQos *singleQos;    //调用者负责申请内存
    int count;    //[in] singleQos的数量
    int actualCount;    //[out] 实际填充的singleQos数量
}AudioRecvQos;

typedef void (*AudioRawFrameCallback)(int streamID, char *data, int datalen, int samplerate, int channels, int bitspersample);

#endif

