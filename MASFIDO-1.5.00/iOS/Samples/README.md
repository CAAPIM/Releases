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

