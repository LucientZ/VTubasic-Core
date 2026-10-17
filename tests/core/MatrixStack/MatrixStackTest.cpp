#include <MatrixStack.h>
#include "TestMacros.h"

using namespace sf::Glsl;

void testMatrixStackInitializes() {
    MatrixStack stack;
    
    Mat3 identityMatrix = sf::Transform(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f
    );

    const Mat3 topMatrix = stack.topMatrix();

    ASSERT(topMatrix.array == identityMatrix.array);
}


int main(){
    testMatrixStackInitializes();
    return 0;
}