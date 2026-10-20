#include "TransformStack.h"

using std::make_shared, std::stack;
using namespace sf::Glsl;
using vtubasic::core::TransformStack;

TransformStack::TransformStack() {
    m_transformStack = make_shared<stack<sf::Transform>>();
    m_transformStack->push(sf::Transform::Identity);
}

TransformStack::~TransformStack() {
}

void TransformStack::pushTransform() {
    m_transformStack->push(sf::Transform::Identity);
}

sf::Glsl::Mat3 TransformStack::popTransform() {
    if (m_transformStack->size() <= 1) {
        throw std::out_of_range("Matrix stack cannot be empty!");
    }

    Mat3 matrix = m_transformStack->top();
    m_transformStack->pop();
    return matrix;
}

size_t TransformStack::stackSize() const {
    return m_transformStack->size();
}

const sf::Transform &TransformStack::topTransform() const {
    return m_transformStack->top();
}
