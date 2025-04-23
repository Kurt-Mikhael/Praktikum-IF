#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int arr_i[2];
    int jumlah;
    int angka1,angka2;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&jumlah);
    int done =0;
    while (done==0){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i]+arr[j])==jumlah){
                    angka1=i;
                    angka2 =j;
                    done = 1;
                }
            }
            if(done==1)break;;
        }
    }
    printf("[%d, %d]\n",angka1,angka2);
    return 0;
}