#pragma once

#include "types.h"
#include "Ball.h"


struct ColliderProps {
    Vect normal;
    Ball* ballA;
    Ball* ballB;
    float overlap;
};
