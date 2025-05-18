#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix m;
    int x;
    scanf("%d", &x);
    readMatrix(&m,x,x);
    int dikenal[x];
    int mengenal[x];
    for(int i = 0; i < x; i++){
        dikenal[i] = 0;
        mengenal[i] = 0;
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            if(m.mem[i][j]==1){
                dikenal[j]++;
                mengenal[i]++;
            }
        }
    }

    for(int i = 0; i < x; i++){
        if(dikenal[i] == x && mengenal[i] == 1){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

