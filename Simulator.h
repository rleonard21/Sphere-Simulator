//
// Created by robert on 6/25/20.
//

#ifndef SPHERE_SIM_SIMULATOR_H
#define SPHERE_SIM_SIMULATOR_H

#include "Sphere.h"
#include "Vector.h"
#include <vector>


const double gravity = -9.81;
const double airDensity = 1.225;


// EFFECTS: struct for passing parameters to simulator constructor
struct SimulationParameters {
    Sphere projectile;

    Vector initialVelocity;
    Vector initialPosition;
    Vector initialWind;
    Vector initialAngularVelocity;

    double deltaT;
    double tMax;
};


// EFFECTS: struct for saving data from simulation
struct SimulationData {
    Vector position;
    Vector velocity;
    Vector force;

    double time = 0;
};


class Simulator {
private:
    std::vector<SimulationData> results;

    SimulationParameters parameters;
    SimulationData stepData;
    Vector weight;


    // EFFECTS: computes force due to gravitational acceleration
    Vector computeWeight() const;


    // EFFECTS: computes force due to the magnus effect (spin)
    Vector computeMagnus() const;


    // EFFECTS: helper to compute the air resistance magnitude
    double computeAirResistanceMagnitude() const;


    // EFFECTS: computes force due to air resistance
    Vector computeAirResistance() const;


    // EFFECTS: computes the net force on the projectile
    Vector computeNetForce() const;


    // EFFECTS: computes the new velocity for the given time step
    void updateVelocity();


    // EFFECTS: computes the new position for the given time step
    void updatePosition();


    // EFFECTS: saves the results of the simulation step
    void saveStepResults();


public:
    // EFFECTS: constructor
    explicit Simulator(SimulationParameters _param) : parameters(_param) {
        this->weight = Vector(0, this->parameters.projectile.mass * gravity, 0);
        this->stepData.position = this->parameters.initialPosition;
        this->stepData.velocity = this->parameters.initialVelocity;

        auto maxDatapoints = static_cast<unsigned long>(this->parameters.tMax / this->parameters.deltaT);
        this->results.reserve(maxDatapoints);
    }


    // EFFECTS: runs the simulation
    void solve();


    // EFFECTS: prints the summary to stdout
    void printResultSummary();


    // EFFECTS: prints the saved data to stdout
    void printResultData() const;


    // EFFECTS: saves data to CSV
    void printCSV() const;
};


#endif //SPHERE_SIM_SIMULATOR_H
