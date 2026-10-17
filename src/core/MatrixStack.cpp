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
    m_matrixStack->push(Mat3(sf::Transform::Identity));
}

sf::Glsl::Mat3 MatrixStack::popMatrix() {
    if (m_matrixStack->size() <= 1) {
        throw std::out_of_range("Matrix stack cannot be empty!");
    }

    Mat3 matrix = m_matrixStack->top();
    m_matrixStack->pop();
    return matrix;
}

int MatrixStack::stackSize() const {
    return m_matrixStack->size();
}

const sf::Glsl::Mat3 &MatrixStack::topMatrix() const {
    return m_matrixStack->top();
}
