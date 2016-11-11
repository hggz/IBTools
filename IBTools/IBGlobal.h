//
//  IBUtil.h
//  IBTools
//
//  Created by Hugo Gonzalez on 11/11/16.
//  Copyright © 2016 Cat Bakery. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Device
#define IS_IPAD ([[UIDevice currentDevice] interfaceIdiom] == UIUserInterfaceIdiomPad)

#pragma mark - Screen
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#define SCREEN_WIDTH SCREEN_SIZE.width
#define SCREEN_HEIGHT SCREEN_SIZE.height
#define SCREEN_SCALE (SCREEN_WIDTH / 320.f)
#define SCALED_SCREEN_SIZE(x) (x * SCREEN_SCALE)
