//
//  MASGroup+IdentityManagement.h
//  MASIdentityManagement
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

#import <MASFoundation/MASFoundation.h>


@class MASFilteredRequest;


/**
 *  This category enables Identity Management features to the group object
 */
@interface MASGroup (IdentityManagement)


# pragma mark - Group Retrieval

///--------------------------------------
/// @name Group Retrieval
///--------------------------------------


/**
 * Retrieves an array of 'MASGroup'.  Note, this version has no paging or filtering at all.  You will
 * receive not only all of the 'MASGroup' instances, but all their fields as well.
 *
 * @param completion Completion block with either the array of 'MASGroup' or 'NSError'.
 */
+ (void)getAllGroupsWithCompletion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion;


/**
 * Retrieves an array of 'MASGroup' with various sorting, paging and included/excluded attribute options.
 *
 * @param sortByAttribute An attribute of the 'MASGroup' that can be used to sort the results. (optional)
 * @param sortOrder The 'MASFilteringRequestSortOrder' direction of the results.  Valid values are
 *     'MASFilteringRequestSortOrderAscending' and 'MASFilteringRequestSortOrderDescending'.
 * @param pageRange 'NSRange' containing pagination values.
 * @param includedAttributes 'NSArray' of 'NSString' attribute names to include in the results for each object.
 *     Note, if there attribute names included the excluded attributes are ignored. (optional)
 * @param excludedAttributes 'NSArray' of 'NSString' attribute names to exclude from the results for each object.
 *     Note, these will only take effect if there are no 'includedAttributes'. (optional)
 * @param completion Completion block with either the array of 'MASGroup' or 'NSError'.
 */
+ (void)getAllGroupsSortedByAttribute:(NSString *)sortByAttribute
    sortOrder:(MASFilteredRequestSortOrder)sortOrder
    pageRange:(NSRange)pageRange
    includedAttributes:(NSArray *)includedAttributes
    excludedAttributes:(NSArray *)excludedAttributes
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion;


/**
 * Retrieves a 'MASGroup' matching the objectId.
 *
 * @param objectId The object identifier used to locate the group.
 * @param completion Completion block with either the 'MASGroup' or 'NSError'.
 */
+ (void)getGroupByObjectId:(NSString *)objectId
    completion:(void (^)(MASGroup *group, NSError *error))completion;


/**
 * Retrieves a 'MASGroup' object matching the objectId with specific attributes.
 *
 * @param objectId The object id used to locate the 'MASGroup'.
 * @param includedAttributes 'NSArray' of 'NSString' attribute names to include in the results for each object.
 *     Note, if there attribute names included the excluded attributes are ignored. (optional)
 * @param excludedAttributes 'NSArray' of 'NSString' attribute names to exclude from the results for each object.
 *     Note, these will only take effect if there are no 'includedAttributes'. (optional)
 * @param completion Completion block with either the 'MASGroup' or 'NSError'.
 */
+ (void)getGroupByObjectId:(NSString *)objectId
    includedAttributes:(NSArray *)includedAttributes
    excludedAttributes:(NSArray *)excludedAttributes
    completion:(void (^)(MASUser *user, NSError *error))completion;


/**
 * Retrieves a 'MASGroup' matching the groupName.
 *
 * @param groupName The group name used to locate the 'MASGroup'.
 * @param completion Completion block with either the 'MASGroup' or 'NSError'.
 */
+ (void)getGroupByGroupName:(NSString *)groupName
    completion:(void (^)(MASGroup *group, NSError *error))completion;


/**
 * Retrieves a 'MASGroup' by matching group name, this is a full 'equalsTo' comparison.
 *
 * @param objectId The object id used to locate the 'MASGroup'.
 * @param includedAttributes 'NSArray' of 'NSString' attribute names to include in the results for each object.
 *     Note, if there attribute names included the excluded attributes are ignored. (optional)
 * @param excludedAttributes 'NSArray' of 'NSString' attribute names to exclude from the results for each object.
 *     Note, these will only take effect if there are no 'includedAttributes'. (optional)
 * @param completion Completion block with either the the 'MASGroup' or 'NSError'.
 */
+ (void)getGroupByGroupName:(NSString *)groupName
    includedAttributes:(NSArray *)includedAttributes
    excludedAttributes:(NSArray *)excludedAttributes
    completion:(void (^)(MASUser *user, NSError *error))completion;



# pragma mark - Filtered Request Group Retrieval

///---------------------------------------------
/// @name Filtered Request Group Retrieval
///---------------------------------------------


/**
 * Retrieves 'MASGroup' objects that matches the 'MASFilteredRequest'.
 *
 * @param filter The 'MASFilteredRequest; to filter results.
 * @param completion Completion block with either the array of 'MASGroup' objects or the 'NSError'.
 */
+ (void)getGroupsByFilteredRequest:(MASFilteredRequest *)filteredRequest
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion;



# pragma mark - Advanced Filtering Group Retrieval

///----------------------------------------
/// @name Advanced Filtering Group Retrieval
///----------------------------------------


/**
 * Retrieves 'MASGroup' objects that matches the custom built filter expression and additional options.
 *
 * @param filterExpression The custom build 'NSString' filter expression.
 * @param sortByAttribute An attribute of the 'MASUser' that can be used to sort the results. (optional)
 * @param sortOrder The 'MASFilteringRequestSortOrder' direction of the results.  Valid values are
 *     'MASFilteringRequestSortOrderAscending' and 'MASFilteringRequestSortOrderDescending'.
 * @param pageRange 'NSRange' containing pagination values.
 * @param includedAttributes 'NSArray' of 'NSString' attribute names to include in the results for each object.
 *     Note, if there attribute names included the excluded attributes are ignored. (optional)
 * @param excludedAttributes 'NSArray' of 'NSString' attribute names to exclude from the results for each object.
 *     Note, these will only take effect if there are no 'includedAttributes'. (optional)
 * @param completion Completion block with either the array of 'MASGroup' objects or NSError.
 */
+ (void)getGroupsByFilterExpression:(NSString *)filterExpression
    sortByAttribute:(NSString *)sortByAttribute
    sortOrder:(MASFilteredRequestSortOrder)sortOrder
    pageRange:(NSRange)pageRange
    includedAttributes:(NSArray *)includedAttributes
    excludedAttributes:(NSArray *)excludedAttributes
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion;



# pragma mark - Instance Methods

///----------------------------------------
/// @name Instance Methods
///----------------------------------------

/**
 * Saves the group object in the cloud.
 *
 * @param completion Completion block with either the MASGroup object or the Error message.
 */
- (void)saveInBackgroundWithCompletion:(void (^)(MASGroup *group, NSError *error))completion;


/**
 * Deletes the group object from the cloud.
 *
 * @param completion Completion block with either Success boolean or the Error message.
 */
- (void)deleteInBackgroundWithCompletion:(void (^)(BOOL success, NSError *error))completion;


/**
 *  Adds an user to the group.
 *
 *  @param user MASUser object
 *  @param completion Completion block with either the MASGroup object or the Error message
 */
- (void)addMember:(MASUser *)user completion:(void (^)(MASGroup *group, NSError *error))completion;


/**
 * Removes an user from the group
 *
 * @param user MASUser object
 * @param completion Completion block with either the MASGroup object or the Error message
 */
- (void)removeMember:(MASUser *)user completion:(void (^)(MASGroup *group, NSError *error))completion;



# pragma mark - Print Attributes

///--------------------------------------
/// @name Print Attributes
///--------------------------------------


/**
 *  List all attributes from the Object
 */
- (void)listAttributes;



# pragma mark - Deprecated

///--------------------------------------
/// @name Deprecated
///--------------------------------------

/**
 * Retrieves all 'MASGroup' objects from the Range passed as parameter.
 *
 * @param pageRange The Range to be used in the pagination
 * @param completion Completion block with either the NSArray of MASGroup object or the Error message
 */
+ (void)getAllGroups:(NSRange)pageRange
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion
    DEPRECATED_MSG_ATTRIBUTE("getAllGroupsSortedByAttribute: method instead.");


/**
 * Retrieves all 'MASGroup' objects that matches the GroupName passed as parameter. It uses a default 
 * of 10 for the itemsPerPage for the pagination.
 *
 * WARNING: this is not an 'equalTo' match on the groupName, rather it is a 'contains' match.
 *
 * @param groupName The group name to be used in the search.
 * @param pageRange The Range to be used in the pagination.
 * @param completion Completion block with either the arrau of 'MASGroup' or 'NSError'.
 */
+ (void)getGroupsWithName:(NSString *)groupName
    range:(NSRange)pageRange
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion
    DEPRECATED_MSG_ATTRIBUTE("getGroupsByFilteredRequest: method instead.");


/**
 * Retrieves all 'MASGroup' objects that matches the Owner passed as parameter. It uses a default of 10 
 * for the itemsPerPage for the pagination.
 *
 * @param owner The owner to be used in the search.
 * @param pageRange The 'NSRange' to be used in the pagination.
 * @param completion Completion block with either the array of 'MASGroup' or 'NSError'.
 */
+ (void)getGroupsWithOwner:(NSString *)owner
    range:(NSRange)pageRange
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion
    DEPRECATED_MSG_ATTRIBUTE("getGroupsByFilteredRequest: method instead.");


/**
 * Retrieves all 'MASGroup' objects that matches the User member passed as parameter. It uses a default
 * of 10 for the itemsPerPage for the pagination.
 *
 * @param user The 'MASUser' to be used in the search.
 * @param pageRange The 'NSRange' to be used in the pagination.
 * @param completion Completion block with either the array of 'MASGroup' or the 'NSError'.
 */
+ (void)getGroupsWithMember:(MASUser *)user
    range:(NSRange)pageRange
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion
    DEPRECATED_MSG_ATTRIBUTE("getGroupsByFilteredRequest: method instead.");


/**
 * Retrieves all 'MASGroup' objects that matches the SCIM 2.0 formatted filter.
 *
 * @param filter The SCIM 2.0 formatted filter to be used in the search.
 * @param pageRange The 'NSRange' to be used in the pagination.
 * @param completion Completion block with either the array of 'MASGroup' or 'NSError'.
 */
+ (void)getGroupsUsingFilter:(NSString *)filter
    range:(NSRange)pageRange
    completion:(void (^)(NSArray *groupList, NSError *error, NSUInteger totalResults))completion
    DEPRECATED_MSG_ATTRIBUTE("getGroupsByFilteredRequest: method instead.");

@end
