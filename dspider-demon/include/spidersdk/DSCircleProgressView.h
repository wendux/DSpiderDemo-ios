//
//  DSCircleProgressView.h
//  spider
//
//  Created by 杜文 on 17/1/9.
//  Copyright © 2017年 杜文. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DSCircleProgressView : UIView
//中心颜色
@property (strong, nonatomic)UIColor *centerColor;
//圆环背景色
@property (strong, nonatomic)UIColor *arcBackColor;
//圆环色
@property (strong, nonatomic)UIColor *arcFinishColor;
@property (strong, nonatomic)UIColor *arcUnfinishColor;
//文字颜色
@property (strong, nonatomic)UIColor *textColor;
//百分比数值（0-1）
@property (assign, nonatomic)float percent;
//圆环宽度
@property (assign, nonatomic)float width;

@end
