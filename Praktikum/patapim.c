
#include <stdio.h>
#include "listdin.h"

int GCD(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    ListDin l;
    CreateListDin(&l, 1000000);
    readList(&l);

    int min = l.buffer[0];
    for (int i = 1; i < NEFF(l); i++){
        if (l.buffer[i] < min){
            min = l.buffer[i];
        }
    }
    int gcd = 0;
    for (int i = 0; i < NEFF(l); i++){
        if(l.buffer[i] != min){
            int selisih = l.buffer[i] - min;
            gcd = GCD(gcd, selisih);
        }
    }
    printf("%d\n", gcd);
    return 0;
}