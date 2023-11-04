#include "types.h"
#include <cmath>


float Vect::norm() {
    return std::sqrt(this->X * this->X + this->Y * this->Y);
}

float Vect::norm2() {
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

bool Bounds::isIn(const Vect &v) {
    if (v.X < this->pA.X || v.X > this->pB.X) {
        return false;
    }
    if (v.Y < this->pA.Y || v.Y > this->pB.Y) {
        return false;
    }
    return true;
}

bool Bounds::isLeft(const Vect &v) {
    return v.X < this->pA.X;
}

bool Bounds::isRight(const Vect &v) {
    return v.X > this->pB.X;
}

bool Bounds::isTop(const Vect &v) {
    return v.Y > this->pB.Y;
}

bool Bounds::isBottom(const Vect &v) {
    return v.Y < this->pA.Y;
}
