# Getting Ready With MASFIDOSample App

## Overview

The MASFIDOSample app present in this repository cannot be run in the present state. 


### Prerequisites

#### SDK LIBRARY FILES

1. Contact the Samsung SDS team to get the 1.5.2 version of Samsung SDS SDK dynamic frameworks.
2. Download the [MAS](https://github.com/CAAPIM/Releases/blob/develop/MAS-1.5.00/iOS/iOS-MobileSDK-1.5.00.zip) and [MASFIDO](https://github.com/CAAPIM/Releases/blob/FIDO_space/MASFIDO-1.5.00/iOS/iOS-MASFIDOSDK-1.5.00.zip) SDK library files 


### MASFIDOSample Project Setup

1. Open MASFIDOSample project in Xcode.
2. Drag the SDK library files, and drop them into your project in the left navigator panel in Xcode. Select the option, `Copy items if needed`.
3. Select MASFIDOSample Project, add the SDK library files in the Embedded Binaries section of the project’s General tab.
3. Select `File->Add files to 'project name'` and add the msso_config.json file from your project folder.


> Note: Make sure that the Facet id of this MASFIDOSample iOS App is added to the Samsung SDS Nexsign server's list of facet ids.
> To know more about Samsung SDS FIDO FacetId, please read Samsung SDS Nexsign Server Installation document.

## Application Flow

#### FIDO Register: Use this button to register your biometrics to various modalities supported by Samsung SDS Nexsign server. You need to provide a valid username to access this API.

#### FIDO Deregister: Use this button to deregister your biometrics to all the modalities already registered for the device. You need to provide a valid username to access this API.

#### FIDO Deregister By Modality: Use this button to deregister one or more biometric modalities already registered for the device. You need to provide a valid username to access this API.

#### Fetch products: This button lists down content of an API which is protected by oauth accesstoken. If the user is not logged in then the system will prompt the Login UI to enter your credentials. This UI has support for FIDO Login (`Login With Biometric` button). Username is mandatory for FIDO login.

#### Fetch products (FIDO T/C Protected API): This button showcases the use case of FIDO Transaction flow, wherein the same `Fetch products` API is protected using FIDO Transaction Confirmation flow. This API needs user to be logged in already, if not, system will prompt for Login.

> Note: The FIDO Authentication and Transaction flow require user to be registered for atleast one of the biometric modalities. If not you'll receive an error from FIDO server.
