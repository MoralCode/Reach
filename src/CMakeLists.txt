find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

# find the command to generate the custom resources
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

set(GRESOURCE_C   ui.gresource.c)
set(GRESOURCE_XML ui.gresource.xml)

# set up the command to generate the custom resources
add_custom_command(
    OUTPUT ${GRESOURCE_C}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS
        --target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        ${GRESOURCE_XML}
    VERBATIM
    MAIN_DEPENDENCY ${GRESOURCE_XML}
    DEPENDS
        reach.glade
)

# create a custom target for the generated ui resources
add_custom_target(
    ui-resource
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C})

# Tell CMAKE that that resource c file is generated
set_source_files_properties(
    ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
    PROPERTIES GENERATED TRUE
)

configure_file(reach.glade . COPYONLY)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} vc config++)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_11)