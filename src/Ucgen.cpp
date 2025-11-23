#include "Ucgen.hpp"
#include <cmath> 

/** * @file Ucgen.cpp
* @description Üçgen çizim algoritmasını barındırır. Her satırda genişleyerek üçgen formu oluşturur.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

Ucgen::Ucgen(int _x, int _y, int _h) 
    : GeometrikSekiller(_x, _y, _h, 0, UCGEN) {
    // Üçgenin taban genişliği 
}

void Ucgen::ciz(char ekran[25][100]) {
    
    int tepeSatir = x - (yukseklik / 2);
    
    for (int i = 0; i < yukseklik; i++) {
       
        int yildizSayisi = 2 * i + 1;
        int baslangicSutun = y - (yildizSayisi / 2);

        for (int j = 0; j < yildizSayisi; j++) {
            int r = tepeSatir + i;
            int c = baslangicSutun + j;

            if (r >= 0 && r < 25 && c >= 0 && c < 100) {
                ekran[r][c] = karakter;
            }
        }
    }
}