//
//  CaptionAndThemeInfo.h
//  BCSNative
//
//  Created by Setoge on 2019/12/18.
//  Copyright © 2019 dutingfu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
字幕 字符串字体大小  1：小(36pt) 2：中(40pt) 3：大(48pt)
*/
typedef enum {
    JMCaptionTextFontSmall = 36,
    JMCaptionTextFontMedium = 40,
    JMCaptionTextFontBig = 48,
}JMCaptionTextFont;
/**
主题 字符串字体大小  1：小(32pt) 2：中(40pt) 3：大(50pt)
*/
typedef enum {
    JMThemeTextFontSmall = 32,
    JMThemeTextFontMedium = 40,
    JMThemeTextFontBig = 50,
}JMThemeTextFont;

@interface CaptionAndThemeInfo : NSObject
@property (nonatomic,assign) int infoType;// 1 主题  2 字幕
@property (nonatomic,assign) int state; // 状态 0：关闭 1：显示，关闭状态 以下字段可以没有
@property (nonatomic,copy) NSString * content; // 内容
@property (nonatomic,assign) int size; // 字体大小 1：小(32pt) 2：中(40pt) 3：大(50pt)
@property (nonatomic,copy) NSString * color; // 颜色 #rrggbb 格式
@property (nonatomic,assign) int align; // 对齐方式 0：居左 1：居中 2：居右
@property (nonatomic,assign) double bottomMargin; // 距离画面底部高度（百分比，3表示 3%）
@property (nonatomic,assign) int speed; //  滚动速度 0：不滚动  1：低速 (25像素/s) 2：中速 (50像素/s)  3：高速 (100像素/s) 从右到左
@property (nonatomic,copy) NSString * bgcolor; // 背景色 #rrggbb 格式
@property (nonatomic,copy) NSString *bgopacity; // 不透明度 1 完全不透明 0 完全透明
@end

NS_ASSUME_NONNULL_END
