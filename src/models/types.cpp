#include "types.h"
#include <cmath>


float Vect::norm() const {
    return std::sqrt(this->X * this->X + this->Y * this->Y);
}

float Vect::norm2() const {
    return this->X * this->X + this->Y * this->Y;
}

Vect Vect::operator+(const Vect& v) const {
    return {this->X + v.X, this->Y + v.Y};
}

Vect Vect::operator-(const Vect& v) const {
    return {this->X - v.X, this->Y - v.Y};
}

Vect Vect::operator*(float scalar) const {
    return {this->X * scalar, this->Y * scalar};
}

Vect Vect::operator/(float scalar) const {
    return {this->X / scalar, this->Y / scalar};
}

bool Bounds::isInside(const Vect& v, float radius) const {
    if (v.X - radius < this->pA.X) return false;
    if (v.X + radius > this->pB.X) return false;
    if (v.Y - radius < this->pA.Y) return false;
    if (v.Y + radius > this->pB.Y) return false;

    return true;
}

bool Bounds::isLeft(const Vect& v, float radius) const {
    return v.X - radius < this->pA.X;
}

bool Bounds::isRight(const Vect& v, float radius) const {
    return v.X + radius > this->pB.X;
}

bool Bounds::isTop(const Vect& v, float radius) const {
    return v.Y + radius > this->pB.Y;
}

bool Bounds::isBottom(const Vect& v, float radius) const {
    return v.Y - radius < this->pA.Y;
}

float Bounds::bottom() const {
    return std::min(this->pA.Y, this->pB.Y);
}

float Bounds::top() const {
    return std::max(this->pA.Y, this->pB.Y);
}

float Bounds::left() const {
    return std::min(this->pA.X, this->pB.X);
}

float Bounds::right() const {
    return std::max(this->pA.X, this->pB.X);
}
