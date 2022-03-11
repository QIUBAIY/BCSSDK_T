

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
* @brief  初始化Dll
* @param  
*     _framSet: 初始化参数初始化
* @return 
*     = 0 成功
*     < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_MediaGeometryInit(MediaFrameworkSetting _framSet,DrawCmdCallBack _cb,int _userId);

/*
* @brief  反初始化Dll
* @return;
*/
MEDIAGEOMETRYDLLAPI void GEO_MediaGeometryUninit(); 

/*
* @brief 
*     添加流信息
* @param
*     _str   ：流信息数组
*     _count ：流个数;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_AddStreamInfo(GEOStreamInfo* _str,int _count);

/*
* @brief 
*     删除指定的流信息
* @param
*     _str   ：流信息数组
*     _count ：流个数;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI	int	 GEO_RemoveStreamInfo(GEOStreamInfo* _str,int _count);

/*
* @brief 
*     更新本地流信息
* @param
*     _MaxCount ：流数组指针
*     _count    ：流信息个数;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int	 GEO_UpdateStreamInfo(GEOStreamInfo* _str, int _count);

/*
* @brief
*     获取流信息;
* @param
*     _MaxCount ：数组长度;
*     _count    ：返回的流信息个数;
* @return
*     = 0 成功;
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_GetStreamInfo(GEOStreamInfo *&_str, int _MaxCount, int& _count);

/*
* @brief 
*     绘制命令
* @param
*     _opType  ：操作类型(直线/曲线/矩形/画椭圆/擦除矩形区域/清空面板/选中一条线(移动、删除、释放);
*     _color   ：颜色;
*     _penWidth：线宽;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_OperateSelect(GEOOperateType _opType, int _color, int _penWidth);

/*
* @brief 
*     取消操作监听
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI void  GEO_OperateCancel();

/*
* @brief 
*     接收数据回调
* @param
*     _buff  ：数据指针地址;
*     _len   ：数据长度;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_PushCmdData(char *_buff,int _len);


/*
* @brief 
*     删除图元
* @return 
      返回删除的图元个数
*/
MEDIAGEOMETRYDLLAPI int  GEO_DeleteGeometrys();

/*
* @brief 
*     注册全屏回调函数
* @param
*     _streamID  ：流Id;
*     _ssCB      ：回调函数;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_RegisterScreenStyle(int _streamID, ScreenStyleCallBack _ssCB);


/*
* @brief 
*     通知参会信息：此处只传递发言者的参会信息
* @param
*     _userIds   ：UserId数组;
*     _count     ：UserId个数;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_JoinMeeting(int* _userIds,int _count);

/*
* @brief 
*     有人退出
* @param
*     _userIds   ：UserId数组;
*     _count     ：UserId个数;
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_LeaveMeeting(int* _userIds,int _count);

/*
* @brief 
*     编辑文字
* @param
*     _str   ：文字内容;
*     _len   ：长度
*     _color ：颜色;
*     _fontSize ：字体大小
*     _point：左上角位置
* @return 
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_EditText(char *_str,int _len,int _color,int _fontSize,int _pX,int _pY);

/*
* @brief
*     撤销重绘等
* @param
*     _type 枚举操作类型
* @return
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_DrawCommand(GEOODrawCmdType _type);


/*
* @brief
*     设置图源管理角色，默认为图层可以不调
* @param
*     _actor   ：角色枚举
* @return
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_SetGraphicManagerActor(GEOOGraphicMangerActor _actor);


/*
* @brief
*     贴图和截图操作
* @param
*     _actor   ：角色枚举
*     _path    ：路径
*     _len     ：子浮串长度
*     _region  ：保存和绘制的区域
* @return
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_ImageOperate(GEOOImageOperation _actor, char *_path, int _len,GEOIRect _region);


/*
* @brief
*     编辑文字
* @param
*     _text   绘制上下文;
*     _stuctlen   ：预留没用
* @return
*     = 0 成功
*	  < 0 失败;
*/
MEDIAGEOMETRYDLLAPI int  GEO_DrawContext(GEODrawHeader *_text,int _stuctlen);

    
MEDIAGEOMETRYDLLAPI int  GEO_PushLocalCommand(int action, int x, int y);
    
    
MEDIAGEOMETRYDLLAPI int  GEO_PushLocalCommandWithScale(int action, int x, int y , int ptw, int pth);
    
#ifdef __cplusplus
}
#endif

#endif
