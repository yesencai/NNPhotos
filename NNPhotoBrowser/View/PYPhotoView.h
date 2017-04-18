//  代码地址: https://github.com/iphone5solo/PYPhotosView
//  代码地址: http://code4app.com/thread-8612-1-1.html
//  Created by CoderKo1o.
//  Copyright © 2016年 iphone5solo. All rights reserved.
//  用于呈现一个图片/视频的视图（支持多种手势）

#import <UIKit/UIKit.h>
#import "UIView+PYExtension.h"
@class PYPhoto, PYPhotoCell, PYPhotosView, PYProgressView, PYPhotoView;

@protocol PYPhotoViewDelegate <NSObject>

@optional
- (void)didSingleClick:(PYPhotoView *)photoView; // 单击
- (void)didLongPress:(PYPhotoView *)photoView;   // 长按
/**
 点击图片中的删除按钮回调
 
 @param images 当前存在的图片（未发布）数组
 @param index 当前图片索引
 */
- (void)photoView:(PYPhotoView *)photoView didDeleteImageWithImages:(NSMutableArray *)images index:(NSInteger)index;

@end

@interface PYPhotoView : UIImageView

@property (nonatomic, weak) id<PYPhotoViewDelegate> delegate;

/** 图片模型 */
@property (nonatomic, strong) PYPhoto *photo;
/** 网络图片*/
@property (nonatomic, copy) NSArray<PYPhoto *> *photos;
/** 本地相册图片 */
@property (nonatomic, strong) NSMutableArray<UIImage *> *images;

/** 是否放大状态 */
@property (nonatomic, assign) BOOL isBig;
/** 是否正在预览*/
@property (nonatomic, assign) BOOL isPreview;
/** 原来的frame*/
@property (nonatomic, assign) CGRect orignalFrame;
/** 放大的倍数 */
@property (nonatomic, assign) CGFloat scale;
/** 判断是否是旋转手势 */
@property (nonatomic, assign, getter=isRotationGesture) BOOL rotationGesture;

/** 在window呈现的view*/
@property (nonatomic, strong) PYPhotoView *windowView;
/** 父控件photosView */
@property (nonatomic, weak) PYPhotosView *photosView;
/** 每个photoView的photoCell */
@property (nonatomic, weak) PYPhotoCell *photoCell;
/** 加载进度view */
@property (weak, nonatomic) PYProgressView *progressView;
/** 加载失败显示图片 */
@property (nonatomic, weak) UIImageView *loadFailureView;

- (void)imageDidPinch:(UIPinchGestureRecognizer *)pinch;
- (void)photoDidRotation:(UIRotationGestureRecognizer *)rotation;

@end
