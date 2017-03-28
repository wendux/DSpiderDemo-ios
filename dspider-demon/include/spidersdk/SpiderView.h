//
//  SpiderView.h
//  spider
//
//  Created by 杜文 on 17/1/9.
//  Copyright © 2017年 杜文. All rights reserved.
//

#import "DWebview.h"



@interface SpiderView : DWebview<WKNavigationDelegate>{
    @private
    NSString * url;
}
@property (nullable, nonatomic, weak) id<JSBWebEventDelegateProtocol> WebEventDelegate;
@property (nullable,copy, nonatomic) NSString * ExceptUrl;
@property (nullable,copy, nonatomic) NSString * Arguments;
- (void)setUserAgent:(NSString * _Nullable )ua;
@end

