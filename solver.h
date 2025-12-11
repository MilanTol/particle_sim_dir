#pragma once

#include <SFML/Graphics.hpp>

#include "particle.h"

class System {

private:
    
    //store particles in vector
    std::vector<Particle> particles;
    
    //system parameters
    float time_step = 1/60;
    float system_width;
    float system_height;

public: 
    
    //add a particle to current particles
    void add_particle(sf::Vector2f position, sf::Vector2f velocity){
        Particle temp_particle = Particle(position, velocity);
        particles.push_back(temp_particle);
    }

    void update(){
        update_particles();
    }
    
    void set_system_size(float width, float height){
        system_width = width;
        system_height = height;
    }


private: //private functions

    void update_particles(){
        for (int i; i < particles.size(); i++){
            particles[i].update(time_step);
        }
    }

    void resolve_boundary(){
        for (int i; i < particles.size(); i++){

        }
    }


};
