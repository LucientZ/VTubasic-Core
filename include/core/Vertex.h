#ifndef VERTEX_H
#define VERTEX_H

struct Vertex {
    float x;
    float y;
    float z;

    // Horizontal (x) position in a texture 
    float u;

    // Vertical (y) position in a texture
    float v;
};

#endif