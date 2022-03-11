//
//  MediaGeometryManager.h
//  BCSNative
//
//  Created by dutingfu on 2018/8/28.
//  Copyright © 2018年 dutingfu. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum _OperateType
{
    OperateType_drawline,           // 画线 带箭头
    OperateType_drawcurve,          // 画曲线
    OperateType_drawrect,           // 画矩形
    OperateType_drawellips,         // 画椭圆
    OperateType_eraseRect,          // 擦除矩形区域
    OperateType_select,             // 选中一条线(移动、删除、释放)
    OperateType_clearBoard,         // 清屏
    OperateType_editText,           // 编辑文字
    OperateType_error_pic,          //
    OperateType_correct_pic,        //
    OperateType_share_pic,          //
    OperateType_plus_pic,           //
    OperateType_flag_pic,           //
    OperateType_star_pic,           //
    OperateType_thumbtack_pic,      //
    OperateType_single_brush,
    OperateType_multi_brush,
    OperateType_rectin_triangle,
    OperateType_lineSegment,        // 画线段
    OperateType_laserPen,           // 激光笔
    OperateType_eraserTool,         // 橡皮擦
}Operatetype;
@protocol MediaGeometryManagerDelegate
-(void)DrawCmdCallBack:(int) _flage buff:(char *)_cmdBuff len:(int) _cmdLen useSecureSend:(int) useSecureSend timeout:(int) timeout;
@end

@interface MediaGeometryManager : NSObject
@property(nonatomic,weak)id<MediaGeometryManagerDelegate>delegate;

/*
 视讯号
 */
- (instancetype)initWithUserid:(NSString *)userid;
/*
 开始数据分享
 */
- (void)onStart:(UIView *)view userid:(NSString *)userid extraInfo:(int)shareType streamid:(int)streamid;
/*
 停止数据分享
 */
- (void)onStop:(NSString *)userid  extraInfo:(int)shareType streamid:(int)streamid;
/*
 发生数据
 */
- (void)pushData:(NSData *)data;
/*
 选择绘制类型
 */
- (void)operateSelecType:(Operatetype)type
                   color:(int)color
                penWidth:(int)penWidth;
/*
 传人绘图坐标
 */
- (void)pushLocalCmd:(int)action x:(int)x y:(int)y width:(int)width height:(int )height;
/*
 绘制文字
 */
- (void)editText:(NSString *)text color:(int)color fontsize:(int)font  px:(int)px py:(int)py;

/*
 * @brief
 *     通知参会信息：此处只传递发言者的参会信息
 * @param
 *     _userIds   ：UserId数组;
 *     _count     ：UserId个数;
 * @return
 *     = 0 成功
 *      < 0 失败;
 */
-(NSInteger)joinMeeting:(NSArray *)userid;
/*
 * @brief
 *     有人退出
 * @param
 *     _userIds   ：UserId数组;
 *     _count     ：UserId个数;
 * @return
 *     = 0 成功
 *      < 0 失败;
 */
-(NSInteger)LeaveMeeting:(NSArray *)userid;
/*
 移除用户信息
 */
- (void)removeUserData:(NSString *)userid;

- (void)clearAllOpetrion;
// 释放接口
- (void)mediaGeometryRelease;


///  接收到白板数据
/// @param data 白板数据
- (void)didReceiveWhiteBoardData:(NSData *)data;

@end
