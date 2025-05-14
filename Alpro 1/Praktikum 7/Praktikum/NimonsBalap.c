#include <stdio.h>
#include"Boolean.h"
#include "listkontigu.h"


int main(){
    ListKontigu lIn;
    ListKontigu lOut;
    int n;
    readList(&lIn);
    scanf("%d", &n);
    CreateList(&lOut);
    int firstId = firstIdx(lIn);
    int len = listLength(lIn);

    int idxMax;
    int count = 0;

    int temp;
    while (count < len - n + 1) {
        idxMax = firstIdx(lIn);
        for (int i = firstIdx(lIn); i < firstIdx(lIn) + n; i++) {
            if (lIn.contents[idxMax] < lIn.contents[i]) idxMax = i;
        }
        insertLast(&lOut, lIn.contents[idxMax]);
        deleteFirst(&lIn, &temp);
        count++;
    }
    printList(lOut);
    printf("\n");
    return 0;
}