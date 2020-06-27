//
// Created by robert on 6/25/20.
//

#include "Simulator.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <cassert>

// EFFECTS: computes force due to gravitational acceleration
Vector Simulator::computeWeight() const {
    return this->weight;
}


// EFFECTS: computes force due to the magnus effect (spin)
Vector Simulator::computeMagnus() const {
    // https://www.grc.nasa.gov/WWW/K-12/airplane/beach.html

    double magnitude = this->parameters.projectile.liftCoefficient * (4.0 / 3.0) * 4 * pow(M_PI, 2) *
                       pow(this->parameters.projectile.radius, 3) * airDensity;

    Vector relativeVelocity = this->stepData.velocity + this->parameters.initialWind;

    Vector f1 = this->parameters.initialAngularVelocity.cross(relativeVelocity);
    return f1 * magnitude;
}


// EFFECTS: helper to compute the air resistance magnitude
double Simulator::computeAirResistanceMagnitude() const {
    double crossSectionalArea = M_PI * pow(this->parameters.projectile.radius, 2.0);

    Vector relativeVelocity = this->stepData.velocity + this->parameters.initialWind;

    // drag = 1/2 * drag coefficient (C) * area (a) * air density (rho) * v^2
    return 0.5 * this->parameters.projectile.dragCoefficient * crossSectionalArea * airDensity *
           pow(relativeVelocity.length(), 2.0);
}


// EFFECTS: computes force due to air resistance
Vector Simulator::computeAirResistance() const {
    Vector relativeVelocity = this->stepData.velocity + this->parameters.initialWind;
    Vector dragDirection = relativeVelocity.unit().negate(); // drag opposes motion

    return dragDirection * computeAirResistanceMagnitude();
}


// EFFECTS: computes the net force on the projectile
void Simulator::updateNetForce() {
    this->stepData.netForce = computeWeight();
    this->stepData.netForce += computeMagnus();
    this->stepData.netForce += computeAirResistance();
}


// EFFECTS: computes the new velocity for the given time step
void Simulator::updateVelocity() {
    Vector netAcceleration = this->stepData.netForce / this->parameters.projectile.mass; // f = m*a, a = f/m
    Vector velocityStep = netAcceleration * this->parameters.deltaT; // v = a*t

    this->stepData.velocity += velocityStep;
}


// EFFECTS: computes the new position for the given time step
void Simulator::updatePosition() {
    Vector positionStep = this->stepData.velocity * this->parameters.deltaT; // compute distance travelled in slice
    this->stepData.position += positionStep;
}


// EFFECTS: saves the results of the simulation step
void Simulator::saveStepResults() {
    this->results.push_back(this->stepData);
}


// EFFECTS: runs the simulation
void Simulator::solve() {
    while (this->stepData.time < this->parameters.tMax &&
           this->stepData.position.y > this->parameters.projectile.radius) {
        updateNetForce();
        updateVelocity();
        updatePosition();
        saveStepResults();

        this->stepData.time += this->parameters.deltaT;
    }
}


// EFFECTS: prints the summary to stdout
void Simulator::printResultSummary() const {
    std::cout << "Travel Time: " << this->stepData.time << "\n";
    std::cout << "Projectile Range: " << this->stepData.position.x * 3.2808399 << " ft\n";
}


// EFFECTS: prints the saved data to stdout
void Simulator::printResultData() const {
    std::cout << "{\n";

    for (const auto &result : this->results) {
        std::cout << "{" << result.position.x << "," << result.position.y << "},\n";
    }

    std::cout << "}\n";
}


// EFFECTS: saves data to CSV
void Simulator::printCSV(const char *filename) const {
    std::ofstream of(filename, std::ios_base::app);

    for (const auto &result : this->results) {
        of << result.position.x << ",";
    }

    of << std::endl;

    for (const auto &result : this->results) {
        of << result.position.y << ",";
    }

    of << std::endl;
    of.close();
}
