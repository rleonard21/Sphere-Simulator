//
// Created by robert on 6/25/20.
//

#ifndef SPHERE_SIM_VECTOR_H
#define SPHERE_SIM_VECTOR_H


class Vector {
private:
    double x;
    double y;
    double z;

public:
    explicit Vector(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}

    

    bool operator==(const Vector &other) const;
};


#endif //SPHERE_SIM_VECTOR_H
