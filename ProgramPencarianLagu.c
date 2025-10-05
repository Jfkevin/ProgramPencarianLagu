#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char judul[100];
    char artis[100];
    char album[100];
    int tahun;
} Lagu;

void readData(Lagu database[], int *jumlahData) {
    FILE *file = fopen("database-musik.txt", "r");
    if (file == NULL) {
        printf("Gagal membaca file database-musik.txt\n");
        exit(1);
    }

    *jumlahData = 0;
    char buffer[300];

    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, "*");
        strcpy(database[*jumlahData].judul, token);

        token = strtok(NULL, "*");
        strcpy(database[*jumlahData].artis, token);

        token = strtok(NULL, "*");
        strcpy(database[*jumlahData].album, token);

        token = strtok(NULL, "*");
        database[*jumlahData].tahun = atoi(token);

        (*jumlahData)++;
    }

    fclose(file);
}

int menu() {
    int pilihan;
    printf("\n============== Daftar Menu ==============\n");
    printf("1. Urutkan Lagu Berdasarkan Judul\n");
    printf("2. Urutkan Lagu Berdasarkan Tahun Rilis\n");
    printf("3. Cari Lagu Berdasarkan Judul\n");
    printf("4. Cari Lagu Berdasarkan Tahun Rilis\n");
    printf("5. Exit\n\n");
    printf("Pilihan menu: ");
    scanf("%d", &pilihan);
    getchar();
    return pilihan;
}

void tukarLagu(Lagu *lagu1, Lagu *lagu2) {
    Lagu temp = *lagu1;
    *lagu1 = *lagu2;
    *lagu2 = temp;
}

void SortJudul(Lagu database[], int jumlahData) {
    int i, j;
    for (i = 0; i < jumlahData - 1; i++) {
        for (j = 0; j < jumlahData - i - 1; j++) {
            if (strcmp(database[j].judul, database[j + 1].judul) > 0) {
                tukarLagu(&database[j], &database[j + 1]);
            }
        }
    }
}

void SortTahun(Lagu database[], int jumlahData) {
    int i, j;
    for (i = 0; i < jumlahData - 1; i++) {
        for (j = 0; j < jumlahData - i - 1; j++) {
            if (database[j].tahun > database[j + 1].tahun) {
                tukarLagu(&database[j], &database[j + 1]);
            }
        }
    }
}

void cetakData(Lagu lagu) {
    printf("Judul: %2s\n", lagu.judul);
    printf("Artis: %2s\n", lagu.artis);
    printf("Album: %2s\n", lagu.album);
    printf("Tahun: %2d\n\n", lagu.tahun);
}

void SearchJudul(Lagu database[], int jumlahData, char judulCari[]) {
    int awal = 0;
    int akhir = jumlahData - 1;
    int ditemukan = 0;

    while (awal <= akhir) {
        int tengah = awal + (akhir - awal) / 2;

        if (strcmp(database[tengah].judul, judulCari) == 0) {
            cetakData(database[tengah]);
            ditemukan = 1;
            break;
        }
        else if (strcmp(database[tengah].judul, judulCari) < 0) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }

    if (!ditemukan) {
        printf("\nLagu dengan judul '%s' tidak ditemukan.\n", judulCari);
    }
}

void SearchTahun(Lagu database[], int jumlahData, int tahun) {
    int i;
    int ditemukan = 0;

    printf("\nDaftar lagu yang rilis pada tahun %d:\n\n", tahun);
    for (i = 0; i < jumlahData; i++) {
        if (database[i].tahun == tahun) {
            cetakData(database[i]);
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("\nTidak ada lagu yang rilis pada tahun %d.\n", tahun);
    }
}

int main() {
    Lagu database[100];
    int jumlahData;
    char judulCari[100];
    int tahunCari;
    int pilihan;

    readData(database, &jumlahData);

    do {
        pilihan = menu();

        switch (pilihan) {
            case 1:
                SortJudul(database, jumlahData);
                printf("\nURUTAN LAGU BERDASARKAN JUDUL\n\n");
                for (int i = 0; i < jumlahData; i++) {
                    cetakData(database[i]);
                }
                break;
            case 2:
                SortTahun(database, jumlahData);
                printf("\nURUTAN LAGU BERDASARKAN TAHUN RILIS\n\n");
                for (int i = 0; i < jumlahData; i++) {
                    cetakData(database[i]);
                }
                break;
            case 3:
                printf("\nMasukkan Judul Lagu Yang Dicari:");
                fgets(judulCari, sizeof(judulCari), stdin);
                judulCari[strcspn(judulCari, "\n")] = '\0';
                SortJudul(database, jumlahData);
                SearchJudul(database, jumlahData, judulCari);
                break;
            case 4:
                printf("\nMasukkan Tahun Rilis Lagu Yang Dicari:");
                scanf("%d", &tahunCari);
                getchar();
                SortTahun(database, jumlahData);
                SearchTahun(database, jumlahData, tahunCari);
                break;
            case 5:
                printf("\nTERIMA KASIH SUDAH MEMAKAI PROGRAM INI\n");
                printf("\nFARRELIUS KEVIN/00000081783\n");
                break;
            default:
                printf("\nPilihan tidak valid. Pilih ulang !!.\n");
        }
    } while (pilihan != 5);

    return 0;
}

