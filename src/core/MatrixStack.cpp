#include "MatrixStack.h"

using std::make_shared, std::stack;
using namespace sf::Glsl;

MatrixStack::MatrixStack() {
    m_matrixStack = make_shared<stack<Mat3>>();
    m_matrixStack->push(Mat3(sf::Transform::Identity));
}

MatrixStack::~MatrixStack() {
}

void MatrixStack::pushMatrix() {
}

void MatrixStack::popMatrix() {
}

int MatrixStack::stackSize() const {
    return m_matrixStack->size();
}

const sf::Glsl::Mat3 &MatrixStack::topMatrix() const {
    return m_matrixStack->top();
}
