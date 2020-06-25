//
// Created by robert on 6/25/20.
//

#ifndef SPHERE_SIM_SPHERE_H
#define SPHERE_SIM_SPHERE_H


class Sphere {
private:
    double mass;
    double radius;
    double dragCoefficient;

public:
    explicit Sphere(double _mass = 0.20, double _radius = 0.03, double _dragCoefficient = 0.5) :
            mass(_mass), radius(_radius), dragCoefficient(_dragCoefficient) {}

};


#endif //SPHERE_SIM_SPHERE_H
