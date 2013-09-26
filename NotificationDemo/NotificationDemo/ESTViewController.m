//
//  ESTViewController.m
//  NotificationDemo
//
//  Created by Marcin Klimek on 9/26/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import "ESTViewController.h"
#import <ESTBeaconManager.h>

@interface ESTViewController ()

@end

@implementation ESTViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    ESTBeaconManager* man = [[ESTBeaconManager alloc] init];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
