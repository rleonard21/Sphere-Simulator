//
// Created by robert on 6/25/20.
//

#ifndef SPHERE_SIM_VECTOR_H
#define SPHERE_SIM_VECTOR_H


struct VectorAngle {
    double theta;
    double phi;
};


class Vector {
public:
    double x;
    double y;
    double z;


    // EFFECTS: constructor
    explicit Vector(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}

    // EFFECTS: returns a new vector that is the negative of this vector
    Vector negate() const;

    // EFFECTS: returns the dot product of two vectors
    double dot(const Vector &v) const;


    // EFFECTS: returns a new vector from the cross product of two vectors
    Vector cross(const Vector &v) const;


    // EFFECTS: returns the unit vector of this vector
    Vector unit() const;


    // EFFECTS: returns the length of this vector
    double length() const;


    // EFFECTS: scalar adds this vector
    Vector operator+(double scalar) const;


    // EFFECTS: scalar subtracts this vector
    Vector operator-(double scalar) const;


    // EFFECTS: scalar multiplies this vector
    Vector operator*(double scalar) const;


    // EFFECTS: scalar divides this vector
    Vector operator/(double scalar) const;


    // EFFECTS: override equality
    bool operator==(const Vector &rhs) const;


    // EFFECTS: element-wise vector addition and assignment
    Vector &operator+=(const Vector &rhs);


    // EFFECTS: element-wise vector/scalar addition and assignment
    Vector &operator+=(double scalar);

    // EFFECTS: element-wise vector-vector multiplication
//    Vector &operator*=(const Vector &rhs);

    // EFFECTS: element-wise vector-scalar multiplication
    Vector &operator*=(double scalar);
};



// EFFECTS: element-wise adds two vectors and returns a new vector
Vector operator+(const Vector &lhs, const Vector &rhs);


// EFFECTS: element-wise subtracts two vectors and returns a new vector
Vector operator-(const Vector &lhs, const Vector &rhs);


// EFFECTS: element-wise multiplies two vectors and returns a new vector
Vector operator*(const Vector &lhs, const Vector &rhs);


// EFFECTS: element-wise divides two vectors and returns a new vector
Vector operator/(const Vector &lhs, const Vector &rhs);


#endif //SPHERE_SIM_VECTOR_H
