cmake_minimum_required(VERSION 2.8)
									

project(DataFileReader)			

set(SOURCE_EXE src/DataFileReaderApp.cpp)		

set(SOURCE_LIB src/FileLine.cpp)			

add_library(fileline STATIC ${SOURCE_LIB})	
add_executable(main ${SOURCE_EXE})	

target_link_libraries(main fileline)		

