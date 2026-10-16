cmake_minimum_required(VERSION  3.23)

project(VTubasicCore)

add_executable(CoreTest)
add_library(VTubasicCore)

target_sources(CoreTest
    PRIVATE
        tests/core/core_test.cpp
)

target_sources(VTubasicCore
    PRIVATE
        src/modules/core/lib.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS 
            src/modules/core/include
        FILES
            src/modules/core/include/lib.h
)


target_link_libraries(CoreTest
  PRIVATE
    VTubasicCore
)