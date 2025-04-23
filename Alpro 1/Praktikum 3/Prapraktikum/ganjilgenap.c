#include <stdio.h>
void sort(int arr[],int n){
    int temp;
    for(int i = 0; i < n; i++) {
        int min_ind = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[min_ind] > arr[j]) {
                min_ind = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
}
int main(){
    int n;
    int done = 0;
    scanf("%d",&n);
    int arr[n];
    int copy[n];
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
        copy[i]=arr[i];
    }
    sort(arr,n);
    sort(copy,n);
    int j =0;
    while(done!=2){
        if(done==0){
            for(int i =0;i<n;i++){
                if(copy[i]%2==0){
                    arr[j]= copy[i];
                    j++;
                }
            }
            done =1;
        }
        if(done==1){
            for(int i =0;i<n;i++){
                if(copy[i]%2!=0){
                    arr[j]= copy[i];
                    j++;
                }
            }
            done =2; 
        }
    }
        
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    } 
}