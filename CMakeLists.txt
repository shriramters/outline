cmake_minimum_required(VERSION 3.26.4)

project(outline)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(external/skity)
add_subdirectory(external/spdlog)

set(EXAMPLE_DEFAULT_FONT "${CMAKE_CURRENT_SOURCE_DIR}/assets/OpenSans/OpenSans-VariableFont_wdth,wght.ttf")

# to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/include/app_config.hpp.in"
    "${PROJECT_BINARY_DIR}/include/app_config.hpp"
)

# Find Vulkan
find_package(Vulkan REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp src/vk_app.cpp src/example.cpp)

target_link_libraries(${PROJECT_NAME} skity Vulkan::Vulkan spdlog::spdlog glfw)

# include directories (must be after add_executable)
target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}/include/"
    "${PROJECT_SOURCE_DIR}/include/"
)