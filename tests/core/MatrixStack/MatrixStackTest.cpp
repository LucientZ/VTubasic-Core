#include <MatrixStack.h>
#include "TestMacros.h"

using namespace sf::Glsl;

void testMatrixStackInitializes() {
    MatrixStack stack;
    
    Mat3 identityMatrix = sf::Transform(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    const Mat3 topMatrix = stack.topMatrix();

    ASSERT(topMatrix.array == identityMatrix.array);
}
TEST_CASE(testMatrixStackInitializes);

void testMatrixStackCannotBeEmpty() {
    MatrixStack stack;
    ASSERT_THROWS(stack.popMatrix());
}
TEST_CASE(testMatrixStackCannotBeEmpty);

int main(){
    for (auto test: getTestFunctions()) {
        test();
    }
    return 0;
}