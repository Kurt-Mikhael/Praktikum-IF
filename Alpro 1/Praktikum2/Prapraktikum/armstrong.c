#include <stdio.h>

int main(){
    int n, doll;
    int jumlah = 0;
    scanf("%d",&n);
    doll = n;
    while (n!=0)
    {
        int angka = n % 10;
        jumlah += angka*angka*angka;
        n /= 10;
    }
    if(jumlah == doll){
        printf("Armstrong");
    }
    else {
        printf("Bukan armstrong");
    }
}