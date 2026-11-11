#pragma once

#ifndef FOW_MESH_CPP
#define FOW_MESH_CPP
#include "mesh.h"
#include "../engine/util.h"

Mesh::Mesh() {
    gen();
}

Mesh::Mesh(MeshType shape) {
    gen();
    switch (shape) {
    case MeshType::PLANE:
        load2Dvertices(Shape::PLANE_VERTICES, Color::Green);
        this->indices = Shape::PLANE_INDICES;
        break;
    case MeshType::CUBE:
        load3Dvertices(Shape::CUBE_VERTICES, Color::Green);
        this->indices = Shape::CUBE_INDICES;
        break;
    case MeshType::PYRAMID:
        load3Dvertices(Shape::CUBE_VERTICES, Color::Green);
        this->indices = Shape::CUBE_INDICES;
        break;
    }
}

void Mesh::gen() {
    vao.gen();
    vbo.gen();
    ebo.gen();
}

void Mesh::bind(GLenum target1, GLenum target2) {
    vao.bind();
    vbo.bind(target1);
    ebo.bind(target2);
}

void Mesh::color(glm::vec4 color) {
    for (Vertex &i : vertices) {
        i.color = color;
    }
}

std::vector<Vertex> Mesh::load2Dvertices(std::vector<glm::vec3> positions, glm::vec4 color) {
    std::vector<Vertex> allVertices;
    for (glm::vec3 position : positions) {
        //push 2 new vertex per position with normal as x then y then z
        allVertices.push_back(Vertex(position, color, glm::vec3(position[0], 0, 0)));
        allVertices.push_back(Vertex(position, color, glm::vec3(0, position[1], 0)));
    }
    return allVertices;
}

std::vector<Vertex> Mesh::load3Dvertices(std::vector<glm::vec3> positions, glm::vec4 color) {
    std::vector<Vertex> allVertices;
    for (glm::vec3 position: positions) {
        //push 3 new vertex per position with normal as x then y then z
        allVertices.push_back(Vertex(position, color, glm::vec3(position[0], 0, 0)));
        allVertices.push_back(Vertex(position, color, glm::vec3(0, position[1], 0)));
        allVertices.push_back(Vertex(position, color, glm::vec3(0, 0, position[2])));
    }
    return allVertices;
}

void Mesh::uv(glm::vec2 uv) {
    for (Vertex &i : vertices) {
        i.uv = uv;
    }
}

void Mesh::buffer() {
    glBufferData(GL_ARRAY_BUFFER,
        vertices.size() * sizeof(Vertex),
        vertices.data(),
        GL_STATIC_DRAW);

    ebo.bind(GL_ELEMENT_ARRAY_BUFFER);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
        indices.size() * sizeof(uint32_t),
        indices.data(),
        GL_STATIC_DRAW);
}

void Mesh::attrib() {
    // position (vec3)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    // color (vec4)
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    // normal (vec3)
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(2);

    // uv (vec2)
    glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glEnableVertexAttribArray(3);
}

void Mesh::draw(GLenum mode) {
    glBindVertexArray(vao.handle);

    if (indices.size() > 0) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.handle);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
    } else
        glDrawArrays(mode, 0, static_cast<GLsizei>(vertices.size()));
}
#endif