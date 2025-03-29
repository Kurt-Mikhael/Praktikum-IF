#include <stdio.h>

int main(){
    int N; int c = 1; int d = 1;
    int a = 1; 

    int b = 1; 
    scanf("%d", &N);
    for(int i = 0; i < N; i++){

        int sekip = 0;

        int slese = 0;
        a = i;
        if(a == N-1){
            sekip = 1;
            slese = 1;
            a = N;
        }
        c = d;

        d = c;

        for(int j = 0; j < N; j++){
            printf("%d", c);


            if(j != N-1) printf(" ");
            if(sekip == 0){
                a += 1;
            } else{
                a -= 1;
            }
            c += a;
            if(a >= N-1 && slese == 0){
                slese = 1;
                sekip = 1;
                a++;
            }
        }
        b++;
        d += b;
        printf("\n");
    }
}