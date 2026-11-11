#pragma once

#ifndef FOW_ENTITY_H
#define FOW_ENTITY_H
#include "../graphics/shader.h"
#include "../graphics/model.h"

typedef struct Entity {
    Model* model;
    //Transform location;
    //Material (optional);

    //Cast Shadows
    //Receive Shadows
    //Visibility Flags
    
    //Animator(optional);
    //RigidBody(optional);
    //Collider(optional);
    //Light(optional);
    //Camera(optional);
    //AudioSource(optional);
    //Script(optional);
    

    void init();
    void update();


} Entity;

#endif