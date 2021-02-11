//
// Created by nikolay on 08.02.2021.
//

#ifndef YAN_SNAKE_APPLICATION_H
#define YAN_SNAKE_APPLICATION_H

#include <string>
#include "Window.h"
#include "Renderer.h"
#include "ActionManager.h"

class Application {
protected:
    Window window;
    Renderer renderer;
    ActionManager actionManager;

    bool running;

    virtual void draw(const Renderer &renderer) = 0;
    virtual void update(const ActionManager &actionManager) = 0;

public:
    Application(const std::string &title, int width, int height);

    void run();
};


#endif //YAN_SNAKE_APPLICATION_H
