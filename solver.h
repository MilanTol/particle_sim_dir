#pragma once

#include <SFML/Graphics.hpp>

#include "particle.h"

class System {

public:
    
    //store particles in vector
    std::vector<Particle> particles;
    
    //system parameters
    float time_step {1.0f/60.0f};
    float system_width;
    float system_height;

    System(float width, float height){
        system_width = width;
        system_height = height;
    }
    
    //add a particle to current particles
    void add_particle(sf::Vector2f position, sf::Vector2f velocity){
        Particle temp_particle = Particle(position, velocity);
        particles.push_back(temp_particle);
    }

    void update(){
        update_particles();
        resolve_boundary();
    }

    float get_density(sf::Vector2f sample_point){

        float density = 0;

        for (int i=0; i < particles.size(); i++){
            density += particles[i].influence(sample_point);
        }

        return density;
    }
    
private: //private functions

    void update_particles(){
        for (int i=0; i < particles.size(); i++){
            particles[i].update(time_step);
        }
    }

    void resolve_boundary() {
        for (int i=0; i < particles.size(); i++){
            if (particles[i].position.x > system_width){
                particles[i].position.x = particles[i].position.x - system_width;
            }
            if (particles[i].position.y > system_height){
                particles[i].position.y = particles[i].position.y - system_height;
            }
            if (particles[i].position.x < 0.0){
                particles[i].position.x = particles[i].position.x + system_width;
            }
            if(particles[i].position.y < 0.0){
                particles[i].position.y = particles[i].position.y + system_height;
            }            
        }        
    }

};
