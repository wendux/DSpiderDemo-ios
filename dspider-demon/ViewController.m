//
//  ViewController.m
//  dspider-demon
//
//  Created by 杜文 on 17/3/21.
//  Copyright © 2017年 wendu. All rights reserved.
//

#import "ViewController.h"
#include "include/spidersdk/dSpider.h"

#define UIColorFromRGB(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue &0xFF00) >>8))/255.0 blue:((float)(rgbValue &0xFF))/255.0 alpha:a]

@interface ViewController ()
@property(weak) DSpiderDataView * spiderView;
@end


@implementation ViewController
@synthesize spiderView;
- (void)viewDidLoad {
    [super viewDidLoad];
    //初始化sdk, appid=1, appid在个人创建app后制动分配
    [dSpider init:1];
    
    CGRect bounds=self.view.bounds;
    int width=bounds.size.width/3;
    int margin=width/3;
    UIButton *btnVisible=[[UIButton alloc] initWithFrame:CGRectMake(margin, 40,width, 45)];
    UIButton *btnSilent=[[UIButton alloc] initWithFrame:CGRectMake(2*margin+width ,40,width, 45)];
    [self.view addSubview: btnVisible];
    [self.view addSubview:btnSilent];
    //添加爬取控件
    DSpiderDataView *_spiderView=[[DSpiderDataView alloc] initWithFrame:bounds];
    spiderView=_spiderView;
    //静默爬取不显示
    [spiderView setHidden:YES];
    [self.view addSubview:spiderView];
    
    btnVisible.backgroundColor=btnSilent.backgroundColor=UIColorFromRGB(0x196296, 0.8f);
    [btnVisible setTitle:@"显式爬取" forState:normal];
    [btnSilent setTitle:@"静默爬取" forState:normal];
    [btnVisible addTarget:self action:@selector(onClick:) forControlEvents:UIControlEventTouchUpInside];
    [btnSilent addTarget:self action:@selector(onClick:) forControlEvents:UIControlEventTouchUpInside];
    
   
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) onClick:(UIButton *) btn{
    if([[btn titleForState:normal] isEqualToString:@"静默爬取"]){
        [self showMessage:@"正在爬取，请稍等！" :@"提示"];
        spiderView.delegate=self;
        
        //执行1号spider(sid=1)
        //1号spider详情：https://dspider.dtworkroom.com/spider/1
        [spiderView start:1];
   
    }else{
        DSpiderViewController *controller=[[DSpiderViewController alloc]init];
        controller.resultDelegate=self;
        [self presentViewController:controller animated:YES completion:nil];
        //执行1号spider(sid=1)
        [controller start:1 title:@"测试"];
        
    }
}

//下面两个是显式爬取的回调
//成功回调
-(void)onSucceed:(NSString *)sessionKey data:(NSMutableArray *)data{
    [self showMessage:[NSString stringWithFormat:@"%@" ,data] :@"显式爬取成功了"];
}
//失败回调
-(void)onFail:(int)code :(NSString *)msg{
     [self showMessage:msg :@"显示爬取失败了"];
}

//下面是静默爬取的回调
-(void)onError:(int)code :(NSString *)msg{
    if([spiderView canRetry]){
       [spiderView retry];
    }
}
-(void)onResult:(NSString *)sessionKey data:(NSMutableArray *)data{
  [self showMessage:[NSString stringWithFormat:@"%@" ,data] :@"静默爬取成功了"];

}
-(void)onProgressShow:(bool)isShow{
  
}



-(void)showMessage:(NSString *)msg :(NSString *)title{
    UIAlertView *alertView = [[UIAlertView alloc]  initWithTitle:title message:msg
                                                        delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil, nil];
    [alertView show];
}


@end
