#include "GeometrikSekiller.hpp"
#include <ctime>
/** * @file GeometrikSekiller.cpp
* @description GeometrikSekiller sınıfının kurucu fonksiyonlarını ve konum değiştirme mantığını içerir.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/


GeometrikSekiller::GeometrikSekiller(int _x, int _y, int _h, int _w, SekilTipi _tip) {
    x = _x;
    y = _y;
    yukseklik = _h;
    genislik = _w;
    tip = _tip;

    // Rastgele karakter atama
    char semboller[] = {'$', '+', '&', '@', '*'};
    karakter = semboller[rand() % 5];
}

void GeometrikSekiller::konumDegistir(int dx, int dy) {
    // Sınır kontrolü burada yapılabilir veya main'de. 
    // Şimdilik sadece değerleri güncelliyoruz.
    x += dx;
    y += dy;
    
    // Ekran dışına çıkmayı engellemek için basit sınırlar (0-24 ve 0-99)
    if(x < 0) x = 0;
    if(x > 24) x = 24;
    if(y < 0) y = 0;
    if(y > 99) y = 99;
}