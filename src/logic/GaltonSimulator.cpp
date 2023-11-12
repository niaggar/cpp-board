#include "GaltonSimulator.h"
#include "Collider.h"
#include "../models/Ball.h"
#include "../models/ColliderProps.h"




GaltonSimulator::GaltonSimulator(GaltonProps props, SimulationProps simProps) {
    this->galtonProps = props;
    this->simulationProps = simProps;
}

GaltonSimulator::~GaltonSimulator() {

}

void GaltonSimulator::update(const float dt) {

}

void GaltonSimulator::reset() {

}

void GaltonSimulator::addObstacle(const Vect& position, const BallProps& props) {
    Ball* ball = new Ball(props);
    ball->setPosition(position);

    this->obstacles.push_back(ball);
}

void GaltonSimulator::updateObstacle(const int index, const Vect& position, const BallProps& props) {
    Ball* ball = this->obstacles[index];
    ball->setPosition(position);
    ball->props = props;
}

void GaltonSimulator::addBall(const Vect& position, const BallProps& props) {
    Ball* ball = new Ball(props);
    ball->setPosition(position);

    this->balls.push_back(ball);
}

void GaltonSimulator::applyForces() {
    auto size = this->balls.size();
    for (int i = 0; i < size; i++) {
        Ball* ball = this->balls[i];
        ball->applyForce(this->simulationProps.gravity * ball->props.mass);
    }
}

void GaltonSimulator::updateBalls(const float dt) {
    auto size = this->balls.size();
    for (int i = 0; i < size; i++) {
        Ball* ball = this->balls[i];
        ball->updatePosition(dt);
        ball->updateVelocity(dt);
    }
}

void GaltonSimulator::validateCollisions() {
    auto ballsSize = this->balls.size();
    auto obstaclesSize = this->obstacles.size();

    for (int i = 0; i < ballsSize; i++) {
        Ball* ball = this->balls[i];

        for (int j = i + 1; j < ballsSize; j++) {
            Ball* otherBall = this->balls[j];
            ColliderProps* haveCollision = Collider::isColliding(*ball, *otherBall);

            if (haveCollision != nullptr) {
                Collider::resolveCollision(*haveCollision);
                Collider::separateBodies(*haveCollision);
            }
        }

        for (int j = 0; j < obstaclesSize; j++) {
            Ball* obstacle = this->obstacles[j];
            ColliderProps* haveCollision = Collider::isColliding(*ball, *obstacle);

            if (haveCollision != nullptr) {
                Collider::resolveCollision(*haveCollision);
                Collider::separateBodies(*haveCollision);
            }
        }
    }
}

void GaltonSimulator::validateConstraints() {

}
