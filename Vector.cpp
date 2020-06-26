//
// Created by robert on 6/25/20.
//

#include "Vector.h"

#include <algorithm>
#include <cmath>


// EFFECTS: returns the dot product of two vectors
double Vector::dot(const Vector &v) const {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}


// EFFECTS: returns a new vector from the cross product of two vectors
Vector Vector::cross(const Vector &v) const {
    return Vector(
            this->y * v.z - this->z * v.y,
            this->z * v.x - this->x * v.z,
            this->x * v.y - this->y * v.x
    );
}


// EFFECTS: returns the unit vector of this vector
Vector Vector::unit() const {
    return *this / this->length();
}


// EFFECTS: returns the length of this vector
double Vector::length() const {
    return sqrt(this->dot(*this));
}


// EFFECTS: scalar adds this vector
Vector Vector::operator+(double scalar) const {
    return Vector(this->x + scalar, this->y + scalar, this->z + scalar);
}


// EFFECTS: scalar subtracts this vector
Vector Vector::operator-(double scalar) const {
    return Vector(this->x - scalar, this->y - scalar, this->z - scalar);
}


// EFFECTS: scalar multiplies this vector
Vector Vector::operator*(double scalar) const {
    return Vector(this->x * scalar, this->y * scalar, this->z * scalar);
}


// EFFECTS: scalar divides this vector
Vector Vector::operator/(double scalar) const {
    return Vector(this->x / scalar, this->y / scalar, this->z / scalar);
}


// EFFECTS: override equality
bool Vector::operator==(const Vector &other) const {
    return this->x == other.x && this->y == other.y && this->z == other.z;
}


// EFFECTS: adds two vectors and returns a new vector
Vector operator+(Vector lhs, const Vector &rhs) {
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}


// EFFECTS: subtracts two vectors and returns a new vector
Vector operator-(Vector lhs, const Vector &rhs) {
    return Vector(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}


// EFFECTS: element-wise multiplies two vectors and returns a new vector
Vector operator*(Vector lhs, const Vector &rhs) {
    return Vector(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}


// EFFECTS: element-wise divides two vectors and returns a new vector
Vector operator/(Vector lhs, const Vector &rhs) {
    return Vector(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}
