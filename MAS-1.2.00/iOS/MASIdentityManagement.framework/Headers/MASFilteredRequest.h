//
//  MASFilteredRequest.h
//  MASIdentityManagement
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

#import <Foundation/Foundation.h>


@class MASFilter;


@interface MASFilteredRequest : NSObject


# pragma mark - Properties

///--------------------------------------
/// @name Properties
///--------------------------------------


@property (nonatomic, strong) MASFilter *filter;
@property (nonatomic, strong) NSString *sortByAttribute;
@property (nonatomic, assign) MASFilteredRequestSortOrder sortOrder;
@property (nonatomic, assign) NSRange paginationRange;
@property (nonatomic, copy) NSArray *includedAttributes;
@property (nonatomic, copy) NSArray *excludedAttributes;


# pragma mark - Filtered Requests

///--------------------------------------
/// @name Filtered Requests
///--------------------------------------


/**
 * Create a default 'MASFilteredRequest'.  The optional request options
 * can then be added individually.  The supported options are:
 *
 *  filter
 *  sortByAttribute
 *  sortOrder
 *  paginationRange
 *  includedAttributes*
 *  excludedAttributes*
 *
 *  * These are mutually exclusive, 'includedAttributes' take precedence.
 *    If the 'includedAttributes' are set, any 'excludedAttributes' are ignored.
 *
 * @return 'MASFilteredRequest'.
 */
+ (MASFilteredRequest *)filteredRequest;



# pragma mark - Advanced Filtered Requests

///--------------------------------------
/// @name Advanced Filtered Requests
///--------------------------------------


/**
 * Retrieve the 'MASFilteredRequest' as a 'NSString' URL query path fragment.
 *
 * For example, if all request query parameters were in use it would look like something like this:
 * 
 *   '?filter=<value>&sortBy=<attribute>&sortOrder=ascending&startIndex=0&count=10&attributes=attribute1,attribute2,...'
 *
 * @return 'NSString' request as a 'NSString' URL query path fragment.
 */
- (NSString *)asStringQueryPath;


/**
 * Create a 'MASFilteredRequest' from a complete SCIM 2.0 expression as an 'NSString'.
 *
 * This is for advanced users that may want to completely write their own complete 
 * filtered request for some reason. Likely where the other API provided don't cover a 
 * use case.
 *
 * For example, if all request query parameters were in use it would look like something like this:
 * 
 *   '?filter=<value>&sortBy=<attribute>&sortOrder=ascending&startIndex=0&count=10&attributes=attribute1,attribute2,...'
 *
 * @param queryPath 'NSString' URL query path fragment.
 * @return 'MASFilteredRequest'.
 */
+ (MASFilteredRequest *)fromStringQueryPath:(NSString *)queryPath;

@end
