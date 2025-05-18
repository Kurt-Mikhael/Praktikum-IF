#include <stdio.h>
#include "matrix.h"

int main(){
    Matrix M;
    int n, m, k, x;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    readMatrix(&M,n,m);
    int cnt = 0;
    for(int i = 0; i <= n - k; i++){
        for(int j = 0; j <= m - k; j++){
            int sum = 0;
            for(int a = i; a < i + k; a++){
                for(int b = j; b < j + k; b++){
                    sum += M.mem[a][b];
                }
            }
            if(sum <= x){
                cnt++;
            }
        }
    }

    printf("%d\n",cnt);
    return 0;
}


