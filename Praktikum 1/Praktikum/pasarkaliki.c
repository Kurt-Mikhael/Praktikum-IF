#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    for (long long i = 0; i < n; i++) {

        for (long long s = 0; s < n - i - 1; s++) {
            printf(" ");
        }

        long long nilai = 1; 
        for (long long j = 0; j <= i; j++) {
            printf("%lld", nilai);
            nilai = nilai * (i - j) / (j + 1);
            if(j !=i){
                printf(" ");
            }
            else{
                printf("");}
        }
        printf("\n");
    }

    return 0;
}