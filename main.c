#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEKLIF_SAYISI 100

typedef struct {
    char isim[50];
    int teklif_miktari;
} Teklif;

void teklifleriGoster(Teklif teklifler[], int teklifSayisi) {
    printf("----- Teklifler -----\n");
    int i;
    for (i = 0; i < teklifSayisi; ++i) {
        printf("%s teklif verdi: %d\n", teklifler[i].isim, teklifler[i].teklif_miktari);
    }
    printf("---------------------\n");
}

void enYuksekTeklifiBelirle(Teklif teklifler[], int teklifSayisi) {
    int enYuksekTeklif = 0;
    char enYuksekTeklifVeren[50];
    int i;
    for (i= 0; i < teklifSayisi; ++i) {
        if (teklifler[i].teklif_miktari > enYuksekTeklif) {
            enYuksekTeklif = teklifler[i].teklif_miktari;
            strcpy(enYuksekTeklifVeren, teklifler[i].isim);
        }
    }

    printf("En yuksek teklif: %s - %d\n", enYuksekTeklifVeren, enYuksekTeklif);
}

int main() {
    Teklif teklifler[MAX_TEKLIF_SAYISI];
    int teklifSayisi = 0;
    char devam;

    do {
        printf("Teklif verenin adini girin: ");
        scanf("%s", teklifler[teklifSayisi].isim);

        printf("Teklif miktarini girin: ");
        scanf("%d", &teklifler[teklifSayisi].teklif_miktari);

        teklifSayisi++;

        printf("Devam etmek ister misiniz? (E/H): ");
        scanf(" %c", &devam);

    } while ((devam == 'E' || devam == 'e') && teklifSayisi < MAX_TEKLIF_SAYISI);

    teklifleriGoster(teklifler, teklifSayisi);
    enYuksekTeklifiBelirle(teklifler, teklifSayisi);

    return 0;
}
