#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

struct Particle{
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;

    void update(float dt){
        velocity += acceleration * dt;
        position += velocity * dt;
    }
};