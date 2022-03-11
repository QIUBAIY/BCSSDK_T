#ifndef MEDIA_FRAMEWORK_API_EXT_H
#define MEDIA_FRAMEWORK_API_EXT_H

#include "MediaFrameworkDef.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*
 * ������Ƶ����������·
 * ����0�ɹ���������id��С�ڵ���0ʧ��
 * ͬ������ʵ��ʹ�õĲ����������õ�������720P��λ����������ͷ��֧�֣����Զ�������ͬʱ��
 * ��paramout�а�ʵ��ʹ�õ����ʷ��ء�������õĲ�������֧�֣�paramout���ݸ�paraminһ��
 */
MEDIAFRAMEWORKAPI int CreateMultiVideoSendStream(MultiStreamVideoParam *paramin, MultiStreamVideoParam *paramout);

/*
 * ɾ����Ƶ����������·
 */
MEDIAFRAMEWORKAPI int DeleteMultiVideoSendStream(int streamid);

/*
 * ������Ƶ����������·ý��ص���ÿ�������ص�������ͬҲ���Բ�ͬ
 */
MEDIAFRAMEWORKAPI int RegisterMultiStreamFrameCallback(int streamid, int subid, MultiStreamFrameCallback callback);

/*
 * �ÿ���Ƶ����������·ý��ص�
 */
MEDIAFRAMEWORKAPI int UnRegisterMultiStreamFrameCallback(int streamid, int subid);

/*
 * ��ȡ��Ƶ����������·������ȫ������
 */
MEDIAFRAMEWORKAPI int GetMultiStreamParam(int streamid, MultiStreamVideoParam *param);

/*
 * ������Ƶ����������·�������ȵ���GetMultiStreamParam��ȡȫ�������������޸�
 */
MEDIAFRAMEWORKAPI int SetMultiStreamParam(int streamid, MultiStreamVideoParam *paramin, MultiStreamVideoParam *paramout);

/*
 * �������ʱ�񣬰������������
 */
MEDIAFRAMEWORKAPI int SetRateListConfig(char *jsonData);

/*
 * �������ݹ���(�����湲��)ģʽ������ƽ��ģʽ������ģʽ������ģʽ
 */
MEDIAFRAMEWORKAPI int SetDataShareMode(DataShareMode mode);

/*
 * ����IDR
 */
MEDIAFRAMEWORKAPI void RequesetIDR(int streamid, int subid);

/*
 * ��ȡ����qos
 */
MEDIAFRAMEWORKAPI int GetMultiStreamQos(int streamid, MultiStreamQos *qos);

#ifdef __cplusplus
}
#endif

#endif