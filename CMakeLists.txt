cmake_minimum_required (VERSION 3.5.1)

project ( embeddedMath CXX)

# brief: library that depends only on stdc for rand().  Provides random related functions, and math on time.


set(CMAKE_MODULE_PATH "/home/bootch/git/nRF5Cmake/")
message(" Module path is ${CMAKE_MODULE_PATH}")


# environment (location of NRF_SDK and other tools)
# i.e. file CMakeEnv.cmake on the MODULE_PATH
include("CMakeEnv")


# scripts specific to nRF5x building
# Defines cmake macros prefixed with "nRF5"
# Sets many cmake vars for tool flags
include("nRF5")


nRF5CheckSetupPreconditions()
nRF5SetBuildOptions()


# No SDK includes
# nRF5SetIncludePaths()
# No SDK_SOURCES except .h files which in-line
# nRF5SetSDKSourcesBasic()


# libraries
# Each specific to a ARM M0 or M4 (nrf51 or nrf52)

add_library(embeddedMath52 STATIC "")

set_target_properties( embeddedMath52
    PROPERTIES
       CHIP "nrf52832_xxaa"
       SOFTDEVICE "none"
       FLOAT_ABI "soft"
    )
nRF5CheckTargetProperties(embeddedMath52)
nRF5ConfigTargetByProperties(embeddedMath52)
# No startup sources or link script

#install(TARGETS embeddedMath52
#    EXPORT embeddedMathTargets
#    DESTINATION lib)
#install(EXPORT embeddedMathTargets
#    DESTINATION lib)




set(MY_SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

list(APPEND MY_SOURCE_LIST
   ${MY_SOURCE_DIR}/random.cpp
   ${MY_SOURCE_DIR}/randomAlarmingClock.cpp
   ${MY_SOURCE_DIR}/timeMath.cpp
)

target_sources(embeddedMath52
    PUBLIC
       "${MY_SOURCE_LIST}"
    )
    
#target_include_directories(embeddedMath52
#   PUBLIC
#       $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
 #      $<INSTALL_INTERFACE:/src>
#   )
   
target_include_directories(embeddedMath52
   PUBLIC
   "${CMAKE_CURRENT_LIST_DIR}/src")
    




