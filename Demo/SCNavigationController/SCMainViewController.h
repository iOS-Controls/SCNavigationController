//
//  SCMainViewController.h
//  SCPageViewController
//
//  Created by Stefan Ceriu on 15/02/2014.
//  Copyright (c) 2014 Stefan Ceriu. All rights reserved.
//

#import "SCEasingFunction.h"

typedef enum {
    SCStackLayouterTypePlain,
    SCStackLayouterTypeSliding,
    SCStackLayouterTypeParallax,
    SCStackLayouterTypeGoogleMaps,
    SCStackLayouterTypeMerryGoRound,
    SCStackLayouterTypeCount
} SCStackLayouterType;

@protocol SCMainViewControllerDelegate;

@interface SCMainViewController : UIViewController

@property (nonatomic, weak, readonly) UILabel *pageNumberLabel;
@property (nonatomic, weak, readonly) UILabel *visiblePercentageLabel;

@property (nonatomic, weak) IBOutlet id<SCMainViewControllerDelegate> delegate;

@property (nonatomic, assign) SCStackLayouterType layouterType;
@property (nonatomic, assign) SCEasingFunctionType easingFunctionType;
@property (nonatomic, assign) NSTimeInterval duration;

@end

@protocol SCMainViewControllerDelegate <NSObject>

@optional

- (void)mainViewControllerDidChangeLayouterType:(SCMainViewController *)mainViewController;

- (void)mainViewControllerDidChangeAnimationType:(SCMainViewController *)mainViewController;

- (void)mainViewControllerDidChangeAnimationDuration:(SCMainViewController *)mainViewController;

- (void)mainViewControllerDidRequestPush:(SCMainViewController *)mainViewController;

- (void)mainViewControllerDidRequestPop:(SCMainViewController *)mainViewController;

- (void)mainViewControllerDidRequestPopToRoot:(SCMainViewController *)mainViewController;

@end