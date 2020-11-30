find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
pkg_check_modules(GLIBM glibmm-2.4)
link_directories(${GTKMM_LIBRARY_DIRS} ${GLIBMM_LIBRARY_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${GTKMM_INCLUDE_DIRS} ${GLIBMM_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

# find the command to generate the custom resources
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

set(GRESOURCE_C   ui.gresource.c)
set(GRESOURCE_H   ui.gresource.h)
set(GRESOURCE_XML ui.gresource.xml)
set(GRESOURCE_XML_IN ui.gresource.xml.in)
set(OLD ${CMAKE_CURRENT_SOURCE_DIR}/${GRESOURCE_XML_IN})
set(NEW ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_XML})

# https://stackoverflow.com/questions/63664809/use-list-as-dependencies-on-add-custom-command
if(NOT EXISTS ${NEW} OR (${OLD} IS_NEWER_THAN ${NEW}))
	configure_file(${GRESOURCE_XML_IN} ${GRESOURCE_XML})
	execute_process(
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMAND ${GLIB_COMPILE_RESOURCES} --generate-dependencies ${GRESOURCE_XML}
		OUTPUT_VARIABLE GRESOURCE_DEPENDENCIES
	)

	# OUTPUT_VARIABLE is not a list but a single string value with newlines
	# Convert it to a list and pop out the last newline character
	string(REPLACE "\n" ";" GRESOURCE_DEPENDENCIES ${GRESOURCE_DEPENDENCIES})
	list(POP_BACK GRESOURCE_DEPENDENCIES)
endif()

# set up the command to generate the custom resources
add_custom_command(
	OUTPUT ${GRESOURCE_C}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND ${GLIB_COMPILE_RESOURCES}
	ARGS
		--generate-source
		--target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
		${NEW}
	VERBATIM
	MAIN_DEPENDENCY ${NEW}
	DEPENDS ${GRESOURCE_DEPENDENCIES}
)

add_custom_command(
	OUTPUT ${GRESOURCE_H}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND ${GLIB_COMPILE_RESOURCES}
	ARGS
		--generate-header
		--target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_H}
		${NEW}
	VERBATIM
	MAIN_DEPENDENCY ${NEW}
	DEPENDS ${GRESOURCE_DEPENDENCIES}
)
# create a custom target for the generated ui resources
add_custom_target(
	ui-resource
	DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
	${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_H}
)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} )
add_library(resources SHARED ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C} ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_H})

# Tell CMAKE that that resource c file is generated
set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
	PROPERTIES GENERATED TRUE
)
set_source_files_properties(
	${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_H}
	PROPERTIES GENERATED TRUE
)

# also make a static library for the unit tests to link to
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})


configure_file(reach.glade . COPYONLY)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES} ${GLIBMM_LIBRARIES} resources vc config++)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib ${GTKMM_LIBRARIES} vc config++)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_11)
