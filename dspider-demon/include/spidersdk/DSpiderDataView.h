//
//  DSpiderDataView.h
//  dspider
//
//  Created by 杜文 on 16/12/28.
//  Copyright © 2016年 杜文. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "spidersdk.h"
#import "JavaScriptBridge.h"
#import "dsbridge.h"
#import "SpiderUtil.h"
#import "SpiderView.h"

@interface DSpiderDataView : UIView <JavascriptBridgeDelegate, JSBWebEventDelegateProtocol>
@property(nonatomic,weak) id<DSpiderDelegate> delegate;
@property(nonatomic,weak) id<Persistence> persistenceDelegate;
-(void)setArguments:(NSDictionary *) args;
-(void)start:(int) sid;
-(void)startDebug: (NSString *)debugScript debugUrl:(NSString *)debugUrl;
-(bool)canRetry;
-(void)retry;
-(void)stop;
@end
