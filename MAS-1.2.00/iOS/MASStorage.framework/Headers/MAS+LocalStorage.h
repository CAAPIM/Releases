//
//  MAS+LocalStorage.h
//  MASStorage
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

#import <MASFoundation/MASFoundation.h>


/**
 *  This category enables Local Storage feature
 */
@interface MAS (LocalStorage)


/**
 * Singleton instance of the MASLocalStorage. It creates the local storage database in
 * case it doesn't exist.
 *
 * @return MASLocalStorage singleton.
 */
+ (void)enableLocalStorage;

@end
