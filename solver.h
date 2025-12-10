#pragma once

#include "particle.h"

class Solver {

public: 
    Solver() = default;

    void add_particle(sf::Vector2f position, float radius){
        Particle new_particle = Particle(position, radius);
        particles.emplace_back(new_particle);
    }

    void update(){
        apply_gravity();
        update_particles(step_dt);
    }

    std::vector<Particle>& get_particles(){
        return particles;
    }

private:
    std::vector<Particle> particles;            // declare particles vector
    sf::Vector2f gravity = {0.0f, -1000.0f};    // set gravity strength
    float step_dt = 1/60;                       // declare time_step
 
    void apply_gravity() {
        for (auto &particle_ : particles)
            particle_.accelerate(gravity);
    }

    void update_particles(float dt) {
        for (auto &particle_ : particles)
            particle_.update(dt);
    }
};