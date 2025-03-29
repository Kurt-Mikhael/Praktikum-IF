#include <stdio.h>

// Program Pemesanan Tiket Mandi Bola

/**
----------------------------------------
Selamat datang di Wahana Mandi Bola!

Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.

Harga tiket:
- Anak-anak (usia 0-12 tahun): Rp 10000
- Dewasa (usia 13-64 tahun): Rp 20000
- Lansia (usia 65 tahun ke atas): Rp 15000

Jumlah anak: <jumlah_anak>
Jumlah dewasa: <jumlah_dewasa>
Jumlah lansia: <jumlah_lansia>
 * Note:
 * - Jumlah anak-anak, dewasa, dan lansia masing-masing tidak akan lebih dari 9
 * - Silakan berkreatifitas sendiri untuk mendapatkan variable yang dibutuhkan dari input
 */


/**
 * Menghitung total biaya tiket berdasarkan jumlah pengunjung
 */
int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    return 10000*jumlah_anak + 20000*jumlah_dewasa + 15000*jumlah_lansia;
}


void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    int Total = HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n", jumlah_anak);
    printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("- Jumlah lansia: %d\n", jumlah_lansia);
    printf("- Total biaya: %d\n", Total);
}


void HandleNimonsHunting(long long input){
    int jumlah_pergerakan = input % 10;
    int jumlah_lubang = (input / 10) % 10;
    int jumlah_harta_karun = (input / 100) % 10;
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", jumlah_pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n", jumlah_lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n", jumlah_harta_karun);
    int total_langkah = 0; int total_harta_karun = 0; int jumlah_lubang_ditutup = 0; int banyak_langkah, ketemu, tutup;
    long long temp = input/1000;
    for (int i = 1; i <= jumlah_pergerakan; i++)
    {
        printf("Langkah ke-%d\n", i);
        banyak_langkah = temp % 10;
        temp /= 10;
        if (banyak_langkah > 0)
        {
            printf("Nimons bergerak sejauh %d langkah\n", banyak_langkah);
            total_langkah += banyak_langkah;
        }
        else
        {
            printf("Nimons tidak bergerak\n");
        }
        ketemu = temp % 10;
        temp /= 10;
        if (ketemu == 1)
        {
            printf("Nimons menemukan harta karun!\n");
            total_harta_karun++;
        }
        tutup = temp % 10;
        temp /= 10;
        if (tutup == 1)
        {
            printf("Nimons menutup lubang!\n");
            jumlah_lubang_ditutup++;
        }
    }
    int harga = temp;
    printf("\n");
    printf("Total lubang yang ditutup: %d dari %d lubang\n", jumlah_lubang_ditutup, jumlah_lubang);
    printf("Total harta karun yang ditemukan: %d\n", total_harta_karun);
    printf("Total harga harta karun yang ditemukan: %d\n", total_harta_karun*harga*5);
    printf("Total langkah yang ditempuh: %d\n", total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %d\n", harga*jumlah_lubang_ditutup);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n", (total_harta_karun*harga*5)-(harga*jumlah_lubang_ditutup));
}



void SelamatDatang(int input){
    int anak = input % 10;
    int dewasa = (input / 10) % 10;
    int lansia = input/100;
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    printf("Jumlah anak: %d\n", anak);
    printf("Jumlah dewasa: %d\n", dewasa);
    printf("Jumlah lansia: %d\n", lansia);
    PrintTiket(anak, dewasa, lansia);
}