cmake_minimum_required(VERSION 3.16)
project(sphere_sim)

set(CMAKE_CXX_STANDARD 17)

add_executable(sphere_sim main.cpp Simulator.cpp Simulator.h Sphere.h Vector.cpp Vector.h UnitConversion.h)

add_executable(vector_test Vector.cpp Vector.h VectorTest.cpp)