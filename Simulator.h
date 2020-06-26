//
// Created by robert on 6/25/20.
//

#ifndef SPHERE_SIM_SIMULATOR_H
#define SPHERE_SIM_SIMULATOR_H

#include "Sphere.h"

#include <vector>

class Simulator {
private:
    Sphere projectile;
    double deltaT;
    std::vector<double> data;

public:
    Simulator();

    void solve();
};


#endif //SPHERE_SIM_SIMULATOR_H
