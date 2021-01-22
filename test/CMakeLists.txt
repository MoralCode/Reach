# set(BINARY ${CMAKE_PROJECT_NAME}_tst)


find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)
pkg_check_modules(GMOCK REQUIRED gmock)
pkg_check_modules(GTKMM gtkmm-3.0)
link_directories(${GTKMM_LIBRARY_DIRS})


include_directories(${GTKMM_INCLUDE_DIRS})
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES true *.h *.cpp)


set(SOURCES ${TEST_SOURCES})


include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)


add_executable(${CMAKE_PROJECT_NAME}_test ${TEST_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_test ${CMAKE_PROJECT_NAME}_lib ${GTKMM_LIBRARIES} ${GTEST_LDFLAGS} ${GMOCK_LDFLAGS})
target_compile_options(${CMAKE_PROJECT_NAME}_test PUBLIC ${GTEST_CFLAGS} ${GMOCK_CFLAGS})

include(CTest)
add_test(first_and_only_test ${CMAKE_PROJECT_NAME}_test)

