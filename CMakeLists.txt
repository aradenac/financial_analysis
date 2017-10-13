cmake_minimum_required(VERSION 3.7)

set(PROJECT "faf")

set(EXEC "faftest")

include_directories("include")
set(CMAKE_BUILD_TYPE Debug)
file(GLOB sources *.cpp src/*.cpp)
file(GLOB includes "include/*.h")

find_package(nlohmann_json)

add_library(${PROJECT} SHARED ${sources} ${includes})

add_executable(${EXEC} ${sources})

target_link_libraries(${EXEC}  pthread curlpp curl   )

install (TARGETS ${PROJECT} DESTINATION bin)
install (FILES ${includes}
         DESTINATION include/${PROJECT})


