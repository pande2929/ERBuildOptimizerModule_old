cmake_minimum_required(VERSION 3.4)
project(ER_Build_Optimizer_Module)

add_subdirectory(pybind11)
pybind11_add_module(ERBuildOptimizer module.cpp)