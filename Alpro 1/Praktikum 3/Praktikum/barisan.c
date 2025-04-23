#include <stdio.h>

int hitungFPB(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int hitungKPK(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return (a * b) / hitungFPB(a, b);
}

int main(){
    int n,skor;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int  maks =0;
    for(int lewat =-1;lewat<n;lewat++){
        int kpk=1; int fpb = 0;
        for(int i = 0;i<n;i++){
            if(i==lewat) continue;
            fpb = hitungFPB(fpb,array[i]);
            kpk = hitungKPK(kpk,array[i]);
        }
        skor = kpk*fpb;
        if(skor >maks){
            maks = skor;
        }
    }
    printf("%d\n",maks);
    return 0;
}