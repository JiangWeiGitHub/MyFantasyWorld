
if "error while loading shared libraries: libfmod.so.6: cannot open shared object file: No such file or directory" shows up, you have to:

sudo cp <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/local/lib/
sudo cp <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/local/lib/
sudo cp <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/include/*.h /usr/local/include/

then run "install-deps-linux.sh" again

maybe you also have to:

cd <*COCOS FOLDER LOCATION*>/external/linux-specific/fmod/prebuilt/64-bit
ln -s libfmod.so libfmod.so.6
ln -s libfmodL.so libfmodL.so.6 
