//
//  Util.h
//  dspider
//
//  Created by 杜文 on 16/12/27.
//  Copyright © 2016年 杜文. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//static NSString * _Nonnull BASE_URL=@"http://172.19.23.62/dSpider-web/1.0/";

static NSString * _Nonnull BASE_URL=@"https://api.dtworkroom.com/1.0/";
static NSString * _Nonnull SDK_VERSION=@"1.0";


@interface SpiderUtil : NSObject <NSURLSessionDelegate>

+ (void)post: (NSString * _Nonnull)url
        data:(NSString * _Nullable) data
        handler:(void (^ _Nonnull)(id _Nullable data  ,NSError * _Nullable error))handler;

+ (void)initSpider:(int) sid  :(int) retryConunt  :(void (^ _Nullable)(NSDictionary * _Nullable data  ,NSError * _Nullable error))handler;
+ (void)post: (NSString * _Nonnull)url
          dataMap:(NSDictionary * _Nullable) data
       handler:(void (^ _Nonnull)(id  _Nullable data  ,NSError * _Nullable error))handler;

+ (void) request: (NSString * _Nonnull) url
          method:(NSString * _Nonnull) method
            data:(NSString * _Nullable)param
         handler:(void (^ _Nonnull)(id _Nonnull data ,NSError * _Nullable error) )handler;

@end
