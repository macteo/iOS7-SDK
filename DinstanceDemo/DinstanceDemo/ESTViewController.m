//
//  ESTViewController.m
//  DinstanceDemo
//
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTViewController.h"
#import <ESTBeaconManager.h>

#define DOT_MIN_POS 150
#define DOT_MAX_POS screenHeight - 70;

@interface ESTViewController () <ESTBeaconManagerDelegate>

@property (nonatomic, strong) ESTBeaconManager* beaconManager;
@property (nonatomic, strong) UIImageView*      positionDot;

@property (nonatomic) float dotMinPos;
@property (nonatomic) float dotRange;

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
    
    // create sample region object (you can additionaly pass major / minor values)
    ESTBeaconRegion* region = [[ESTBeaconRegion alloc] initRegionWithIdentifier:@"EstioteSampleRegion"];
    
    // start looking for estimtoe beacons in region
    // when beacon ranged beaconManager:didRangeBeacons:inRegion: invoked
    [self.beaconManager startRangingBeaconsInRegion:region];
    
    
    
    /////////////////////////////////////////////////////////////
    // setup view
    
    // background
    
    CGRect          screenRect          = [[UIScreen mainScreen] bounds];
    CGFloat         screenHeight        = screenRect.size.height;
    UIImageView*    backgroundImage;
    
    if (screenHeight > 480)
    {
        backgroundImage = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"backgroundBig"]];
    }
    else
    {
        backgroundImage = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"backgroundSmall"]];
    }
    
    [self.view addSubview:backgroundImage];
    
    // position dot
    
    self.positionDot = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"dotImage"]];
    [self.positionDot setCenter:self.view.center];
    [self.positionDot setAlpha:1.];
    
    [self.view addSubview:self.positionDot];
    
    self.dotMinPos = 150;
    self.dotRange = self.view.bounds.size.height  - 220;
}


-(void)beaconManager:(ESTBeaconManager *)manager
     didRangeBeacons:(NSArray *)beacons
            inRegion:(ESTBeaconRegion *)region
{
    ESTBeacon* closestBeacon;

    if([beacons count] > 0)
    {
        // beacon array is sorted based on distance
        // closest beacon is the first one
        closestBeacon = [beacons objectAtIndex:0];
        
        // calculate and set new y position
        float newYPos = self.dotMinPos + (closestBeacon.ibeacon.rssi / -100) * self.dotRange;
        self.positionDot.center = CGPointMake(self.view.bounds.size.width / 2, newYPos);
    }
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}







@end
