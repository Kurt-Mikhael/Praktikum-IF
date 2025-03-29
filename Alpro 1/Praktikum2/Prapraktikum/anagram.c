#include <stdio.h>
#include <string.h>

// Fungsi untuk menghitung frekuensi karakter dalam string
int hitungFrekuensi(char str[100], char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c)  // str[i] mengakses karakter ke-i dari string
            count++;
    }
    return count;
}

// Fungsi untuk menentukan apakah dua string adalah anagram
int isAnagram(char str1[100], char str2[100]) {
    // Jika panjang string berbeda, bukan anagram
    if (strlen(str1) != strlen(str2))
        return 0;

    // Loop melalui setiap karakter di str1
    for (int i = 0; i < strlen(str1); i++) {
        char currentChar = str1[i];  // str1[i] mengakses karakter ke-i dari str1
        // Hitung frekuensi karakter di str1 dan str2
        int freq1 = hitungFrekuensi(str1, currentChar);
        int freq2 = hitungFrekuensi(str2, currentChar);
        // Jika frekuensi tidak sama, bukan anagram
        if (freq1 != freq2)
            return 0;
    }
    return 1;
}

int main() {
    char str1[100], str2[100];

    // Input dua string
    printf("Masukkan string pertama: ");
    scanf("%s", str1);  // str1 adalah array karakter, tapi dikirim sebagai pointer
    printf("Masukkan string kedua: ");
    scanf("%s", str2);  // str2 adalah array karakter, tapi dikirim sebagai pointer

    // Cek apakah anagram
    if (isAnagram(str1, str2))
        printf("Anagram\n");
    else
        printf("Bukan Anagram\n");

    return 0;
}