cmake_minimum_required(VERSION 3.18.2)
project(remote)

set(CMAKE_CXX_STANDARD 14)

add_executable(remote main.cpp ShareMemory.cpp ShareMemory.h pkg/threadPool/KThreadPool.cpp pkg/threadPool/KThreadPool.h)