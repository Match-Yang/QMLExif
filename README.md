# QMLExif

[![License](https://img.shields.io/badge/license-LGPLv3%2B-blue.svg)](https://www.gnu.org/licenses/lgpl-3.0.html)

QMLExif is a pulgin for reading exif infomation from image file by [libexif](http://libexif.sourceforge.net/).

##Dependencies

- Qt 5.0 or higher.
- [libexif](http://libexif.sourceforge.net/)

## Build & Install

- `$git clone https://github.com/Match-Yang/QMLExif.git`
- `$cd QMLExif`
- `$mkdir build; cd build`
- `qmake ..`
- `make`
- `sudo make install`

## How to use
You can refer to the example/main.qml for how to use this plugin.

You can run the below command to check the example:
- `$qmlscene example/main.qml`

It will show a window like below if you already install this plugin correctly.

![example](https://cloud.githubusercontent.com/assets/5242852/21955194/ab4c863c-daa0-11e6-88ce-0e33d3d965b8.jpg)