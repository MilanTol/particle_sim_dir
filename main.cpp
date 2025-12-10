#include <iostream>
#include <SFML/Graphics.hpp>

#include "renderer.h"
#include "solver.h"


int main() {
    //declare window size
    constexpr int32_t window_width = 840;
    constexpr int32_t window_height = 840;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "name_for_simulation",
                                sf::Style::Default, settings);

    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);

    Renderer renderer(window);


    Solver solver;
    solver.set_boundary((float)window_height, (float)window_width, 0., 0.);
    Particle& particle = solver.add_particle({420.0, 420.0}, 10.0);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        solver.update();
        window.clear(sf::Color::White);
        renderer.render(solver);
        // show the rendered frame
        window.display();
    }

    return 0;
}