//
//  MASMessage.h
//  MASConnecta
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

@import Foundation;

#import <MASFoundation/MASFoundation.h>


#import "MASConnectaConstants.h"


/**
 * MASMessage.
 */
@interface MASMessage : NSObject
    <NSCoding>



///--------------------------------------
/// @name Properties
///--------------------------------------

# pragma mark - Properties

/**
 * The version of the message format.
 */
@property (nonatomic, copy, readonly) NSString *version;


/**
 *  The topic of the message
 */
@property (nonatomic, copy, readonly) NSString *topic;


/**
 * The object identifier of the message receiver.
 */
@property (nonatomic, copy, readonly) NSString *receiverObjectId;


/**
 * The MASSenderType representing the sender.
 */
@property (nonatomic, assign, readonly) MASSenderType senderType;


/**
 * The object identifier of the message sender.
 */
@property (nonatomic, copy, readonly) NSString *senderObjectId;


/**
 *  The DisplayName (field in the /UserInfo mapping in the Gateway) of the message sender.
 */
@property (nonatomic, copy, readonly) NSString *senderDisplayName;


/**
 * The timestamp when the message was sent in UTC format.
 */
@property (nonatomic, copy, readonly) NSDate *sentTime;


/**
 * The payload in NSData format.
 */
@property (nonatomic, copy, readonly) NSData *payload;


/**
 * The content type of the payload.
 */
@property (nonatomic, copy, readonly) NSString *contentType;


/**
 *  The content encoding of the payload.
 */
@property (nonatomic, copy, readonly) NSString *contentEncoding;


///--------------------------------------
/// @name Lifecycle
///--------------------------------------

# pragma mark - Lifecycle

- (instancetype)initWithPayloadData:(NSData *)payload
                           contentType:(NSString *)contentType;

- (instancetype)initWithPayloadString:(NSString *)payload
                             contentType:(NSString *)contentType;

- (instancetype)initWithPayloadImage:(UIImage *)payload
                            contentType:(NSString *)contentType;

///--------------------------------------
/// @name Public
///--------------------------------------

# pragma mark - Public

/**
 * The payload property in NSString format.
 *
 * @return NSString.
 */
- (NSString *)payloadTypeAsString;



/**
 *  The senderType property in UIImage format.
 *
 *  @return UIImage
 */
- (UIImage *)payloadTypeAsImage;



/**
 * The senderType property in NSString format.
 *
 * @return NSString.
 */
- (NSString *)senderTypeAsString;



/**
 * The MASSenderType in NSString format.
 *
 * @param type MASSenderType.
 * @return NSString.
 */
+ (NSString *)stringFromSenderType:(MASSenderType)type;

@end
