#include <stdio.h>

int main(){
    int list[5]={1,2,3,4,5};
    for(int i = 0;i<4;i++){
        for(int j = 4;j>i;j--){
            if(list[j] > list[j-1]){
                int temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
            }
        }
    }
    for(int i = 0;i<5;i++){
        printf("%d ",list[i]);
    }
    printf("\n");

    for(int i = 0;i<4;i++){
        for(int j = 0;j<4-i;j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    for(int i = 0;i<5;i++){
        printf("%d ",list[i]);
    }
    printf("\n");
    return 0;
}