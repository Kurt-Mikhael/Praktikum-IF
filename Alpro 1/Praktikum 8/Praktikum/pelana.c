#include <stdio.h>
#include "matrix.h"
//#include "matrix.c"

int main(){
    Matrix m;
    int r, k;
    int cnt = 0;
    scanf("%d %d", &r, &k);
    readMatrix(&m, r, k);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < k; j++){
            int flag = 1;
            for(int x = 0; x < k; x++){
                if(m.mem[i][j] > m.mem[i][x]){
                    flag = 0;
                    break;
                }
            }
            for(int y = 0; y < r; y++){
                if(m.mem[i][j] < m.mem[y][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                printf("(%d,%d,%d)\n", i, j, m.mem[i][j]);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}
