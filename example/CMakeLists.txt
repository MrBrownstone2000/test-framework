cmake_minimum_required(VERSION 3.29)
project(example_tests)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE UnitTests)
