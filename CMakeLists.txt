cmake_minimum_required(VERSION 3.22)
project(test_TaskManager
        VERSION 1.0.0
        LANGUAGES CXX)
add_subdirectory(src)
add_subdirectory(test)

target_compile_options(exec_taskmanager PUBLIC -O2 -Wall)
target_compile_features(exec_taskmanager PUBLIC cxx_std_20)
