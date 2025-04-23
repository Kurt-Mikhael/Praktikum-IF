#include <stdio.h>

int main() {
    int n;
    int n_cari;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &n_cari);
    int arr_i[n_cari];
    int indeks = 0;
    while (indeks < n_cari) {
        int angka;
        int ketemu = -1;
        int kiri = 0;
        int kanan = n - 1;
        scanf("%d", &angka); 
        while (kiri <= kanan) {
            int tengah = kiri + (kanan - kiri) / 2;
            if (arr[tengah] == angka) {
                ketemu = tengah;
                kanan = tengah - 1;  
            } else if (arr[tengah] < angka) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }
        arr_i[indeks] = ketemu;
        indeks++;  
    }
    printf("[");
    for (int i = 0; i < n_cari; i++) {
        printf("%d", arr_i[i]);
        if(i==n_cari-1)printf("]\n");
        else printf(", ");
    }
    return 0;
}