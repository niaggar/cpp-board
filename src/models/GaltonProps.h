#pragma once

#include <string>
#include "types.h"


struct GridProps {
    float cellSize;
    int nRows, nCols;
};


struct GaltonProps {
    std::string name;
    float maxSize;
    Bounds bounds;
    GridProps gridProps;
};

struct SimulationProps {
    float timeStep;
    float maxTime;
    int subSteps;
    bool detectFloor;
    Vect gravity;
};
