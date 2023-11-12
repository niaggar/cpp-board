#pragma once


struct Vect {
    float X, Y;

    float norm() const;
    float norm2() const;
    Vect operator+(const Vect& v) const;
    Vect operator-(const Vect& v) const;
    Vect operator*(float scalar) const;
    Vect operator/(float scalar) const;
};

struct Bounds {
    Vect pA, pB;

    bool isInside(const Vect& v, float radius) const;
    bool isLeft(const Vect& v, float radius) const;
    bool isRight(const Vect& v, float radius) const;
    bool isTop(const Vect& v, float radius) const;
    bool isBottom(const Vect &v, float radius) const;

    float bottom() const;
    float top() const;
    float left() const;
    float right() const;
};

struct MinMax {
    float min, max;
};
