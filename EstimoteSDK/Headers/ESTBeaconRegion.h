//
//  ESTBeaconRegion.h
//  EstimotePrivSDK7
//
//  Created by Marcin Klimek on 9/21/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/*
 *  CLBeaconMajorValue
 *
 *  Discussion:
 *    Type represents the most significant value in a beacon.
 *
 */
typedef uint16_t ESTBeaconMajorValue;

/*
 *  CLBeaconMinorValue
 *
 *  Discussion:
 *    Type represents the least significant value in a beacon.
 *
 */
typedef uint16_t ESTBeaconMinorValue;


@interface ESTBeaconRegion : CLBeaconRegion

/**
 *  initWithIdentifier:
 *
 *    Initialize a Estimote beacon region. Major and minor values will be wildcarded.
 *
 **/
- (id)initRegionWithIdentifier:(NSString *)identifier;

/**
 *  initWithProximityUUID:major:identifier:
 *
 *    Initialize a Estimote beacon region with major value. Minor value will be wildcarded.
 *
 **/
- (id)initRegionWithMajor:(ESTBeaconMajorValue)major identifier:(NSString *)identifier;

/**
 *  initWithMajor:minor:identifier:
 *
 *    Initialize a Estimote beacon region identified by a major and minor values.
 *
 **/
- (id)initRegionWithMajor:(ESTBeaconMajorValue)major minor:(ESTBeaconMinorValue)minor identifier:(NSString *)identifier;

@end
