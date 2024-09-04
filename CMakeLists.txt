cmake_minimum_required(VERSION 3.16)

project(StudentManager C)

file(GLOB_RECURSE SRC_LIST
	*.h
 	*.c
)
list(REMOVE_ITEM ${SRC_LIST} main.c test.c)

add_executable(${PROJECT_NAME} main.c ${SRC_LIST})
add_executable(test_${PROJECT_NAME} test.c ${SRC_LIST})

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()
