#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

#include "Simulator.h"
#include "UnitConversion.h"


// SIMULATION: varying weight projectiles, everything else constant
void setupVaryingWeights(std::vector<Simulator> &s);


// SIMULATION: varying weights, constant muzzle energy
void setupConstantEnergy(std::vector<Simulator> &s);


// SIMULATION: constant weight, varying head/tail wind
void setupVaryingWind(std::vector<Simulator> &s);


int main() {
    std::vector<Simulator> simulations;

    setupVaryingWind(simulations);

    // clear datafile
    std::ofstream out("results.dat");
    out << "";
    out.close();

    for(Simulator &s : simulations) {
        s.solve();
        s.printCSV("results.dat");
    }

}


void setupVaryingWeights(std::vector<Simulator> &s) {
    SimulationParameters param = {
            Sphere(g_to_kg(0.20), mm_to_m(3), 0.5, 0.2),
            0.0001,
            1000,
            Vector(fps_to_ms(400), 0, 0),
            Vector(0, 1, 0),
            Vector(),
            Vector(0, 0, 250)
    };

    for(int i = 0; i < 6; i++) {
        param.projectile.mass = g_to_kg(0.2 + 0.05 * i);
        s.emplace_back(param);
    }
}


// SIMULATION: varying weights, constant muzzle energy
void setupConstantEnergy(std::vector<Simulator> &s) {
    SimulationParameters param = {
            Sphere(g_to_kg(0.20), mm_to_m(3), 0.5, 0.2),
            0.0001,
            10,
            Vector(fps_to_ms(400), 0, 0),
            Vector(0, 1, 0),
            Vector(),
            Vector(0, 0, 200)
    };

    const double energy = 1.95; // muzzle energy in joules

    for(int i = 0; i < 5; i++) {
        param.projectile.mass = g_to_kg(0.2 + 0.05 * i);
        param.initialVelocity = Vector(sqrt(2 * energy / param.projectile.mass), 0, 0);
        s.emplace_back(param);
    }
}


// SIMULATION: constant weight, varying head/tail wind
void setupVaryingWind(std::vector<Simulator> &s) {
    SimulationParameters param = {
            Sphere(g_to_kg(0.25), mm_to_m(3), 0.5, 0.2),
            0.0001,
            10,
            Vector(fps_to_ms(350), 0, 0),
            Vector(0, 1, 0),
            Vector(),
            Vector(0, 0, 200)
    };


    for(int i = -3; i <= 3; i+=6) {
        param.initialWind.x = i;
        s.emplace_back(param);
    }
}
