
#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik l1,l2;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    readList(&l1);
    readList(&l2);
    int len1 = listLength(l1);
    int len2 = listLength(l2);

    ListStatik l3;
    CreateListStatik(&l3);
    for(int i = 0;i<len1;i++){
        l3.contents[i]= l1.contents[i];
    }
    for(int i = 0;i<len2;i++){
        l3.contents[i+len1]= l2.contents[i];
    }
    sortList(&l3, TRUE);

    printList(l3);
    printf("\n");
    return 0;
    

}