# bin/bash

mkdir lib
wget https://github.com/google/googletest/archive/release-1.8.1.tar.gz
tar xf release-1.8.1.tar.gz
rm -rf release-1.8.1.tar.gz
cd googletest-release-1.8.1
cmake -DBUILD_SHARED_LIBS=ON .
make
cd -
mv googletest-release-1.8.1/googletest/include/ include/
mv googletest-release-1.8.1/googlemock/gtest/lib*.so lib/
rm -rf googletest-release-1.8.1
