#include <stdio.h>


int main() {
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
    while (B != 0) {
        int temp = B;  
        B = A % B;   
        A = temp;   
    }
    printf("%d", A);
    printf("\n");
    return 0;
}