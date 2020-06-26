//
// Created by robert on 6/25/20.
//

#include "Vector.h"

#include <algorithm>
#include <cmath>


// EFFECTS: returns a new vector that is the negative of this vector
Vector Vector::negate() const {
    return Vector(-this->x, -this->y, -this->z);
}


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
bool Vector::operator==(const Vector &rhs) const {
    return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
}


// EFFECTS: element-wise vector addition and assignment
Vector &Vector::operator+=(const Vector &rhs) {
    *this = *this + rhs;
    return *this;
}


// EFFECTS: element-wise vector/scalar addition and assignment
Vector &Vector::operator+=(double scalar) {
    *this = *this + scalar;
    return *this;
}


// EFFECTS: adds two vectors and returns a new vector
Vector operator+(const Vector &lhs, const Vector &rhs) {
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}


// EFFECTS: subtracts two vectors and returns a new vector
Vector operator-(const Vector &lhs, const Vector &rhs) {
    return Vector(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}


// EFFECTS: element-wise multiplies two vectors and returns a new vector
Vector operator*(const Vector &lhs, const Vector &rhs) {
    return Vector(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}


// EFFECTS: element-wise divides two vectors and returns a new vector
Vector operator/(const Vector &lhs, const Vector &rhs) {
    return Vector(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}
