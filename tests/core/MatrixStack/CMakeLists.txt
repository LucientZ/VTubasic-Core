add_executable(MatrixStackTest MatrixStackTest.cpp)

target_link_libraries(MatrixStackTest
    PRIVATE
        VTubasicCore
        SFML::Graphics
)

add_test(MatrixStackTesting MatrixStackTest)