cmake_minimum_required(VERSION  3.23)

project(VTubasicCore)

add_executable(MyProgram)
# add_library(VTubasicCore)


target_sources(MyProgram
  PRIVATE
    src/main.cpp
)

