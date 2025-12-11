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

    void render(System& system){

        target.clear(sf::Color::Black);             //Set background color to black]
        sf::CircleShape circle{1.0f};               //declare circle object
        const auto& particles = system.particles;
        
        for (int i; i < particles.size(); i++){
            circle.setPointCount(32);
            circle.setPosition(particles[i].position);
            circle.setScale(5.0, 5.0);
            circle.setFillColor(sf::Color::Blue);
            target.draw(circle);
        }       
    }
};
