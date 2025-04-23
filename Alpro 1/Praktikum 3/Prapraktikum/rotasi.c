#include <stdio.h>
void rotasi90(int arr[],int n){
    int doll[n*n];
    for(int i=0;i<n*n;i++){
        doll[i]= arr[i];
    }
    int ind_depan =0;
    int ind_belakang = (n*n)-n;
    int indeks = ind_belakang;
    while(ind_depan!=n*n){
        arr[ind_depan]= doll[indeks];
        ind_depan ++;
        indeks -= n;
        if(ind_depan%n==0){
            ind_belakang ++;
            indeks = ind_belakang;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n*n];
    for(int i =0;i<n*n;i++){
        scanf("%d",&arr[i]);
    }
    rotasi90(arr,n);
    for(int i =0;i<n*n;i++){
        printf("%d",arr[i]);
        if((i == n*n -1)||(i+1)%n ==0){
            printf("\n");
        }
        else printf(" ");
    }
}