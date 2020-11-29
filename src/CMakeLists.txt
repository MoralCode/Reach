find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# also make a static library for the unit tests to link to
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})


configure_file(reach.glade . COPYONLY)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} vc config++)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib ${GTKMM_LIBRARIES} vc config++)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_11)