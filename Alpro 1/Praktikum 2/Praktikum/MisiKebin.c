#include <stdio.h>
void countPrime(int *A, int *B, int *total){
    if(*A>*B){
        for(int i = *B;i<=*A;i++){
            int flag = 1;
            for(int j = 2;j<i;j++){
                if(i%j == 0){
                    flag = 0;
                }
            }
            if (flag ==1 && i != 1){
                (*total)++;
        }
    }
}
    else {
        for(int i = *A;i<=*B;i++){
            int flag = 1;
            for(int j = 2;j<i;j++){
                if(i%j == 0){
                    flag = 0;
                }
            }
            if (flag ==1 && i != 1){
                (*total)++;
        }
    }

    }
}

int main()
{
    int angka1,angka2 , jumlah;
    jumlah = 0;
    scanf("%d %d",&angka1,&angka2);
    countPrime(&angka1, &angka2, &jumlah);
    printf("%d\n", jumlah);
    return 0;
}