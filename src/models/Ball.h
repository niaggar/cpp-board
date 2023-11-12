#pragma once

#include "BallProps.h"
#include "types.h"


class Ball {
public:
    BallProps props{};
    Vect position{};
    Vect velocity{};
    Vect force{};

    Ball(BallProps props);

    void setPosition(Vect pos);
    void setVelocity(Vect vel);
    void setForce(Vect f);

    void applyForce(const Vect& f);

    void updatePosition(float dt);
    void updateVelocity(float dt);
};
