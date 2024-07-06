cmake_minimum_required(VERSION 3.16)

project(StudentManager C)

add_compile_options()

add_executable(${PROJECT_NAME}
	main.c
	GLOBAL.h
	GLOBAL.c
	NodeData.h
	NodeData.c
	Node.h
	Node.c
	LinkedList.h
	LinkedList.c
	Filter.h
	Filter.c
	Sorter.h
	Sorter.c
	Compatibility.h
)

add_executable(test
	test.c
	GLOBAL.h
	GLOBAL.c
	NodeData.h
	NodeData.c
	Node.h
	Node.c
	LinkedList.h
	LinkedList.c
)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()