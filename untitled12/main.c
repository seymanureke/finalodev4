#include "hash.h"
#include "graph.h"

// Bellek İzleme Raporu Fonksiyonu
void bellekRaporu(HashTable* ht, LojistikGraf* g) {
    printf("\n--- BELLEK IZLEME RAPORU (RAM DURUMU) ---\n");
    printf("Hash Tablosu Baslangic Adresi: %p\n", (void*)ht->tablolar);

    printf("\n[Hash Tablosu Detaylari]\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(ht->tablolar[i].aktif == 1) {
            printf("Indis %d | Paket: %s | Bellek Adresi: %p\n",
                   i, ht->tablolar[i].paketID, (void*)&ht->tablolar[i]);
        }
    }

    printf("\n[Graf / Sehir Yapisi Detaylari]\n");
    for(int i = 0; i < g->sehirSayisi; i++) {
        printf("Sehir: %s | Adres: %p\n", g->sehirler[i].sehirAdi, (void*)&g->sehirler[i]);
        Edge* temp = g->sehirler[i].komsuListesi;
        while(temp != NULL) {
            printf("  -> Baglanti (Edge) Adresi: %p | Hedef Indis: %d\n", (void*)temp, temp->hedefIndis);
            temp = temp->next;
        }
    }
    printf("---------------------------------\n");
}

int main() {
    // 1. Sistemleri Baslat
    HashTable* lojistikHash = hashInit();
    LojistikGraf* lojistikGraf = grafInit();

    // 2. Sehirleri ve Yollari Ekle (Graf)
    sehirEkle(lojistikGraf, "Istanbul");
    sehirEkle(lojistikGraf, "Ankara");
    sehirEkle(lojistikGraf, "Izmir");
    sehirEkle(lojistikGraf, "Bursa");

    yolEkle(lojistikGraf, "Istanbul", "Ankara", 450);
    yolEkle(lojistikGraf, "Istanbul", "Bursa", 150);
    yolEkle(lojistikGraf, "Ankara", "Izmir", 600);
    yolEkle(lojistikGraf, "Bursa", "Izmir", 330);

    // 3. Paketleri Ekle (Hash - Tip B & Acik Adresleme Testi)
    Paket p1 = {"TR101", "Elektronik", "Ankara", 1};
    Paket p2 = {"TR102", "Tekstil", "Izmir", 1};
    Paket p3 = {"TR103", "Gida", "Bursa", 1};

    paketEkle(lojistikHash, p1);
    paketEkle(lojistikHash, p2);
    paketEkle(lojistikHash, p3);

    // 4. BFS Gezinmesi (Senin Gorevin)
    printf("\nLojistik Agi Geziliyor (BFS):\n");
    bfsGezinme(lojistikGraf, 0); // Istanbul'dan basla

    // 5. Bellek Raporunu Yazdir (Odevin Ek Dosyasi Icin)
    bellekRaporu(lojistikHash, lojistikGraf);

    // Bellek temizleme (Hoca kod kalitesine bakarsa arti puan!)
    free(lojistikHash->tablolar);
    free(lojistikHash);
    // (Graf icin de free dongusu eklenebilir)

    return 0;
}