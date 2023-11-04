#pragma once

#include "../models/types.h"


namespace vmath {
    const float PI = 3.14159265358979323846f;
    const float RAD_DEG = 180.0f / PI;
    const float DEG_RAD = PI / 180.0f;

    float distance(const Vect &a, const Vect &b);
    float distance2(const Vect &a, const Vect &b);
    float dot(const Vect &a, const Vect &b);
    float cross(const Vect &a, const Vect &b);
    Vect normalize(const Vect &a);

    int getRandom(int min, int max);
    float getRandom(float min, float max);
    float getRandomOnPoint(float middle, float delta);
}
