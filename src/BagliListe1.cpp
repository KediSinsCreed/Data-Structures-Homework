/** * @file BagliListe1.cpp
* @description BagliListe1 sınıfının fonksiyon gövdelerini içerir. Düğüm ekleme, silme ve menü yazdırma işlemleri buradadır.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

#include "BagliListe1.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

BagliListe1::BagliListe1() {
    ilk = nullptr;
    son = nullptr;
    elemanSayisi = 0;
}

BagliListe1::~BagliListe1() {
    Dugum1* gecici = ilk;
    while (gecici != nullptr) {
        Dugum1* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}


void BagliListe1::ekle(bool rastgeleDoldur) {
    Dugum1* yeni = new Dugum1();
    
    if (rastgeleDoldur) {
        
        // rand() % 7 -> 0 ile 6 arası üretir.
        // + 2 eklersek -> 2 ile 8 arası olur.
        int adet = (rand() % 7) + 2; 
        
        for(int i=0; i<adet; i++){
            int tip = rand() % 3;
            
            // Konumlar (0-24, 0-99)
            int x = rand() % 25;
            int y = rand() % 100;

            if(tip == 0) {
                
                int h = (rand() % 9) + 2; 
                int w = (rand() % 9) + 2; 
                yeni->veri->ekle(new DikDortgen(x, y, h, w));
            }
            else if(tip == 1) {
                
                int h = (rand() % 8) + 3; 
                yeni->veri->ekle(new Ucgen(x, y, h));
            }
            else {
            
                int h = (rand() % 8) + 3; 
                yeni->veri->ekle(new Yildiz(x, y, h));
            }
        }
    }
    // Not: rastgeleDoldur false ise (Dosya modu), içi boş bir liste eklenir.

    if (ilk == nullptr) {
        ilk = yeni;
        son = yeni;
    } else {
        son->sonraki = yeni;
        yeni->onceki = son;
        son = yeni;
    }
    elemanSayisi++;
}

// Dosyadan okurken son eklenen listeyi bulup içine şekil atmak için
BagliListe2* BagliListe1::getSonListe() {
    if (son != nullptr) return son->veri;
    return nullptr;
}

BagliListe2* BagliListe1::getDugum(int index) {
    Dugum1* gecici = ilk;
    int sayac = 0;
    while (gecici != nullptr) {
        if (sayac == index) return gecici->veri;
        gecici = gecici->sonraki;
        sayac++;
    }
    return nullptr;
}

void BagliListe1::sil(int index) {
    if (ilk == nullptr) return;

    Dugum1* silinecek = ilk;
    int sayac = 0;

    while (silinecek != nullptr && sayac < index) {
        silinecek = silinecek->sonraki;
        sayac++;
    }

    if (silinecek == nullptr) return; 

    if (silinecek == ilk) {
        ilk = silinecek->sonraki;
        if (ilk != nullptr) {
            ilk->onceki = nullptr;
        } else {
            son = nullptr; 
        }
    } 
    else if (silinecek == son) {
        son = silinecek->onceki;
        if (son != nullptr) {
            son->sonraki = nullptr;
        } else {
            ilk = nullptr;
        }
    } 
    else {
        silinecek->onceki->sonraki = silinecek->sonraki;
        silinecek->sonraki->onceki = silinecek->onceki;
    }

    delete silinecek; 
    elemanSayisi--;
}