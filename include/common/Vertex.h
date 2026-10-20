#ifndef VERTEX_H
#define VERTEX_H

#include <SFML/Graphics.hpp>

namespace vtubasic::core {
    /**
     * @brief Representation of a single point in 2D space.
     * This also contains a texture position for rendering 2D meshes.
     * 
     */
    struct Vertex {
        sf::Vector2<float> worldPosition;
        sf::Vector2<uint32_t> texturePosition;
    };
}


#endif