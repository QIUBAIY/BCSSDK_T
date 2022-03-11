//
//  HTTPDNSConfig.h
//  BCSNative
//
//  Created by ButelMac on 2020/10/14.
//  Copyright © 2020 redcdn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HTTPDNSConfig : NSObject
/// 全球加速功能参数
/// 是否支持HTTPDNS
+ (void)setSupportHTTPDNS:(BOOL) HTTPDNS;
/// 0 国内 ；1国外
+ (void)setHTTPDNSType:(int)type;
/// 设置地区简码
+ (void)setAreaCode:(NSString *)areaCode;
/// + (void)setHTTPDNS加速启动地址
+ (void)setHTTPDNSSTPRCAccUrl:(NSString *)STPRCAccUrl;
/// stp启动地址
+ (void)setHTTPDNSStpIPMap:(NSString *)StpIPMap;
 /// 获取stp多路地址
+ (void)setHTTPDNSStpMultiPathMap:(NSString *)StpMultiPathMap;
///Hostip映射表
+ (void)setHTTPDNSHostIpMap:(NSString *)HostIpMap;
/// 接收白名单列表
+ (void)setHTTPDNSRelayWhiteList:(NSString *)RelayWhiteList;
/// 获取 qos RecverIP多路映射表
+ (void)setHTTPDNSQosReceiveIPMap:(NSString *)QosReceiveIPMap;
/// 获取 qos RecverIP多路映射表
+ (void)setHTTPDNSQosRecverIPMultiPathMap:(NSString *)QosRecverIPMultiPathMap;
/// 获取HOST多路映射表
+ (void)setHTTPDNSHostIpMultiPathMap:(NSString *)HostIpMultiPathMap;
 /// 日志上传加速地址解析 logUploadAccUrl
+ (void)setHTTPDNStLogUploadAccUrl:(NSString *)LogUploadAccUrl;
/// 获取是否支持HTTPDNS
+ (BOOL)getSupportHTTPDNS;
/// 0 国内 ；1国外
+ (int) getHttpDNSType;
/// httpDNS加速启动地址
+ (NSString *) getHttpDNSSTPRCAccUrl;
/// stp启动地址
+ (NSString *) getHttpDNSStpIPMap;
 /// 获取stp多路地址
+ (NSString *) getHttpDNSStpMultiPathMap;
///Hostip映射表
+ (NSString *) getHttpDNSHostIpMap;
/// 接收白名单列表
+ (NSString *) getHttpDNSRelayWhiteList;
/// 获取 qos RecverIP多路映射表
+ (NSString *) getHttpDNSQosReceiveIPMap;
/// 获取 qos RecverIP多路映射表
+ (NSString *) getHttpDNSQosRecverIPMultiPathMap;
/// 获取HOST多路映射表
+ (NSString *) getHttpDNSHostIpMultiPathMap;
 /// 日志上传加速地址解析 logUploadAccUrl
+ (NSString *) getHttpDNStLogUploadAccUrl;
/// 获取地区简码
+ (NSString *) getAreaCode;
@end

NS_ASSUME_NONNULL_END
