//
//  AuthenticateInfo.h
//  DataCenter
//
//  Created by dutingfu on 15/11/4.
//  Copyright © 2015年 dutingfu. All rights reserved.
//
/** @brief 鉴权解析的数据结构 */
#import <Foundation/Foundation.h>

@interface AuthenticateInfo : NSObject <NSCoding>

@property(nonatomic,copy)NSString * appType;
@property(nonatomic,copy)NSString * blockStrangeCall;
@property(nonatomic,copy)NSString * headUrl;
@property(nonatomic,copy)NSString * imei;
@property(nonatomic,copy)NSString * imeiPreBind;
@property(nonatomic,copy)NSString * mail;
@property(nonatomic,copy)NSString * mobile;
@property(nonatomic,copy)NSString * nickname;
@property(nonatomic,copy)NSString * nubeNumber;
@property(nonatomic,copy)NSString * phone;
@property(nonatomic,copy)NSString * prod002;
@property(nonatomic,copy)NSString * productId;
@property(nonatomic,copy)NSString * securityNumber;
@property(nonatomic,copy)NSString * uid;
@property(nonatomic,copy)NSString * accessToken;
@property(copy,nonatomic)NSString * deviceType;
@property(assign,nonatomic) NSInteger isEnableMeeting;
@property(assign,nonatomic) NSInteger isEnableQueue;
@property(assign,nonatomic) NSInteger isEnableCharMessage;
@property(assign,nonatomic) NSInteger isEnableShortVideo;
@property(assign,nonatomic) NSInteger isEnablePicture;
@property(assign,nonatomic) NSInteger isEnableCard;
@property(assign,nonatomic) NSInteger changPwdFlg;
@end
