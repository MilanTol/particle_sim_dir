#pragma once

#include "particle.h"

class Solver {

public: 
    Solver() = default;

private:
    float step_dt = 1/60;
    std::vector<Particle> particles;
    sf::Vector2f gravity = {0.0f, -1000.0f};
};