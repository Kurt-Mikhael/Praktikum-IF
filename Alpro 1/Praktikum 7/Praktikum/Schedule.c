#include "Boolean.h"
#include <stdio.h>
#include "listkontigu.h"

int main() {
    ListKontigu l;
    int n;
    scanf("%d", &n);

    int list_element;
    CreateList(&l);
    int idxGreater;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &list_element);
        if (i == 0) insertFirst(&l, list_element);
        else {
            idxGreater = IDX_UNDEF;
            for (int j = 0; j < listLength(l); j++) {
                if (l.contents[j] > list_element) {
                    idxGreater = j;
                    break;
                }
            }

            if (idxGreater == IDX_UNDEF) insertLast(&l, list_element);
            else {
                insertAt(&l, list_element, idxGreater);
            }
        }

        printList(l);
        printf("\n");
    }
    return 0;
}