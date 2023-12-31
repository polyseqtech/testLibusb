cmake_minimum_required(VERSION 3.24.0)

# For Windows
if (WIN32)
    message(STATUS windows system)
    # Qt5 config路径
    set(CMAKE_PREFIX_PATH  D:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5)
    # 找x64库
#        set(VCPKG_TARGET_TRIPLET "x64-windows")
    #    set(VCPKG_ROOT "$ENV{USERPROFILE}/vcpkg")
    set(VCPKG_HOME "$ENV{USERPROFILE}/vcpkg")
    file(TO_CMAKE_PATH "${VCPKG_HOME}" VCPKG_HOME)
    add_definitions(-D_WIN32_WINNT=0x600)
endif()

# For macOS and Linux (including Ubuntu)
if (APPLE OR UNIX)
    set(VCPKG_HOME "$ENV{HOME}/vcpkg")
    set(CMAKE_PREFIX_PATH  $ENV{HOME}/Qt/5.15.2/gcc_64/lib/cmake/Qt5)
endif()

# 首选C++17，没有会使用上一个版本off
set(CMAKE_CXX_STANDARD 17 REQUIRED)

set (CMAKE_TOOLCHAIN_FILE "${VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake")
message(CMAKE_TOOLCHAIN_FILE =${CMAKE_TOOLCHAIN_FILE})

project(FPGA_Command LANGUAGES CXX)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)



find_package(Qt5  REQUIRED COMPONENTS Core Network)
message(== CMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH})
message(CMAKE_TOOLCHAIN_FILE =${CMAKE_TOOLCHAIN_FILE})

find_package(libusb CONFIG REQUIRED)

find_package(OpenCV CONFIG REQUIRED)

add_executable(control main.cpp
    CommandContent.h CommandContent.cpp
    CommandRegister.h
    FpgaCommand.h FpgaCommand.cpp
    DeviceControl.h DeviceControl.cpp)


target_link_libraries(control
        Qt5::Core
)
# 包含头文件
target_include_directories(control PRIVATE ${LIBUSB_INCLUDE_DIRS})
# 链接libusb
target_link_libraries(control ${LIBUSB_LIBRARIES})
# 链接opencv
target_link_libraries(control opencv_ml opencv_dnn opencv_core opencv_flann)
