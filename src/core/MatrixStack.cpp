#include "MatrixStack.h"

using std::make_shared, std::stack;
using namespace sf::Glsl;

MatrixStack::MatrixStack() {
    m_matrixStack = make_shared<stack<Mat4>>();
    m_matrixStack->push(Mat4(sf::Transform::Identity));
}

MatrixStack::~MatrixStack() {
}

void MatrixStack::pushMatrix() {
}

void MatrixStack::popMatrix() {
}

const sf::Glsl::Mat4 &MatrixStack::topMatrix() const {
    return m_matrixStack->top();
}
