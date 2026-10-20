#include "TransformStack.h"

using std::make_shared, std::stack, sf::Transform;
using vtubasic::core::TransformStack;

TransformStack::TransformStack() {
    m_transformStack = make_shared<stack<Transform>>();
    m_transformStack->push(Transform::Identity);
}

TransformStack::~TransformStack() {
}

void TransformStack::pushTransform() {
    m_transformStack->push(Transform::Identity);
}

sf::Transform TransformStack::popTransform() {
    if (m_transformStack->size() <= 1) {
        throw std::out_of_range("Matrix stack cannot be empty!");
    }

    Transform transform = m_transformStack->top();
    m_transformStack->pop();
    return transform;
}

size_t TransformStack::stackSize() const {
    return m_transformStack->size();
}

const sf::Transform &TransformStack::topTransform() const {
    return m_transformStack->top();
}
