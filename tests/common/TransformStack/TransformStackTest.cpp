#include "TestMacros.h"
#include <TransformStack.h>

using vtubasic::core::TransformStack;

static const sf::Transform identityTransform = sf::Transform::Identity;

void testTransformStackInitializes() {
    TransformStack stack;

    const sf::Transform &topTransform = stack.topTransform();

    ASSERT(stack.stackSize() == 1);
    ASSERT(topTransform == identityTransform);
}
TEST_CASE(testTransformStackInitializes);

void testTransformStackCannotBeEmpty() {
    TransformStack stack;
    ASSERT_THROWS(stack.popTransform());
}
TEST_CASE(testTransformStackCannotBeEmpty);

void testTransformStackPush() {
    TransformStack stack;

    stack.pushTransform();
    const sf::Transform &topTransform = stack.topTransform();

    ASSERT(stack.stackSize() == 2);
    ASSERT(topTransform == identityTransform);
}
TEST_CASE(testTransformStackPush);

void testTransformStackPop() {
    TransformStack stack;

    const sf::Transform &topTransform = stack.topTransform();

    stack.pushTransform();
    ASSERT(stack.stackSize() == 2);
    assert(&topTransform != &stack.topTransform());

    stack.popTransform();
    assert(stack.stackSize() == 1);
    assert(&topTransform == &stack.topTransform());
}
TEST_CASE(testTransformStackPop);

int main() {
    runAllTests();
    return 0;
}