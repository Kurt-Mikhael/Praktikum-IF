#include "Boolean.h"
#include <stdio.h>
#include "listkontigu.h"


int isSorted(ListKontigu l){
    for(int i = 0; i<listLength(l)-1;i++){
        if(l.contents[i] > l.contents[i+1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    ListKontigu l;
    CreateList(&l);
    int flag =1;
    int idxGreater;
    readList(&l);
    int sorted = isSorted(l);
    if(sorted == 1){
        printf("YA\n");
        return 0;
    }
    else{
        for(int i = 0; i<listLength(l);i++){
            if(l.contents[i] > l.contents[i+1]){
                idxGreater = i;
                break;
            }
        }
        int idxLast = lastIdx(l);
        ListKontigu lCopy;
        CreateList(&lCopy);
        copyList(l,&lCopy);
        while(idxGreater < idxLast){
            int idxTempLast = idxLast;
            copyList(lCopy,&l);
            for(int i = idxGreater; i<=idxLast;i++){
                l.contents[i] = lCopy.contents[idxTempLast--];
            }
            if(isSorted(l) == 1){
                printf("YA\n");
                printf("%d %d\n", idxGreater, idxLast);
                return 0;
            }
            idxLast--;
        }
    }
    printf("TIDAK\n");
    return 0;
}