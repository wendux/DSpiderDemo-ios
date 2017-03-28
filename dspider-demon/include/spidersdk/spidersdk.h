
#import <Foundation/Foundation.h>

//Result code
typedef enum DSPIDER_STATE{
    DSPIDER_SUCCEED,
    DSPIDER_WEB_ERROR,
    DSPIDER_SCRIPT_ERROR,
    DSPIDER_PAGE_CHANGED,
    DSPIDER_TIMEOUT,
    DSPIDER_SERVICE_ERROR,
    DSPIDER_ERROR_MSG
}DSPIDER_STATE;



//For DSpiderViewController delegate
@protocol DSpiderResult<NSObject>
@optional
- (void) onSucceed:(NSString *) sessionKey data:(NSMutableArray * ) data;
- (void) onFail:(int)code :(NSString *)msg;
- (BOOL) onRetry:(int)code :(NSString *)msg;
@end

//For DSpiderDataView delegate
@protocol DSpiderDelegate<NSObject>
@optional
- (void) onResult:(NSString *) sessionKey data:(NSMutableArray * ) data;
- (void) onProgress:(int)progress :(int)max;
- (void) onProgressMsg:(NSString *)msg;
- (void) onError:(int)code :(NSString *)msg;
- (void) onProgressShow:(bool) isShow;
- (void) onScriptLoaded:(int) tryTimes;
- (void) onLog:(NSString *)msg :(int) type;
@end

//For data persistence
@protocol Persistence<NSObject>
@optional
-(void) save:(NSString*)key :(NSString *) value;
-(NSString *)read: (NSString*)key;
@end

