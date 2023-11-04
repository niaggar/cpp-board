#include "vmath.h"
#include <cmath>
#include <random>


float vmath::distance(const Vect &a, const Vect &b) {
    return std::sqrt(vmath::distance2(a, b));
}

float vmath::distance2(const Vect &a, const Vect &b) {
    return (float)pow(b.X - a.X, 2) + (float)pow(b.Y - a.Y, 2);
}

float vmath::dot(const Vect &a, const Vect &b) {
    return a.X * b.X + a.Y * b.Y;
}

float vmath::cross(const Vect &a, const Vect &b) {
    return a.X * b.Y - a.Y * b.X;
}

Vect vmath::normalize(const Vect &a) {
    float len = a.norm();
    return {a.X / len, a.Y / len};
}

int vmath::getRandom(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist_x(min, max);

    return dist_x(gen);
}

float vmath::getRandom(float min, float max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist_x(min, max);

    return dist_x(gen);
}

float vmath::getRandomOnPoint(float middle, float delta) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist_x(middle - (delta / 2.0f), middle + (delta / 2.0f));

    return dist_x(gen);
}
