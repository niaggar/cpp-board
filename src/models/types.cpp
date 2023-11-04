#include "types.h"
#include <cmath>


float Vect::norm() const {
    return std::sqrt(this->X * this->X + this->Y * this->Y);
}

float Vect::norm2() const {
    return this->X * this->X + this->Y * this->Y;
}

Vect Vect::operator+(const Vect &v) const {
    return {this->X + v.X, this->Y + v.Y};
}

Vect Vect::operator-(const Vect &v) const {
    return {this->X - v.X, this->Y - v.Y};
}

Vect Vect::operator*(float scalar) const {
    return {this->X * scalar, this->Y * scalar};
}

Vect Vect::operator/(float scalar) const {
    return {this->X / scalar, this->Y / scalar};
}

bool Bounds::isIn(const Vect &v) const {
    if (v.X < this->pA.X || v.X > this->pB.X) {
        return false;
    }
    if (v.Y < this->pA.Y || v.Y > this->pB.Y) {
        return false;
    }
    return true;
}

bool Bounds::isLeft(const Vect &v) const {
    return v.X < this->pA.X;
}

bool Bounds::isRight(const Vect &v) const {
    return v.X > this->pB.X;
}

bool Bounds::isTop(const Vect &v) const {
    return v.Y > this->pB.Y;
}

bool Bounds::isBottom(const Vect &v) const {
    return v.Y < this->pA.Y;
}
