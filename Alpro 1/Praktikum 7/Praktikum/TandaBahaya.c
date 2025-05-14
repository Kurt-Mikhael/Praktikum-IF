#include <stdio.h>
#include"Boolean.h"
#include "listkontigu.h"

int main(){
    ListKontigu l;
    int n;
    CreateList(&l);
    readList(&l);
    for(int i =0;i<listLength(l)-2;i++){
        for(int j = i+1;j<listLength(l)-1;j++){
            for(int k = j+1;k<listLength(l);k++){
                if(l.contents[i]<l.contents[k] && l.contents[k]<l.contents[j]){
                    printf("Nyalakan\n");
                    return 0;
                }
            }
        }
    }
    printf("Santai\n");
    return 0;
}
