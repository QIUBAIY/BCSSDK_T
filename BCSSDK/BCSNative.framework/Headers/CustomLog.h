//
//  CustomLog.h
//  DataCenter
//
//  Created by dshy1234 on 5/15/15.
//  Copyright (c) 2015 redcdn. All rights reserved.
//
#import "DDLog.h"

#ifndef DataCenter_CustomLog_h
#define DataCenter_CustomLog_h


#endif

#define CustomLogE(frmt, ...) DDLogError(frmt, ##__VA_ARGS__)
#define CustomLogW(frmt, ...) DDLogWarn(frmt, ##__VA_ARGS__)
#define CustomLogI(frmt, ...) DDLogInfo(frmt, ##__VA_ARGS__)
#define CustomLogD(frmt, ...) DDLogDebug(frmt, ##__VA_ARGS__)
#define CustomLogDBegin(frmt, ...) DDLogDebug(frmt, ##__VA_ARGS__)
#define CustomLogDEnd(frmt, ...) DDLogDebug(frmt, ##__VA_ARGS__)
#define CustomLogV(frmt, ...) DDLogVerbose(frmt, ##__VA_ARGS__)
//#define CustomLogE(frmt, ...)
//#define CustomLogW(frmt, ...)
//#define CustomLogI(frmt, ...)
//#define CustomLogD(frmt, ...)
//#define CustomLogDBegin(frmt, ...)
//#define CustomLogDEnd(frmt, ...)
//#define CustomLogV(frmt, ...) 
