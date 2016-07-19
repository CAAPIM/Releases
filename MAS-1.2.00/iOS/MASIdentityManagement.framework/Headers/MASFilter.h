//
//  MASFilter.h
//  MASIdentityManagement
//
//  Copyright (c) 2016 CA, Inc.
//
//  This software may be modified and distributed under the terms
//  of the MIT license. See the LICENSE file for details.
//

#import <Foundation/Foundation.h>


@interface MASFilter : NSObject


# pragma mark - Filters

///--------------------------------------
/// @name Filters
///--------------------------------------


/**
 * Create a 'MASFilter' that filters by an attribute that contains within it the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'co'. The expected behaviour is that
 * the entire operator value must be a substring of the attribute value for a match.
 *
 * e.g. filter=name.familyName co "O'Malley"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute contains:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that ends with the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'ew'. The expected behaviour is that
 * the entire operator value must be a substring of the attribute value, matching at the
 * end of the attribute value.  This criterion is satisfied if the two strings are identical.
 *
 * e.g. filter=userName ew "an"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute endsWith:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is equal to the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'eq'. The expected behaviour is that
 * the attribute and operator values must be identical for a match.
 *
 * e.g. filter=userName eq "bjensen"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute equalTo:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is greater than the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'gt'. The expected behaviour is that
 * if the attribute value is greater than the operator value, there is a match. The actual 
 * comparison is dependent on the attribute type.  For string attribute types, this is a               |
 * lexicographical comparison, and for DateTime types, it is a chronological comparison.  
 * For integer attributes, it is a comparison by numeric value. Boolean and Binary attributes 
 * SHALL cause a failed response (HTTP status code 400) with "scimType" of "invalidFilter".
 *
 * e.g. filter=meta.lastModified gt "2011-05-13T04:42:34Z"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute greaterThan:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is greater than OR equal to the 
 * given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'ge'. The expected behaviour is that
 * if the attribute value is greater than or equal to the operator value, there is a match.  
 * The actual comparison is dependent on the attribute type.  For string attribute types, 
 * this is a lexicographical comparison, and for DateTime types, it is a chronological 
 * comparison.  For integer attributes, it is a comparison by numeric value. Boolean and 
 * Binary attributes SHALL cause a failed response (HTTP status code 400) with "scimType" of             |
 * "invalidFilter".
 *
 * e.g. filter=meta.lastModified ge "2011-05-13T04:42:34Z"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute greaterThanOrEqualTo:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is less than the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'lt'. The expected behaviour is that
 * if the attribute value is less than the operator value, there is a match. The actual 
 * comparison is dependent on the attribute type. For string attribute types, this is a
 * lexicographical comparison, and for DateTime types, it is a chronological comparison.  
 * For integer attributes, it is a comparison by numeric value. Boolean and Binary attributes 
 * SHALL cause a failed response (HTTP status code 400) with "scimType" of "invalidFilter".
 *
 * e.g. filter=meta.lastModified lt "2011-05-13T04:42:34Z"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute lessThan:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is less than OR equal to the 
 * given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'le'. The expected behaviour is that
 * If the attribute value is less than or equal to the operator value, there is a match.  
 * The actual comparison is dependent on the attribute type. For string attribute types,
 * this is a lexicographical comparison, and for DateTime types, it is a chronological 
 * comparison. For integer attributes, it is a comparison by numeric value. Boolean and
 * Binary attributes SHALL cause a failed response (HTTP status code 400) with "scimType" 
 * of "invalidFilter".
 *
 * e.g. filter=meta.lastModified le "2011-05-13T04:42:34Z"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute lessThanOrEqualTo:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is NOT equal to the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'ne'. The expected behaviour is
 * that the attribute and operator values are not identical.
 *
 * e.g. filter=userName ne "bjensen"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute notEqualTo:(NSString *)value;


/**
 * Create a 'MASFilter' that filters by an attribute that is present.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'pr'. The expected behaviour is that
 * if the attribute has a non-empty or (has value) | non-null value, or if it contains a
 * non-empty node for complex attributes, there is a match.
 *
 * e.g. filter=title pr
 *
 * @param attribute The 'NSString' attribute identifier.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttributePresent:(NSString *)attribute;


/**
 * Create a 'MASFilter' that filters by an attribute that starts with the given value.
 *
 * This corresponds to the SCIM 2.0 attribute operator 'sw'. The expected behaviour is 
 * that the entire operator value must be a substring of the attribute value, starting 
 * at the  beginning of the attribute value.  This criterion is satisfied if the two 
 * strings are identical.
 *
 * e.g. filter=userName sw "J"
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute startsWith:(NSString *)value;



# pragma mark - Advanced Filtering

///--------------------------------------
/// @name Advanced Filtering
///--------------------------------------


/**
 * Retrieve the 'MASFilter' as an 'NSString' expression in SCIM 2.0 format.
 *
 * @return 'NSString' expression in SCIM 2.0 format.
 */
- (NSString *)asStringFilterExpression;


/**
 * Create a 'MASFilter' that filters by an attribute, attribute operator and value.
 *
 * All convenience filter methods in 'Filters'use this method to construct their instances.
 *
 * @param attribute The 'NSString' attribute identifier.
 * @param attributeOperator The 'MASFilterAttributeOperator' attribute operator.
 * @param value The 'NSString' attribute value.
 * @return 'MASFilter'.
 */
+ (MASFilter *)filterByAttribute:(NSString *)attribute withAttributeOperator:(MASFilterAttributeOperator)attributeOperator andValue:(NSString *)value;


/**
 * Create a 'MASFilter' from a complete SCIM 2.0 expression as an 'NSString'.
 *
 * This is for advanced users that may want to completely write their own 
 * SCIM 2.0 filter expressions for some reason. Likely this will be used where 
 * the other API provided don't cover a use case.
 *
 * Note, at this time logical operators are NOT supported.
 *
 * @param expression 'NSString' expression in SCIM 2.0 format.
 * @return 'MASFilter'.
 */
+ (MASFilter *)fromStringFilterExpression:(NSString *)expression;

@end
