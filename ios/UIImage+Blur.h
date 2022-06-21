//
//  UIImage+Blur.h
//  IOS-Categories (https://github.com/shaojiankui/iOS-Categories)
//
//  Created by Jakey on 15/6/5.
//  Copyright (c) 2015年 www.skyfox.org. All rights reserved.
//

#import <UIKit/UIKit.h>
FOUNDATION_EXPORT double ImageEffectsVersionNumber;
FOUNDATION_EXPORT const unsigned char ImageEffectsVersionString[];
@interface UIImage (Blur)

/*!
 *  @author DT, 15-09-02 19:09:19
 *
 *  @brief  图片高斯模糊
 *
 *  @return UIImage
 */
- (UIImage *)lightImage;

/*!
 *  @author DT, 15-09-02 19:09:35
 *
 *  @brief  图片高亮高斯模糊
 *
 *  @return UIImage
 */
- (UIImage *)extraLightImage;

/*!
 *  @author DT, 15-09-02 19:09:09
 *
 *  @brief  图片暗色高斯模糊
 *
 *  @return UIImage
 */
- (UIImage *)darkImage;

/*!
 *  @author DT, 15-09-02 19:09:28
 *
 *  @brief  图片高斯模糊
 *
 *  @param tintColor 高斯模糊颜色
 *
 *  @return UIImage
 */
- (UIImage *)tintedImageWithColor:(UIColor *)tintColor;

/*!
 *  @author DT, 15-09-02 19:09:57
 *
 *  @brief  图片模糊
 *
 *  @param blurRadius 模糊范围
 *
 *  @return UIImage
 */
- (UIImage *)blurredImageWithRadius:(CGFloat)blurRadius;

/*!
 *  @author DT, 15-09-02 19:09:12
 *
 *  @brief  图片模糊
 *
 *  @param blurSize 模糊位置
 *
 *  @return UIImage
 */
- (UIImage *)blurredImageWithSize:(CGSize)blurSize;

/*!
 *  @author DT, 15-09-02 19:09:24
 *
 *  @brief  图片模糊
 *
 *  @param blurSize              模糊位置
 *  @param tintColor             模糊颜色
 *  @param saturationDeltaFactor <#saturationDeltaFactor description#>
 *  @param maskImage             <#maskImage description#>
 *
 *  @return return value description
 */
- (UIImage *)blurredImageWithSize:(CGSize)blurSize
                        tintColor:(UIColor *)tintColor
            saturationDeltaFactor:(CGFloat)saturationDeltaFactor
                        maskImage:(UIImage *)maskImage;


- (UIImage *)blurredImageWithRadius:(CGFloat)radius iterations:(NSUInteger)iterations tintColor:(UIColor *)tintColor;
@end
