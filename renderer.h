#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Renderer{  

private:
    sf::RenderTarget& target;

public:
    Renderer(sf::RenderTarget& target_)
        : target{target_} //create reference to render object
    {}

    void render(){
        target.clear(sf::Color::Black);             //Set background color to black]
        sf::CircleShape circle{1.0f};               //declare circle object
        circle.setPointCount(32);                   //Set the number of points of the circle?
        circle.setPosition({420.0f, 420.0f}); 
        circle.setScale(10.0f, 10.0f);              //scale the circle
        circle.setFillColor(sf::Color::Blue);       //set color of circle
        target.draw(circle);
    }
};
