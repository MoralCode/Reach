# set(BINARY ${CMAKE_PROJECT_NAME}_tst)


find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)


set(SOURCES ${TEST_SOURCES})

add_executable(${CMAKE_PROJECT_NAME}_test ${TEST_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}_test ${GTEST_LDFLAGS})
target_compile_options(${CMAKE_PROJECT_NAME}_test PUBLIC ${GTEST_CFLAGS})

include(CTest)
add_test(first_and_only_test ${CMAKE_PROJECT_NAME}_test)



# file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

# set(SOURCES ${TEST_SOURCES})

# add_executable(${BINARY} ${TEST_SOURCES})

# add_test(NAME ${BINARY} COMMAND ${BINARY})

# target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)