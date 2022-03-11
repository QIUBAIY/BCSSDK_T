
#ifndef __MEDIAGEOMETRYAPIDEF_H__
#define __MEDIAGEOMETRYAPIDEF_H__

typedef struct __GEOStreamInfo
{
	__GEOStreamInfo()
	{
		Reset();
	};
	void Reset()
	{
		userId = 0;
		streamId = 0;
		hwnd = 0;
	}
	void* hwnd;                    // stream对应渲染窗口HWND
	int   userId;                  // Stream对应的Share UserId
	int   streamId;                // StreamId
}GEOStreamInfo;


enum GEOOperateType
{
	GEO_drawline,           // 画线 带箭头
	GEO_drawcurve,          // 画曲线
	GEO_drawrect,           // 画矩形
	GEO_drawellips,         // 画椭圆
	GEO_eraseRect,          // 擦除矩形区域
	GEO_select,             // 选中一条线(移动、删除、释放)
	GEO_clearBoard,         // 清屏
	GEO_editText,           // 编辑文字
	GEO_error_pic,          //
	GEO_correct_pic,        //
	GEO_share_pic,          //
	GEO_plus_pic,           // 
	GEO_flag_pic,           //
	GEO_star_pic,           //
	GEO_thumbtack_pic,      //
	GEO_single_brush,    
	GEO_multi_brush,     
	GEO_rectin_triangle, 
	GEO_lineSegment,        // 画线段
	GEO_laserPen,           // 激光笔
	GEO_eraserTool,         // 橡皮擦
	GEO_vector_pic,         // 矢量图
	GEO_vector_pic2,        // 矢量图
	GEO_pass_pic,           // pass
	GEO_draw_backGround,    // 贴图背景
	GEO_draw_mouse,			//绘制鼠标
	GEO_arrow_pic,	//弧形箭头
	GEO_arrow_pic1,   
	GEO_arrow_pic2,
	GEO_arrow_pic3,
	GEO_arrow_pic4,
	GEO_arrow_pic5,
	GEO_arrow_pic6,
	GEO_arrow_pic7,
	GEO_arrow_pic8,
	GEO_arrow_pic9,
	GEO_arrow_pic10,
	GEO_arrow_pic11,
	GEO_arrow_pic12,
	GEO_arrow_pic13,
	GEO_arrow_pic14,
	GEO_arrow_pic15,
};

enum GEOODrawCmdType
{
	GEO_DrawUnKnow = 0,
	GEO_DrawCmdRevocation,      // 回退
	GEO_DrawCmdRepaint,         // 重绘
	GEO_DrawCmdDeleteMySelf,    // 删除自己
	GEO_DrawCmdDeleteOthers,    // 删除别人
	GEO_DrawCmdDeleteAll,       // 删除全部（只隐藏没有销毁上下文）
	GEO_DrawCmdDsetoryAllData, // 删除全部（销毁上下文）
};

enum GEOOGraphicMangerActor
{
	GEO_GraphLayerManger = 0,    // 图层
	GEO_WhiteBoardManager,       // 白板
	GEO_ProgressCaptuerManager,         // 进程采集
};

enum GEOOImageOperation
{
	GEO_ScreenShot = 0,    // 截图
	GEO_Chartlet           // 贴图
};

enum GEOOptState
{
	GEO_Color = 0,          // 颜色
	GEO_LinWidth,           // 线宽
	GEO_FontSize,           // 字号
	GEO_FontStyle,          // 字风格
};


enum GEOGetDrawState
{
	GEO_isSave = 0,        // 是否需要保存
};

enum GEO_CallBackStaticType
{
	GEO_IcrPackage,        // 增量包
	GEO_WholePackage,      // 全量包
	GEO_ConvertPackage,    // 转发包
	GEO_RecvPackage,    // 转发包
};


struct GEOIRect
{
	int left;
	int right;
	int top;
	int bottom;
};

struct GEODrawHeader
{
	GEOOperateType type;
	int            structSen;
};

enum GEOFontStyle
{
	GEO_SongType,                  // 宋体
	GEO_SoftBlack,                 // 微软雅黑
	GEO_BlackType,                 // 黑体
	GEO_YouYuanType,               // 幼圆字体
	GEO_Arial,                     // Arial字体
};

struct GEOIDrawTextContext
{
	GEODrawHeader header;
	char          *str;
	int   strlen;
	int   color;
	int   fontSize;
	int   px;
	int   py;
	GEOFontStyle fType;
	bool  isBlacken;
	bool  isTilting;
	bool  isUnderline;
};

/** param：参数描述
 * _flage：        发送的标记信息，0:标识广播信息; _flage>0:_flage: 该消息的接收者Id(会议中分配的ClientId)；
 * _cmdBuff:       数据起始地址；
 * _cmdLen:        数据长度；
 *  useSecureSend: 0非安全消息，1: 安全消息；
 *  timeout:       超时时间；
 */
typedef void(*DrawCmdCallBack)(int _flage,char *_cmdBuff, int _cmdLen,int useSecureSend,int timeout);


#pragma  region backGround


enum MPU_DrawContextMsg
{
	MPU_CONTEXT_BKGROND_MSG = 1,  // 设置背景图的MsgId
};

struct GEOIDrawBkGrondUrlContext
{
	char *remoutUrl;                // remout url
	int   remoutUrlLen;             // url lenth
};

/** param:绘制上下文回调
* _msgId：        回调MsgId；
* _context:       数据地址（根据MsgId进行解析相关内容）；
* contexLen:      回调结构体的内容的长度（可以做基本内容校验）
*/
typedef void(*DrawContextCallBack)(MPU_DrawContextMsg _msgId, void *_context, int contLen);

// 贴背景图 结构体
struct GEOIDrawBkGroundContext
{
	GEODrawHeader header;       // header.type = GEO_draw_backGround
	char         *remoutUrl;
	int           remoutUrlLen;
	char         *localUrl;
	int           localUrlLen;
};
  /*Note:
   调用GEO_DrawContext() 传递结构内容  
   header.type = GEO_draw_backGround */

#pragma endregion

#endif