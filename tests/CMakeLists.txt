cmake_minimum_required(VERSION 3.6)
project(client_cpp_tests)

set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("catch")

set(SOURCE_FILES
        main.cpp
        geometrie/vecteur.cpp
        formes/cercle.cpp formes/triangle.cpp formes/polygone.cpp formes/groupe.cpp transformations/translation.cpp ../transformation/homothetie.cpp ../transformation/homothetie.h transformations/homothetie.cpp transformations/rotation.cpp formes/segment.cpp)
add_executable(client_cpp_tests ${SOURCE_FILES})
target_link_libraries(client_cpp_tests libclient_cpp)
