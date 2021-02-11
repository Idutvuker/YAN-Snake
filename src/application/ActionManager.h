//
// Created by nikolay on 09.02.2021.
//

#ifndef YAN_SNAKE_ACTIONMANAGER_H
#define YAN_SNAKE_ACTIONMANAGER_H

#include <vector>

class ActionManager {
public:
    enum KeyState{
        RELEASED,
        JUST_PRESSED,
        PRESSED,
        JUST_RELEASED
    };

private:
    std::vector<KeyState> keyMap;
    bool shouldQuit = false;

public:
    ActionManager();

    void update();
    bool isShouldQuit() const;

    KeyState getKeyState(SDL_Keycode key) const;

    bool isPressed(SDL_Keycode key) const;

    bool isJustPressed(SDL_Keycode key) const;

};


#endif //YAN_SNAKE_ACTIONMANAGER_H
