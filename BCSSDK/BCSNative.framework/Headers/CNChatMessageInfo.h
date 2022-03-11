//
//  CNChatMessageInfo.h
//  MeetingRoom
//
//  Created by Setoge on 2019/12/17.
//  Copyright © 2019 dutingfu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CNChatMessageInfo : NSObject
///1 发送的消息; 2 接收到的消息
@property (nonatomic,assign) int messageOperation;
///IM聊天类型：1为私聊，2为公众，
@property (nonatomic,assign) int chatType;
///IM消息类型，目前只有0（文字消息）
@property (nonatomic,assign) int IMMsgType;
///消息的唯一标识
@property (strong,nonatomic)NSString *messageID;
///发送者的视讯号
@property (strong,nonatomic)NSString *senderNube;
///发送者的名称
@property (strong,nonatomic)NSString *senderName;
///被at的参会者视讯号数组
@property (strong,nonatomic)NSArray *atNubes;
///信息接收者的视讯号
@property (strong,nonatomic)NSString *receive;
///聊天内容
@property (strong,nonatomic)NSString *msgContent;
///单位：秒
@property (nonatomic,assign) NSInteger timestamp;
/// 信息接收者昵称
@property (nonatomic, strong) NSString *receiveName;
/// 信息的颜色
@property (nonatomic, strong) NSString *msgColor;
@end

NS_ASSUME_NONNULL_END
