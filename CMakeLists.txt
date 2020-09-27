cmake_minimum_required(VERSION 3.8)

project(reach VERSION 1.0
		DESCRIPTION "Linux Contacts app"
		LANGUAGES CXX)


add_executable(reach src/main.cpp)
target_compile_features(reach PRIVATE cxx_std_11)
