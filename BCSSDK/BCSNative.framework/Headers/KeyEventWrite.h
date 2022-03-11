//
//  KeyEventWrite.h
//  JustMeeting
//
//  Created by dutingfu on 15/8/4.
//  Copyright (c) 2015年 青牛软件. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  关键事件检测
 */

@interface KeyEventWrite : NSObject
+ (id)sharedKeyEventWrite;
/**
 *  把关键事件写入文件
 *
 *  @param eventID    事件的ID
 *  @param ResultDesc 结果描述
 *  @param result     返回的结果
 *  @param date       系统时间
 */
- (void)writeToFile:(NSString *)eventID
         descriptin:(NSString *)ResultDesc
             result:(BOOL)result
               date:(NSString *)date;
/**
 *  对外使用的类方法，简化写入步骤
 *
 *  @param eventID    事件id
 *  @param ResultDesc 结果描述
 *  @param result     返回结果
 */
+ (void)write:(NSString *)eventID
   descriptin:(NSString *)ResultDesc
       result:(BOOL )result;
/**
 *  把日期转换为字符串
 *
 *  @param date 要转换的日期
 *
 *  @return 转换后返回的字符串
 */
- (NSString *)changeDateToString:(NSDate *)date;
/**
 *  删除文件
 */
- (void)deleteFile;


/**
 *  str串是否是空串
 */
+ (BOOL)isEmpty:(NSString *)str;

/**
 * 字典转成字符串
 */
+ (NSString *)dictionaryToJsonString:(NSDictionary *)dic;

@end
