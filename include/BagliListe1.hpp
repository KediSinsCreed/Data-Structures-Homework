#ifndef BAGLILISTE1_HPP
#define BAGLILISTE1_HPP

/** * @file BagliListe1.hpp
* @description Çift yönlü bağlı liste yapısının sınıf tanımıdır. Sol menüdeki düğümleri ve sayfalamayı yönetir.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/
#include "BagliListe2.hpp"

class Dugum1 {
public:
    BagliListe2* veri; 
    Dugum1* sonraki;
    Dugum1* onceki;

    Dugum1() {
        veri = new BagliListe2(); 
        sonraki = nullptr;
        onceki = nullptr;
    }
    ~Dugum1() {
        delete veri; 
    }
};

class BagliListe1 {
private:
    Dugum1* ilk;
    Dugum1* son;
    int elemanSayisi;

public:
    BagliListe1();
    ~BagliListe1();

    // GÜNCELLEME: Rastgele mi yoksa boş mu ekleneceğini seçiyoruz
    void ekle(bool rastgeleDoldur = true); 
    
    // GÜNCELLEME: Dosyadan okurken son eklenen listeye ulaşmak için
    BagliListe2* getSonListe();

    void menuYazdir(int seciliIndex, int sayfaBaslangic);
    BagliListe2* getDugum(int index);
    
    int getElemanSayisi() const { return elemanSayisi; }
    
    void sil(int index); 
};

#endif