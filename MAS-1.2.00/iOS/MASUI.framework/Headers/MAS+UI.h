//
//  MAS+UI.h
//  MASUI
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

#import <MASFoundation/MASFoundation.h>

/**
 *  This category enables UI features
 */
@interface MAS (UI)


///--------------------------------------
/// @name Authentication Handling
///--------------------------------------

# pragma mark - Authentication Handling

/**
 * Detect if handling of authentication UI is enabled.
 *
 * @return Returns YES if enabled, NO if not.  The default is YES.
 */
+ (BOOL)willHandleAuthentication;


/**
 * Set the handling state of the authentication UI by this framework.
 *
 * @param handle YES if you want the framework to enable it, NO if not.
 *     YES is the default.
 */
+ (void)setWillHandleAuthentication:(BOOL)handle;



/**
 * Detect if handling of OTP authentication UI is enabled.
 *
 * @return Returns YES if enabled, NO if not.  The default is YES.
 */
+ (BOOL)willHandleOTPAuthentication;



/**
 * Set the handling state of the OTP authentication UI by this framework.
 *
 * @param handle YES if you want the framework to enable it, NO if not.
 *     YES is the default.
 */
+ (void)setWillHandleOTPAuthentication:(BOOL)handle;

@end
