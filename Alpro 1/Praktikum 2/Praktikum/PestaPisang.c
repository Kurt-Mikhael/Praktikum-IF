#include <stdio.h>
#include <math.h>
int jumlah(int a,int b,int c,int d,int e){
    return a+b+c+d+e;
}
double avg(int n){
    return n/5.0f;
}
void hai(int n){
    if(n>=10){
        printf("Pesta Nimons Sukses!\n");
    }
    else{
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}
int main(){
    int n1,n2,n3,n4,n5;
    int total=0; double rata=0.0;
    scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
    total = jumlah(n1,n2,n3,n4,n5);
    rata = avg(total);
    printf("%d\n",total);
    printf("%lf\n",rata);
    hai(rata);
    return 0;
}