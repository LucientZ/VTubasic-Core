#include "TestMacros.h"
#include <MatrixStack.h>

using namespace sf::Glsl;

static const Mat3 identityMatrix = sf::Transform::Identity;

void testMatrixStackInitializes() {
    MatrixStack stack;

    const Mat3 &topMatrix = stack.topMatrix();

    ASSERT(stack.stackSize() == 1);
    ASSERT(topMatrix.array == identityMatrix.array);
}
TEST_CASE(testMatrixStackInitializes);

void testMatrixStackCannotBeEmpty() {
    MatrixStack stack;
    ASSERT_THROWS(stack.popMatrix());
}
TEST_CASE(testMatrixStackCannotBeEmpty);

void testMatrixStackPush() {
    MatrixStack stack;

    stack.pushMatrix();
    const Mat3 &topMatrix = stack.topMatrix();

    ASSERT(stack.stackSize() == 2);
    ASSERT(topMatrix.array == identityMatrix.array);
}
TEST_CASE(testMatrixStackPush);

void testMatrixStackPop() {
    MatrixStack stack;

    const Mat3 &topMatrix = stack.topMatrix();

    stack.pushMatrix();
    ASSERT(stack.stackSize() == 2);
    assert(&topMatrix != &stack.topMatrix());

    stack.popMatrix();
    assert(stack.stackSize() == 1);
    assert(&topMatrix == &stack.topMatrix());
}
TEST_CASE(testMatrixStackPop);

int main() {
    runAllTests();
    return 0;
}