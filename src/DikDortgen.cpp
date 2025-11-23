#include "DikDortgen.hpp"

/** * @file DikDortgen.cpp
* @description Dikdörtgen çizim algoritmasını barındırır.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

DikDortgen::DikDortgen(int _x, int _y, int _h, int _w) 
    : GeometrikSekiller(_x, _y, _h, _w, DIKDORTGEN) {}

void DikDortgen::ciz(char ekran[25][100]) {
    int baslangicSatir = x - (yukseklik / 2);
    int baslangicSutun = y - (genislik / 2);

    for (int i = 0; i < yukseklik; i++) {
        for (int j = 0; j < genislik; j++) {
            int r = baslangicSatir + i;
            int c = baslangicSutun + j;

            // Dizi sınırlarını aşmamak için kontrol
            if (r >= 0 && r < 25 && c >= 0 && c < 100) {
                ekran[r][c] = karakter;
            }
        }
    }
}