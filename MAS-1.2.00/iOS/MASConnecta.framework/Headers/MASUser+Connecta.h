//
//  MASUser+Connecta.h
//  MASConnecta
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

@import Foundation;
@class  MASMessage;

/**
 *  This category enables messaging feature to the authenticated user
 */
@interface MASUser (Connecta)


///--------------------------------------
/// @name Properties
///--------------------------------------

#pragma mark - Properties

/**
 *  Message Queue array
 */
@property (nonatomic, strong, nullable) NSMutableArray *messageQueue;



///--------------------------------------
/// @name Methods
///--------------------------------------

#pragma mark - Send methods

/**
 *  This method sends a message from the current logged user to a existing User
 *
 *  @param message    The Message to be sent. Only NSString or MASMessage objects are supported
 *  @param user       MASUser object
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)sendMessage:(nonnull NSObject *)message
             toUser:(nonnull MASUser *)user
         completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method sends a message from the current logged user to a existing User on a specified topic.
 *  Message object must be either NSString or NSData.
 *
 *  @param message    The Message to be sent. Only NSString or MASMessage objects are supported
 *  @param user       The MASUser object recipient
 *  @param topic      The Custom Topic where the message will be sent. Set to Nil to sent to the UserId topic
 *  @param completion The Completion block with either Success or the Error object
 */
- (void)sendMessage:(nonnull NSObject *)message
             toUser:(nonnull MASUser *)user
            onTopic:(nullable NSString *)topic
         completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method sends a message from the current logged user to a existing Group
 *
 *  @param message    The Message to be sent. Only NSString or MASMessage objects are supported
 *  @param group      The MASGroup object recipient
 *  @param completion The Completion block with either the Success or the Error message
 */
- (void)sendMessage:(nonnull NSObject *)message
            toGroup:(nonnull MASGroup *)group
         completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method sends a message from the current logged user to a existing Device
 *
 *  @param message    The Message to be sent. Only NSString or MASMessage objects are supported
 *  @param device     The MASDevice object
 *  @param completion The Completion block with either the Success or the Error message
 */
- (void)sendMessage:(nonnull NSObject *)message
           toDevice:(nonnull MASDevice *)device
         completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;


#pragma mark - Listen methods (start)

/**
 *  This method Subscribe the current logged user to a specific GroupId
 *
 *  @param group      The group to subscribe to
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)startListeningToMesasgesFromGroup:(nonnull MASGroup *)group
                               completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method Subscribe the current logged user to a specific Device
 *
 *  @param device     The Device to subscribe to
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)startListeningToMessagesFromDevice:(nonnull MASDevice *)device
                               completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method enables Income Message to the current authenticated user
 *
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)startListeningToMyMessages:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



#pragma mark - Listen methods (stop)

/**
 *  This method Unsubscribe the user from a specific Group
 *
 *  @param group      The group to unsubscribe to
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)stopListeningToMessagesFromGroup:(nonnull MASGroup *)group
                              completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method Unsubscribe the user from a specific Device
 *
 *  @param device     The device to unsubscribe to
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)stopListeningToMessagesFromDevice:(nonnull MASDevice *)device
                              completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;



/**
 *  This method disables Income Message to the current authenticated user
 *
 *  @param completion Completion block with either the Success or the Error message
 */
- (void)stopListeningToMyMessages:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;


@end
