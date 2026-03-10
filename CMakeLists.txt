cmake_minimum_required(VERSION 3.26)
project(BalancedRandomnessEngine)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES 
    "source/main.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} "source/BREngine.cpp")

# Add include directories
target_include_directories(${PROJECT_NAME}
	PUBLIC "./source")