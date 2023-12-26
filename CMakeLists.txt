cmake_minimum_required(VERSION 3.27)
project(DriverBase)

set(CMAKE_CXX_STANDARD 17)

# https://github.com/SergiusTheBest/FindWDK
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/Dependencies/FindWDK/cmake")
find_package(WDK REQUIRED)

if (NOT WDK_FOUND)
    message(FATAL_ERROR "You MUST have the Windows Driver Kit to build this CMake project! Install it at https://learn.microsoft.com/en-us/windows-hardware/drivers/download-the-wdk#download-icon-step-3-install-wdk")
endif ()

set(SOURCE_FILES driver_entry.cpp)
include_directories(${PROJECT_NAME} "${CMAKE_SOURCE_DIR}/Dependencies")

# The base for CLion drivers.
# Uncomment to modify WDK_WINVER
# set(WDK_WINVER "0x0601") # 0x0601 is the default.
message(STATUS "The driver will be built for Winver " ${WDK_WINVER})

wdk_add_driver(${PROJECT_NAME}
        EXCLUDE_FROM_ALL
        KMDF 1.15
        WINVER ${WDK_WINVER}
        ${SOURCE_FILES})