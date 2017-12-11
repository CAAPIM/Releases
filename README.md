
# Mobile SDK for CA Mobile API Gateway

## Version 1.6.00

**Released**: 12/21/17

## Features and Enhancements

### Improved app testing experience with device registration  
In previous versions, the SDK displayed "device already registered" errors when you installed/uninstalled apps during testing with multiple users. The errors are legitimate for production environments because the MAG server secures devices with this simple logic: only the previously-registered user or client can perform the re-registration. But this made app testing painful. 

In this release, the Mobile SDK generates a new device identifier after uninstall/reinstall, which reduces the likelihood that you'll get this error again. If you do get the error, we've provided the steps to remove the device from the MAG Manager.

- [iOS App Testing](mas.ca.com/docs/ios/1.6.00/guides/#app-testing)
- [Android App Testing](mas.ca.com/docs/android/1.6.00/guides/#app-testing)
- [Cordova App Testing](mas.ca.com/docs/cordova/1.6.00/guides/#app-testing)
            
### Cordova Mobile SDK Enhancements

- **Web browser authentication**  
The Mobile SDK now provides a browser-based login page using Chrome Custom Tabs (Android) or Safari View Controller (iOS), giving you the flexibility to choose between a native, or browser-based login page. If you have a suite of mobile applications, browser-based login lets you dynamically change the login template of all the apps without modifying them individually. Using a browser-based login flow, the user is directed to a customized login page for user authentication. 
**Requires**: Mobile Developer Console version 1.1.0

Cordova link

- **Use the Mobile SDK to invoke APIs on non-CA gateways**  
It’s a reality. You don't always have the CA API Gateway fronting all your APIs. You have other API management products already in place with APIs that are exposed directly on those products. You can now use the Mobile SDK to invoke APIs on these non-CA gateways. Extends vendor support in your APIM infrastructure.  

  - [Blog: How to Make Secure Calls to APIs from External Servers](https://www.ca.com/us/developers/mas/blog/how-to-make-secure-calls-to-apis-from-external-servers.html)
  - [iOS Send HTTP Requests to External APIs](http://mas.ca.com/docs/ios/1.6.00/guides/#send-http-requests-to-external-apis)
  - [Android Send HTTP Requests to External APIs](http://mas.ca.com/docs/android/1.6.00/guides/#send-http-requests-to-external-apis)

- **JSON Web Token (JWT) to validate data recipients**  
By validating data recipients using JWT, you can add another layer of security beyond mutual SSL and OAuth.
**Requires**: Advanced developer experience (because feature is implemented only in the SDK)  

  - [iOS Validate Data Recipients Using JWT](http://mas.ca.com/docs/ios/1.6.00/guides/#jwt-data)  
  - [Android Validate Data Recipients Using JWT](http://mas.ca.com/docs/android/1.6.00/guides/#jwt-data) 

- **Dynamic Client Configuration Using Enrollment URL**   
The Cordova Mobile SDK now supports managing the msso_config.json file outside of the app bundle. This feature provides another layer of security, and avoids having to reinstall the app to receive updates or when using a different MAG server. To understand the benefits, see [Dynamic Client Configuration](https://docops.ca.com/display/MAG/.Dynamic+Client+Enrollment+v4.1). For the new SDK initialization method, see [Start with Enrollment URL](mas.ca.com/docs/cordova/1.6.00/guides/#set-up-project-and-start-the-sdk).
            
## Compatibility 

| Mobile SDK | CA Mobile API Gateway | OAuth Toolkit | CA API Gateway  |
|------------|-----------------------|---------------|-----------------|
| 1.6        | 4.1                   | 4.2           | 9.3             |
| 1.4, 1.5   | 4.0                   | 4.0, 4.1*     | 9.2             |
| 1.3        | 3.3                   | 3.6           | 9.2.x, 9.1.x    |
| 1.2        | 3.2                   | 3.5, 3.5.1    | 9.1.0           |

\*Using MAG 4.0 with OTK 4.1 requires a software compatibility patch. See [OTK 4.1 Release Notes](https://docops.ca.com/display/OTK41/Release+Notes)

## Platform Testing 

 Platform | Tested                                   | Should Work                              |
| -------- | ---------------------------------------- | ---------------------------------------- |
| iOS      | <li>11.X</li><li>10.X</li> <li>10.1.1</li> | iOS 9.3.2 and above.  <br>Note: TLS 1.2 is required for iOS clients.</br> |
| Android  | <li>8.0</li><li>7.1.1</li> <li>6.0.1</li> <li>5.1.5</li> <li>4.4.2</li> | 4.4.2 and above      

## Mobile Integrations and Solutions

- [Rapid App Security](https://docops.ca.com/ras)
- [CA Mobile API Gateway: Samsung SDS Nexsign Integration](https://docops.ca.com/ca-mobile-api-gateway-samsung-sds-nexsign-integration)

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

## License

Copyright (c) 2016 CA. All rights reserved.

This software may be modified and distributed under the terms
of the MIT license. See the [LICENSE][license-link] file for details.

 [license-link]: /LICENSE
