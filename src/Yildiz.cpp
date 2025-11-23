/** * @file Yildiz.cpp
* @description Yıldız çizim algoritmasını barındırır. Önce genişleyip sonra daralan (baklava dilimi) bir yapı çizer.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/

#include "Yildiz.hpp"


Yildiz::Yildiz(int _x, int _y, int _h) 
    : GeometrikSekiller(_x, _y, _h, 0, YILDIZ) {}

void Yildiz::ciz(char ekran[25][100]) {
    int baslangicSatir = x - (yukseklik / 2);
    int orta = yukseklik / 2;

    for (int i = 0; i < yukseklik; i++) {
        int yildizSayisi;

        if (yukseklik % 2 == 0) {
            // --- ÇİFT SAYI DURUMU (Örn: h=6) ---
            // 0, 1, 2. satırlar artar (1, 3, 5)
            // 3, 4, 5. satırlar azalır (5, 3, 1)
            if (i < orta) {
                yildizSayisi = 2 * i + 1;
            } else {
                // Simetrik aynalama formülü
                yildizSayisi = 2 * (yukseklik - 1 - i) + 1;
            }
        } 
        else {
            // --- TEK SAYI DURUMU (Örn: h=5) ---
            // 0, 1, 2. satırlar artar (1, 3, 5) -> 2 orta noktadır
            // 3, 4. satırlar azalır (3, 1)
            if (i <= orta) {
                yildizSayisi = 2 * i + 1;
            } else {
                yildizSayisi = 2 * (yukseklik - 1 - i) + 1;
            }
        }

        // Konumlama (Tam Ortalamak İçin)
        int baslangicSutun = y - (yildizSayisi / 2);

        for (int j = 0; j < yildizSayisi; j++) {
            int r = baslangicSatir + i;
            int c = baslangicSutun + j;

            // Ekran sınırlarını aşmamak için kontrol
            if (r >= 0 && r < 25 && c >= 0 && c < 100) {
                ekran[r][c] = karakter;
            }
        }
    }
}