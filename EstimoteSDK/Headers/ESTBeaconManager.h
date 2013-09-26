//
//  ESTBeaconManager.h
//  private-sdk-ios7
//
//  Created by Marcin Klimek on 9/18/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "ESTBeaconRegion.h"
#import "ESTBeacon.h"

@class ESTBeaconManager;

@protocol ESTBeaconManagerDelegate <NSObject>

@optional

/**
 * Method returns NSArray of all discoverd beacons
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as CLBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
      didRangeBeacons:(NSArray *)beacons
             inRegion:(ESTBeaconRegion *)region;

/**
 * Method returns NSArray of all discoverd beacons
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
rangingBeaconsDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;


/**
 * Method returns NSArray of all discoverd beacons
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
monitoringDidFailForRegion:(ESTBeaconRegion *)region
           withError:(NSError *)error;
/**
 * Method triggered when estimote beacon region enter
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
      didEnterRegion:(ESTBeaconRegion *)region;


/**
 * Method triggered when estimote beacon region exit
 *
 * @param manager estimote beacon manager
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
       didExitRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when estimote beacon region exit
 *
 * @param manager estimote beacon manager
 * @param state estimote beacon region state
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManager:(ESTBeaconManager *)manager
     didDetermineState:(CLRegionState)state
             forRegion:(ESTBeaconRegion *)region;

/**
 * Method triggered when estimote beacon region exit
 *
 * @param manager estimote beacon manager
 * @param state estimote beacon region state
 * @param region estimote beacon region
 *
 * @return void
 */
-(void)beaconManagerDidStartAdvertising:(ESTBeaconManager *)peripheral
                                  error:(NSError *)error;

/**
 * Method returns NSArray of all discoverd bluetooth beacons
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as CLBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
          didDiscoverBeacons:(NSArray *)beacons
                    inRegion:(ESTBeaconRegion *)region;

/**
 * Method returns NSArray of all discoverd bluetooth beacons
 *
 * @param manager estimote beacon manager
 * @param beacons all beacons as CLBeacon objects
 * @param region estimote beacon region
 *
 * @return void
 */
- (void)beaconManager:(ESTBeaconManager *)manager
    didFailDiscoveryInRegion:(ESTBeaconRegion *)region;

@end

@interface ESTBeaconManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <ESTBeaconManagerDelegate> delegate;

@property (nonatomic) BOOL avoidUnknownStateBeacons;

/**
 * startRangingBeaconsInRegion:
 *
 * Discovers all Estimote beacons that are visible in range.
 * returned Array contain ESTBeacon objects.
 *
 * @return void
 */
-(void)startRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * startMonitoringForRegion:
 *
 * Starts monitoring Estimote beacons regions.
 *
 * @return void
 */
-(void)startMonitoringForRegion:(ESTBeaconRegion*)region;

/**
 * startMonitoringForRegion:
 *
 * Starts monitoring Estimote beacons regions.
 *
 * @return void
 */
-(void)stopRangingBeaconsInRegion:(ESTBeaconRegion*)region;

/**
 * startMonitoringForRegion:
 *
 * Starts monitoring Estimote beacons regions.
 *
 * @return void
 */
-(void)stopMonitoringForRegion:(ESTBeaconRegion *)region;

/**
 * requestStateForRegion:
 *
 * Request state for Estimote beacons regions.
 *
 * @return void
 */
-(void)requestStateForRegion:(ESTBeaconRegion *)region;

/**
 * requestStateForRegion:
 *
 * Request state for Estimote beacons regions.
 *
 * @return void
 */
-(void)startAdvertisingWithMajor:(ESTBeaconMajorValue)major
                       withMinor:(ESTBeaconMinorValue)minor
                  withIdentifier:(NSString*)identifier;

/**
 * startEstimoteBeaconsDiscoveryForRegion:
 *
 * Start beacon discovery process (bluetooth based)
 *
 * @return void
 */
-(void)startEstimoteBeaconsDiscoveryForRegion:(ESTBeaconRegion*)region;

/**
 * stopEstimoteBeaconDiscovery:
 *
 * Stop beacon discovery process (bluetooth based)
 *
 * @return void
 */
-(void)stopEstimoteBeaconDiscovery;

@end

