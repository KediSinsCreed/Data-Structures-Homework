/** * @file Main.cpp
* @description Programın giriş noktasıdır. Menü yönetimi, dosya okuma, çizim döngüsü ve kullanıcı girişleri burada işlenir.
* @course 2. Öğretim A Grubu
* @assignment 1. Ödev
* @date 23.11.2025
* @author Emir Abdullah Önal - emir.onal@ogr.sakarya.edu.tr
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <conio.h> 
#include <windows.h> 
#include <sstream>
#include <fstream> // Dosya okuma için

#include "BagliListe1.hpp"
#include "BagliListe2.hpp"
#include "GeometrikSekiller.hpp"

using namespace std;

void imlecGizle() {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(out, &cursorInfo);
}

// Dosyadan okuyup listeleri oluşturan fonksiyon
void dosyadanOku(BagliListe1* yonetici) {
    ifstream dosya("veriler.txt"); 
    if (!dosya.is_open()) {
        cout << "HATA: veriler.txt dosyasi bulunamadi!" << endl;
        system("pause");
        exit(0);
    }

    string satir;
    char tur;
    int x, y, h, w;

    while (dosya >> tur) { // İlk karakteri oku (L, D, U, Y)
        if (tur == 'L') {
            // "LISTE" kelimesinin geri kalanını ("ISTE") oku ama kullanma
            string cop; getline(dosya, cop); 
            
            // Yeni boş bir liste (düğüm) ekle (Rastgele doldurma = false)
            yonetici->ekle(false); 
        }
        else if (tur == 'D') {
            dosya >> x >> y >> h >> w;
            BagliListe2* sonListe = yonetici->getSonListe();
            if(sonListe) sonListe->ekle(new DikDortgen(x, y, h, w));
        }
        else if (tur == 'U') {
            dosya >> x >> y >> h;
            BagliListe2* sonListe = yonetici->getSonListe();
            if(sonListe) sonListe->ekle(new Ucgen(x, y, h));
        }
        else if (tur == 'Y') {
            dosya >> x >> y >> h;
            BagliListe2* sonListe = yonetici->getSonListe();
            if(sonListe) sonListe->ekle(new Yildiz(x, y, h));
        }
    }
    dosya.close();
    cout << "Dosya basariyla okundu." << endl;
    Sleep(1000); 
}

void dosyayaKaydet(BagliListe1* yonetici) {
    ofstream dosya("veriler.txt"); // Dosyayı sıfırlayıp açar (Truncate)
    
    if (!dosya.is_open()) {
        cout << "HATA: Dosya yazma modunda acilamadi!" << endl;
        return;
    }

    int toplamListe = yonetici->getElemanSayisi();
    
    // Ana listedeki her düğümü gez
    for (int i = 0; i < toplamListe; i++) {
        // Her düğüm yeni bir "LISTE" demektir
        dosya << "LISTE" << endl;

        BagliListe2* icListe = yonetici->getDugum(i);
        int sekilSayisi = icListe->getElemanSayisi();

        // İç listedeki her şekli gez
        for (int j = 0; j < sekilSayisi; j++) {
            GeometrikSekiller* sekil = icListe->getEleman(j);
            
            // Şeklin tipine göre dosyaya formatlı yaz
            if (sekil->getTip() == DIKDORTGEN) {
                // Format: D X Y H W
                dosya << "D " << sekil->getX() << " " << sekil->getY() << " " 
                      << sekil->getYukseklik() << " " << sekil->getGenislik() << endl;
            }
            else if (sekil->getTip() == UCGEN) {
                // Format: U X Y H
                dosya << "U " << sekil->getX() << " " << sekil->getY() << " " 
                      << sekil->getYukseklik() << endl;
            }
            else if (sekil->getTip() == YILDIZ) {
                // Format: Y X Y H
                dosya << "Y " << sekil->getX() << " " << sekil->getY() << " " 
                      << sekil->getYukseklik() << endl;
            }
        }
    }
    dosya.close();
    cout << "Guncel durum veriler.txt dosyasina kaydedildi." << endl;
}

int main() {
    imlecGizle();
    srand(time(0)); 

    BagliListe1* yoneticiListesi = new BagliListe1();

    // --- GİRİŞ MENÜSÜ ---
    system("cls");
    cout << "Hosgeldiniz!" << endl;
    cout << "1. Rastgele Uretim" << endl;
    cout << "2. Dosyadan Okuma (veriler.txt)" << endl;
    cout << "Seciminiz: ";
    
    char secim;
    cin >> secim;

    if (secim == '2') {
        // Dosya Modu
        dosyadanOku(yoneticiListesi);
    } else {
        
        // İSTEK: Rastgele modda 20 eleman olsun
        for(int i=0; i<20; i++) {
            yoneticiListesi->ekle(true); // true = Rastgele doldur
        }
    }

    // --- PROGRAMIN ANA DÖNGÜSÜ ---

    int seciliAnaDugumIndex = 0; 
    int sayfaBaslangic = 0;      
    bool iceriGirildi = false;   
    int seciliSekilIndex = 0; 

    while(true) {
        system("cls"); 
        
        char tuval[25][100];
        for(int i=0; i<25; i++) {
            for(int j=0; j<100; j++) {
                tuval[i][j] = ' ';
            }
        }

        BagliListe2* aktifListe = yoneticiListesi->getDugum(seciliAnaDugumIndex);
        if(aktifListe != nullptr) {
            aktifListe->tumunuCiz(tuval);
        }

        int toplamEleman = yoneticiListesi->getElemanSayisi();
        
        // Sayfalama
        if (seciliAnaDugumIndex >= sayfaBaslangic + 5) sayfaBaslangic += 5;
        if (seciliAnaDugumIndex < sayfaBaslangic) sayfaBaslangic -= 5;

        for (int i = 0; i < 25; i++) {
            int suankiKutuIndex = sayfaBaslangic + (i / 5);
            int kutuSatiri = i % 5; 

            stringstream ss;
            
            if (suankiKutuIndex < toplamEleman) {
                BagliListe2* tempDugum = yoneticiListesi->getDugum(suankiKutuIndex);
                
                if (kutuSatiri == 0) ss << "*******"; 
                else if (kutuSatiri == 1) {
                    ss << left << setw(6) << tempDugum->getElemanSayisi() << "*";
                    if (suankiKutuIndex == seciliAnaDugumIndex) ss << " <---";
                }
                else if (kutuSatiri == 2) ss << "*******"; 
            } 

            cout << setw(15) << left << ss.str(); 
            cout << "| "; 

            for (int j = 0; j < 100; j++) {
                cout << tuval[i][j];
            }
            cout << endl;
        }

        cout << "----------------------------------------------------------------" << endl;
        if (!iceriGirildi) {
            cout << "[MOD: LISTE GEZINTISI] (Secili: " << seciliAnaDugumIndex << ")" << endl; 
            cout << "W/S: Yukari/Asagi | F: Secili Listeye Gir | ESC: Cikis";
        } else {
            int toplamSekil = (aktifListe != nullptr) ? aktifListe->getElemanSayisi() : 0;
            cout << "[MOD: SEKIL KONTROL] (Sekil: " << seciliSekilIndex + 1 << "/" << toplamSekil << ")" << endl;
            cout << "WASD: Hareket | H: Sonraki Sekil | G: Sil | K: Geri Don";
        }

        int tus = _getch();

        if (!iceriGirildi) {
            if (tus == 'w' || tus == 'W') {
                if (seciliAnaDugumIndex > 0) seciliAnaDugumIndex--;
            }
            else if (tus == 's' || tus == 'S') {
                if (seciliAnaDugumIndex < toplamEleman - 1) seciliAnaDugumIndex++;
            }
            else if (tus == 'f' || tus == 'F') {
                iceriGirildi = true;
                seciliSekilIndex = 0; 
            }
            else if (tus == 27) break; 
        } 
        else {
            if (aktifListe == nullptr || aktifListe->getElemanSayisi() == 0) {
                iceriGirildi = false;
                continue;
            }
            
            if (tus == 'h' || tus == 'H') {
                seciliSekilIndex++;
                if (seciliSekilIndex >= aktifListe->getElemanSayisi()) {
                    seciliSekilIndex = 0; 
                }
            }

            GeometrikSekiller* sekil = aktifListe->getEleman(seciliSekilIndex);
            
            if (sekil == nullptr) {
                seciliSekilIndex = 0;
                sekil = aktifListe->getEleman(0);
            }

            if (sekil != nullptr) {
                if (tus == 'w' || tus == 'W') sekil->konumDegistir(-1, 0);
                else if (tus == 's' || tus == 'S') sekil->konumDegistir(1, 0);
                else if (tus == 'a' || tus == 'A') sekil->konumDegistir(0, -1);
                else if (tus == 'd' || tus == 'D') sekil->konumDegistir(0, 1);
                else if (tus == 'g' || tus == 'G') {
                    aktifListe->sil(seciliSekilIndex);
                    seciliSekilIndex = 0; 

                    if (aktifListe->getElemanSayisi() == 0) {
                        iceriGirildi = false; 
                        yoneticiListesi->sil(seciliAnaDugumIndex);
                        if (seciliAnaDugumIndex >= yoneticiListesi->getElemanSayisi() && seciliAnaDugumIndex > 0) {
                            seciliAnaDugumIndex--;
                        }
                    }
                }
            }
            if (tus == 'k' || tus == 'K') iceriGirildi = false;
        }
    } 
    dosyayaKaydet(yoneticiListesi);
    delete yoneticiListesi;
    return 0;
}