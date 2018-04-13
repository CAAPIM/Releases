
# Mobile SDK for CA Mobile API Gateway

## Release 1.7.00

**Released**: TBD

### Features and Enhancements

#### Xamarin Mobile SDK

Use the Xamarin Mobile SDK to code once in C#, and deliver apps in iOS and Android. 

In this version, we support the [Xamarin MASFoundation Library](link TBD), and these features:

- Authentication and authorization, limited to:  
  - Device Registration
  - User log in and client credentials
  - Fingerprint session lock
  - Single Sign-on 
- Secure access to APIs
- Send HTTP Requests to external APIs

##### Get Started 

The easiest way to get the Xamarin Mobile SDK is through Visual Studio, which embeds the NuGet dependency manager. Or, you can get the library on the [NuGet site](https://www.nuget.org/packages?q=MASFoundation).

Either way, here's how to [Get Started: Xamarin Mobile SDK](LInk - Common Guide)

### Compatibility

| CA Mobile API Gateway | OAuth Toolkit |
| --------------------- | ------------- |
| 4.1                   | 4.2           |
| 4.0                   | 4.1           |
| 3.3                   | 3.6           |
| 3.2                   | 3.5           |

**Note**: Some Mobile SDK features depend on a specific version of CA Mobile API Gateway. Check [MAG Feature Release Comparison](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/release-notes/release-comparison), or contact [Developer Support](https://www.ca.com/us/developers/mas/support.html?id=4). 

### Platform Testing 

| Platform | Supported     | Compatible                               |
| -------- | ------------- | ---------------------------------------- |
| iOS      | 10.x and 11.0 | iOS 9.3.2 and above. Note: TLS 1.2 is required for iOS clients. |
| Android  | 6.0 to 8.1    | 4.4.2 and above.                         |
| Cordova  | TBD           | TBD                                      |
| Xamarin  | TBD           | TBD                                      |  

**Note**: Our Mobile SDK is tested only on devices using official platform versions. The SDK may behave in unexpected ways if users have devices with unsupported versions.

### Known Issues

| Issue                                    | Description                              | Workaround                               |
| :--------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| (US466920: All SDKs) Errors on specific devices | If you have unexplained or intermittent SDK errors that occur only on specific devices, environments or settings, it may be because users are using an supported version of the platform, or they have tampered or customized the device. The Mobile SDK is tested only on devices using official platform versions.  When devices are tampered with or customized, the SDK can behave in unexpected ways. | Check that users are using a supported version for their platform. Next, verify that users have not jailbroken or unlocked the OS (iOS), or customized the device ROM (Android). If either case is true, users should upgrade to a supported version of their platform. |
| Apple SDK bug                            | If the MAG/OTK is configured to generate an HTTP 403 error, and the client certificate is configured for mutual SSL, the Apple Transport Layer determines that the certificate is bad and kills the entire transaction with the following error: `FAILED: Error Domain=NSURLErrorDomain Code=-1206 "The server “our.server.here” requires a client certificate.` | Developers can workaround the bug in their app, or Admins can change all HTTP status codes from 403 to another status code. |
| Social login limitation                  | (MCT-177) The social login feature of the Mobile SDK does not work if you have installed the Mobile App Services (MAS) solution kit. | Contact Services for help with customizing policies for IDPs. |

### Changelogs

**iOS**
- MASFoundation: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/master/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/master/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/master/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/master/CHANGELOG.md)

**[Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)**

**Cordova**
- Cordova-MAS-Foundation: [Changelog](https://github.com/CAAPIM/Cordova-MAS-Foundation/blob/master/ChangeLog.md)
- Cordova-MAS-Connecta: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Connecta/blob/master/ChangeLog.md)
- Cordova-MAS-IdentityManagement: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-IdentityManagement/blob/master/ChangeLog.md)
- Cordova-MAS-Storage: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Storage/blob/master/ChangeLog.md)

## Release 1.6.10

**Released**: 03/6/18

- MASFoundation only: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- [Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)

## Release 1.6.00

**Released**: 12/28/17

### Features and Enhancements

#### Improved app testing experience with device registration  
In previous versions, the SDK displayed "device already registered" errors when you installed/uninstalled apps during testing with multiple users. The errors are legitimate for production environments because the MAG server secures devices with this simple logic: only the previously-registered user or client can perform the re-registration. But this made app testing painful. 

In this release, the Mobile SDK generates a new device identifier after uninstall/reinstall, which reduces the likelihood that you'll get this error again. If you do get the error, we've provided the steps to remove the device from the MAG Manager.

- [iOS App Testing](http://mas.ca.com/docs/ios/1.6.00/guides/#app-testing)
- [Android App Testing](http://mas.ca.com/docs/android/1.6.00/guides/#app-testing)
- [Cordova App Testing](http://mas.ca.com/docs/cordova/1.6.00/guides/#app-testing)
            
#### Customize requests to access APIs

Use the new iOS MASRequestBuilder method to build a custom request to access an API. Build a request programmatically using MAS.invoke and add your own parameters. 

- [iOS Access APIs](http://mas.ca.com/docs/ios/1.6.00/guides/#access-apis)

#### Support of session lock/unlock with iOS Face ID: 

Expanding our current support for iOS Fingerprint Session lock, the Mobile SDK integrates seamlessly with facial recognition technology introduced by Apple for iPhone X.  

#### Cordova enhancements

- **Use the Mobile SDK to invoke APIs on non-CA gateways**  
It’s a reality. You don't always have the CA API Gateway fronting all your APIs. You have other API management products already in place with APIs that are exposed directly on those products. You can now use the Mobile SDK to invoke APIs on these non-CA gateways. Extends vendor support in your APIM infrastructure.  

  - [Blog: How to Make Secure Calls to APIs from External Servers](https://www.ca.com/us/developers/mas/blog/how-to-make-secure-calls-to-apis-from-external-servers.html)
  - [Cordova Send HTTP Requests to External APIs](http://mas.ca.com/docs/cordova/1.6.00/guides/#send-http-requests-to-external-apis)

- **JSON Web Token (JWT) to validate data recipients**  
By validating data recipients using JWT, you can add another layer of security beyond mutual SSL and OAuth. <br>**Requires**: Advanced developer experience (because feature is implemented only in the SDK).</br>  

  - [Cordova Validate Data Recipients Using JWT](http://mas.ca.com/docs/cordova/1.6.00/guides/#validate-data-recipients-using-jwt) 
  - [Cordova Sign Requests Using JWT](http://mas.ca.com/docs/cordova/1.6.00/guides/#jwt-data)

- **Dynamic Client Configuration Using Enrollment URL**   
The Cordova Mobile SDK now supports managing the msso_config.json file outside of the app bundle. This feature provides another layer of security, and avoids having to reinstall the app to receive updates or when using a different MAG server. To understand the benefits, see [Dynamic Device Enrollment](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/prepare-devices-and-apps-for-developers/dynamic-device-enrollment). For the new SDK initialization method, see [Start with Enrollment URL](http://mas.ca.com/docs/cordova/1.6.00/guides/#set-up-project-and-start-the-sdk).
            
### Compatibility 

The following versions are supported in Mobile SDK 1.6.00 (plus minor releases):

| CA Mobile API Gateway | OAuth Toolkit |
| --------------------- | ------------- |
| 4.1                   | 4.2           |
| 4.0                   | 4.1           |
| 3.3                   | 3.6           |
| 3.2                   | 3.5           |

**Note**: Some Mobile SDK features depend on a specific version of CA Mobile API Gateway. Check [MAG Feature Release Comparison](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/release-notes/release-comparison), or contact [Developer Support](https://www.ca.com/us/developers/mas/support.html?id=4). 


### Platform Testing 

| Platform | Supported                                | Compatible                               |
| -------- | ---------------------------------------- | ---------------------------------------- |
| iOS      | 10.x and 11.0                            | iOS 9.3.2 and above. Note: TLS 1.2 is required for iOS clients. |
| Android  | 6.0 to 8.1                               | 4.4.2 and above.                         |
| Cordova  | <li>iOS 10.x and 11.0</li><li> Android 7.0 to 8.1</li> |                                          |

**Note**: Our Mobile Android SDK is tested only on devices using Android official versions. In devices using a custom ROM, the SDK may not work as expected.

### Limitations

| Issue                              | Description                              | Workaround                               |
| ---------------------------------- | ---------------------------------------- | ---------------------------------------- |
| Client certificate error (iOS)     | If you configured MAG to generate an HTTP 403 error, and the client certificate is configured for mutual SSL, the Apple Transport Layer determines that the certificate is bad and kills the entire transaction with the following error: `FAILED: Error Domain=NSURLErrorDomain Code=-1206 "The server “our.server.here” requires a client certificate.` | Change all HTTP status codes from 403 to another status code. |
| Proximity login with BLE (Android) | (DE258130) The message, "BLE advertisement has been found with Rssi: XXX," is displayed when BLE signal is received. Proximity login with BLE may not work on apps using the default JSON configuration. Depending on the device, you may need to increase the default range of the signal strength so devices can communicate using BLE. | (Admin) In the msso_config.json file, find the msso_ble_rssi value, and increase the range from -35 (default) to -80 or higher. You may need to play with these values. |
| Social Login (all SDKs)            | (MCT-177) The Mobile SDK authenticates only against a supported IDP using the User Management library. A social login implementation requires other identity providers. | (Admin) Customize MAG policies for other IDPs. |

### Changelogs

**iOS**
- MASFoundation: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/master/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/master/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/master/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/master/CHANGELOG.md)

**[Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)**

**Cordova**
- Cordova-MAS-Foundation: [Changelog](https://github.com/CAAPIM/Cordova-MAS-Foundation/blob/master/ChangeLog.md)
- Cordova-MAS-Connecta: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Connecta/blob/master/ChangeLog.md)
- Cordova-MAS-IdentityManagement: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-IdentityManagement/blob/master/ChangeLog.md)
- Cordova-MAS-Storage: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Storage/blob/master/ChangeLog.md)

## More Info

- [Developer website and documentation](https://www.ca.com/us/developers/mas.html)
- [CA Mobile API Gateway documentation](https://docops.ca.com/mag)
- [CA Mobile API Gateway communities](https://communities.ca.com/community/ca-api-management-community/content?filterID=contentstatus%5Bpublished%5D~category%5Bca-mobile-api-gateway%5D)
- [CA Support Online](https://support.ca.com/)

## License

Copyright (c) 2016 CA. All rights reserved.

This software may be modified and distributed under the terms
of the MIT license. See the [LICENSE][license-link] file for details.

 [license-link]: /LICENSE
