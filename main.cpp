#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>
#include <chrono>

#include "renderer.h"
#include "solver.h"



int main() {
    //declare window size
    constexpr int32_t window_width = 1000;
    constexpr int32_t window_height = 1000;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "name_for_simulation",
                                sf::Style::Default, settings);

    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);

    Renderer renderer(window);

    //intialize the system
    System system(window_width, window_height);

    //generate particles at random positions
    std::mt19937_64 rng; // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);

    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);

    int number_of_particles = 1000;
    for (int i=0; i<number_of_particles; i++){
        double rand1 = unif(rng);
        double rand2 = unif(rng);
        double rand3 = unif(rng);
        double rand4 = unif(rng);

        float rand_x = rand1 * window_width;
        float rand_y = rand2 * window_height;
        float rand_vx = rand3 * 10;
        float rand_vy = rand4 * 10;

        std::cout << rand_vx << std::endl;

        system.add_particle({rand_x, rand_y}, {rand_vx, rand_vy});
    }
    

    //load the renderer
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        system.update();
        window.clear(sf::Color::White);
        renderer.render(system);
        // show the rendered frame
        window.display();

        //std::cout << system.calculate_density({120.0, 420.0}) << std::endl;
    }

    return 0;
}