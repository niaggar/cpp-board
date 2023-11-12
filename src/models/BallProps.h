#pragma once


enum class BodyType {
    STATIC,
    DYNAMIC
};

struct BallProps {
    float mass;
    float invMass;
    float radius;
    float damping;
    BodyType bodyType;

    BallProps() = default;
    BallProps(float mass, float radius, float damping, BodyType bodyType) {
        this->mass = mass;
        this->radius = radius;
        this->damping = damping;
        this->bodyType = bodyType;
        this->invMass = 1 / mass;
    }
};
