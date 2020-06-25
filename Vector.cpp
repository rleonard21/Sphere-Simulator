//
// Created by robert on 6/25/20.
//

#include "Vector.h"

bool Vector::operator==(const Vector &other) const {
    return this->x == other.x && this->y == other.y && this->z == other.z;
}