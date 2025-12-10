#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "solver.h"

class Renderer{  

private:
    sf::RenderTarget& target;

public:
    Renderer(sf::RenderTarget& target_)
        : target{target_} //create reference to render object
    {}

    void render(Solver& solver){
        target.clear(sf::Color::Black);             //Set background color to black]
        sf::CircleShape circle{1.0f};               //declare circle object
        const auto& particles = solver.get_particles();
        for (auto& particle_: particles){
            circle.setPointCount(32);
            circle.setPosition(particle_.position);
            circle.setScale(10.0f, 10.0f);
            circle.setFillColor(sf::Color::Blue);
            target.draw(circle);
        }       
    }
};
