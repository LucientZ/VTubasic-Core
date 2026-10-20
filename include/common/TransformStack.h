#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <stack>

namespace vtubasic::core {

    /**
     * @brief A transform stack allows for the creation of a transformation
     * hierarchy. Through various push and pop operations, the hierarchy can
     * be implemented via an algorithm similar to depth-first traversal.
     * 
     */
    class TransformStack {
    public:
        TransformStack();
        virtual ~TransformStack();
    
        /**
         * @brief Adds a new identity transformation to the top of the stack
         */
        void pushTransform();
    
        /**
         * @brief Pops the currently active transformation off of the stack and returns it
         *
         * @return sf::Glsl::Mat3
         */
        sf::Transform popTransform();
    
        /**
         * @brief Gets the amount of transformations in the stack.
         *
         * @return size_t
         */
        size_t stackSize() const;
    
        const sf::Transform &topTransform() const;
    
    private:
        std::shared_ptr<std::stack<sf::Transform>> m_transformStack;
    };
}


#endif