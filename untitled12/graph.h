#ifndef GRAPH_H
#define GRAPH_H

#include "common.h"

#define MAX_SEHIR 10

typedef struct {
    Sehir sehirler[MAX_SEHIR];
    int sehirSayisi;
} LojistikGraf;

LojistikGraf* grafInit();
void sehirEkle(LojistikGraf* g, char* isim);
void yolEkle(LojistikGraf* g, char* kaynak, char* hedef, int mesafe);
void bfsGezinme(LojistikGraf* g, int baslangicIndis); // Senin özel görevin

#endif