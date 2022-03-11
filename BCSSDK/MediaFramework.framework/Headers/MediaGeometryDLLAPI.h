

#ifndef __MEDIAGEOMETRYDLLAPI_H__
#define __MEDIAGEOMETRYDLLAPI_H__


#include "MediaFrameworkDef.h"
#include "MediaGeometryDef.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef _WIN32
#ifdef  MEDIAGEOMETRYDLL_EXPORT
#define MEDIAGEOMETRYDLLAPI __declspec(dllexport)
#else
#define MEDIAGEOMETRYDLLAPI __declspec(dllimport)
#pragma comment(lib, "MediaGeometryDLL.lib")
#endif
#else
#define MEDIAGEOMETRYDLLAPI
#endif


/*
* @brief  ��ʼ��Dll
* @param  
*     _framSet: ��ʼ��������ʼ��
* @return 
*     = 0 �ɹ�
*     < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_MediaGeometryInit(MediaFrameworkSetting _framSet,DrawCmdCallBack _cb,int _userId);

/*
* @brief  ����ʼ��Dll
* @return;
*/
MEDIAGEOMETRYDLLAPI void GEO_MediaGeometryUninit(); 

/*
* @brief 
*     �������Ϣ
* @param
*     _str   ������Ϣ����
*     _count ��������;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_AddStreamInfo(GEOStreamInfo* _str,int _count);

/*
* @brief 
*     ɾ��ָ��������Ϣ
* @param
*     _str   ������Ϣ����
*     _count ��������;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI	int	 GEO_RemoveStreamInfo(GEOStreamInfo* _str,int _count);

/*
* @brief 
*     ���±�������Ϣ
* @param
*     _MaxCount ��������ָ��
*     _count    ������Ϣ����;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int	 GEO_UpdateStreamInfo(GEOStreamInfo* _str, int _count);

/*
* @brief
*     ��ȡ����Ϣ;
* @param
*     _MaxCount �����鳤��;
*     _count    �����ص�����Ϣ����;
* @return
*     = 0 �ɹ�;
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_GetStreamInfo(GEOStreamInfo *&_str, int _MaxCount, int& _count);

/*
* @brief 
*     ��������
* @param
*     _opType  ����������(ֱ��/����/����/����Բ/������������/������/ѡ��һ����(�ƶ���ɾ�����ͷ�);
*     _color   ����ɫ;
*     _penWidth���߿�;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_OperateSelect(GEOOperateType _opType, int _color, int _penWidth);

/*
* @brief 
*     ȡ����������
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI void  GEO_OperateCancel();

/*
* @brief 
*     �������ݻص�
* @param
*     _buff  ������ָ���ַ;
*     _len   �����ݳ���;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_PushCmdData(char *_buff,int _len);


/*
* @brief 
*     ɾ��ͼԪ
* @return 
      ����ɾ����ͼԪ����
*/
MEDIAGEOMETRYDLLAPI int  GEO_DeleteGeometrys();

/*
* @brief 
*     ע��ȫ���ص�����
* @param
*     _streamID  ����Id;
*     _ssCB      ���ص�����;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_RegisterScreenStyle(int _streamID, ScreenStyleCallBack _ssCB);


/*
* @brief 
*     ֪ͨ�λ���Ϣ���˴�ֻ���ݷ����ߵĲλ���Ϣ
* @param
*     _userIds   ��UserId����;
*     _count     ��UserId����;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_JoinMeeting(int* _userIds,int _count);

/*
* @brief 
*     �����˳�
* @param
*     _userIds   ��UserId����;
*     _count     ��UserId����;
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_LeaveMeeting(int* _userIds,int _count);

/*
* @brief 
*     �༭����
* @param
*     _str   ����������;
*     _len   ������
*     _color ����ɫ;
*     _fontSize �������С
*     _point�����Ͻ�λ��
* @return 
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_EditText(char *_str,int _len,int _color,int _fontSize,int _pX,int _pY);

/*
* @brief
*     �����ػ��
* @param
*     _type ö�ٲ�������
* @return
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_DrawCommand(GEOODrawCmdType _type);


/*
* @brief
*     ����ͼԴ�����ɫ��Ĭ��Ϊͼ����Բ���
* @param
*     _actor   ����ɫö��
* @return
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_SetGraphicManagerActor(GEOOGraphicMangerActor _actor);


/*
* @brief
*     ��ͼ�ͽ�ͼ����
* @param
*     _actor   ����ɫö��
*     _path    ��·��
*     _len     ���Ӹ�������
*     _region  ������ͻ��Ƶ�����
* @return
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_ImageOperate(GEOOImageOperation _actor, char *_path, int _len,GEOIRect _region);


/*
* @brief
*     �༭����
* @param
*     _text   ����������;
*     _stuctlen   ��Ԥ��û��
* @return
*     = 0 �ɹ�
*	  < 0 ʧ��;
*/
MEDIAGEOMETRYDLLAPI int  GEO_DrawContext(GEODrawHeader *_text,int _stuctlen);

    
MEDIAGEOMETRYDLLAPI int  GEO_PushLocalCommand(int action, int x, int y);
    
    
MEDIAGEOMETRYDLLAPI int  GEO_PushLocalCommandWithScale(int action, int x, int y , int ptw, int pth);
    
#ifdef __cplusplus
}
#endif

#endif
