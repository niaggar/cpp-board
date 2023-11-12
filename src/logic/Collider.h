#pragma once

#include <algorithm>
#include "../models/ColliderProps.h"
#include "../models/Ball.h"
#include "../models/types.h"
#include "../models/BallProps.h"
#include "../utils/vmath.h"


namespace Collider {
    void resolveCollision(const ColliderProps& props);
    void resolveConstraint(Ball& ball, const Bounds& bounds, float borderDamping);
    void separateBodies(const ColliderProps& props);

    ColliderProps* isColliding(const Ball& ballA, const Ball& ballB);
};
