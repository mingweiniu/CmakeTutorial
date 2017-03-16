cmake_minimum_required (VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

set(PRROJ_NAME 02Boost)
project (${PRROJ_NAME})

set(SOURCES "main.cpp")
add_executable(${PRROJ_NAME} ${SOURCES})


#finding Boost
set(NEED_BOOST_COMPONENTS filesystem system)
include(${CMAKE_SOURCE_DIR}/cmake/getBoost.cmake)


if(Boost_FOUND)
	#add_definitions(-DBOOST_ALL_NO_LIB)
	message("Boost_FOUND & set boost include/libs")
	set(PROJ_INCLUDE_DIRS ${PROJ_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
	set(PROJ_LIBRARIES ${PROJ_LIBRARIES} ${Boost_LIBRARIES})
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
