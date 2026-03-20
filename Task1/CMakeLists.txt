cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME Task1)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
    src/main.cpp
    src/User.cpp
    src/Group.cpp
    src/UserManager.cpp
    src/CommandProcessor.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
