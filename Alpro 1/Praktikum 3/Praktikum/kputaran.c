#include <stdio.h>

int main(){
    int geser;
    int n;
    scanf("%d",&n);
    scanf("%d",&geser);
    int arr[n];
    for(int i  = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<geser;i++){
        int terakhir = arr[n-1];
        for(int j=n-1;j>=0;j--){
            if(j==0){
                arr[j]= terakhir;
            }
            else{
                arr[j]= arr[j-1];
            }
        }
    }
    for(int i  = 0;i<n;i++){
        printf("%d",arr[i]);
        if(i==n-1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}