#include <cmath>
#include "Collider.h"


void Collider::resolveCollision(const ColliderProps& props) {
    Vect normal = props.normal;
    Ball *ballA = props.ballA;
    Ball *ballB = props.ballB;

    Vect relVel = ballB->velocity - ballA->velocity;
    float velAlongNormal = vmath::dot(relVel, normal);

    if (velAlongNormal > 0) return;

    float e = std::min(ballA->props.damping, ballB->props.damping);

    float j = -(1 + e) * velAlongNormal;
    j /= ballA->props.invMass + ballB->props.invMass;

    Vect impulse = normal * j;
    ballA->velocity = ballA->velocity - impulse * ballA->props.invMass;
    ballB->velocity = ballB->velocity + impulse * ballB->props.invMass;
}

void Collider::resolveConstraint(Ball& ball, const Bounds& bounds, float borderDamping) {
    if (bounds.isBottom(ball.position, ball.props.radius)){
        ball.position.Y = bounds.bottom() - ball.props.radius;
        ball.velocity.Y *= -borderDamping;
    }
    else if (bounds.isTop(ball.position, ball.props.radius)){
        ball.position.Y = bounds.top() + ball.props.radius;
        ball.velocity.Y *= -borderDamping;
    }

    if (bounds.isLeft(ball.position, ball.props.radius)){
        ball.position.X = bounds.left() + ball.props.radius;
        ball.velocity.X *= -borderDamping;
    }
    else if (bounds.isRight(ball.position, ball.props.radius)){
        ball.position.X = bounds.right() - ball.props.radius;
        ball.velocity.X *= -borderDamping;
    }
}

void Collider::separateBodies(const ColliderProps &props) {
    Ball *ballA = props.ballA;
    Ball *ballB = props.ballB;

    if (ballA->props.bodyType == BodyType::STATIC) {
        ballB->position = ballB->position - props.normal * props.overlap;
    }
    if (ballB->props.bodyType == BodyType::STATIC) {
        ballA->position = ballA->position + props.normal * props.overlap;
    }
    else {
        ballA->position = ballA->position + props.normal * props.overlap / 2;
        ballB->position = ballB->position - props.normal * props.overlap / 2;
    }
}

ColliderProps* Collider::isColliding(const Ball& ballA, const Ball& ballB) {
    Vect relative = ballB.position - ballA.position;
    float dist = relative.norm2();
    float radius = ballA.props.radius + ballB.props.radius;

    if (dist > radius * radius) return nullptr;

    auto *props = new ColliderProps();
    props->normal = vmath::normalize(relative);
    props->ballA = (Ball*) &ballA;
    props->ballB = (Ball*) &ballB;
    props->overlap = radius - std::sqrt(dist);

    return props;
}
