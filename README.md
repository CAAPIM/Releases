Back to > [iOS Mobile SDK](https://github.com/CAAPIM/iOS-MAS-SDK)
<hr/>

# Mobile SDK for CA Mobile API Gateway

## Release 1.6.00

**Release Date**: 12/21/17
- **Type**: Full (Mobile SDK, MAG, and OTK)
- **MAG**: 4.1
- **OTK**: 4.2
- [CA Mobile API Gateway documentation](https://docops.ca.com/mag)

### Features and Enhancements

| Features and Enhancements                | Description                              | Platform     | Where? |
| :--------------------------------------- | :--------------------------------------- | :----------- | ------ |
| Improved app testing experience with device registration | In previous versions, the SDK displayed "device already registered" errors when you installed/uninstalled apps during testing with multiple users. The errors are legitimate for production environments because the MAG server secures devices with this simple logic: only the previously-registered user or client can perform the re-registration. But this made app testing painful. <p>In this release, the Mobile SDK generates a new device identifier after uninstall/reinstall, which reduces the likelihood that you'll get this error again. If you do get the error, we've provided the steps in Troubleshooting to remove the device from the MAG Manager.</p> | iOS, Android | n/a    |
| Backward compatibility for Mobile SDK    | The Mobile SDK is now compatible with MAG 3.2 and above. | iOS, Android | n/a    |
| Web browser authentication               | TBD                                      | Cordova      | <link> |
| Use the Mobile SDK to invoke APIs on non-CA gateways | It’s a reality. You don't always have the CA API Gateway fronting all your APIs. You have other API management products already in place with APIs that are exposed directly on those products. You can now use the Mobile SDK to invoke APIs on these non-CA gateways. Extends vendor support in your APIM infrastructure. | Cordova      | <link>   
            
### Platform Testing 

 Platform | Tested                                   | Should Work                              |
| -------- | ---------------------------------------- | ---------------------------------------- |
| iOS      | <li>11.0</li><li>10.3</li> <li>10.1.1</li> <li>9.3.2</li> | iOS 9.3.2 and above.  <br>Note: TLS 1.2 is required for iOS clients.</br> |
| Android  | <li>8.0</li><li>7.1.1</li> <li>6.0.1</li> <li>5.1.5</li> <li>4.4.2</li> | 4.4.2 and above      

### Mobile Integrations and Solutions

[Rapid App Security](https://docops.ca.com) - waiting on Satya<br>
[CA Mobile API Gateway: Samsung SDS Nexsign Integration](https://docops.ca.com/ca-mobile-api-gateway-samsung-sds-nexsign-integration)</br>

### Known Issues

| Issue | Description |
|-------|-------------|
|       |             |
|       |             |

### Resolved Issues

| Issue | Description |
|-------|-------------|
|       |             |
|       |             |

### Changelogs

**iOS**
- MASFoundation:[Changelog](https://github.com/CAAPIM/iOS-MAS-Foundation/blob/develop/CHANGELOG.md)
- MASConnecta: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Connecta/blob/develop/CHANGELOG.md)
- MASIdentityManagement: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-IdentityManagement/blob/develop/CHANGELOG.md)
- MASStorage: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-Storage/blob/develop/CHANGELOG.md)
- MASUI: [ChangeLog](https://github.com/CAAPIM/iOS-MAS-UI/blob/develop/CHANGELOG.md)

**[Android SDK ChangeLog](https://github.com/CAAPIM/Android-MAS-SDK/blob/develop/ChangeLog.md)**

**[Cordova SDK ChangeLog](https://github.com/CAAPIM/MAS-Storage-Cordova/blob/develop/ChangeLog.md)**



## License

Copyright (c) 2016 CA. All rights reserved.

This software may be modified and distributed under the terms
of the MIT license. See the [LICENSE][license-link] file for details.


 [mas.ca.com]: http://mas.ca.com/
 [license-link]: /LICENSE
