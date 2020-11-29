find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

add_executable(${CMAKE_PROJECT_NAME} 
	main.cpp
	gui.h
	gui.cpp )

configure_file(reach.glade . COPYONLY)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} vc)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_11)