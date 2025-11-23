#ifndef DIKDORTGEN_HPP
#define DIKDORTGEN_HPP

#include "GeometrikSekiller.hpp"

/** * @file DikDortgen.hpp
* @description Dikdörtgen şeklinin sınıf tanımıdır. GeometrikSekiller sınıfından kalıtım alır.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

class DikDortgen : public GeometrikSekiller {
public:
    DikDortgen(int _x, int _y, int _h, int _w);
    void ciz(char ekran[25][100]) override;
};

#endif