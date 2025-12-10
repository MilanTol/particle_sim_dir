#pragma once

#include "particle.h"

class Solver {

public: 
    Solver() = default;

    void update(){
        apply_gravity();
        update_particles();
    }

private:
    float step_dt = 1/60;
    std::vector<Particle> particles;
    sf::Vector2f gravity = {0.0f, -1000.0f};

    void apply_gravity() {
        for (auto &particle_ : particles)
            particle_.accelerate(gravity);
    }

    void update_particles() {
        for (auto &particle_ : particles)
            particle_.accelerate(gravity);
    }
};