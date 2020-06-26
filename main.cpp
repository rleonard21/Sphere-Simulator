#include <iostream>

#include "Simulator.h"
#include "UnitConversion.h"

int main() {
    SimulationParameters param = {
            Sphere(g_to_kg(0.3), mm_to_m(3), 0.5),
            Vector(fps_to_ms(400), fps_to_ms(100), 0),
            Vector(0, 1, 0),
            Vector(),
            Vector(0, 0, 200),
            0.000001,
            100
    };

    Simulator s(param);


    for (int i = 0; i < 8; i++) {
        s.solve();
        s.printResultSummary();
    }

}
