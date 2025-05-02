#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l;
    
    CreateListStatik(&l);
    int n;
    int idx;
    int  angka;
    int diambil;

    scanf("%d", &n);
    while(n != -1){

        if( n == 1 ){

            scanf("%d %d", &angka, &idx);
            if( isFull(l) ){
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
            else if( isIdxValid(l,idx) && idx <= listLength(l) ){
                insertAt(&l, angka, idx);
            }
            else{
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
            printList(l);
            printf("\n");
        }
        else{
            scanf("%d", &idx);
            if ( isEmpty(l) ){
                printf("Aw, gabisa ngelakuin aksi itu\n");
            }
            else if( isIdxEff(l,idx) ){
                deleteAt(&l, &diambil, idx);
            }
            else{
                printf("Aw, gabisa ngelakuin aksi itu\n");

            }
            printList(l);

            printf("\n");
        }
        
        scanf("%d", &n);
    }
}