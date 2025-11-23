#ifndef GEOMETRIKSEKILLER_HPP
#define GEOMETRIKSEKILLER_HPP

/** * @file GeometrikSekiller.hpp
* @description Tüm şekillerin türetildiği soyut temel sınıf (Base Class). Koordinat, boyut ve Z değeri özelliklerini tanımlar.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

#include <cstdlib> 

enum SekilTipi { DIKDORTGEN, UCGEN, YILDIZ };

class GeometrikSekiller {
protected:
    int x, y; 
    int yukseklik;
    int genislik; 
    char karakter; 
    SekilTipi tip;
    
    
    int zDegeri; 

public:
    GeometrikSekiller(int _x, int _y, int _h, int _w, SekilTipi _tip);
    virtual ~GeometrikSekiller() {} 

    virtual void ciz(char ekran[25][100]) = 0; 
    void konumDegistir(int dx, int dy); 
    
    int getX() const { return x; }
    int getY() const { return y; }

  
    void setZ(int _z) { zDegeri = _z; }
    int getZ() const { return zDegeri; }

    int getYukseklik() const { return yukseklik; }
    int getGenislik() const { return genislik; }
    SekilTipi getTip() const { return tip; }
};

#endif