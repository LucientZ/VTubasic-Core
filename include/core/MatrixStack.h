#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

class MatrixStack {
    public:
        MatrixStack();

        /**
         * @brief Pushes currently active matrix to the top of the stack
         */
        void pushMatrix();

        /**
         * @brief Pops matrix from the top of the stack and sets the current matrix to be the one on the top
         */
        void popMatrix();
};

#endif