#ifndef MEDIA_FRAMEWORK_API_EXT_H
#define MEDIA_FRAMEWORK_API_EXT_H

#include "MediaFrameworkDef.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * 创建视频多流发送链路
 * 大于0成功，返回流id；小于等于0失败
 * 同步返回实际使用的参数，如设置的码率是720P档位，但是摄像头不支持，会自动降档，同时会
 * 在paramout中把实际使用的码率返回。如果设置的参数可以支持，paramout内容跟paramin一样
 */
MEDIAFRAMEWORKAPI int CreateMultiVideoSendStream(MultiStreamVideoParam *paramin, MultiStreamVideoParam *paramout);

/*
 * 删除视频多流发送链路
 */
MEDIAFRAMEWORKAPI int DeleteMultiVideoSendStream(int streamid);

/*
 * 设置视频多流发送链路媒体回调，每个子流回调可以相同也可以不同
 */
MEDIAFRAMEWORKAPI int RegisterMultiStreamFrameCallback(int streamid, int subid, MultiStreamFrameCallback callback);

/*
 * 置空视频多流发送链路媒体回调
 */
MEDIAFRAMEWORKAPI int UnRegisterMultiStreamFrameCallback(int streamid, int subid);

/*
 * 获取视频多流发送链路参数，全量返回
 */
MEDIAFRAMEWORKAPI int GetMultiStreamParam(int streamid, MultiStreamVideoParam *param);

/*
 * 设置视频多流发送链路参数，先调用GetMultiStreamParam获取全量参数，按需修改
 */
MEDIAFRAMEWORKAPI int SetMultiStreamParam(int streamid, MultiStreamVideoParam *paramin, MultiStreamVideoParam *paramout);

/*
 * 设置码率表格，包括人像和数据
 */
MEDIAFRAMEWORKAPI int SetRateListConfig(char *jsonData);

/*
 * 设置数据共享(含桌面共享)模式，包括平衡模式、质量模式和流畅模式
 */
MEDIAFRAMEWORKAPI int SetDataShareMode(DataShareMode mode);

/*
 * 请求IDR
 */
MEDIAFRAMEWORKAPI void RequesetIDR(int streamid, int subid);

/*
 * 获取多流qos
 */
MEDIAFRAMEWORKAPI int GetMultiStreamQos(int streamid, MultiStreamQos *qos);

#ifdef __cplusplus
}
#endif

#endif