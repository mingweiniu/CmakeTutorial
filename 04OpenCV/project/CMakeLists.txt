cmake_minimum_required(VERSION 3.5)
# C++14 is required
set(CMAKE_CXX_STANDARD 14)

set(PRROJ_NAME "04OpenCV")
project (${PRROJ_NAME})

include_directories("${CMAKE_SOURCE_DIR}/include")


set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE My_LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
#file(GLOB_RECURSE My_LIB_SOURCES "${CMAKE_SOURCE_DIR}/src/hw1/*.cpp")
file(GLOB_RECURSE My_HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")
set(HEADERS ${HEADERS} ${My_HEADERS}) 
set(SOURCES ${SOURCES} main.cpp ${HEADERS}) 
set(LIB_SOURCES ${LIB_SOURCES})
add_executable(${PRROJ_NAME} ${SOURCES})


# if windows
# you need add the directory of opencv to environment variable, and log out
# for example $ENV:OpenCV_DIR is "C:\\opencv\\build" 
# and this path has such "OpenCVConfig-version.cmake" files

if(WIN32)
    find_path(OpenCV_DIR OpenCVConfig.cmake HINTS
        "$ENV{CV_ROOT}"
        "$ENV{OpenCV_ROOT}"
        "$ENV{OpenCV_DIR}"
    )
    message("OpenCV_DIR is ${OpenCV_DIR}") 
endif() 


find_package(OpenCV REQUIRED)
message("OpenCV_FOUND is ${OpenCV_FOUND}") 
if(OpenCV_FOUND)
    set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
    set(PROJ_LIBRARIES ${PROJ_LIBRARIES} ${OpenCV_LIBS})
endif() 



message("include_directories(${PROJ_INCLUDE_DIRS})")
include_directories(${PROJ_INCLUDE_DIRS})


add_subdirectory(src/hw1)
set(My_LIB "hw1")
add_library("lib_${My_LIB}" ${My_LIB_SOURCES} ) 
set(PROJ_LIBRARIES ${PROJ_LIBRARIES} "lib_${My_LIB}")


message("target_link_libraries(${PRROJ_NAME} ${PROJ_LIBRARIES})")
target_link_libraries(${PRROJ_NAME} ${PROJ_LIBRARIES})

set(MY_CPP_FLAGS ${MY_CPP_FLAGS})
if(UNIX)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CPP_FLAGS} -I/usr/local/include -Wall")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib") 
endif()
