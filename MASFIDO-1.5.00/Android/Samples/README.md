# Getting ready with MASFIDOSample App

## Overview
The MASFIDOSample app present in this repository cannot be run in the present state. User needs to download this app and open it in Android Studio. Contact the Samsung SDS Nexsign administrator to get the 1.5.2 version of Samsung SDS libraries. Put all these libraries in the libs folder of the app.
Download the [MAS][mas-lib] and [MASFIDO][masfido-lib] libraries to be used with this app.

### Compile dependencies
Add the below mentioned MAS, MASFIDO and Samsung SDS dependencies to the project. Drop the below files into the libs folder of the app. The build.gradle already has the entries for the below listed files.

```
//Samsung SDS dependencies
model-1.4.3-combiner.aar
model-1.4.3-face-lr_nn.aar
model-1.4.3-voice-tssv-udp_enUS.aar
samsungsds-biosdk-1.5.2.aar
samsungsds-bm-1.5.2.aar
samsungsds-sm-1.5.2.aar
samsungsds-um-1.5.2.jar
smma-3.1.0-android.aar
uaf-authenticator-1.5.2.aar
uaf-nexsign-client-1.5.2.aar
vvutils-3.1.0.aar

// MASFIDO dependencies
masfido-core-1.5.00.aar
masfido-sds-1.5.00.aar

// MAS dependencies
mas-foundation-1.5.00.aar
mas-ui-1.5.00.aar
```
### Server Configuration file
Copy the msso_config.json file generated from the server into the assets folder of the sample app

### Additional dependencies
MASFIDOSample app depends on certain more 3rd party dependencies. These dependencies are already added into the build.gradle file.

``
Note: Make sure that the Facet id of this Android app is added to the Samsung SDS Nexsign server's list of facet ids. To know more about Samsung SDS FIDO FacetId, please read Samsung SDS Nexsign Server Installation document.
``

## Application Flow

#### FIDO Registration: Use this button to register your biometrics to various modalities supported by Samsung SDS Nexsign server. You need to provide a valid username to access this API.

#### FIDO Deregistration: Use this button to deregister your biometrics to various modalities supported by Samsung SDS Nexsign server. You need to provide a valid username to access this API.

#### List Items: This button lists down content of an API which is protected by oauth accesstoken. If the user is not logged in then the system will prompt the Login UI to enter your credentials. This UI has support for FIDO Login (`Login With Biometric` button). Username is mandatory for FIDO login.

#### FIDO Protected List Items: This button showcases the use case of FIDO Transaction flow, wherein the same `List Items` API is protected using FIDO Transaction Confirmation flow. This API needs user to be logged in already, if not, system will prompt for Login.

```Note: The FIDO Authentication and Transaction flow require user to be registered for atleast one of the biometric modalities. If not you'll receive an error from FIDO server.``` 

 [mas-lib]: https://github.com/CAAPIM/Releases/blob/master/MAS-1.5.00/Android/Android-MobileSDK-1.5.00.zip
 [masfido-lib]: https://github.com/CAAPIM/Releases/blob/master/MASFIDO-1.5.00/Android/Android-MASFIDOSDK-1.5.00.zip