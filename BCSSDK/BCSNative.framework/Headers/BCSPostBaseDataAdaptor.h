//
//  AFNPostBaseDataAdaptor.h
//  AFNetworking iOS Example
//
//  Created by dshy1234 on 15/4/20.
//  Copyright (c) 2015年 Gowalla. All rights reserved.
//

#import "ContentNewParser.h"

#import <UIKit/UIKit.h>
@class AFHTTPRequestSerializer;
typedef void (^succeedBlock)(NSDictionary * _Nullable dic);
typedef void (^failedBlock)(long errorCode,NSString * _Nullable des);
typedef NS_ENUM(NSInteger, RequestSerializerType) {
    RequestTypeJSON,//默认从0开始
    RequestTypeHTTP
};
@interface BCSPostBaseDataAdaptor : NSObject

@property (strong,nullable)id body;
- (int)parseJsonCode:(id _Nullable )jsonObj;
- (void)cancel;

//直播室获取直播源
- (int)refresh:(NSString *_Nullable)url
         prama:(NSDictionary *_Nullable)prama
       succeed:(void (^_Nullable)(NSDictionary * _Nullable dic))succeed
        failed:(void (^_Nonnull)(long errorCode, NSString * _Nullable des))failed;

- (int)excute:(NSString *_Nullable)url
        prama:(NSDictionary *_Nullable)prama
      succeed:(void (^_Nullable)(NSDictionary * _Nullable dic))succeed
       failed:(void (^_Nullable)(long errorCode, NSString * _Nullable des))failed;

//双服务器调用方法 同时请求
-(int)concurrent:(NSString *_Nullable)firurl
          secUrl:(NSString *_Nullable)securl
           prama:(NSDictionary *_Nullable)prama
         succeed:(succeedBlock _Nullable )succeed
          failed:(failedBlock _Nullable )failed;
//双服务器调用方法 串行请求
-(int)Serial:(NSString *_Nullable)firurl
      secUrl:(NSString *_Nullable)securl
       prama:(NSDictionary *_Nullable)prama
     succeed:(void (^_Nullable)(NSDictionary * _Nullable dic))succeed
      failed:(void (^_Nullable)(long errorCode, NSString * _Nullable des))failed;
//检查是否有密码专用
-(int)Check:(NSString*_Nullable)firurl
     secUrl:(NSString*_Nullable)securl
      prama:(NSDictionary *_Nullable)prama
    succeed:(void(^_Nullable)(NSDictionary* _Nullable dic))succeed
     failed:(void (^_Nullable)(long errorCode,NSString * _Nullable des))failed;

- (ContentNewParser *_Nullable)getParser;
- (id _Nonnull )parseContentBody:(NSDictionary *_Nullable)dic;
- (id _Nonnull )parseContentBody:(NSDictionary *_Nonnull)firdic
                         withDic:(NSDictionary *_Nullable)secdic;
- (int)get:(NSString *_Nullable)url
     prama:(NSDictionary *_Nullable)prama
   succeed:(void (^_Nullable)(NSDictionary * _Nullable dic))succeed
    failed:(void (^_Nullable)(long errorCode, NSString * _Nullable des))failed;
- (int)postSync:(NSString *_Nullable)url
          prama:(NSDictionary *_Nullable)prama
        succeed:(void (^_Nullable)(NSDictionary * _Nullable dic))succeed
         failed:(void (^_Nullable)(long errorCode, NSString * _Nullable des))failed;
- (RequestSerializerType)getSerializerType;
- (int)excute:(NSString *_Nullable)url
        prama:(NSString *_Nullable)filePath
      succeed:(void (^_Nullable)(NSDictionary * _Nullable dic))succeed
       failed:(void (^_Nullable)(long errorCode, NSString * _Nullable des))failed
      process:(void (^_Nullable)(int process))process;
@end

