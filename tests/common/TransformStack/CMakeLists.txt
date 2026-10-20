add_executable(TransformStackTest TransformStackTest.cpp)

target_link_libraries(TransformStackTest
    PRIVATE
        VTubasicCore
        SFML::Graphics
)

add_test(TransformStackTesting TransformStackTest)