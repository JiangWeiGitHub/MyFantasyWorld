# Cocos2d-X

### Information
+ Version: 3.14.1
+ [*download path*](http://www.cocos2d-x.org/filedown/cocos2d-x-3.14.1.zip)
+ Host: Ubuntu 16.04.1 Desktop amd64
+ [**Official Site**](http://cocos2d-x.org/)
+ [**Official Github**](https://github.com/cocos2d/cocos2d-x)

### Run Test Sample
+ download
+ unzip
+ enter into root of this unzip folder
+ run command like below:
```
  sudo cp ./external/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/local/lib/
  sudo cp ./external/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/local/lib/
  ln -s libfmod.so libfmod.so.6
```
PS: [*because of this*](http://discuss.cocos2d-x.org/t/error-while-building-for-linux-libfmod-so-6/26553)

+ enter into `/build` folder
+ cd `./build`
+ run `./install-deps-linux.sh`
+ run `cmake ..`
+ run `make`
+ run test sample like `./bin/cpp-tests/cpp-tests`
