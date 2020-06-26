//
// Created by robert on 6/25/20.
//

#include "Simulator.h"

// EFFECTS: computes force due to gravitational acceleration
Vector Simulator::computeWeight() const {
    return this->weight;
}


// EFFECTS: computes force due to the magnus effect (spin)
Vector Simulator::computeMagnus() const {

}


// EFFECTS: computes force due to air resistance
Vector Simulator::computeAirResistance() const {

}


// EFFECTS: computes the net force on the projectile
Vector Simulator::computeNetForce() const {
    Vector netForce;

    netForce.add(computeWeight());
    netForce.add(computeMagnus());
    netForce.add(computeAirResistance());

    return netForce;
}


// EFFECTS: computes the new velocity for the given time step
void Simulator::updateVelocity() {
    Vector netForce = computeNetForce();

    Vector netAcceleration = netForce / this->weight; // f = m*a, a = f/m
    Vector velocityStep = netAcceleration * this->parameters.deltaT; // v = a*t

    this->velocity.add(velocityStep);
}


// EFFECTS: computes the new position for the given time step
void Simulator::updatePosition() {
    Vector positionStep = this->velocity * this->parameters.deltaT; // compute distance travelled in slice
    this->position.add(positionStep);
}


// EFFECTS: saves the results of the simulation step
void Simulator::saveStepResults() {
    this->results.push_back(this->stepData);
}


// EFFECTS: runs the simulation
void Simulator::solve() {
    Vector newVelocity;
    Vector newPosition;

    double time = 0;

    while(time < this->parameters.tMax) {
        updateVelocity();
        updatePosition();
        saveStepResults();
    }
}
