//
//  CNSpeakerInfo.h
//  BCSNative
//
//  Created by Setoge on 2020/3/22.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MediaStreamInfo.h"
NS_ASSUME_NONNULL_BEGIN

@interface CNSpeakerInfo : NSObject

/**
 * @note 发言者视讯号
*/
@property (strong,nonatomic)NSString *accountID;
/**
 * @note 发言者名称
*/
@property (strong,nonatomic)NSString *accountName;
/**
 * @note 发言者状态（使用枚举，避免后续需要扩展邀请嘉宾等特殊身份，默认1）
 1: 发言者
 2: 旁观者 （不发言）
*/
@property (assign,nonatomic)int speakerType;

/**
 * @note 是否是主持人（默认false）
 YES: 主持人
 NO:非主持人
 */
@property (nonatomic,assign) BOOL isMaster;

/**
 * @note 是否是主讲人（默认false）
 YES: 主持人
 NO:非主持人
 */
@property (nonatomic,assign) BOOL isPresenter;

/**
 * @note 是否是开启共享者： YES 是共享者 ；NO 非共享者，
 */
@property (nonatomic,assign) BOOL isSharing;

/**
 * @note  标记mic 的关闭打开状态 YES 打开 NO 关闭，
*/
@property (assign,nonatomic) BOOL isMicOpening;

/**
 * @note 标记 camera的状态 YES 打开 NO 关闭，
 */
@property (assign,nonatomic) BOOL isCameraOpening;

/**
 * @note 视频本地锁定状态（默认NO）
 YES: 被本地锁定
 NO：未被本地锁定
 */
@property (nonatomic,assign) BOOL isLocalLocking;

/**
 * @note 举手状态（默认NO）；YES: 举手 ；NO：未举手
*/
@property (nonatomic,assign) BOOL isHandup;

/**
 * @note 举手时间，取消举手时设置为 0；当时时间戳 毫秒
*/
@property (nonatomic,assign) int handupTime;

/**
 * @note 加入会议序列(自增，可能不连续）
*/
@property (nonatomic,assign) int joinSeq;

/**
 * @note 发言序列(自增，可能不连续）
*/
@property (nonatomic,assign) int speakSeq;

/**
 * @note 参会方数据流信息
*/
@property (strong,nonatomic) NSMutableDictionary *streamsInfo;
///interActInfo 互动方状态：1为互动，2为取消互动 当前为发言状态时，该值才有意义，互动状态，1为互动（音视频都有），2为取消互动（只有视频）
@property (nonatomic,assign) int interActInfo;
///数据共享状态 1. 打开 ;2. 关闭
@property (nonatomic,assign) int dataShareInfo;
/// 目前白板共享使用的是屏幕共享的字段，增加新字段，暂不启用
@property (nonatomic,assign) int whiteBoardShare;
///屏幕共享状态  1. 打开 ;2. 关闭
@property (nonatomic,assign) int screenShareInfo;

///云台控制  1. 支持 ;2. 不支持
@property (nonatomic,assign) BOOL isSupportPTZ;
@end

NS_ASSUME_NONNULL_END
