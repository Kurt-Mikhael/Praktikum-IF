#include <stdio.h>
#include "time.h"
#include "boolean.h"

int main(){
    int  n;
    TIME t1,t2;
    scanf("%d",&n);
    long min = __LONG_MAX__;
    long max = -1;
    TIME nulismin;
    TIME nulismax;
    int i = 0;
    while (i != n){
        printf("[%d]\n",i+1);
        BacaTIME(&t1);
        BacaTIME(&t2);
        long detik1 = TIMEToDetik(t1);
        long detik2 = TIMEToDetik(t2);
        long durasi;
        if (detik1  < detik2){
            durasi = detik2 - detik1;
            if(detik1 < min){
                min = detik1;
                nulismin = t1;
            }
            if(detik2 > max){
                max = detik2;
                nulismax = t2;
            }
        }
        else if (detik1 > detik2){
            durasi = detik1 - detik2;
            if(detik2 < min){
                min = detik2;
                nulismin = t2;
            }
            if(detik1 > max){
                max = detik1;
                nulismax = t1;
            }
        }
        else if (detik1 == detik2){
            durasi = 0;
            if(detik1 < min){
                min = detik1;
                nulismin = t1;
            }
            if(detik2 > max){
                max = detik2;
                nulismax = t2;
            }
        }
        printf("%ld\n",durasi);
        i++;
    }
    TulisTIME(nulismin);
    printf("\n");
    TulisTIME(nulismax);
    printf("\n");
    return 0;
}