#ifndef BAGLILISTE2_HPP
#define BAGLILISTE2_HPP

#include "GeometrikSekiller.hpp"
#include "DikDortgen.hpp"
#include "Ucgen.hpp"
#include "Yildiz.hpp"


/** * @file BagliListe2.hpp
* @description Tek yönlü bağlı liste yapısının sınıf tanımıdır. Geometrik şekilleri tutar ve Z-Sıralaması (Derinlik) yönetimini sağlar.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

class Dugum2 {
public:
    GeometrikSekiller* veri;
    Dugum2* sonraki;

    Dugum2(GeometrikSekiller* _veri) {
        veri = _veri;
        sonraki = nullptr;
    }
    ~Dugum2(){
        delete veri; 
    }
};

class BagliListe2 {
private:
    Dugum2* ilk;
    int elemanSayisi;
    
    // YENİ EKLENEN: Sayaç değişkeni
    int zSayac; 

public:
    BagliListe2();
    ~BagliListe2();

    void ekle(GeometrikSekiller* veri);
    void sil(int index);
    void tumunuCiz(char ekran[25][100]);
    int getElemanSayisi() const;
    
    GeometrikSekiller* getEleman(int index);
};

#endif