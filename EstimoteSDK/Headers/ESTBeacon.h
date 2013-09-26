//
//  ESTBeacon.h
//  EstimotePrivSDK7
//
//  Created by Marcin Klimek on 9/19/13.
//  Copyright (c) 2013 Estimote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "ESTBeaconDefinitions.h"

////////////////////////////////////////////////////////////////////
// Estimote beacon delegate protocol


@protocol ESTBeaconDelegate <NSObject>

@optional
- (void)beaconConnectionDidFail:(NSError*)error;
- (void)beaconConnectionDidSucceeded;
- (void)beaconDidDisconnect;

@end


////////////////////////////////////////////////////////////////////
// Interface definition


@interface ESTBeacon : NSObject

@property (nonatomic)           ESTBeaconFirmwareState  firmwareState;

/////////////////////////////////////////////////////
// bluetooth properties available when used with
// startEstimoteBeaconsDiscoveryForRegion:

@property (nonatomic, strong)   CBPeripheral*           peripheral;
@property (nonatomic, strong)   NSString*               macAddress;
@property (nonatomic, strong)   NSNumber*               measuredPower;
@property (nonatomic, strong)   NSNumber*               major;
@property (nonatomic, strong)   NSNumber*               minor;
@property (nonatomic, strong)   NSNumber*               rssi;

/////////////////////////////////////////////////////
// core location properties

@property (nonatomic, strong)   CLBeacon*               ibeacon;


/**
 * Connect device to particular beacon
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
-(void)connectToBeaconWithCompletition:(ESTCompletitionBlock)completition;

/**
 * Disconnect device with particular beacon
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
-(void)disconnectBeaconWithCompletition:(ESTCompletitionBlock)completition;

/**
 * Read major of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return Point Major and Minor points
 */
- (void)readBeaconMajorWithCompletition:(ESTUnsignedCompletitionBlock)completition;

/**
 * Read minor of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return Point Major and Minor points
 */
- (void)readBeaconMinorWithCompletition:(ESTUnsignedCompletitionBlock)completition;

/**
 * Read frequency and minor of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)readBeaconFrequencyWithCompletition:(ESTUnsignedCompletitionBlock)completition;


/**
 * Read power of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return float value of beacon power
 */
- (void)readBeaconPowerWithCompletition:(ESTUnsignedCompletitionBlock)completition;

/**
 * Read battery level of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)readBeaconBatteryWithCompletition:(ESTUnsignedCompletitionBlock)completition;

/**
 * Read firmware version of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)readBeaconFirmwareVersionWithCompletition:(ESTStringCompletitionBlock)completition;

/**
 * Read hardware version of connected beacon
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)readBeaconHardwareVersionWithCompletition:(ESTStringCompletitionBlock)completition;


/**
 * Write major param of connected beacon.
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)writeBeaconMajor:(short)major withCompletition:(ESTUnsignedCompletitionBlock)completition;

/**
 * Write minor param of connected beacon.
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)writeBeaconMinor:(short)minor withCompletition:(ESTUnsignedCompletitionBlock)completition;

/**
 * Write frequency of connected beacon.
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)writeBeaconFrequency:(short)frequency withCompletition:(ESTUnsignedCompletitionBlock)completition;


/**
 * Write power of connected beacon.
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
- (void)writeBeaconPower:(ESTBeaconPower)power withCompletition:(ESTUnsignedCompletitionBlock)completition;


/**
 * Check if firmware update is available for this beacon.
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
-(void)checkFirmwareUpdateWithCompletition:(ESTBoolCompletitionBlock)completition;

/**
 * Update firmware of connected beacon.
 *
 * @param completition Block handling operation completition
 *
 * @return void
 */
-(void)updateBeaconFirmwareWithCompletition:(ESTCompletitionBlock)completition;

@end
