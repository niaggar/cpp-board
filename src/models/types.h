#pragma once


struct Vect {
    float X, Y;

    float norm();
    float norm2();
    Vect operator+(const Vect &v) const;
    Vect operator-(const Vect &v) const;
    Vect operator*(float scalar) const;
    Vect operator/(float scalar) const;
};

struct Bounds {
    Vect pA, pB;

    bool isIn(const Vect &v);
    bool isLeft(const Vect &v);
    bool isRight(const Vect &v);
    bool isTop(const Vect &v);
    bool isBottom(const Vect &v);
};
