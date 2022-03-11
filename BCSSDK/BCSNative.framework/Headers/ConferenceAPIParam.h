//
//  ConferenceAPIParam.h
//  BCSNative
//
//  Created by 杨礼正 on 2021/8/20.
//  Copyright © 2021 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ConferenceInitParam : NSObject
///后台创建用户时生成的userId
@property(nonatomic,copy)NSString *userId;
///appkey
@property(nonatomic,copy)NSString *appkey;
///昵称
@property(nonatomic,copy)NSString *nickName;
///签名串
@property(nonatomic,copy)NSString *accessToken;
///签名生成时间，格式采用YYMMDDHHMMSS，如20200722200000
@property(nonatomic,copy)NSString *tokenTime;
///nps服务器地址，支持|分割设置多地址
@property(nonatomic,copy)NSString *server;
///nps 服务器访问时的设备类型参数
@property(nonatomic,copy)NSString *deviceType;
///签名算法版本号
@property(nonatomic,copy)NSString *signatureVersion;
// 账号
@property(nonatomic, copy)NSString *account;
// 群组
@property(nonatomic, copy)NSString *group;
@end

NS_ASSUME_NONNULL_END
