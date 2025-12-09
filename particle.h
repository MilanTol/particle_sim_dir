#pragma once

#include <SFML/Graphics.hpp>

struct Particle
{
    sf::Vector2f position;
    sf::Vector2f position_last;
    sf::Vector2f acceleration;
    float radius = 10.0f;

    Particle() = default;
    Particle(sf::Vector2f position_, float radius_)
        : position{position_}
        , position_last{position_}
        , acceleration{0.0f, 0.0f}
        , radius{radius_}
    {}

    void update (float dt){
        sf::Vector2f displacement = position - position_last;
        position_last = position;
        position = position + displacement + acceleration * (dt*dt);
        acceleration = {};
    }

    void accelerate (sf::Vector2f a){
        acceleration += a;
    }

    void set_velocity (sf::Vector2f v, float dt){
        position_last = position - (v*dt);
    }
    
    void add_velocity (sf::Vector2f v, float dt){
        position_last -= v*dt;
    }

    sf::Vector2f get_velocity (float dt){
        return (position - position) * dt;
    }
};
