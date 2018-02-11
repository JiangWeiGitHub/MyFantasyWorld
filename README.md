# Build Process for New Ubuntu 16.04.3 64Bit
+ Clone this project first
+ Download **cocos2d-x-3.16.zip** [Download Path](http://www.cocos2d-x.org/filedown/cocos2d-x-3.16.zip)
+ Unzip cocos2d-x-3.16.zip into this project's root folder
+ edit **CMakeLists.txt**
```
    set(COCOS2D_ROOT ${CMAKE_SOURCE_DIR}/cocos2d-x-3.16)
````
+ Configure environment

```
    sudo ./cocos2d-x-3.16/setup.py
```
+ Link lib (music modules need)
```
    sudo cp ./cocos2d-x-3.16/external/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/local/lib/
    sudo cp ./cocos2d-x-3.16/external/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/local/lib/
    cd /usr/local/lib/
    sudo ln -s libfmod.so libfmod.so.6
```
+ Install essential packages
```
    sudo ./cocos2d-x-3.16/build/install-deps-linux.sh
```
+ cmake .
+ make
+ ./bin/MyFantasyWorld
