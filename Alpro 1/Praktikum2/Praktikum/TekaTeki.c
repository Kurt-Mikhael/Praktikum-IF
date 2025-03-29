#include <stdio.h>

long long  kombinasi(int n, int k){
    long long angka1 =1;
    long long angka2 =1;
    for(int i=1;i<=k;i++){
        angka1 *= n;
        n--;
        angka2 *= i;
    }
    long long hasil = angka1/angka2;
    return hasil;
}

long long catalan(int n){
    long long hasil = kombinasi(2*n,n)/(n+1);
    return hasil;
}