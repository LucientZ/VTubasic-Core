cmake_minimum_required(VERSION 3.24)

project(VTubasicCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)
add_executable(CoreTest)
add_library(VTubasicCore)

# SFML Setup
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build static libraries" FORCE)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG        "3.1.0"
    GIT_SHALLOW    ON
)
FetchContent_MakeAvailable(SFML)

# ===== Core Library Setup ===== 

target_sources(VTubasicCore
    PRIVATE
        src/core/lib.cpp
        src/core/render.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS 
            include/core
        FILES
            include/core/lib.h
            include/core/render.h
)

target_link_libraries(VTubasicCore 
    PRIVATE
        SFML::Graphics
)

# ===== Tests ===== 

target_sources(CoreTest
    PRIVATE
        tests/core/core_test.cpp
)

target_link_libraries(CoreTest
  PRIVATE
    VTubasicCore
)

add_test(NAME CoreLibSmokeTest COMMAND CoreTest)
