#include "engine.h"

Engine::Engine(int horsepower) : horsepower_(horsepower) {}

int Engine::getHorsepower() const {
    return horsepower_;
}