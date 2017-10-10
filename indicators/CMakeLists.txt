project("indicators")

file(

        GLOB_RECURSE

        source_files

        src/*

)

include_directories(include/)

set (CMAKE_CXX_FLAGS "-g")

add_executable(indicators main.cpp ${source_files})
