#include <stdio.h>

int main() {
    int jumlahRumah, jumlahVirus;
    scanf("%d %d", &jumlahRumah, &jumlahVirus);
    
    long long afinitas[jumlahRumah], afinitasUrut[jumlahRumah];
    long long nilaiMaks = 0, nilaiAlternatif = 0;
    
    for(int i = 0; i < jumlahRumah; i++) {
        scanf("%lld", &afinitas[i]);
        afinitasUrut[i] = afinitas[i];
    }
    
    for(int i = 0; i < jumlahRumah-1; i++) {
        for(int j = 0; j < jumlahRumah-i-1; j++) {
            if(afinitasUrut[j] > afinitasUrut[j+1]) {
                long long temp = afinitasUrut[j];
                afinitasUrut[j] = afinitasUrut[j+1];
                afinitasUrut[j+1] = temp;
            }
        }
    }
    
    long long ujungBesar = (afinitas[0] >= afinitas[jumlahRumah-1]) 
                         ? afinitas[0] : afinitas[jumlahRumah-1];
    
    nilaiMaks = ujungBesar;
    nilaiMaks += (afinitasUrut[jumlahRumah-1] == ujungBesar) 
               ? afinitasUrut[jumlahRumah-2] 
               : afinitasUrut[jumlahRumah-1];
    
    if(jumlahVirus > 1) {
        int sisa = jumlahVirus + 1;
        for(int i = jumlahRumah-1; i >= 0; i--) {
            if(afinitasUrut[i] < 0 && sisa < jumlahVirus-1) break;
            nilaiAlternatif += afinitasUrut[i];
            sisa--;
            if(sisa == 0) break;
        }
    }
    
    if(nilaiAlternatif > nilaiMaks) {
        nilaiMaks = nilaiAlternatif;
    }
    
    printf("%lld\n", nilaiMaks);
    return 0;
}