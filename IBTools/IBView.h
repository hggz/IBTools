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
