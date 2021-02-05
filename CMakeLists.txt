cmake_minimum_required (VERSION 2.8)

project(NTRIP)

set(NTRIP_VERSION_MAJOR 0)
set(NTRIP_VERSION_MINOR 1)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_RELEASE "-Os")

set(GMock_DIR CMake_helpers)
set(libCommon_DIR CMake_helpers)

set(QT_QMAKE_EXECUTABLE "${CMAKE_CURRENT_SOURCE_DIR}/../qt-x11/bin/qmake")
find_package(Qt4)

if(NOT QT4_FOUND)
    # unset the executable path
    set(QT_QMAKE_EXECUTABLE)
    find_package(Qt4)
endif()

find_package(Doxygen)
find_package(libCommon REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(doxygen_${PROJECT_NAME}
		  ${DOXYGEN_EXECUTABLE}
		  ${CMAKE_CURRENT_SOURCE_DIR}/doxygen/DEFAULT_PLATFORM_CONFIG.doxygen)

set_property(DIRECTORY APPEND PROPERTY
	     ADDITIONAL_MAKE_CLEAN_FILES
	     ../documentation)

get_target_property(DOC_TARGET doc TYPE)
if(NOT DOC_TARGET)
	add_custom_target(doc)
endif()

string(COMPARE EQUAL ${CMAKE_PROJECT_NAME} ${PROJECT_NAME} top_level)
if(top_level)
	add_dependencies(doc doxygen_${PROJECT_NAME})
endif()

set(NTRIP_SOURCES
        SocketInterfaceDevice.cpp
	corrector_ctl.cpp
	corrector_mgr.cpp
	ntrip_corrector.cpp)

set(NTRIP_HEADERS
        SocketInterfaceDevice.h
        corrector_ctl.h
        corrector_mgr.h
        ntrip_corrector.h)

QT4_WRAP_CPP(NTRIP_HEADERS_MOC ${NTRIP_HEADERS})

set(PROJECT_SOURCE_FILES
        ${NTRIP_SOURCES})

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
include_directories(${COMMON_INCLUDE_DIR} "~/work/OutbackMAX/max_terminal_application/ui/")

add_library(NTRIP STATIC ${PROJECT_SOURCE_FILES} ${NTRIP_HEADERS_MOC})

FILE(GLOB NTRIP_headers "*.h")

# Install stuff in the correct places.
install (TARGETS NTRIP DESTINATION lib)
install (FILES ${NTRIP_headers} DESTINATION include/HemisphereGPS/NTRIP)

