#ifndef MMEDIAFRAMEWORKAPI_H
#define MMEDIAFRAMEWORKAPI_H

#include "MediaFrameworkDef.h"

#ifdef __cplusplus
extern "C"
{
#endif
    
    
    ////////////////////system init&release////////////////START
    /*
     * @brief 媒体框架初始化
     * @param setting 初始化参数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int MediaFrameworkInit(MediaFrameworkSetting *setting);
    
    /*
     * @brief 媒体框架反初始化
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int MediaFrameworkRelease();
    
    ////////////////////system init&release////////////////END
    
    
    /////////////////////stream operation//////////////////START
    /*
     * @brief 创建链路
     * @param type 链路类型
     * @param synID 音视频同步ID，具有相同ID的音视频做同步
     * @param param 链路参数，可以为NULL
     * @return 成功返回链路ID；小于等于0表示失败
     * @note 1). 创建链路时如果指定链路参数，则创建完成后可以直接start；如果不指定链路参数，则必须要设置必要的链路属性后才能start。
     *       2). 创建音频链路时，如果不指定参数，则默认是混音的；如果指定参数，可以通过参数里的isMix指定是否混音。
     */
    MEDIAFRAMEWORKAPI int CreateStream(StreamType type, char synID[64], StreamParam *param);
    
    /*
     * @brief 删除链路
     * @param streamID 链路ID
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int DeleteStream(int streamID);
    
    /*
     * @brief 启动链路
     * @param streamID 链路ID
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int StartStream(int streamID);
    
    /*
     * @brief 停止链路
     * @param streamID 链路ID
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int StopStream(int streamID);
    /*
     * @brief 设置链路源
     * @param streamID 链路ID
     * @param source stream源
     * @return 成功返回0；失败返回错误码
     * @note 可以在链路运行过程中设置此属性。如切换摄像头。
     */
    MEDIAFRAMEWORKAPI int SetSource(int streamID, StreamSource *source);
    
    /*
     * @brief 获取链路源
     * @param streamID 链路ID
     * @param[out] source 链路源信息
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetSource(int streamID, StreamSource *source);
    
    /*
     * @brief 设置渲染窗口
     * @param streamID 链路ID
     * @param displayWindow 渲染窗口句柄
     * @param aspx 视频宽高比分子
     * @param aspy 视频宽高比分母
     * @return 成功返回0；失败返回错误码
     * @note 四种情况：
     1. aspx和aspy都为0，保证视频宽高比的情况下填满窗口，有可能会有黑边。(默认)
     2. aspx和aspy都为-1，视频填满窗口，不保证视频宽高必。
     3. aspx和aspy都大于0，强制使用设置的宽高比。
     4. aspx和aspy都为－2，保证视频宽高比的情况下填满窗口，可能出现图像被截断。
     * @warrning 如果对非视频链路调用这个接口会失败
     */
    MEDIAFRAMEWORKAPI int SetDisplayWindow(int streamID, void *displayWindow, int aspx, int aspy);
    
    /*
     * @brief 获取渲染窗口
     * @param streamID 链路ID
     * @param[out] displayWindow 返回渲染窗口句柄
     * @param[out] aspx 返回视频宽高比分子
     * @param[out] aspy 返回视频宽高比分母
     * @return 成功返回0；失败返回错误码
     * @warrning 如果对非视频链路调用这个接口会失败
     */
    MEDIAFRAMEWORKAPI int GetDisplayWindow(int streamID, void **displayWindow, int *aspx, int *aspy);
    
    /*
     * @brief 设置音频渲染设备
     * @param streamID 链路ID
     * @param device 音频播放设备名称
     * @return 成功返回0；失败返回错误码
     * @note 对于混音的音频链路，可以使用任何一个参加混音的链路来设置播放设备名称，如果多次设置，以最后一次设置为准
     *       对于非混音的音频链路，可以为所有链路设置同一个播放设备，也可以设置不同的播放设备。
     */
    MEDIAFRAMEWORKAPI int SetAudioRender(int streamID, char device[256]);
    
    /*
     * @param 获取音频链路当前使用的音频播放设备名称
     * @param[out] device 存储音频设备名称
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetAudioRender(int streamID, char device[256]);
    
    /*
     * @brief 设置码率
     * @param streamID 链路ID
     * @param bitrate 码率值，单位b
     * @return 成功返回0；失败返回错误码
     */
    //MEDIAFRAMEWORKAPI int SetBitrate(int streamID, int bitrate);
    
    /*
     * @brief 获取码率
     * @param 链路ID
     * @param[out] bitrate 返回的码率值
     * @return 成功返回0；失败返回错误码
     */
    //MEDIAFRAMEWORKAPI int GetBitrate(int streamID, int *bitrate);
    
    /*
     * @brief 为音视频链路设置目标直播链路
     * @param streamID 音视频链路ID
     * @param liveStreamID 直播链路ID
     * @return 成功返回0；失败返回错误码
     * @warrning 如果对非音视频链路调用此函数会失败
     */
    //MEDIAFRAMEWORKAPI int SetLiveStream(int streamID, int liveStreamID);
    
    /*
     * @brief 当音视频源为文件或网络时，可以设置是否要对媒体数据进行转码
     * @param streamID 链路ID
     * @param isTranscode 是否转码。0表示不转码；非零表示转码
     * @return 成功返回0；失败返回错误码
     * @warrning 当stream源是文件、网络或者直播stream时可设置此属性，其它
     *           情况下设置无效。
     */
    MEDIAFRAMEWORKAPI int SetIsTranscode(int streamID, int isTranscode);
    
    /*
     * @brief 获取链路是否对source做转码
     * @param streamID 链路ID
     * @param[out] isTranscode 返回是否转码
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetIsTranscode(int streamID, int *isTranscode);
    
    /*
     * @brief 设置是否渲染视频，可以支持关闭预览，只接收不渲染
     * @param streamID 链路ID
     * @param isRender 是否渲染视频。0表示不渲染；非零表示渲染
     * @return 成功返回0；失败返回错误码
     * @note 此属性对视频发送和接收stream都可用。
     * @warrning 仅Video Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetIsRenderVideo(int streamID, int isRender);
    
    /*
     * @brief 获取链路是否渲染视频
     * @param streamID 链路ID
     * @param[out] isRender 返回是否渲染视频
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetIsRenderVideo(int streamID, int *isRender);
    
    /*
     * @brief 对于视频发送链路，可以设置只预览，不做编码发送
     * @param streamID 链路ID
     * @param isSend 是否发送。0表示不发送；非零表示发送
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetIsSendVideo(int streamID, int isSend);
    
    /*
     * @brief 获取链路是否发送视频数据
     * @param streamID 链路ID
     * @param[out] isSend 返回是否发送视频数据
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetIsSendVideo(int streamID, int *isSend);
    
    ///*
    // * @brief 设置音频采集是否做去噪
    // * @param streamID 链路ID
    // * @param isDenoise 是否去噪。0表示不去噪
    // * @return 成功返回0；失败返回错误码
    // */
    //MEDIAFRAMEWORKAPI int SetIsDenoise(int streamID, int isDenoise);//这个是否放到音效里？包括降噪的强度参数
    
    /*
     * @brief 设置视频采集参数
     * @param streamID 链路ID
     * @param param 视频采集参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetVideoCaptureParam(int streamID, VideoCapParam *param);
    
    /*
     * @brief 获取视频采集参数
     * @param streamID 链路ID
     * @param[out] param 视频采集参数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetVideoCaptureParam(int streamID, VideoCapParam *param);
    
    /*
     * @brief 设置视频编码参数
     * @param streamID 链路ID
     * @param param 视频编码参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetVideoEncodeParam(int streamID, VideoEncParam *param);
    
    /*
     * @brief 获取视频编码参数
     * @param streamID 链路ID
     * @param[out] param 视频编码参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetVideoEncodeParam(int streamID, VideoEncParam *param);
    
    /*
     * @brief 设置视频编码类型，硬编或软编
     * @param streamID 链路ID
     * @param param 视频编码类型
     * @return 成功返回0；失败返回错误码
     * @warrning 如果对非视频链路调用这个接口会失败
     */
    //MEDIAFRAMEWORKAPI int SetVideoCodecType(int streamID, VideoCodecType type);
    
    /*
     * @brief 设置音频采集参数
     * @param streamID 链路ID
     * @param param 音频采集参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetAudioCaptureParam(int streamID, AudioCapParam *param);
    
    /*
     * @brief 获取音频采集参数
     * @param streamID 链路ID
     * @param[out] param 返回音频采集参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetAudioCaptureParam(int streamID, AudioCapParam *param);
    
    /*
     * @brief 设置音频编码参数
     * @param streamID 链路ID
     * @param param 音频编码参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetAudioEncodeParam(int streamID, AudioEncParam *param);
    
    /*
     * @brief 获取音频编码参数
     * @param streamID 链路ID
     * @param[out] param 音频编码参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Send Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetAudioEncodeParam(int streamID, AudioEncParam *param);
    
    /*
     * @brief 设置是否需要混音
     * @param streamID 链路ID
     * @param isAudioMix 是否需要混音。0表示不需要；非零表示需要
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Stream支持此属性
     */
    //MEDIAFRAMEWORKAPI int SetIsAudioMix(int streamID, int isAudioMix);
    
    /*
     * @brief 获取是否需要混音
     * @param streamID 链路ID
     * @param[out] isAudioMix 返回是否需要混音
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Stream支持此属性
     */
    //MEDIAFRAMEWORKAPI int GetIsAudioMix(int streamID, int *isAudioMix);
    
    /*
     * @brief 设置回声消除延时
     * @param echotail 延时值
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetEchoTail(int echotail);
    
    /*
     * @brief 获取回声消除延时
     * @param[out] echotail 返回回声消除延时
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetEchoTail(int *echotail);
    
    /*
     * @brief 设置是否使用AGC
     * @param streamID
     * @param isAGC 是否使用AGC。0表示不使用；非零表示使用
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetIsAGC(int streamID, int isAGC);
    
    /*
     * @brief 获取是否使用AGC
     * @param streamID
     * @param[out] isAGC 返回是否使用AGC
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetIsAGC(int streamID, int *isAGC);
    
    /*
     * @brief 设置是否使用AEC
     * @param isAEC 是否使用AEC。0表示不使用；非零表示使用
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetIsAEC(int isAEC);
    
    /*
     * @brief 获取是否使用AEC
     * @param[out] isAEC 返回是否使用AEC。0表示不使用AEC；非零表示使用AEC
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetIsAEC(int *isAEC);
    
    /*
     * @brief 设置直播录制参数
     * @param streamID 链路ID
     * @param param 直播录制参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Live Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetLiveParam(int streamID, LiveParam *param);
    
    /*
     * @brief 获取直播录制参数
     * @param streamID 链路ID
     * @param[out] param 返回直播录制参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Live Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetLiveParam(int streamID, LiveParam *param);
    
    /*
     * @brief 设置音频效果
     * @param streamID 链路ID
     * @param effect 音频效果
     * @param param 音频效果参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetAudioEffect(int streamID, int effect, void *param);
    
    /*
     * @brief 获取音频效果
     * @param streamID 链路ID
     * @param effect 音频效果
     * @param[out] param 返回音频效果参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Audio Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetAudioEffect(int streamID, int effect, void *param);
    
    /*
     * @brief 设置视频效果
     * @param streamID 链路ID
     * @param effect 视频效果
     * @param param 视频效果参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetVideoEffect(int streamID, int effect, void *param);
    
    /*
     * @brief 设置视频效果
     * @param streamID 链路ID
     * @param effect 视频效果
     * @param[out] param 返回视频效果参数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅Video Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int GetVideoEffect(int streamID, int effect, void *param);
    
    /*
     * @brief 设置视频缩放比例
     * @param streamID 链路ID
     * @param x_position 缩放中心点x坐标
     * @param y_position 缩放中心点y坐标
     * @param scalefactor 缩放比例
     * @return 成功返回0，失败返回其他值
     * @warrning 仅Video recv Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetVideoZoomScale(int streamID, float x_position, float y_position, float scalefactor);
    
    /*
     * @brief 设置媒体拖曳移动的坐标
     * @param streamID 链路ID
     * @param tx 水平方向位移
     * @param ty 垂直方向位移
     * @return 成功返回0，失败返回其他值
     * @warrning 仅Video recv Stream支持此属性
     */
    MEDIAFRAMEWORKAPI int SetVideoMove(int streamID, float tx, float ty);
    
    /*
     * @brief 获取视频缩放比例信息
     * @param streamID 链路ID
     * @param x_position 缩放中心点x坐标
     * @param y_position 缩放中心点y坐标
     * @return 成功返回0，失败返回其他值
     * @warrning 仅Video Stream支持此属性
     */
    //MEDIAFRAMEWORKAPI int GetVideoZoomScale(int streamID, float *x_position, float *y_position, float *scalefactor);
    
    /*
     * @brief 更新视频链路信息
     * @param streamID 链路ID
     * @param streamInfo 视频链路信息指针
     * @param streamnum 视频链路个数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int UpdateLiveStreamVideoInfo(int streamID, VideoStreamInfo *streamInfo, int streamnum);//只针对livestream，函数名上区分下，比如UpdateLiveStreamVideoStreamInfo 缺livestreamID
    
    /*
     * @brief 获取直播链路视频流信息
     * @param streamID 链路ID
     * @param[out] streamInfo 返回直播链路视频流信息
     * @param maxnum  streamInfo中最大存储的视频流个数
     * @param[out] streamnum 直播链路中实际的视频流个数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetLiveStreamVideoInfo(int streamID, VideoStreamInfo *streamInfo, int maxnum, int *streamnum);
    
    /*
     * @brief 更新音频链路信息
     * @param 链路ID
     * @param streamInfo 音频链路信息指针
     * @param streamnum 音频链路个数
     * @param 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int UpdateLiveStreamAudioInfo(int streamID, AudioStreamInfo *streamInfo, int streamnum);//只针对livestream，函数名上区分下，比如UpdateLiveStreamAudioStreamInfo 缺livestreamID
    
    /*
     * @brief 获取直播链路音频流信息
     * @param streamID 链路ID
     * @param[out] streamInfo返回直播链路音频流信息
     * @param maxnum streamInfo中最大存储的音频流个数
     * @param streamnum 直播链路中的实际音频流个数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetLiveStreamAudioInfo(int streamID, AudioStreamInfo *streamInfo, int maxnum, int *streamnum);
    
    /*
     * @brief 媒体数据接收回调
     * @param streamID 媒体链路ID
     * @param pFrame 媒体数据指针
     * @param frameLen 媒体数据长度
     */
    MEDIAFRAMEWORKAPI void PushFrame(int streamID, FrameType type, char *pFrame, int frameLen);
    
    /*
     * @brief 拍照并保存图像文件
     * @param type 保存图像的格式
     * @param filepath 图像文件存储路径
     * @param streamID 要进行拍照的链路ID
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int TakePicture(PictureType type, char filepath[256], int streamID);
    
    /*
     * @brief 注册媒体数据发送回调
     * @param streamID 链路ID
     * @param fun 媒体数据发送回调
     * @return 成功返回0；失败返回错误码
     * @note 同一stream可以支持多个数据发送回调；
     *       livestream支持设置数据发送回调
     */
    MEDIAFRAMEWORKAPI int RegisterFrameSendFunc(int streamID, FrameSend fun);
    
    /*
     * @brief 解除注册媒体数据发送回调
     * @param streamID 链路ID
     * @param fun 要解除注册的回调函数指针
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int UnRegisterFrameSendFunc(int streamID, FrameSend fun);
    
    /*
     * @brief 注册原始媒体数据回调
     * @param streamID 链路ID
     * @param cb 原始媒体数据回调
     * @return 成功返回0；失败返回错误码
     * @note  仅针对视频链路
     */
    MEDIAFRAMEWORKAPI int RegisterRawMediaFrameCallback(int streamID, RawMediaFrameCallback cb);
    
    /*
     * @brief 解除注册原始媒体数据回调
     * @param streamID 链路ID
     * @param cb 原始媒体数据回调
     * @return 成功返回0；失败返回错误码
     * @note  仅针对视频链路
     */
    MEDIAFRAMEWORKAPI int UnRegisterRawMediaFrameCallback(int streamID, RawMediaFrameCallback cb);
    
    /*
     * @brief 设置设备丢失回调
     * @param streamID 链路ID
     * @param devLostCB 设备丢失回调
     * @return 成功返回0；失败返回错误码
     * @warrning 如果对非音视频链路调用此函数会失败
     */
    MEDIAFRAMEWORKAPI int SetDeviceLostCallback(int streamID, DeviceLostCallBack devLostCB);
    
    /*
     * @brief 获取所有链路信息
     * @param streamInfo 调用这传入的存储链路信息的指针
     * @param maxlen streamInfo所能存储的最大长度
     * @return 返回streamInfo的实际长度；小于等于0表示失败
     */
    MEDIAFRAMEWORKAPI int GetStreamInfo(char *streaminfo, int maxlen);
    
    
    /*
     * @brief 获取摄像头的位置信息(正在使用的是前置(1)还是后置摄像头(2))
     * @param streamID 链路ID
     * @param[out] status 返回位置信息
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetCapturePositionStatus(int streamID, int * status);
    
    
    /*
     * @brief 设置接收链路的渲染图像是否镜像
     * @param streamID 链路ID
     * @param isMirror 是否镜像。0表示不镜像；非零表示镜像
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetIsMirror(int streamID, int isMirror);
    
    
    /*
     * @brief 设置指定音频接收链路的缓存控制信息
     * @param streamID 链路ID
     * @param AudioMaxBufferNum 音频包缓冲的最大个数
     * @param AudioStartVadBufferNum 开始清理空音时的包个数
     * @param AudioStopVadBufferNum 停止清理空音时的包个数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetOneAudioMixRecvBufferNum(int streamID, int AudioMaxBufferNum, int AudioStartVadBufferNum, int AudioStopVadBufferNum);
    
    
    /*
     * @brief 获得指定音频接收链路的缓存控制信息
     * @param streamID 链路ID
     * @param[out] AudioMaxBufferNum 音频包缓冲的最大个数
     * @param[out] AudioStartVadBufferNum 开始清理空音时的包个数
     * @param[out] AudioStopVadBufferNum 停止清理空音时的包个数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetOneAudioMixRecvBufferNum(int streamID, int *AudioMaxBufferNum, int *AudioStartVadBufferNum, int *AudioStopVadBufferNum);
    
    
    /*
     * @brief 设置所有音频接收链路的缓存控制信息
     * @param AudioMaxBufferNum 音频包缓冲的最大个数
     * @param AudioStartVadBufferNum 开始清理空音时的包个数
     * @param AudioStopVadBufferNum 停止清理空音时的包个数
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetAudioMixRecvBufferNum(int AudioMaxBufferNum, int AudioStartVadBufferNum, int AudioStopVadBufferNum);
    
    
    /*
     * @brief 获取音频混合接收链路缓冲数据队列长度
     * @param streamID 链路ID， *size 缓冲长度
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int GetAudioMixRecvQueueSize(int streamID, int *size);
    
    //////////////////////////////////stream opertion////////////////////////END
    
    /////////////////////////////////device test/////////////////////////////START
    
    /*
     * @brief 获取视频采集设备列表
     * @param devInfo 调用者分配存储空间，用来存储设备信息
     * @param maxNum devInfo最多可以存储的设备个数，如果小于实际设备个数，则只会填充maxNum个设备信息到devInfo里
     * @param devicenum 实际设备个数
     * @return 成功返回0；失败返回错误码
     * @warrning 仅当函数返回0时保证devInfo和devicenum中值的有效性。
     */
    MEDIAFRAMEWORKAPI int GetVideoDeviceList(VideoDeviceInfo *devInfo, int maxNum, int *devicenum);
    
    /*
     * @brief 获取音频采集设备列表
     * @param devicelist 调用者分配存储空间，用来存储设备名称
     * @param listsize devicelist最多可以存储的设备个数，如果小于实际设备个数，则只会填充listsize个设备到devicelist里
     * @param devicenum 实际设备个数
     * @return 成功返回0；失败返回错误码
     * @warrning 为每个设备名称分配不小于256B的存储空间;
     *           仅当函数返回0时保证devicelist和devicenum中值的有效性。
     */
    MEDIAFRAMEWORKAPI int GetAudioCaptureDeviceList(char** devicelist,int listsize,int *devicenum);
    
    /*
     * @brief 获取音频播放设备列表
     * @param devicelist 调用者分配存储空间，用来存储设备名称
     * @param listsize devicelist最多可以存储的设备个数，如果小于实际设备个数，则只会填充listsize个设备到devicelist里
     * @param devicenum 实际设备个数
     * @return 成功返回0；失败返回错误码
     * @warrning 为每个设备名称分配不小于256B的存储空间;
     *           仅当函数返回0时保证devicelist和devicenum中值的有效性。
     */
    MEDIAFRAMEWORKAPI int GetAudioRenderDeviceList(char** devicelist,int listsize,int *devicenum);
    
    /*
     * @brief 视频采集设备测试
     * @param device 视频采集设备名称
     * @param displayWindow 预览窗口句柄
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int StartVideoCaptureTest(int width, int height, int fps, VideoColorSpace colorspace, char device[256], void *displayWindow);
    
    /*
     * @brief 停止视频采集设备测试
     */
    MEDIAFRAMEWORKAPI int StopVideoCaptureTest();
    /*
     * @brief 音频采集设备测试
     * @param device 音频采集设备名称
     * @param dataCallback 音频采集数据回调
     * @param audiofile 音频文件名
     * @return 成功返回0；失败返回错误码
     */
    //增加存文件功能
    MEDIAFRAMEWORKAPI int StartAudioCaptureTest(int samplerate, int channels, int bitspersample, char device[256], AudioCapTestDataCallback dataCallback, char audiofile[256]);
    
    /*
     * @brief 停止音频采集设备测试
     */
    MEDIAFRAMEWORKAPI int StopAudioCaptureTest();
    
    /*
     * @brief 音频播放设备测试，需要使用特定的文件类型
     * @param device 音频播放设备名称，可以为NULL
     * @param audiofile 音频测试文件
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int StartAudioRenderTest(char device[256], char audiofile[256], AudioRenderPlayFinishCallback cb, void *ctx);
    
    /*
     * @brief 停止音频播放设备测试
     */
    MEDIAFRAMEWORKAPI int StopAudioRenderTest();
    
    /*
     * @brief 平台OpengGL版本提示是否可以视频渲染
     * @return 成功返回0，失败返回其他值
     */
    MEDIAFRAMEWORKAPI int OpenGLVerisonTest();
    
    /////////////////////////////////device test/////////////////////////////END
    
    ////////////////////////////////misc////////////////////////////////////START
    /*
     * @brief 获取qos
     * @param qos 调用者传入的存储qos数据的指针
     * @param maxlen qos指针能存储的最大长度
     * @return 返回qos数据的实际长度；小于等于0表示失败
     */
    MEDIAFRAMEWORKAPI int GetQos(char *qos, int maxlen);
    ////////////////////////////////misc////////////////////////////////////END
    
    ////////////////////////////////FrameTimeCallback////////////////////////////////////START
    /*
     * @brief 设置链路时间点回调函数
     * @param streamID 直播流链路ID
     * @param cb 链路时间点回调函数指针
     * @return返回0，失败返回其他值
     */
    MEDIAFRAMEWORKAPI int SetStreamTimeCB(int streamID, void *cb);
    ////////////////////////////////misc////////////////////////////////////END
    
    ////////////////////////////////SVC////////////////////////////////////START
    /*
     * @brief 注册媒体数据发送回调
     * @param streamID 链路ID
     * @param fun 媒体数据发送回调
     * @return 成功返回0；失败返回错误码
     * @note 同一stream可以支持多个数据发送回调；
     *       livestream支持设置数据发送回调
     */
    
    MEDIAFRAMEWORKAPI int RegisterFrameSendExFunc(int streamID, FrameSendEx fun);
    
    /*
     * @brief 媒体数据接收回调
     * @param type 媒体数据类型
     * @param pFrame 媒体数据指针
     */
    MEDIAFRAMEWORKAPI void PushFrameEx(int streamID, FrameType type, char *pFrame, int frameLen, unsigned short seq, int flag);
    
    ////////////////////////////////SVC////////////////////////////////////END
    /*
     * @brief 绘制图元
     * @param streamID 链路id
     * @param element 要绘制的图元，请参考Drawdef.h中相关定义
     * @return 具体返回值请根据当前绘制的图元判断
     */
    MEDIAFRAMEWORKAPI int DrawElement(int streamID, void *element);
    
    /*
     * @brief 执行命令
     * @param streamID 链路id
     * @param cmd 要执行的命令，请参考Drawdef.h中相关定义
     * @return 具体返回值请根据当前执行的命令判断
     */
    MEDIAFRAMEWORKAPI int DrawCommand(int streamID, void *cmd);
    
    /*
     * @brief 在指定的流里的Source布局发生改变的时候回调图元管理模块
     * @param streamID 流ID，
     * @param cb 对应图元管理模块的回调入口
     * @return >0成功返回的是对应的Sourceid；-1失败
     */
    MEDIAFRAMEWORKAPI int RegisterLayoutCallBack(int streamID, LayoutStateCallBack cb);
    
    /*
     * @brief 注册屏幕状态回调
     * @param streamID 流ID
     * @param ssCB 屏幕状态回调函数入口,当布局从分屏变为某一路全屏的时候，或者从全屏变为分屏的时候；
     * @return 0 成功转化； -1 传下来的Sourceid找不到
     */
    MEDIAFRAMEWORKAPI int RegisterScreenStyleCallBack(int streamID, ScreenStyleCallBack ssCB);
    
    
    ////////////////////////////////AUDIO////////////////////////////////////START
    
    /*
     * @brief 注册音频DB回调函数
     * @param streamID 链路ID
     * @param cb 音频DB回调函数指针
     * @return 成功返回0；失败返回错误码
     * @warrning 仅音频链路支持此设置
     */
    MEDIAFRAMEWORKAPI int RegisterAudioDBCallback(int streamID, AudioDBCallback cb);
    
    
    /*
     * @brief 设置音频音量，包括采集和播放音量
     * @param devName 设备名称
     * @param volume 音量大小，范围0~100
     * @return 成功返回0；失败返回错误码
     */
    MEDIAFRAMEWORKAPI int SetVolume(char devName[256], int volume);
    
    /*
     * @brief 获取音量值，包括采集和播放音量
     * @param devName 设备名称
     * @return <0失败；>=0音量值
     */
    MEDIAFRAMEWORKAPI int GetVolume(char devName[256]);
    
    MEDIAFRAMEWORKAPI int SetIsSendAudio(int streamID, int isSend);
    
    ////////////////////////////////AUDIO////////////////////////////////////END
    
    MEDIAFRAMEWORKAPI int SetFrameworkEventCallback(FrameworkEventCallback cb);

    MEDIAFRAMEWORKAPI void MediaFrameworkMsgNotify(int streamID, char* msgInfo, char* out_result, int out_len);

    MEDIAFRAMEWORKAPI int GetStreamQosEx(int streamID, QosBase* qos);

    MEDIAFRAMEWORKAPI void PushFrameEx2(int streamID, MediaPacket *packet);

    /*
     * @brief 设置音频发送链路媒体回调
     * @param streamID 流id
     * @param cb 回调函数指针
     * @return 成功返回0；其他值失败
     */
    MEDIAFRAMEWORKAPI int SetAudioEncodedFrameCallback(int streamID, AudioEncodedFrameCallback cb);

    /*
     * @brief 设置当前说话者回调，用来通知UI当前哪些人在说话
     * @param streamID 流id
     * @param cb 回调函数指针
     * @return 成功返回0；其他值失败
     */
    MEDIAFRAMEWORKAPI int SetCurrentSpeakerCallback(int streamID, CurrentSpeakerCallback cb);

    MEDIAFRAMEWORKAPI int RegisterAudioRawFrameCallback(int streamID, AudioRawFrameCallback cb);

#ifdef __cplusplus
}
#endif

#endif
