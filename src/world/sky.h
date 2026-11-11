#pragma once

#ifndef FOW_SKY_H
#define FOW_SKY_H

typedef struct Sky {
    float vertices[24] = {
        // positions
        -1, -1, -1,
         1, -1, -1,
         1,  1, -1,
        -1,  1, -1,
        -1, -1,  1,
         1, -1,  1,
         1,  1,  1,
        -1,  1,  1
    };

    unsigned int indices[12] = {
        // back face
        0, 1, 2,  2, 3, 0,

        // front face
        4, 5, 6,  6, 7, 4,

        // etc...
    };
} Sky;



#endif