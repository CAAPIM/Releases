//
//  MASIdentityManagementConstants.h
//  MASIdentityManagement
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

#import <Foundation/Foundation.h>


# pragma mark - Common Constants

///--------------------------------------
/// @name Common Constants
///--------------------------------------


static NSString *const MASIdMgmtAmpersand = @"&";
static NSString *const MASIdMgmtComma = @",";
static NSString *const MASIdMgmtDisplay = @"display";
static NSString *const MASIdMgmtEmptySpace = @" ";
static NSString *const MASIdMgmtFilter = @"filter";
static NSString *const MASIdMgmtFilterPrefix = @"filter=";
static NSString *const MASIdMgmtNoSpace = @"";
static NSString *const MASIdMgmtResources = @"Resources";
static NSString *const MASIdMgmtQuestionMark = @"?";
static NSString *const MASIdMgmtValue = @"value";
static NSString *const MASIdMgmtAttributes = @"attributes";

// Pagination
static NSString *const MASIdMgmtStartIndex = @"startIndex";
static NSString *const MASIdMgmtCount = @"count";
static NSString *const MASIdMgmtTotalResults = @"totalResults";


# pragma mark - Attribute Operator Constants

///--------------------------------------
/// @name Attribute Operator Constants
///--------------------------------------


/**
 * SCIM 2.0 'NSString' values matching the MASFilterAttributeOperator enumerated types.
 */
static NSString *const MASIdMgmtAttributeOperatorContains = @"co";
static NSString *const MASIdMgmtAttributeOperatorPresent = @"pr";

static NSString *const MASIdMgmtAttributeOperatorEndsWith = @"ew";
static NSString *const MASIdMgmtAttributeOperatorStartsWith = @"sw";

static NSString *const MASIdMgmtAttributeOperatorEqualTo = @"eq";
static NSString *const MASIdMgmtAttributeOperatorNotEqualTo = @"ne";

static NSString *const MASIdMgmtAttributeOperatorGreaterThan = @"gt";
static NSString *const MASIdMgmtAttributeOperatorGreaterThanOrEqualTo = @"ge";
static NSString *const MASIdMgmtAttributeOperatorLessThan = @"lt";
static NSString *const MASIdMgmtAttributeOperatorLessThanOrEqualTo = @"le";


/**
 * MASFilterAttributeOperator enumeration types that map to the SCIM 2.0 attribute 
 * operator types.
 */
typedef NS_ENUM(NSInteger, MASFilterAttributeOperator)
{
    /** SCIM 2.0 attribute operator type 'co' */
    MASFilterAttributeOperatorContains,
    
    /** SCIM 2.0 attribute operator type 'pr' */
    MASFilterAttributeOperatorPresent,
    
    /** SCIM 2.0 attribute operator type 'ew' */
    MASFilterAttributeOperatorEndsWith,
    
    /** SCIM 2.0 attribute operator type 'sw' */
    MASFilterAttributeOperatorStartsWith,
    
    /** SCIM 2.0 attribute operator type 'eq' */
    MASFilterAttributeOperatorEqualTo,
    
    /** SCIM 2.0 attribute operator type 'ne' */
    MASFilterAttributeOperatorNotEqualTo,
    
    /** SCIM 2.0 attribute operator type 'gt' */
    MASFilterAttributeOperatorGreaterThan,
    
    /** SCIM 2.0 attribute operator type 'ge' */
    MASFilterAttributeOperatorGreaterThanOrEqualTo,
    
    /** SCIM 2.0 attribute operator type 'lt' */
    MASFilterAttributeOperatorLessThan,
    
    /** SCIM 2.0 attribute operator type 'le' */
    MASFilterAttributeOperatorLessThanOrEqualTo
};


# pragma mark - Logical Operator Constants

///--------------------------------------
/// @name Logical Operator Constants
///--------------------------------------


/**
 * SCIM 2.0 'NSString' values matching the MASFilterLogicalOperator enumerated types.
 */
static NSString *const MASIdMgmtLogicalOperatorAnd = @"and";
static NSString *const MASIdMgmtLogicalOperatorNot = @"not";
static NSString *const MASIdMgmtLogicalOperatorOr = @"or";


/**
 * MASFilterAttributeOperator enumeration types that map to the SCIM 2.0 logical
 * operator types.
 */
typedef NS_ENUM(NSInteger, MASFilterLogicalOperator)
{
    /** SCIM 2.0 logical operator type 'and' */
    MASFilterLogicalOperatorAnd,
    
    /** SCIM 2.0 logical operator type 'or' */
    MASFilterLogicalOperatorOr,
    
    /** SCIM 2.0 logical operator type 'not' */
    MASFilterLogicalOperatorNot,
};


# pragma mark - SCIM Constants

///--------------------------------------
/// @name SCIM Constants
///--------------------------------------


/**
 * The SCIM end point key.
 */
static NSString *const MASSCIMEndPointKey = @"scim-path";


# pragma mark - Sorting Constants

///--------------------------------------
/// @name Sorting Constants
///--------------------------------------


/**
 * SCIM 2.0 'NSString' values matching the MASFilteredRequestSortOrder enumerated types.
 */
static NSString *const MASIdMgmtSortOrderAscending = @"ascending";
static NSString *const MASIdMgmtSortOrderDescending = @"descending";


/**
 * MASFilteredRequestSortOrder enumeration types that map to the SCIM 2.0 sort
 * order types.
 */
typedef NS_ENUM(NSInteger, MASFilteredRequestSortOrder)
{
    /** SCIM 2.0 sort order 'ascending' (default) */
    MASFilteredRequestSortOrderAscending,
    
    /** SCIM 2.0 sort order 'descending' */
    MASFilteredRequestSortOrderDescending
};


# pragma mark - Error Constants

///--------------------------------------
/// @name Error Constants
///--------------------------------------


/**
 * SCIM 2.0 'NSString' values matching the MASFilteredRequestSortOrder enumerated types.
 */
static NSString *const kSDKErrorDomain = @"com.ca.MASIdentityManagement:ErrorDomain";


/**
 * MASIdentityManagementError enumeration types.
 */
typedef NS_ENUM (NSUInteger, MASIdentityManagementError)
{
    MASIdentityManagementErrorMASResponseInfoBodyEmpty = 101,
    MASIdentityManagementErrorGroupNotFound = 102
};



# pragma mark - Operation Constants

///--------------------------------------
/// @name Operation Constants
///--------------------------------------

static NSString *const MASIdMgmtOp = @"op";
static NSString *const MASIdMgmtOperationAdd = @"add";
static NSString *const MASIdMgmtOperationRemove = @"remove";


/**
 * MASGroupMemberOperation enumeration types.
 */
typedef NS_ENUM (NSUInteger, MASGroupMemberOperation)
{
    MASGroupMemberOperationAdd,
    MASGroupMemberOperationRemove,
};



# pragma mark - Group Constants

///--------------------------------------
/// @name Group Constants
///--------------------------------------

static NSString *const MASIdMgmtGroupAttributeId = @"id";
static NSString *const MASIdMgmtGroupAttributeDisplayName = @"displayName";
static NSString *const MASIdMgmtGroupAttributeOwner = @"owner";
static NSString *const MASIdMgmtGroupAttributeMembers = @"members";



# pragma mark - User Constants

///--------------------------------------
/// @name User Constants
///--------------------------------------

static NSString *const MASIdMgmtUserAttributeId = @"id";
static NSString *const MASIdMgmtUserAttributeUserName = @"userName";

static NSString *const MASIdMgmtUserAttributeName = @"name";
static NSString *const MASIdMgmtUserAttributeFamilyName = @"familyName";
static NSString *const MASIdMgmtUserAttributeGivenName = @"givenName";
static NSString *const MASIdMgmtUserAttributeFormattedName = @"formattedName";

static NSString *const MASIdMgmtUserAttributeEmails = @"emails";
static NSString *const MASIdMgmtUserAttributePhoneNumbers = @"phoneNumbers";
static NSString *const MASIdMgmtUserAttributeAddresses = @"addresses";
static NSString *const MASIdMgmtUserAttributeGroups = @"groups";
static NSString *const MASIdMgmtUserAttributeActive = @"active";

static NSString *const MASIdMgmtUserAttributePhotos = @"photos";
static NSString *const MASIdMgmtUserAttributeThumbnailPhoto =@"thumbnail";


# pragma mark - Interface

/** 
 * The MASIdentityManagementConstants define common identity management constants
 * and provide some convenience methods.
 */
@interface MASIdentityManagementConstants : NSObject


# pragma mark - Attribute & Logical Operators

///--------------------------------------
/// @name Attribute & Logical Operators
///--------------------------------------


/**
 * Retrieve the 'NSString' value of a 'MASFilterAttributeOperator'.
 *
 * @param attributeOperator The 'MASFilterAttributeOperator'.
 * @return 'NSString'.
 */
+ (NSString *)attributeOperatorToString:(MASFilterAttributeOperator)attributeOperator;


/**
 * Retrieve the 'NSString' value of a 'MASFilterLogicalOperator'.
 *
 * @param logicalOperator The 'MASFilterLogicalOperator'.
 * @return 'NSString'.
 */
+ (NSString *)logicalOperatorToString:(MASFilterLogicalOperator)logicalOperator;



# pragma mark - Sorting

///--------------------------------------
/// @name Sorting
///--------------------------------------

/**
 * Retrieve the 'NSString' value of a 'MASFilteredRequestSortOrder'.
 *
 * @param sortOrder The 'MASFilteredRequestSortOrder'.
 * @return 'NSString'.
 */
+ (NSString *)lsortOrderToString:(MASFilteredRequestSortOrder)sortOrder;

@end
