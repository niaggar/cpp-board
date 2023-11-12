#include "Ball.h"


Ball::Ball(BallProps props) {
    this->props = props;
    this->position = {0.0f, 0.0f};
    this->velocity = {0.0f, 0.0f};
    this->force = {0.0f, 0.0f};
}

void Ball::setPosition(Vect pos) {
    this->position = pos;
}

void Ball::setVelocity(Vect vel) {
    this->velocity = vel;
}

void Ball::setForce(Vect f) {
    this->force = f;
}

void Ball::applyForce(const Vect& f) {
    this->force = this->force + f;
}

void Ball::updatePosition(float dt) {
    this->position = this->position + (this->velocity * dt);
}

void Ball::updateVelocity(float dt) {
    this->velocity = this->velocity + (this->force * this->props.invMass * dt);
}
