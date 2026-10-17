#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

#include <stack>
#include <memory>
#include <SFML/Graphics.hpp>

class MatrixStack {
    public:
        MatrixStack();
        virtual ~MatrixStack();

        /**
         * @brief Pushes currently active matrix to the top of the stack
         */
        void pushMatrix();

        /**
         * @brief Pops matrix from the top of the stack and sets the current matrix to be the one on the top
         */
        void popMatrix();

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