cmake_minimum_required(VERSION 3.10)

project(PyVector)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 11)

# --- PART A: THE DOWNLOADER (FetchContent) ---
# We use this instead of finding it on the system.

include(FetchContent)

# 1. Declare where to get 'fmt'
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        10.2.1  # The version we want
)



# 2. Download and prepare it
FetchContent_MakeAvailable(fmt)


find_package(Python3 COMPONENTS Interpreter Development REQUIRED)


# Standard pybind11 lookup (since you have it via pip)
execute_process(
    COMMAND "${Python3_EXECUTABLE}" -c "import pybind11; print(pybind11.get_cmake_dir())"
    OUTPUT_VARIABLE pybind11_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

list(APPEND CMAKE_PREFIX_PATH "${pybind11_DIR}")
find_package(pybind11 REQUIRED)

# --- PART C: THE BUILD ---
# Create the module
pybind11_add_module(py_vector py_vector.cpp)

# --- PART D: THE LINKING ---
# Connect 'fmt' to our module so we can use fmt::print
target_link_libraries(py_vector PRIVATE fmt::fmt)

install(TARGETS py_vector DESTINATION .)
