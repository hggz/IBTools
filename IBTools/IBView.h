//
//  IBView.h
//  IBTools
//
//  Created by Hugo Gonzalez on 11/11/16.
//  Copyright © 2016 Cat Bakery. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IBTools/IBGlobal.h>

@class IBView;
@protocol IBViewListener <NSObject>
@optional 
- (void)IBViewTouchesBegan:(IBView *)view touches:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)IBViewTouchesMoved:(IBView *)view touches:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
- (void)IBViewTouchesEnded:(IBView *)view touches:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event;
@end

IB_DESIGNABLE
@interface IBView : UIView
@property (nonatomic) BOOL isInterfaceBuilder;
@property (nonatomic, assign) id<IBViewListener> viewListenerDelegate;
@end

@implementation IBView

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    if ((self = [super initWithCoder:aDecoder])) {
        [self sharedInitialization];
    }
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame {
    if ((self = [super initWithFrame:frame])) { 
        [self sharedInitialization];
    }
    return self;
}

- (void)prepareForInterfaceBuilder {
    self.isInterfaceBuilder = YES;
}

// Added swift support since nsstringfromclass returns TargetName.ClassName
- (void)sharedInitialization {
    UIView *view = [[[NSBundle bundleForClass:[self class]] loadNibNamed:[NSStringFromClass([self class]) componentsSeparatedByString:@"."].lastObject owner:self options:nil] firstObject];
    [self addSubview:view];
    view.frame = self.bounds;
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesBegan:touches withEvent:event];
    if ([_viewListenerDelegate respondsToSelector:@selector(IBViewTouchesBegan:touches:withEvent:)]) {
        [_viewListenerDelegate IBViewTouchesBegan:self touches:touches withEvent:event];
    }
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesMoved:touches withEvent:event];
    if ([_viewListenerDelegate respondsToSelector:@selector(IBViewTouchesMoved:touches:withEvent:)]) {
        [_viewListenerDelegate IBViewTouchesMoved:self touches:touches withEvent:event];
    }
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    [super touchesEnded:touches withEvent:event];
    if ([_viewListenerDelegate respondsToSelector:@selector(IBViewTouchesEnded:touches:withEvent:)]) {
        [_viewListenerDelegate IBViewTouchesEnded:self touches:touches withEvent:event];
    }
}

@end
