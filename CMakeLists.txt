cmake_minimum_required(VERSION 3.13.4)

project(2d-game)
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
  PUBLIC
  src/main.cpp
  )
