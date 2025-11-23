/** * @file BagliListe2.cpp
* @description BagliListe2 sınıfının fonksiyonlarıdır. Şekil ekleme, silme ve Z değerine göre sıralayıp çizdirme işlemleri buradadır.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

#include "BagliListe2.hpp"
#include <iostream>
#include <cstdlib> // Rand fonksiyonu için

using namespace std;

BagliListe2::BagliListe2() {
    ilk = nullptr;
    elemanSayisi = 0;
    zSayac = 0; 
}

BagliListe2::~BagliListe2() {
    Dugum2* gecici = ilk;
    while (gecici != nullptr) {
        Dugum2* silinecek = gecici;
        gecici = gecici->sonraki;
        delete silinecek;
    }
}

void BagliListe2::ekle(GeometrikSekiller* veri) {
    // --- RANDOM VE BENZERSİZ Z DEĞERİ ATAMA ---
    int rastgeleZ;
    bool cakismaVar;

    do {
        cakismaVar = false;
        // 0 ile 20 arasında rastgele bir sayı üret
        rastgeleZ = rand() % 21; 

        // Listeyi gez ve bu sayı daha önce verilmiş mi kontrol et
        Dugum2* tara = ilk;
        while (tara != nullptr) {
            if (tara->veri->getZ() == rastgeleZ) {
                cakismaVar = true; // Eyvah, bu sayı kullanımda!
                break; // Döngüden çık, while'a geri dön ve yeni sayı üret
            }
            tara = tara->sonraki;
        }
    } while (cakismaVar); // Çakışma olduğu sürece döngü devam eder

    // Bulduğumuz benzersiz sayıyı ata
    veri->setZ(rastgeleZ);


    // --- STANDART EKLEME İŞLEMİ ---
    Dugum2* yeni = new Dugum2(veri);
    if (ilk == nullptr) {
        ilk = yeni;
    } else {
        Dugum2* gecici = ilk;
        while (gecici->sonraki != nullptr) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
    elemanSayisi++;
}

void BagliListe2::sil(int index) {
    if (ilk == nullptr) return;

    Dugum2* silinecek = nullptr;
    Dugum2* onceki = nullptr;

    if (index == 0) {
        // Baştakini silme
        silinecek = ilk;
        ilk = ilk->sonraki;
        delete silinecek;
    } else {
        // Aradan veya sondan silme
        onceki = ilk;
        int i = 0;
        while(onceki->sonraki != nullptr && i < index - 1) {
            onceki = onceki->sonraki;
            i++;
        }
        
        if(onceki->sonraki != nullptr) {
            silinecek = onceki->sonraki;
            onceki->sonraki = silinecek->sonraki;
            delete silinecek;
        }
    }
    elemanSayisi--;
}

void BagliListe2::tumunuCiz(char ekran[25][100]) {
    if (elemanSayisi == 0) return;

    // 1. Elemanları geçici bir diziye kopyala
    GeometrikSekiller** sekilDizisi = new GeometrikSekiller*[elemanSayisi];
    
    Dugum2* temp = ilk;
    int i = 0;
    while (temp != nullptr) {
        sekilDizisi[i] = temp->veri;
        temp = temp->sonraki;
        i++;
    }

    // 2. SIRALAMA (BÜYÜKTEN KÜÇÜĞE)
    
    
    for (int a = 0; a < elemanSayisi - 1; a++) {
        for (int b = 0; b < elemanSayisi - a - 1; b++) {
           
            if (sekilDizisi[b]->getZ() < sekilDizisi[b+1]->getZ()) {
                // Swap
                GeometrikSekiller* takas = sekilDizisi[b];
                sekilDizisi[b] = sekilDizisi[b+1];
                sekilDizisi[b+1] = takas;
            }
        }
    }

    // 3. Çizim
    for (int k = 0; k < elemanSayisi; k++) {
        sekilDizisi[k]->ciz(ekran);
    }

    delete[] sekilDizisi;
}

int BagliListe2::getElemanSayisi() const {
    return elemanSayisi;
}

GeometrikSekiller* BagliListe2::getEleman(int index) {
    Dugum2* gecici = ilk;
    int sayac = 0;
    while (gecici != nullptr) {
        if (sayac == index) return gecici->veri;
        gecici = gecici->sonraki;
        sayac++;
    }
    return nullptr;
}