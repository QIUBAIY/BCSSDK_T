//
//  MeetingProxyManager.h
//  BCSNative
//
//  Created by 杨礼正 on 2021/8/19.
//  Copyright © 2021 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
///会议的模式
typedef enum {
    PROXY_TYPE_HTTPDNS = 1 //HTTPDNS模块

} MEETING_PROXY_TYPE;

typedef void(^MeetingProxy)(NSDictionary *config,void(^onSuccess)(NSDictionary *proxyInfo),void(^onFaild)(int code,NSString* message));

@interface ProxyManager : NSObject
/**
 *添加会议模块代理
 *@param proxy MeetingProxy对象
 *@param type MeetingProxy对象类型：MEETING_PROXY_TYPE
 *
 */

-(int)addMeetingProxy:(MeetingProxy)proxy proxyType:(MEETING_PROXY_TYPE)type;


/**
 *获取会议模块代理
 *
 *@param type MeetingProxy对象类型：MEETING_PROXY_TYPE
 *返回MeetingProxy对象
 *
 */
-(MeetingProxy)getMeetingProxy:(MEETING_PROXY_TYPE)type;
@end

NS_ASSUME_NONNULL_END
