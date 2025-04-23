#include <stdio.h>

int main(){
    int banyak_e,banyak_r,langkah;
    scanf("%d",&banyak_e);
    scanf("%d",&banyak_r);
    int array[banyak_e];
    int doll[banyak_e] ;
    int array_langkah[banyak_r];
    for(int i = 0;i<banyak_e;i++){
        int angka;
        scanf("%d",&angka);
        array[i]= angka;
        doll[i]= array[i];
    }
    for(int i = 0;i<banyak_r;i++){
        int n;
        scanf("%d",&n);
        array_langkah[i]= n;
    }
    for(int i = 0;i<banyak_r;i++){
        for(int h = 0; h < banyak_e; h++) {
            array[h] = doll[h];
        }
        langkah = array_langkah[i];
        for(int j=0;j<langkah;j++){
            int last = array[banyak_e-1];
            for(int v= banyak_e-1;v>=0;v--){
                if(v==0){
                    array[v]=last;
                }
                else{
                    array[v]= array[v-1];
                }
            }
        }
        printf("[");
        for(int h=0;h<banyak_e;h++){
            printf("%d",array[h]);
            if(h==banyak_e-1)printf("]");
            else printf(", ");
        }
        printf("\n");
    }
    return 0;
}