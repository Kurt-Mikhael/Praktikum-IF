#include <stdio.h>

int main(){
    int n, i, pangkat, sblm_ada=0;
    scanf("%d", &n);

    if (n<=1){
        printf("Masukkan bilangan lebih besar dari 1\n");
    }
    else if(n==1){
        printf("1\n");
    }
    else{
        pangkat = 0;
        while (n % 2 == 0){
            pangkat = pangkat + 1;
            n/=2;
        }
        if(pangkat>0){
            sblm_ada = 1;
            printf("%d", 2);
            if(pangkat>1){
                printf("^%d", pangkat);
            }
        }
        for (i=3; i*i<= n;i+=2){
            pangkat = 0;
            while(n%i==0){
                pangkat = pangkat + 1;
                n/=i;
            }
            if(pangkat>0){
                if(sblm_ada == 1){
                    printf(" * ");
                }
                sblm_ada = 1;
                printf("%d",i);
                if(pangkat>1){
                    printf("^%d", pangkat);
                }
            }
        }

        if(n>2){
            if(sblm_ada == 1){
                printf(" * ");
            }
            printf("%d", n);
        }
        printf("\n");
    }
    return 0;
}