#include <iostream>

#include "Simulator.h"
#include "UnitConversion.h"

int main() {
    SimulationParameters param = {
            Sphere(g_to_kg(0.20), mm_to_m(3), 0.5, 0.2),
            Vector(fps_to_ms(400), 0, 0),
            Vector(0, 1, 0),
            Vector(),
            Vector(0, 0, 180),
            0.0001,
            1000
    };

    Simulator s1(param);
    s1.solve();
    s1.printCSV("1.csv");
    s1.printResultSummary();

    param.projectile.mass = g_to_kg(0.3);
    Simulator s2(param);
    s2.solve();
    s2.printCSV("2.csv");
    s2.printResultSummary();

    param.projectile.mass = g_to_kg(0.4);
    Simulator s3(param);
    s3.solve();
    s3.printCSV("3.csv");
    s3.printResultSummary();
}
