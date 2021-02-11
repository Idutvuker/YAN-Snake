//
// Created by nikolay on 08.02.2021.
//

#include <iostream>

#include "Application.h"
#include "../constants.h"

Application::Application(const std::string &title, int width, int height) :
        window(title, width, height),
        renderer(window),
        running(false) {}

void Application::run() {
    running = true;

    while (running) {
        actionManager.update();
        if (actionManager.isShouldQuit())
            running = false;

        update(actionManager);

        renderer.setDrawColor(Constants::Colors::BACKGROUND);
        renderer.clear();

        draw(renderer);

        renderer.present();

        SDL_Delay(Constants::App::UPDATE_DELAY);
    }
}
