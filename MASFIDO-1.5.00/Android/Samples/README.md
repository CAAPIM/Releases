# Getting ready with MASFIDOSample App

## Overview
The MASFIDOSample app present in this repository cannot be run in the present state. User needs to download this app and open it in Android Studio. Contact the Samsung SDS team to get the 1.5.2 version of Samsung SDS libraries. Put all these libraries in the libs folder of the app.
Download the [MAS][mas-lib] and [MASFIDO][masfido-lib] libraries and add them too in the app's libs folder. 

## Compile dependencies
Add the below mentioned MAS and Samsung SDS dependencies to the project. Copy the below files into the libs folder of the app.

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
masui-1.5.00.aar
```
## Server Configuration file
Copy the msso_config.json file generated from the server into the assets folder of the sample app

## Additional dependencies
MASFIDOSample app depends on certain more 3rd party dependencies. Developer needs to add the below mentioned entries into the build.gradle file.
```
    compile 'net.openid:appauth:0.6.1'
    compile 'com.android.support:appcompat-v7:26.0.0'
    compile 'com.android.support:design:26.0.0'
    compile 'com.nimbusds:nimbus-jose-jwt:4.37.1'
    compile 'org.slf4j:slf4j-api:1.7.5'
    compile 'org.apache.commons:commons-lang3:3.0'
    compile 'org.jbundle.util.osgi.wrapped:org.jbundle.util.osgi.wrapped.org.apache.http.client:4.1.2'
    compile 'com.google.code.gson:gson:2.2.4'
    compile 'com.google.guava:guava:23.0-android'
    compile 'org.restlet.jee:org.restlet:2.2.+'
```
``
Note: Make sure that the Facet id of this Android app is added to the Samsung SDS Nexsign server's list of facet ids. To know more about Samsung SDS FIDO FacetId, please read Samsung SDS Nexsign Server Installation document.
``

 [mas-lib]: https://github.com/CAAPIM/Releases/blob/master/MAS-1.5.00/Android/Android-MobileSDK-1.5.00.zip
 [masfido-lib]: https://github.com/CAAPIM/Releases/blob/master/MASFIDO-1.5.00/Android/Android-MASFIDOSDK-1.5.00.zip