cmake_minimum_required(VERSION 3.8)

project(reach VERSION 1.0
		DESCRIPTION "Linux Contacts app"
		LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

include(ExternalProject)
ExternalProject_Add(libvc
	GIT_REPOSITORY https://github.com/libvc/libvc.git
	GIT_TAG 4f79cf94d6fce163e3e012939c83b4b395a832f1
	 #--Update/Patch step----------
  	UPDATE_COMMAND touch <SOURCE_DIR>/config.h COMMAND mkdir -p <SOURCE_DIR>/include <SOURCE_DIR>/lib    # Source work-tree update command
	#--Configure step-------------
	CONFIGURE_COMMAND autoreconf -f -i COMMAND ./configure --prefix=<INSTALL_DIR>
	BUILD_IN_SOURCE 1        # Use source dir for build dir
	INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}"  )

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

	

add_executable(reach 
	src/main.cpp
	src/importwindow.cpp
	src/importwindow.h )
target_link_libraries(reach ${GTKMM_LIBRARIES})
target_compile_features(reach PRIVATE cxx_std_11)
