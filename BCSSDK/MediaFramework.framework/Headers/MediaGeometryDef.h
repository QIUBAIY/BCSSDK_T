
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
	void* hwnd;                    // stream��Ӧ��Ⱦ����HWND
	int   userId;                  // Stream��Ӧ��Share UserId
	int   streamId;                // StreamId
}GEOStreamInfo;


enum GEOOperateType
{
	GEO_drawline,           // ���� ����ͷ
	GEO_drawcurve,          // ������
	GEO_drawrect,           // ������
	GEO_drawellips,         // ����Բ
	GEO_eraseRect,          // ������������
	GEO_select,             // ѡ��һ����(�ƶ���ɾ�����ͷ�)
	GEO_clearBoard,         // ����
	GEO_editText,           // �༭����
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
	GEO_lineSegment,        // ���߶�
	GEO_laserPen,           // �����
	GEO_eraserTool,         // ��Ƥ��
	GEO_vector_pic,         // ʸ��ͼ
	GEO_vector_pic2,        // ʸ��ͼ
	GEO_pass_pic,           // pass
	GEO_draw_backGround,    // ��ͼ����
	GEO_draw_mouse,			//�������
	GEO_arrow_pic,	//���μ�ͷ
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
	GEO_DrawCmdRevocation,      // ����
	GEO_DrawCmdRepaint,         // �ػ�
	GEO_DrawCmdDeleteMySelf,    // ɾ���Լ�
	GEO_DrawCmdDeleteOthers,    // ɾ������
	GEO_DrawCmdDeleteAll,       // ɾ��ȫ����ֻ����û�����������ģ�
	GEO_DrawCmdDsetoryAllData, // ɾ��ȫ�������������ģ�
};

enum GEOOGraphicMangerActor
{
	GEO_GraphLayerManger = 0,    // ͼ��
	GEO_WhiteBoardManager,       // �װ�
	GEO_ProgressCaptuerManager,         // ���̲ɼ�
};

enum GEOOImageOperation
{
	GEO_ScreenShot = 0,    // ��ͼ
	GEO_Chartlet           // ��ͼ
};

enum GEOOptState
{
	GEO_Color = 0,          // ��ɫ
	GEO_LinWidth,           // �߿�
	GEO_FontSize,           // �ֺ�
	GEO_FontStyle,          // �ַ��
};


enum GEOGetDrawState
{
	GEO_isSave = 0,        // �Ƿ���Ҫ����
};

enum GEO_CallBackStaticType
{
	GEO_IcrPackage,        // ������
	GEO_WholePackage,      // ȫ����
	GEO_ConvertPackage,    // ת����
	GEO_RecvPackage,    // ת����
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
	GEO_SongType,                  // ����
	GEO_SoftBlack,                 // ΢���ź�
	GEO_BlackType,                 // ����
	GEO_YouYuanType,               // ��Բ����
	GEO_Arial,                     // Arial����
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

/** param����������
 * _flage��        ���͵ı����Ϣ��0:��ʶ�㲥��Ϣ; _flage>0:_flage: ����Ϣ�Ľ�����Id(�����з����ClientId)��
 * _cmdBuff:       ������ʼ��ַ��
 * _cmdLen:        ���ݳ��ȣ�
 *  useSecureSend: 0�ǰ�ȫ��Ϣ��1: ��ȫ��Ϣ��
 *  timeout:       ��ʱʱ�䣻
 */
typedef void(*DrawCmdCallBack)(int _flage,char *_cmdBuff, int _cmdLen,int useSecureSend,int timeout);


#pragma  region backGround


enum MPU_DrawContextMsg
{
	MPU_CONTEXT_BKGROND_MSG = 1,  // ���ñ���ͼ��MsgId
};

struct GEOIDrawBkGrondUrlContext
{
	char *remoutUrl;                // remout url
	int   remoutUrlLen;             // url lenth
};

/** param:���������Ļص�
* _msgId��        �ص�MsgId��
* _context:       ���ݵ�ַ������MsgId���н���������ݣ���
* contexLen:      �ص��ṹ������ݵĳ��ȣ���������������У�飩
*/
typedef void(*DrawContextCallBack)(MPU_DrawContextMsg _msgId, void *_context, int contLen);

// ������ͼ �ṹ��
struct GEOIDrawBkGroundContext
{
	GEODrawHeader header;       // header.type = GEO_draw_backGround
	char         *remoutUrl;
	int           remoutUrlLen;
	char         *localUrl;
	int           localUrlLen;
};
  /*Note:
   ����GEO_DrawContext() ���ݽṹ����  
   header.type = GEO_draw_backGround */

#pragma endregion

#endif