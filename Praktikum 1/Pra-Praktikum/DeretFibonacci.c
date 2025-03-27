#include <stdio.h>

int main(){
    int n;
    int angka1 = 0;
    int angka2 = 1;
    int angka3 ;
    scanf("%d",&n);

        printf("%d %d ",angka1, angka2);
        for(int i=3;i <=n; i++ ){
            angka3 = angka1+angka2;
            printf("%d",angka3);
            angka1 = angka2;
            angka2 = angka3;
            if(i== n){
                printf("");
            }
            else{
                printf(" ");
            }
    }
    
    printf("\n");
    return 0 ;
}