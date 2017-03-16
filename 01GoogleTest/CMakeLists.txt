cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

set(PRROJ_NAME 01GoogleTest)
project (${PRROJ_NAME})

set(SOURCES "main.cpp")
add_executable(${PRROJ_NAME} ${SOURCES})

#find googleTest
message("find_package(GTest)")
find_package(GTest)
message("GTEST_FOUND is${TEST_FOUND })
if(GTEST_FOUND)
	set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
	set(PROJ_LIBRARIES ${PROJ_LIBRARIES} ${GTEST_BOTH_LIBRARIES})
endif()

message("include_directories(${PROJ_INCLUDE_DIRS})")
include_directories(${PROJ_INCLUDE_DIRS})
message("target_link_libraries(${PRROJ_NAME} ${PROJ_LIBRARIES})")
target_link_libraries(${PRROJ_NAME} ${PROJ_LIBRARIES})


if(UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include  -Wall")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")
endif()
