//
//  JavaScriptBridge.h
//  dspider
//
//  Created by 杜文 on 16/12/28.
//  Copyright © 2016年 杜文. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SpiderView.h"

//JavaScript bridge implementation delegate
@protocol JavascriptBridgeDelegate<NSObject>
@required
- (void) setProgress:(int) progress;
- (void) setProgressMax:(int)max;
- (void) finish:(NSString *)sessionKey :(NSMutableArray<NSString *>*)result :(int) code :(NSString *)errmsg;
- (void) setProgressMsg:(NSString *)msg;
- (bool) isStart;
@optional
- (void) log:(NSString *)msg :(int) type;
- (void) showProgress:(bool) show;
-(void) save:(NSString*)key :(NSString *) value;
-(NSString *)read: (NSString*)key;

@end

@interface JavaScriptBridge : NSObject
-(instancetype)init:(id<JavascriptBridgeDelegate>)delegate;
@property (weak) SpiderView * webview;
@end
