#ifndef UCGEN_HPP
#define UCGEN_HPP

#include "GeometrikSekiller.hpp"

/** * @file Ucgen.hpp
* @description Üçgen şeklinin sınıf tanımıdır. GeometrikSekiller sınıfından kalıtım alır.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

class Ucgen : public GeometrikSekiller {
public:
    Ucgen(int _x, int _y, int _h);
    void ciz(char ekran[25][100]) override;
};

#endif