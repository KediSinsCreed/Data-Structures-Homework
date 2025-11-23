#ifndef YILDIZ_HPP
#define YILDIZ_HPP

#include "GeometrikSekiller.hpp"

/** * @file Yildiz.hpp
* @description Yıldız şeklinin sınıf tanımıdır. GeometrikSekiller sınıfından kalıtım alır.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

class Yildiz : public GeometrikSekiller {
public:
    Yildiz(int _x, int _y, int _h);
    void ciz(char ekran[25][100]) override;
};

#endif