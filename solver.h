#pragma once

#include "particle.h"

class Solver {

public: 

    Solver() = default;


    Particle& add_particle(sf::Vector2f position, float radius){
        Particle new_particle = Particle(position, radius);
        return particles.emplace_back(new_particle);
    }


    void update(){
        apply_gravity();
        update_particles(step_dt);
        apply_boundary();
    }


    std::vector<Particle>& get_particles(){
        return particles;
    }


    void set_boundary(float max_x, float max_y, float min_x, float min_y){
        upperbound_x = max_x;
        upperbound_y = max_y;
        lowerbound_x = min_x;
        lowerbound_x = min_y;
        systemlength_x = upperbound_x - lowerbound_x;
        systemlength_y = upperbound_y - lowerbound_y;
    }


    float calculate_density(sf::Vector2f sample_point){

        float density = 0.0;
        const float mass = 1.0;

        for (auto& particle_: particles){
            density += mass * particle_.influence(sample_point);
        }

        return density;
    }


private:

    std::vector<Particle> particles;            // declare particles vector
    sf::Vector2f gravity = {0.0f, 0.0f};    // set gravity strength
    float step_dt = 1.0f/60;                       // declare time_step
    

    float upperbound_x;
    float upperbound_y;
    float lowerbound_x;
    float lowerbound_y;
    float systemlength_x;
    float systemlength_y;


    void apply_gravity() {
        for (auto& particle_ : particles){
            particle_.accelerate(gravity);
        }
    }


    void update_particles(float dt) {
        for (auto& particle_ : particles){
            particle_.update(dt);
        }
    }


    void apply_boundary() {
        for (auto& particle_ : particles){
            if (particle_.position.x > upperbound_x){
                particle_.position.x = particle_.position.x - systemlength_x;
            }
            if (particle_.position.y > upperbound_y){
                particle_.position.y = particle_.position.y - systemlength_y;
            }
            if (particle_.position.x < lowerbound_x){
                particle_.position.x = particle_.position.x + systemlength_x;
            }
            if(particle_.position.y < lowerbound_y){
                particle_.position.y = particle_.position.y + systemlength_y;
            }            
        }        
    }
};