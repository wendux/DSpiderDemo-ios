//
//  DSpiderViewController.h
//  spider
//
//  Created by 杜文 on 17/1/9.
//  Copyright © 2017年 杜文. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DSCircleProgressView.h"
#import "DSpiderDataView.h"
#import "spidersdk.h"

@interface DSpiderViewController : UIViewController<DSpiderDelegate>
-(void)setArguments:(NSDictionary *) args;
-(void)start:(int) sid title:(NSString *)title;
-(void)startDebug:(NSString *)title debugScript:(NSString *)debugScript debugUrl:(NSString *)debugUrl;
@property(nonatomic,weak) id<DSpiderResult> resultDelegate;
@property(nonatomic,weak,setter=setPersistenceDelegate:) id<Persistence> persistenceDelegate;
@end
