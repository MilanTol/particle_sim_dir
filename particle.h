#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;

struct Particle{
    Vector2f position;
    Vector2f velocity;
    Vector2f acceleration;
    float influence_radius {50};
    
    Particle(Vector2f position_, Vector2f velocity_){
        position = position_;
        velocity = velocity_;
    }

    void update(float dt){
        velocity += acceleration * dt;
        position += velocity * dt;
    }

    float influence(Vector2f sample_point){
        Vector2f diff = position - sample_point;
        float distance = std::sqrt(diff.x*diff.x + diff.y*diff.y);
        return influence_kernel(distance);
    }

private:

    float influence_kernel(float distance){
        float value = influence_radius - distance;
        float volume = M_PI * std::pow(influence_radius, 5) / 10;
        return value * value * value / volume;
    }
};