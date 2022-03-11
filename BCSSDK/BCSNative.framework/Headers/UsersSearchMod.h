//
//  UsersSearchMod.h
//  BCSNative
//
//  Created by butelmac on 2021/5/21.
//  Copyright © 2021 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface UsersSearchMod : NSObject

@property(strong, nonatomic) NSString * nubeNumber;
@property(strong, nonatomic) NSString * nickName;
@property(strong, nonatomic) NSString * headUrl;



@property(copy, nonatomic) NSString * fullPym;
//
//@property(strong, nonatomic) NSString * netTestUrl;
@property(copy, nonatomic) NSString * firstLetter;

@property(strong, nonatomic) NSString * appType;
@property(strong, nonatomic) NSString * uid;
@property(strong, nonatomic) NSString * mobile;//Add
// v2.7_1 企业中心接口新添加字段
@property(copy, nonatomic) NSString * serviceType;//Add
@property(copy,nonatomic)NSString *  useEndTime;
@property(copy,nonatomic)NSString * useStartTime;
@property(copy,nonatomic)NSString * firstLoginTime;
@property(copy,nonatomic)NSString * tradeIds;
@property(copy,nonatomic)NSString * paidType;
@property(copy,nonatomic)NSString * deviceType;
@property(assign,nonatomic) NSInteger isEnableMeeting;
@property(assign,nonatomic) NSInteger isEnableQueue;
@property(assign,nonatomic) NSInteger isEnableCharMessage;
@property(assign,nonatomic) NSInteger isEnableShortVideo;
@property(assign,nonatomic) NSInteger isEnablePicture;
@property(assign,nonatomic) NSInteger isEnableCard;
@property(strong, nonatomic) NSString * name;
@property(strong,nonatomic) NSString * realName;
@property(assign, nonatomic) int canAdd; //1:可添加   2:已添加  3:不可添加
@property(strong, nonatomic) NSString * imeiPreBind;
@property(assign, nonatomic) BOOL   isCloseSpeaker;


// mds拓展字段
@property (nonatomic, copy) NSString *hospitalOrcompanyName;

@property (nonatomic, copy) NSString *deptName;

@property (nonatomic, copy) NSString *professionName;

@property (nonatomic, copy) NSString *deptPhoneNum;

@property (nonatomic, copy) NSString *groupId;

@property (nonatomic, assign) long contactType;

@property (nonatomic, assign) long long addtionalTime;

@end

NS_ASSUME_NONNULL_END
