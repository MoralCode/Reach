cmake_minimum_required(VERSION 3.8)

project(reach VERSION 1.0
		DESCRIPTION "Linux Contacts app"
		LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)


link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})






add_executable(reach 
	src/main.cpp
	src/importwindow.cpp
	src/importwindow.h )

target_compile_options(reach PRIVATE -Wall)
target_compile_options(reach PRIVATE -Wextra)

target_link_libraries(reach ${GTKMM_LIBRARIES} /usr/local/lib/libvc.so)
target_compile_features(reach PRIVATE cxx_std_11)
