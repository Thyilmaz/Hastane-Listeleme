#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Hasta yapisi
typedef struct Hasta {
    char isim[50];
    int yas;
    int oncelik;  // 1: Yuksek, 2: Orta, 3: Dusuk
    int receteNo;
    struct Hasta *sonraki;
} Hasta;

// Bagli liste baslangici
Hasta *bas = NULL;

// Recete numarasi uretme fonksiyonu
int receteNoUret() {
    return rand() % 9000 + 1000; // 1000-9999 arasi rastgele sayi
}

// Yeni hasta ekleme fonksiyonu (oncelik sirasina gore)
void hastaEkle(char isim[], int yas, int oncelik) {
    if (oncelik < 1 || oncelik > 3) {
        printf("Gecersiz oncelik seviyesi! (1: Yuksek, 2: Orta, 3: Dusuk)\n");
        return;
    }

    Hasta *yeni = (Hasta *)malloc(sizeof(Hasta));
    strcpy(yeni->isim, isim);
    yeni->yas = yas;
    yeni->oncelik = oncelik;
    yeni->receteNo = receteNoUret();
    yeni->sonraki = NULL;

    if (bas == NULL || bas->oncelik > oncelik) {
        yeni->sonraki = bas;
        bas = yeni;
    } else {
        Hasta *gecici = bas;
        while (gecici->sonraki != NULL && gecici->sonraki->oncelik < oncelik) {
            gecici = gecici->sonraki;
        }
        yeni->sonraki = gecici->sonraki;
        gecici->sonraki = yeni;
    }
    printf("Hasta eklendi: %s, Oncelik: %d, Recete No: %d\n", isim, oncelik, yeni->receteNo);
}

// Oncelikli hastayi cikarma fonksiyonu
void hastaCagir() {
    if (bas == NULL) {
        printf("Bekleyen hasta yok.\n");
        return;
    }
    Hasta *gecici = bas;
    printf("Hasta cagiliyor: %s, Yas: %d, Oncelik: %d, Recete No: %d\n",
           gecici->isim, gecici->yas, gecici->oncelik, gecici->receteNo);
    bas = bas->sonraki;
    free(gecici);
}

// Bekleyen hastalari listeleme fonksiyonu
void hastalariListele() {
    if (bas == NULL) {
        printf("Bekleyen hasta yok.\n");
        return;
    }
    printf("Bekleyen hastalar:\n");
    Hasta *gecici = bas;
    while (gecici != NULL) {
        printf("- %s (Yas: %d, Oncelik: %d, Recete No: %d)\n",
               gecici->isim, gecici->yas, gecici->oncelik, gecici->receteNo);
        gecici = gecici->sonraki;
    }
}

// Bellek temizleme fonksiyonu
void listeyiTemizle() {
    Hasta *gecici = bas;
    while (gecici != NULL) {
        Hasta *sil = gecici;
        gecici = gecici->sonraki;
        free(sil);
    }
    bas = NULL;
}

int main() {
    srand(time(NULL)); // Rastgele recete numarasi icin
    int secim;
    char isim[50];
    int yas, oncelik;

    while (1) {
        printf("\n--- Acil Servis Sistemi ---\n");
        printf("1. Yeni Hasta Kaydi\n");
        printf("2. Hasta Cagir\n");
        printf("3. Bekleyen Hastalari Listele\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");

        if (scanf("%d", &secim) != 1) {
            printf("Gecersiz giris! Lutfen bir sayi girin.\n");
            while (getchar() != '\n'); // Tamponu temizle
            continue;
        }
        getchar(); // Yeni satir karakterini temizle

        switch (secim) {
            case 1:
                printf("Hasta Ismi: ");
                fgets(isim, sizeof(isim), stdin);
                isim[strcspn(isim, "\n")] = 0; // Yeni satiri temizle

                printf("Yas: ");
                if (scanf("%d", &yas) != 1) {
                    printf("Gecersiz giris! Lutfen bir sayi girin.\n");
                    while (getchar() != '\n');
                    continue;
                }

                printf("Oncelik (1: Yuksek, 2: Orta, 3: Dusuk): ");
                if (scanf("%d", &oncelik) != 1 || oncelik < 1 || oncelik > 3) {
                    printf("Gecersiz oncelik seviyesi!\n");
                    while (getchar() != '\n');
                    continue;
                }
                hastaEkle(isim, yas, oncelik);
                break;
            case 2:
                hastaCagir();
                break;
            case 3:
                hastalariListele();
                break;
            case 4:
                printf("Sistemden cikiliyor...\n");
                listeyiTemizle();
                return 0;
            default:
                printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }
}
