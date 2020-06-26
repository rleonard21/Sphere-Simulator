//
// Created by robert on 6/25/20.
//

#ifndef SPHERE_SIM_SPHERE_H
#define SPHERE_SIM_SPHERE_H


struct Sphere {
    double mass;
    double radius;
    double dragCoefficient;
    double liftCoefficient;

    explicit Sphere(double _mass = 0.20 / 1000, double _radius = 3 / 1000, double _dragCoefficient = 0.5,
                    double _liftCoefficient = 1) :
            mass(_mass), radius(_radius), dragCoefficient(_dragCoefficient), liftCoefficient(_liftCoefficient) {}
};


#endif //SPHERE_SIM_SPHERE_H
