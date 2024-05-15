# ipu7-camera-bins

This repository supports MIPI cameras through the IPU7 on Intel Lunar Lake platform.
There are 4 repositories that provide the complete setup:

- https://github.com/intel/ipu7-drivers - kernel drivers for the IPU and sensors
- https://github.com/intel/ipu7-camera-bins - IPU firmware and proprietary image processing libraries
- https://github.com/intel/ipu7-camera-hal - HAL for processing of images in userspace
- https://github.com/intel/icamerasrc/tree/icamerasrc_slim_api (branch:icamerasrc_slim_api) - Gstreamer src plugin

## Content of this repository:
- IPU7 firmware binaries
- Library binary dependencies for ipu7-camera-hal
- Header files for those libraries

## Deployment
ipu7-camera-bins should be copied to build server and target
```
# Runtime files
mkdir -p /lib/firmware/intel
cp -r ipu7-camera-bins/lib/firmware/intel/*.bin /lib/firmware/intel/
cp ipu7-camera-bins/lib/lib* /usr/lib/
# Development files
mkdir -p /usr/include /usr/lib/pkgconfig
cp -r ipu7-camera-bins/include/* /usr/include/
cp -r ipu7-camera-bins/lib/pkgconfig/* /usr/lib/pkgconfig/
```
