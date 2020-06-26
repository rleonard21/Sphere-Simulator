//
// Created by robert on 6/26/20.
//

#ifndef SPHERE_SIM_UNITCONVERSION_H
#define SPHERE_SIM_UNITCONVERSION_H


double fps_to_ms(double fps) { return fps * 0.3048; }

double g_to_kg(double g) { return g / 1000; }

double mm_to_m(double mm) { return mm / 1000; }

double m_to_ft(double m) { return m * 3.2808399; }


#endif //SPHERE_SIM_UNITCONVERSION_H
