cmake_minimum_required (VERSION 3.5)

set(PRROJ_NAME cmake_test_boost)
project (${PRROJ_NAME})

set(SOURCES "main.cpp")
add_executable(${PRROJ_NAME} ${SOURCES})

#find Boost

set(NEED_BOOST_COMPONENTS thread date_time)
include(${CMAKE_SOURCE_DIR}/cmake/Modules/getBoost.cmake)

if(Boost_FOUND)
	#add_definitions(-DBOOST_ALL_NO_LIB)
	message("Boost_FOUND & include_directories(${BOOST_INCLUDE_DIRS})")
	include_directories(${Boost_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})
	message("target_link_libraries(${PRROJ_NAME} ${BOOST_LIBRARIES})")
	target_link_libraries(${PRROJ_NAME} ${Boost_LIBRARIES})

endif()

if(UNIX)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include  -Wall")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")

endif()
