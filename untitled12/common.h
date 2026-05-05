#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Paket Yapısı (Hash Tablosunda saklanacak)
typedef struct {
    char paketID[20];
    char icerik[50];
    char hedefSehir[30];
    int aktif; // Açık Adresleme için: 0=Boş, 1=Dolu, -1=Silinmiş
} Paket;

// Graf Kenar Yapısı (Komşuluk Listesi için)
typedef struct Edge {
    int hedefIndis;
    int mesafe;
    struct Edge* next;
} Edge;

// Şehir Yapısı (Graf Düğümü)
typedef struct {
    char sehirAdi[30];
    Edge* komsuListesi;
} Sehir;

#endif