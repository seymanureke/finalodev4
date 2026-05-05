#include "graph.h"

LojistikGraf* grafInit() {
    LojistikGraf* g = (LojistikGraf*)malloc(sizeof(LojistikGraf));
    g->sehirSayisi = 0;
    for(int i=0; i<MAX_SEHIR; i++) {
        g->sehirler[i].komsuListesi = NULL;
    }
    return g;
}

void sehirEkle(LojistikGraf* g, char* isim) {
    if(g->sehirSayisi < MAX_SEHIR) {
        strcpy(g->sehirler[g->sehirSayisi].sehirAdi, isim);
        g->sehirSayisi++;
    }
}

void yolEkle(LojistikGraf* g, char* kaynak, char* hedef, int mesafe) {
    int kIndis = -1, hIndis = -1;
    for(int i=0; i<g->sehirSayisi; i++) {
        if(strcmp(g->sehirler[i].sehirAdi, kaynak) == 0) kIndis = i;
        if(strcmp(g->sehirler[i].sehirAdi, hedef) == 0) hIndis = i;
    }

    if(kIndis != -1 && hIndis != -1) {
        Edge* yeniKenar = (Edge*)malloc(sizeof(Edge));
        yeniKenar->hedefIndis = hIndis;
        yeniKenar->mesafe = mesafe;
        yeniKenar->next = g->sehirler[kIndis].komsuListesi;
        g->sehirler[kIndis].komsuListesi = yeniKenar;
    }
}

// SENİN GÖREVİN: BFS Gezinmesi
void bfsGezinme(LojistikGraf* g, int baslangicIndis) {
    int visited[MAX_SEHIR] = {0};
    int queue[MAX_SEHIR];
    int front = 0, rear = 0;

    visited[baslangicIndis] = 1;
    queue[rear++] = baslangicIndis;

    printf("BFS Gezinmesi: ");
    while(front < rear) {
        int suanki = queue[front++];
        printf("%s -> ", g->sehirler[suanki].sehirAdi);

        Edge* temp = g->sehirler[suanki].komsuListesi;
        while(temp != NULL) {
            if(!visited[temp->hedefIndis]) {
                visited[temp->hedefIndis] = 1;
                queue[rear++] = temp->hedefIndis;
            }
            temp = temp->next;
        }
    }
    printf("BITIS\n");
}