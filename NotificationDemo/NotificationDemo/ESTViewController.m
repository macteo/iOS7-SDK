//
//  ESTViewController.m
//  NotificationDemo
//
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTViewController.h"
#import <ESTBeaconManager.h>

@interface ESTViewController () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeaconManager* beaconManager;
@property (nonatomic, strong) UIImageView*      bgImageView;
@property (nonatomic, assign) BOOL              notificationShown;
@property (nonatomic, strong) UIImageView*      productImage;

@end

@implementation ESTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    /////////////////////////////////////////////////////////////
    // setup Estimote beacon manager
    
    // craete manager instance
    self.beaconManager = [[ESTBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    self.beaconManager.avoidUnknownStateBeacons = YES;
    
    // create sample region with major value defined
    ESTBeaconRegion* region = [[ESTBeaconRegion alloc] initRegionWithMajor:222
                                                                identifier:@"EstioteSampleRegion"];
    
    // start looking for estimtoe beacons in region
    // when beacon ranged beaconManager:didEnterRegion:
    // and beaconManager:didExitRegion: invoked
    [self.beaconManager startMonitoringForRegion:region];
    
    
    /////////////////////////////////////////////////////////////
    // setup view
    
    // background
    
    [self setProductImage];
    [self.view addSubview:self.productImage];
}

-(void)beaconManager:(ESTBeaconManager *)manager
      didEnterRegion:(ESTBeaconRegion *)region
{
    // iPhone/iPad entered beacon zone
    [self setDiscountImage];
}

-(void)beaconManager:(ESTBeaconManager *)manager
       didExitRegion:(ESTBeaconRegion *)region
{
    // iPhone/iPad left beacon zone
    [self setProductImage];
}

-(void)setProductImage
{
    // product image when user outside beacon zone
    
    CGRect          screenRect          = [[UIScreen mainScreen] bounds];
    CGFloat         screenHeight        = screenRect.size.height;
    
    if (screenHeight > 480)
    {
        self.productImage = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"beforeNotificationBig"]];
    }
    else
    {
        self.productImage = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"beforeNotificationSmall"]];
    }
}


-(void)setDiscountImage
{
    // product image when user inside beacon zone
    
    CGRect          screenRect          = [[UIScreen mainScreen] bounds];
    CGFloat         screenHeight        = screenRect.size.height;
    
    if (screenHeight > 480)
    {
        self.productImage = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"afterNotificationBig"]];
    }
    else
    {
        self.productImage = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"afterNotificationSmall"]];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
