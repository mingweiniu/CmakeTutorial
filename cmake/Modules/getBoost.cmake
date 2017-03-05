
if(WiN32)
	add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
endif()

message("setting boost")
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_STATIC_RUNTIME ON)
SET(Boost_DEBUG ON)
message("find_package(Boost)")
find_package(Boost)