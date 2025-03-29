#include <stdio.h>

int permutasi(int x,int y){
    int doll = x;
    int angka = 1;
    for(int i=1;i<=y;i++){
        angka*= doll ;
        doll--;
    }
    return angka;
}

int kombinasi(int x,int y){
    int doll1= x ;
    int doll2 = 1;
    int angka1 = 1;int angka2 = 1;
    for(int i = 1 ; i<=y;i++){
        angka1*= doll1;
        doll1--;
        angka2 *= doll2;
        doll2 ++;
    }
    return angka1/angka2;
}
int main(){
    int a,b; 
    int per,kom;
    scanf("%d %d",&a,&b);
    kom = kombinasi(a,b);
    per= permutasi(a,b);
    printf("%d %d",kom, per);

}
    