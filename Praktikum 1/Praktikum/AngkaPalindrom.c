#include <stdio.h>
int main(){
    int n;
    int belakang;
    int sisa;
    int asli;
    belakang = 0;
    scanf("%d",&n);
    asli = n;
    while (n!=0)
    {
        sisa = n%10;
        belakang = belakang *10 +sisa;
        n/=10;
    }
    if(asli==belakang){
        printf("1");
    }
    else{
        printf("0");
    }
    
    printf("\n");
    return 0;
}