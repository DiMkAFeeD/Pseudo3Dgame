cmake_minimum_required(VERSION 3.10)
project(Pseudo3D)

set(SFML_DIR "C:/PATH/SFML-3.0.0/lib/cmake/SFML")

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window System)

set(SOURCES
    src/main.cpp
"src/Map.cpp"
"src/Player.cpp"

)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} SFML::Graphics SFML::Window SFML::System)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
