#ifndef HASH_H
#define HASH_H

#include "common.h"

#define TABLE_SIZE 13 // Çakışmaları görebilmek için küçük bir asal sayı seçtik

typedef struct {
    Paket* tablolar; // Dinamik dizi olarak tutacağız (Bellek raporu için önemli)
} HashTable;

HashTable* hashInit();
int hashFonksiyonu(char* anahtar); // Senin "Tip B" fonksiyonun
void paketEkle(HashTable* ht, Paket p);
Paket* paketSorgula(HashTable* ht, char* paketID);

#endif