#pragma once


struct Vect {
    float X, Y;

    float norm() const;
    float norm2() const;
    Vect operator+(const Vect &v) const;
    Vect operator-(const Vect &v) const;
    Vect operator*(float scalar) const;
    Vect operator/(float scalar) const;
};

struct Bounds {
    Vect pA, pB;

    bool isIn(const Vect &v) const;
    bool isLeft(const Vect &v) const;
    bool isRight(const Vect &v) const;
    bool isTop(const Vect &v) const;
    bool isBottom(const Vect &v) const;
};
