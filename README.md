
if "error while loading shared libraries: libfmod.so.6: cannot open shared object file: No such file or directory" shows up, you have to:

sudo cp <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/local/lib/
sudo cp <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/local/lib/
sudo cp <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/include/*.h /usr/local/include/

then run "install-deps-linux.sh" again 
