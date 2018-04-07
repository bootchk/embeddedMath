Library of math for time and random numbers.

Used by SleepSyncAgent library.  In other words, a layer between SyncAgent and the platform.

Depends on rand() from std c lib (newlib).



Cmake:

Requires nRF5Cmake repository.

    mkdir cmakeBuild
    cd cmakeBuild
    cmake -G "Ninja" -DCMAKE_TOOLCHAIN_FILE=/home/bootch/git/nRF5Cmake/toolchain-gnu-arm.cmake ..
    cmake --build . --target embeddedMath52
    



Changelog

1.  Extracted from SleepSyncAgent
2.  Removed circular dependence with radioSoC library.  Moved some methods back to radioSoC/clock
3.  Added cmake scripts
