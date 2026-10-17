#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

class MatrixStack {
public:
    MatrixStack();
    virtual ~MatrixStack();

    /**
     * @brief Adds a new identity matrix to the top of the stack
     */
    void pushMatrix();

    /**
     * @brief Pops the currently active matrix off of the stack and returns it
     *
     * @return sf::Glsl::Mat3
     */
    sf::Glsl::Mat3 popMatrix();

    /**
     * @brief Gets the amount of matrices in the stack.
     *
     * @return int
     */
    int stackSize() const;

    const sf::Glsl::Mat3 &topMatrix() const;

private:
    std::shared_ptr<std::stack<sf::Glsl::Mat3>> m_matrixStack;
};

#endif