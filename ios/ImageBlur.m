// ImageBlur.m

#import "ImageBlur.h"
#import "UIImage+Blur.h"

@implementation ImageBlur

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(blur:(NSString *)fromPath
                  toFile:(NSString *)toFile
                  radius:(int)radius
                  resolve:(RCTPromiseResolveBlock)resolve
                  rejecter:(RCTPromiseRejectBlock)reject) {
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES);
    NSString *cachePath = [paths firstObject];
    NSString *dirPath = [cachePath stringByAppendingString:@"/"];
    NSString *savePath = [dirPath stringByAppendingString:toFile];
    BOOL fileExists = [[NSFileManager defaultManager] fileExistsAtPath:savePath];
    if (fileExists) {
        resolve(savePath);
        return;
    }
    UIImage *image = [UIImage imageWithContentsOfFile:fromPath];
    UIImage *blurImage = [image blurredImageWithRadius:radius];
    [UIImagePNGRepresentation(blurImage) writeToFile:savePath atomically:YES];
    resolve(savePath);
}
@end
