//
//  DSWaveView.h
//  spider
//
//  Created by 杜文 on 17/1/10.
//  Copyright © 2017年 杜文. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DSWaveView : UIView
@property (nonatomic, strong) UIColor *firstWaveColor;

-(void)setOffset:(CGFloat) offset;
-(void)start;
@end
