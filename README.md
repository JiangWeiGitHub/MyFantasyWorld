# Build Process for New Ubuntu 16.04.3 64Bit
+ Clone this project first
+ Download **cocos2d-x-3.16.zip** somewhere [Download Path](http://www.cocos2d-x.org/filedown/cocos2d-x-3.16.zip)
+ Unzip cocos2d-x-3.16.zip into this project's root folder
+ edit **CMakeLists.txt** *set(COCOS2D_ROOT ${CMAKE_SOURCE_DIR}/cocos2d-x-3.16)*
+ sudo ./cocos2d-x-3.16/setup.py
+ sudo ./cocos2d-x-3.16/build/install-deps-linux.sh
+ cmake .
+ make
+ ./bin/MyFantasyWorld
