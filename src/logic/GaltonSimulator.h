#pragma once

#include <vector>
#include "../models/types.h"
#include "../models/GaltonProps.h"
#include "../models/BallProps.h"
#include "../models/Ball.h"


class GaltonSimulator {
public:
    GaltonSimulator(GaltonProps props, SimulationProps simProps);
    ~GaltonSimulator();

    void update(float dt);
    void reset();

    void addObstacle(const Vect& position, const BallProps& size);
    void updateObstacle(int index, const Vect& position, const BallProps& size);
    void addBall(const Vect& position, const BallProps& size);

private:
    GaltonProps galtonProps;
    SimulationProps simulationProps;

    std::vector<Ball*> balls;
    std::vector<Ball*> obstacles;

    void applyForces();
    void updateBalls(float dt);
    void validateCollisions();
    void validateConstraints();
};
