cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME Homework)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES
    main.cpp
    User.cpp
    Group.cpp
    UserManager.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

