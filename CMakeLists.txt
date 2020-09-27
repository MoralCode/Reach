cmake_minimum_required(VERSION 3.8)

project(reach VERSION 1.0
		DESCRIPTION "Linux Contacts app"
		LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)


link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

	

add_executable(reach 
	src/main.cc
	src/helloworld.cc
	src/helloworld.h )
target_link_libraries(reach ${GTKMM_LIBRARIES})
target_compile_features(reach PRIVATE cxx_std_11)
