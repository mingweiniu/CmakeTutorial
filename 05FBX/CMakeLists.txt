cmake_minimum_required(VERSION 3.5)
# C++14 is required
set(CMAKE_CXX_STANDARD 14)

set(PRROJ_NAME "05FBX")
project (${PRROJ_NAME})

# user define Find_packages
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)


include_directories("${CMAKE_SOURCE_DIR}/include")
set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} "${PROJECT_SOURCE_DIR}/include")

file(GLOB_RECURSE My_HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")
set(HEADERS ${HEADERS} ${My_HEADERS}) 
set(SOURCES ${SOURCES} main.cpp ${HEADERS}) 
set(LIB_SOURCES ${LIB_SOURCES})
add_executable(${PRROJ_NAME} ${SOURCES})



# finding FBX
set(PACKAGE_TARGET FBX)
find_package(${PACKAGE_TARGET})
message("${PACKAGE_TARGET}_FOUND is ${${PACKAGE_TARGET}_FOUND}") 
if(${${PACKAGE_TARGET}_FOUND})
    set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} "${${PACKAGE_TARGET}_INCLUDE_DIRS}")
    set(PROJ_LIBRARIES ${PROJ_LIBRARIES} "${${PACKAGE_TARGET}_LIBS}")
endif() 



message("include_directories(${PROJ_INCLUDE_DIRS})")
include_directories(${PROJ_INCLUDE_DIRS})

#set(My_LIB "mylib")
#add_subdirectory("src/${My_LIB}")
#add_library("lib_${My_LIB}" ${My_LIB_SOURCES} ) 
#set(PROJ_LIBRARIES ${PROJ_LIBRARIES} "lib_${My_LIB}")

message("target_link_libraries(${PRROJ_NAME} ${PROJ_LIBRARIES})")
target_link_libraries(${PRROJ_NAME} ${PROJ_LIBRARIES})



set(MY_CPP_FLAGS ${MY_CPP_FLAGS})
if(UNIX)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CPP_FLAGS} -I/usr/local/include -Wall")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib") 
endif()
