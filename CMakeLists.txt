cmake_minimum_required(VERSION 3.8)

project(reach VERSION 1.0
		DESCRIPTION "Linux Contacts app"
		LANGUAGES C CXX)

# This adds the src folder to the list of irectories to search when #include-ing local project files, such as #include "gui.h" from the unit tests
#https://raymii.org/s/tutorials/Cpp_project_setup_with_cmake_and_unit_tests.html#toc_3
include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
