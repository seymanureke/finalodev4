#include "hash.h"

HashTable* hashInit() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->tablolar = (Paket*)calloc(TABLE_SIZE, sizeof(Paket));
    for(int i=0; i<TABLE_SIZE; i++) ht->tablolar[i].aktif = 0; // Hepsi boş başlasın
    return ht;
}

// TIP B: Polinomik Rolling Hash (Öğrenci numarana özel seçim)
int hashFonksiyonu(char* anahtar) {
    unsigned long hash = 0;
    for (int i = 0; anahtar[i] != '\0'; i++) {
        hash = (hash * 31) + anahtar[i];
    }
    return hash % TABLE_SIZE;
}

void paketEkle(HashTable* ht, Paket p) {
    int index = hashFonksiyonu(p.paketID);
    int ilkIndex = index;

    // AÇIK ADRESLEME (Linear Probing)
    while (ht->tablolar[index].aktif == 1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == ilkIndex) {
            printf("Tablo dolu!\n");
            return;
        }
    }

    ht->tablolar[index] = p;
    ht->tablolar[index].aktif = 1;
    printf("Paket %s, index %d konumuna yerlestirildi.\n", p.paketID, index);
}