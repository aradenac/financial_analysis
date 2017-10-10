
set(PROJECT_NAME "threading")
project(${PROJECT_NAME})

file ( GLOB source_files *.cpp)

add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} pthread)
