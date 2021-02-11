//
// Created by nikolay on 09.02.2021.
//

#include <SDL.h>
#include "ActionManager.h"

void ActionManager::update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            shouldQuit = true;
    }

    const Uint8 *keyState = SDL_GetKeyboardState(nullptr);

    for (int i = 0; i < keyMap.size(); i++) {
        KeyState newState = keyMap[i];

        if (keyState[i]) {
            switch (keyMap[i]) {
                case JUST_PRESSED:
                    newState = PRESSED;
                    break;
                case RELEASED:
                case JUST_RELEASED:
                    newState = JUST_PRESSED;
                    break;
                default:
                    break;
            }
        }
        else {
            switch (keyMap[i]) {
                case JUST_PRESSED:
                case PRESSED:
                    newState = JUST_RELEASED;
                    break;
                case JUST_RELEASED:
                    newState = RELEASED;
                    break;
                default:
                    break;
            }
        }

        keyMap[i] = newState;
    }
}

ActionManager::KeyState ActionManager::getKeyState(SDL_Keycode key) const {
    if (0 <= key && key < keyMap.size())
        return keyMap[key];

    return RELEASED;
}

bool ActionManager::isShouldQuit() const {
    return shouldQuit;
}

ActionManager::ActionManager() {
    int numkeys;
    SDL_GetKeyboardState(&numkeys);

    keyMap.resize(numkeys, RELEASED);
}

bool ActionManager::isJustPressed(SDL_Keycode key) const {
    return getKeyState(key) == JUST_PRESSED;
}

bool ActionManager::isPressed(SDL_Keycode key) const {
    KeyState state = getKeyState(key);
    return state == JUST_PRESSED || state == PRESSED;
}
