#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

struct Particle
{
    sf::Vector2f position;
    sf::Vector2f position_last;
    sf::Vector2f acceleration;
    float radius = 1.0;
    float influence_radius = 5.0;

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

    float influence(sf::Vector2f sample_point){

        //compute distance from sample_point to position of particle
        sf::Vector2f diff = position - sample_point;
        float distance = std::sqrt(diff.x * diff.x + diff.y * diff.y);

        //compute influence value
        float value = influence_radius - distance;
        if (value < 0){
            return 0;
        }

        float volume = M_PI * std::pow(influence_radius, 8) / 4;
        return value * value * value / volume;
    }
};
