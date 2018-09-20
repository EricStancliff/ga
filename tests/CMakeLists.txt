
macro(add_test testname testsource)
add_executable(${testname} ${testsource})
target_link_libraries(${testname} core window shapes)
include_directories(${testname} ${GA_INCLUDE_DIR})
install (TARGETS ${testname} DESTINATION bin)
endmacro()

add_test(newwindow newwindow.cpp)