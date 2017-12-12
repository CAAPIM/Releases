
# Mobile SDK for CA Mobile API Gateway

## Version 1.6.00

**Released**: 12/21/17

## Features and Enhancements

### Improved app testing experience with device registration  
In previous versions, the SDK displayed "device already registered" errors when you installed/uninstalled apps during testing with multiple users. The errors are legitimate for production environments because the MAG server secures devices with this simple logic: only the previously-registered user or client can perform the re-registration. But this made app testing painful. 

In this release, the Mobile SDK generates a new device identifier after uninstall/reinstall, which reduces the likelihood that you'll get this error again. If you do get the error, we've provided the steps to remove the device from the MAG Manager.

- [iOS App Testing](mas.ca.com/docs/iOS/1.6.00/guides/#app-testing)
- [Android App Testing](mas.ca.com/docs/android/1.6.00/guides/#app-testing)
- [Cordova App Testing](mas.ca.com/docs/cordova/1.6.00/guides/#app-testing)
            
### Customize requests to access APIs

Use the new iOS MASRequestBuilder method to build a custom request to access an API. Build a request programmatically using MAS.invoke and add your own parameters. 

- [iOS Access APIs](mas.ca.com/docs/iOS/1.6.00/guides/#access-apis)

### Cordova enhancements

- **Use the Mobile SDK to invoke APIs on non-CA gateways**  
It’s a reality. You don't always have the CA API Gateway fronting all your APIs. You have other API management products already in place with APIs that are exposed directly on those products. You can now use the Mobile SDK to invoke APIs on these non-CA gateways. Extends vendor support in your APIM infrastructure.  

  - [Blog: How to Make Secure Calls to APIs from External Servers](https://www.ca.com/us/developers/mas/blog/how-to-make-secure-calls-to-apis-from-external-servers.html)
  - [Cordova Send HTTP Requests to External APIs](http://mas.ca.com/docs/cordova/1.6.00/guides/#send-http-requests-to-external-apis)

- **JSON Web Token (JWT) to validate data recipients**  
By validating data recipients using JWT, you can add another layer of security beyond mutual SSL and OAuth. <br>**Requires**: Advanced developer experience (because feature is implemented only in the SDK).</br>  

  - [Cordova Validate Data Recipients Using JWT](http://mas.ca.com/docs/cordova/1.6.00/guides/#validate-data-recipients-using-jwt) 
  - [Cordova Sign Requests Using JWT](http://mas.ca.com/docs/ios/1.5.00/guides/#jwt-data)

- **Dynamic Client Configuration Using Enrollment URL**   
The Cordova Mobile SDK now supports managing the msso_config.json file outside of the app bundle. This feature provides another layer of security, and avoids having to reinstall the app to receive updates or when using a different MAG server. To understand the benefits, see [Dynamic Device Enrollment](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/prepare-devices-and-apps-for-developers/dynamic-device-enrollment). For the new SDK initialization method, see [Start with Enrollment URL](mas.ca.com/docs/cordova/1.6.00/guides/#set-up-project-and-start-the-sdk).
            
## Compatibility 

The following versions are supported in Mobile SDK 1.6:

| CA Mobile API Gateway | OAuth Toolkit |
| --------------------- | ------------- |
| 4.1                   | 4.2           |
| 4.0                   | 4.1           |
| 3.3                   | 3.6           |
| 3.2                   | 3.5           |

**Note**: Some Mobile SDK features may depend on a specific version of CA Mobile API Gateway. Check [MAG Feature Release Comparison](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/release-notes/release-comparison), or contact [Developer Support](https://www.ca.com/us/developers/mas/support.html?id=4). 


## Platform Testing 

 Platform | Supported                                  | Should Work                              |
| -------- | ---------------------------------------- | ---------------------------------------- |
| iOS      | 10.x and 11.0 | iOS 9.3.2 and above.  <br>Note: TLS 1.2 is required for iOS clients.</br> |
| Android  | 4.4.2 to 8.0 | 4.4.2 and above |      


## Known Issues (Waiting for Alan & Kiran regression testing)

| Issue | Description |
|-------|-------------|
|       |             |
|       |             |

## Changelogs

**iOS**
- MASFoundation: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/develop/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/develop/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/develop/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/develop/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/develop/CHANGELOG.md)

**[Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/develop/ChangeLog.md)**

**[Cordova SDK ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Foundation/blob/US419011-cordova-native-gaps/ChangeLog.md)**


## More Info

- [CA Support Online](https://support.ca.com/)
- [Developer website and documentation](https://www.ca.com/us/developers/mas.html)
- [CA Mobile API Gateway documentation](https://docops.ca.com/mag)
- [CA Mobile API Gateway communities](https://communities.ca.com/community/ca-api-management-community/content?filterID=contentstatus%5Bpublished%5D~category%5Bca-mobile-api-gateway%5D)

## License

Copyright (c) 2016 CA. All rights reserved.

This software may be modified and distributed under the terms
of the MIT license. See the [LICENSE][license-link] file for details.

 [license-link]: /LICENSE
