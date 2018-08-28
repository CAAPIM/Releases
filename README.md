
# Mobile SDK for CA Mobile API Gateway

## Release 1.8.00

<br>**Released**: September 5, 2018</br>

### Features and Enhancements

#### Android P Support

Android P was released August 7, 2018 with new security features. We made substantive changes to our Mobile SDK for Android P, and we sent out advanced customer notification so you could prepare for these changes. 

The Mobile SDK supports Android P for:
- Android native
- Xamarin-Android

**Note:** Cordova is not supported in this release. Watch for updates when Apache officially releases support for Android P. 

#### Mobile SDK Changes for Android P

Whether you have an existing Mobile SDK app, or this is your first app, review this section to ensure success with Android P devices. Although the changes to Android P were substantial, the changes you need to make are minimal.

**Q. What change did you make to the Mobile SDK for Android P?**<br>
A. The key change is the new Secure Account Manager Storage (AMS). If you implemented the original AMS (and you implemented your own encryption), the Secure AMS now includes encryption. Secure AMS is the default for storing app data (device and mag identifiers) for Android P. Keys and certificates are still stored in the Android keystore. We made other changes to support Android P, but they are handled under the covers for you. </br>

**Q. Is updating to Secure AMS easy? Do I have to update the msso_config.json file after upgrading to 1.8.00?**<br>
A. Yes, there are only a few steps to implement Secure AMS. And, no you don't have to update the msso_config.json. (The Android P requirement to re-register the device is handled seamlessly for you.)</br>

**Q. If I created an app using the original AMS where I implemented my own encryption, will my app still work with Android P?**<br> 
A. Yes, your app will work "as is". However, we still recommend that you upgrade and implement Secure AMS to ensure that your app aligns with Android P encryption requirements. </br> 

**Q. Does Secure AMS support SSO?**<br>
A. Yes. Just remember that all SSO apps must use the same storage methods or SSO won't work. That is, SSO apps cannot mix different token storage methods: Android keystore, original AMS, and Secure AMS.</br>

For details, see:
- [Prepare for Android P - Android native](http://mas.ca.com/docs/android/latest/guides/#prepare-for-android-p)
- [Prepare for Android P - Xamarin-Android](http://mas.ca.com/docs/xamarin/latest/guides/android/#prepare-for-android-p)

#### Secure Account Manager Storage for Android

We added encryption to the Android AccountManager Storage (AMS). Although Android KeyStore is still the preferred method for token storage, this improvement adds security for devices where PIN/Lock is not available. Secure AMS avoids account data from being easily extracted with a rooted device. This feature is backward compatible with the existing AMS implementation in the Android Mobile SDK.

For details, see [Add Secure Account Manager Storage](http://mas.ca.com/docs/android/latest/guides/#add-secure-account-manager-storage).

#### New Apple Face ID Setting for User Session Lock/Unlock (iOS, Xamarin-iOS, Cordova)

If you've implemented the user session lock/unlock feature in the MASFoundation, you should update your privacy settings as a result of Apple updates to FaceID. Although MASFoundation will not crash if you do not change the setting, user session lock/unlock will automatically fallback to the system Passcode prompt (instead of biometric local authentication). To update, add the usage string `NSFaceIDusageDescription` to **Privacy - Face ID Usage Description** in your app's info.plist. 

#### Offline Logout (iOS, Android, Xamarin, Cordova)

The Mobile SDK now support offline log out. This new method lets you delete or keep user credentials upon error (such as server is not reachable). See Changelogs for your platform for details.

### Product Compatibility

| CA Mobile API Gateway | CA API Management OAuth Toolkit | CA API Gateway | Mobile SDK for CA Mobile API Gateway |
| --------------------- | ------------------------------- | -------------- | ------------------------------------ |
| 4.1                   | 4.3, 4.2                        | 9.3            | 1.8, 1.7, 1.6                        |
| 4.0                   | 4.1`*`, 4.0                     | 9.2            | 1.8, 1.7, 1.6, 1.5, 1.4              |
| 3.3                   | 3.6                             | 9.2, 9.1`**`   | 1.8, 1.7, 1.6, 1.3                   |
| 3.2                   | 3.5                             | 9.1            | 1.8, 1.7, 1.6, 1.2                   |

`*` Requires software compatibility patch. See [OTK 4.1 Release Notes](https://docops.ca.com/display/OTK41/Release+Notes).
<br>`**` Cassandra 3.x is not support in CA API Gateway version 9.1.x.</br>

**Note**: All minor versions (CRs) are supported as part of the major release.
<br>**Note**: Some Mobile SDK features depend on a specific version of CA Mobile API Gateway. Check [MAG Feature Release Comparison](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/release-notes/release-comparison), or contact [Developer Support](https://www.ca.com/us/developers/mas/support.html?id=4).</br>

### SDK Platform Support

| Platform | Supported                                |
| -------- | ---------------------------------------- |
| iOS      | <li>9.0 through 11.0</li>                |
| Android  | <li>4.4.2 through 9</li>                 |
| Cordova  | <li>7.0.1, 7.10, and 8.0.0 </li>         |
| Xamarin  | <li>(iOS) 9.0 through 11.0</li><li>(Android) 4.4.2 through 9.0</li> |

**Note**: Our Mobile SDK is tested only on devices using official platform versions. The SDK may behave in unexpected ways if users have devices with unsupported versions.

### Known Issues

| Issue or Limitation                      | Description                              | Workaround                               |
| ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| Mobile SDK only supports HS256 algorithm for signing id_tokens | Although MAG supports HS265, RS256, and any custom algorithm, the Mobile SDK currently only supports HS256 for signing id_token. In this release, we improved the SDK so it now handles: <li>HS256 where token ID is supported and a signature is validated.</li> <li>Other algorithms where signature validation is not supported (and id_tokens are not accepted and signatures fail). For example, RS256.</li> | If your current MAG/OTK implementation: <li> **Uses HS256**, nothing needs to be done.</li> <li>**Uses any other algorithm,** you can skip signature validation on the client side. For workaround, see Troubleshooting, Error: JWT token not valid for your platform.</li> |

### Changelogs

**iOS**
- MASFoundation: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/master/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/master/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/master/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/master/CHANGELOG.md)

**Android**
- [Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)

**Cordova**
- Cordova-MAS-Foundation: [Changelog](https://github.com/CAAPIM/Cordova-MAS-Foundation/blob/master/ChangeLog.md)
- Cordova-MAS-Connecta: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Connecta/blob/master/ChangeLog.md)
- Cordova-MAS-IdentityManagement: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-IdentityManagement/blob/master/ChangeLog.md)
- Cordova-MAS-Storage: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Storage/blob/master/ChangeLog.md)

**Xamarin**
- [Xamarin ChangeLog](https://github.com/CAAPIM/Xamarin-MAS-Foundation/blob/master/CHANGELOG.md)

## Release 1.7.10

<br>**Released**: July 16, 2018</br>

### Features and Enhancements

#### New Cordova User Authentication Methods

We've added two new user authentication methods in the Cordova Mobile SDK that let you control authentication callbacks at the application level. Use these methods when your app needs to invoke a protected endpoint without the user being logged in, or when login tokens expire.

- `MAS.setAuthCallbackHandler(authHandler)`  
  Sets the authentication handler and overrides the default Cordova plugin behavior.
- `MAS.removeAuthCallbackHandler()`    
  Removes the authentication handler and resets callback handling to default login page.

For details, see [Explicit User Authentication Handling](http://mas.ca.com/docs/cordova/latest/guides/#explicit-user-authentication-handling)

#### Support for JSON Array Object

The MASRequest class now supports JSONArray object for all platforms.  

### Changelogs

**iOS**
- MASFoundation: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/master/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/master/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/master/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/master/CHANGELOG.md)

**Android**
- [Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)

**Cordova**
- Cordova-MAS-Foundation: [Changelog](https://github.com/CAAPIM/Cordova-MAS-Foundation/blob/master/ChangeLog.md)
- Cordova-MAS-Connecta: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Connecta/blob/master/ChangeLog.md)
- Cordova-MAS-IdentityManagement: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-IdentityManagement/blob/master/ChangeLog.md)
- Cordova-MAS-Storage: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Storage/blob/master/ChangeLog.md)

**Xamarin**
- [Xamarin ChangeLog](https://github.com/CAAPIM/Xamarin-MAS-Foundation/blob/master/CHANGELOG.md)


## Release 1.7.00

<br>**Released**: June 21, 2018</br>

### Features and Enhancements

#### New! Mobile SDK for Xamarin®

The Mobile SDK for Xamarin allows you to secure your cross-platform mobile apps with CA Mobile API Gateway. In this version, we support [Xamarin MASFoundation](https://github.com/CAAPIM/Xamarin-MAS-SDK/tree/master) with these features:

- Authentication and Authorization, limited to:  
  - Password and client credentials flows, with device registration
  - Fingerprint session lock
  - Single Sign-on
- Securely access to APIs:  
  - Request methods (GET, POST, PUT, DELETE) and Request Builder
  - Geolocation
  - SSL pinning
  - Access APIS hosted in external servers
- All SDK initialization options and advanced configuration

The easiest way to get the Xamarin Mobile SDK is through Visual Studio, which embeds the NuGet dependency manager. Or, you can get MASFoundation.Xamarin on the [NuGet site](https://www.nuget.org/packages?q=MASFoundation).

Either way, here's how to [Get Started: Xamarin Mobile SDK](http://mas.ca.com/docs/xamarin/latest/guides/).

#### Cordova App CLI Utility

The new Cordova app CLI utility lets you create a MAS-enabled Cordova app with just three commands:
- **mas forge** creates a Cordova project at the specified path
- **mas configure** lets you add the msso_config.json file to the project
- **mas prepare** prepares the app with these libraries: MAS-Template, MASFoundation, MASIdentity Management, MASConnecta, and MASStorage

[Get CLI Utility](https://github.com/CAAPIM/Cordova-MAS-CLI)

### Sample Apps Have Moved

As of 1.6.00, all sample apps have moved to their respective repositories:
- [Android](https://github.com/CAAPIM/Android-MAS-SDK#sample-apps)
- [iOS](https://github.com/CAAPIM/iOS-MAS-SDK#sample-apps)
- [Cordova](https://github.com/CAAPIM/Cordova-MAS-SDK#android)
- [Xamarin](https://github.com/CAAPIM/Xamarin-MAS-SDK#sample-apps)

### Product Compatibility

| CA Mobile API Gateway | CA API Management OAuth Toolkit | CA API Gateway | Mobile SDK for CA Mobile API Gateway |
| --------------------- | ------------------------------- | -------------- | ------------------------------------ |
| 4.1                   | 4.3, 4.2                        | 9.3            | 1.7, 1.6                             |
| 4.0                   | 4.1`*`, 4.0                     | 9.2            | 1.7, 1.6, 1.5, 1.4                   |
| 3.3                   | 3.6                             | 9.2, 9.1`**`   | 1.7, 1.6, 1.3                        |
| 3.2                   | 3.5                             | 9.1            | 1.7, 1.6, 1.2                        |

`*` Requires software compatibility patch. See [OTK 4.1 Release Notes](https://docops.ca.com/display/OTK41/Release+Notes).
<br>`**` Cassandra 3.x is not support in CA API Gateway version 9.1.x.</br>

**Note**: All minor versions (CRs) are supported as part of the major release.
<br>**Note**: Some Mobile SDK features depend on a specific version of CA Mobile API Gateway. Check [MAG Feature Release Comparison](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/release-notes/release-comparison), or contact [Developer Support](https://www.ca.com/us/developers/mas/support.html?id=4).</br>

### SDK Platform Support

| Platform | Supported                                |
| -------- | ---------------------------------------- |
| iOS      | <li>9.0 through 11.0</li>                         |
| Android  | <li>4.4.2 through 8.1.0</li>                     |
| Cordova  | <li>7.0.1 and 7.10</li>                           |
| Xamarin  | <li>(iOS) 9.0 through 11.0</li><li>(Android) 4.4.2 through 8.1.0</li> |

**Note**: Our Mobile SDK is tested only on devices using official platform versions. The SDK may behave in unexpected ways if users have devices with unsupported versions.

### Known Issues

| Issue or Limitation                      | Description                              | Workaround                               |
| :--------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| (US466920: All SDKs) Errors on specific devices | If you have unexplained or intermittent SDK errors that occur only on specific devices, environments or settings, it may be because users are using an supported version of the platform, or they have tampered or customized the device. The Mobile SDK is tested only on devices using official platform versions.  When devices are tampered with or customized, the SDK can behave in unexpected ways. | Check that users are using a supported version for their platform. Next, verify that users have not jailbroken or unlocked the OS (iOS), or customized the device ROM (Android). If either case is true, users should upgrade to a supported version of their platform. |
| Request with client certificate on HTTP 403 fails | If the MAG/OTK is configured to generate an HTTP 403 error, and the client certificate is configured for mutual SSL, the Apple Transport Layer determines that the certificate is bad and kills the entire transaction with the following error: `FAILED: Error Domain=NSURLErrorDomain Code=-1206 "The server “our.server.here” requires a client certificate.` | Developers can workaround the bug in their app, or Admins can change all HTTP status codes from 403 to another status code. |
| (MCT-177: All SDKs) Social login limitation | The social login feature of the Mobile SDK does not work if you have installed the Mobile App Services (MAS) solution kit. | Contact Services for help with customizing policies for IDPs. |
| (DE355995) JWT access token generation and validation | Although OTK supports issuing and validating UUID and JWT access tokens, the JWT access token is not currently supported by the CA Mobile API Gateway. | None.                                    |

### Changelogs

**iOS**
- MASFoundation: [Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/master/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/master/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/master/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/master/CHANGELOG.md)

**Android**
- [Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)

**Cordova**
- Cordova-MAS-Foundation: [Changelog](https://github.com/CAAPIM/Cordova-MAS-Foundation/blob/master/ChangeLog.md)
- Cordova-MAS-Connecta: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Connecta/blob/master/ChangeLog.md)
- Cordova-MAS-IdentityManagement: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-IdentityManagement/blob/master/ChangeLog.md)
- Cordova-MAS-Storage: [ChangeLog](https://github.com/CAAPIM/Cordova-MAS-Storage/blob/master/ChangeLog.md)

**Xamarin**
- [Xamarin ChangeLog](https://github.com/CAAPIM/Xamarin-MAS-Foundation/blob/master/CHANGELOG.md)

## Release 1.6.10

**Released**: March 6, 2018

- [iOS MASFoundation Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/master/CHANGELOG.md)
- [Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)

## Release 1.6.00

**Released**: December 28, 2017

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

  - [Blog: How to Make Secure Calls to APIs from External Servers](http://www.ca.com/us/developers/mas/blog/how-to-make-secure-calls-to-apis-from-external-servers.html)
  - [Cordova Send HTTP Requests to External APIs](http://mas.ca.com/docs/cordova/1.6.00/guides/#send-http-requests-to-external-apis)

- **JSON Web Token (JWT) to validate data recipients**  
By validating data recipients using JWT, you can add another layer of security beyond mutual SSL and OAuth. <br>**Requires**: Advanced developer experience (because feature is implemented only in the SDK).</br>  

  - [Cordova Validate Data Recipients Using JWT](http://mas.ca.com/docs/cordova/1.6.00/guides/#validate-data-recipients-using-jwt) 
  - [Cordova Sign Requests Using JWT](http://mas.ca.com/docs/cordova/1.6.00/guides/#jwt-data)

- **Dynamic Client Configuration Using Enrollment URL**   
The Cordova Mobile SDK now supports managing the msso_config.json file outside of the app bundle. This feature provides another layer of security, and avoids having to reinstall the app to receive updates or when using a different MAG server. To understand the benefits, see [Dynamic Device Enrollment](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/prepare-devices-and-apps-for-developers/dynamic-device-enrollment). For the new SDK initialization method, see [Start with Enrollment URL](http://mas.ca.com/docs/cordova/1.6.00/guides/#set-up-project-and-start-the-sdk).
            
#### Sample Apps Have Moved

As of 1.6.00, all sample apps have moved to GitHub:

- [Android](https://github.com/CAAPIM/Releases/tree/GA-1.7-Release-Notes/MAS-1.6.00/Android/Samples)
- [iOS](https://github.com/CAAPIM/Releases/tree/GA-1.7-Release-Notes/MAS-1.6.00/iOS/Samples)
- [Cordova](https://github.com/CAAPIM/Releases/tree/GA-1.7-Release-Notes/MAS-1.6.00/Cordova/Samples)
- [Xamarin](https://github.com/CAAPIM/Releases/tree/GA-1.7-Release-Notes/MAS-1.6.00/Xamarin/Samples)


### Product Compatibility 

The following versions are supported in Mobile SDK 1.6.00 (plus minor releases):

| CA Mobile API Gateway | OAuth Toolkit |
| --------------------- | ------------- |
| 4.1                   | 4.2           |
| 4.0                   | 4.1           |
| 3.3                   | 3.6           |
| 3.2                   | 3.5           |

**Note**: Some Mobile SDK features depend on a specific version of CA Mobile API Gateway. Check [MAG Feature Release Comparison](https://docops.ca.com/ca-mobile-api-gateway/4-1/en/release-notes/release-comparison), or contact [Developer Support](https://www.ca.com/us/developers/mas/support.html?id=4). 


### SDK Support

| Platform | Supported                                |
| -------- | ---------------------------------------- |
| iOS      | <li>9.0 through 11.0</li>                         |
| Android  | <li>4.4.2 through 8.1.0</li>                      |
| Cordova  | <li>7.0.1 and 7.10</li>                           |
| Xamarin  | <li>(iOS) 9.0 through 11.0</li><li>(Android) 4.4.2 through 8.1.0</li> |

**Note**: Our Mobile SDK is tested only on devices using official platform versions. The SDK may behave in unexpected ways if users have devices with unsupported versions.

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

**Android**
- [Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/master/ChangeLog.md)

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
