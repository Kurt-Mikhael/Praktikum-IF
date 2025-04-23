#include <stdio.h>
#include <string.h>

int main(){
    char kata[1001];
    scanf("%s",kata);
    int len = strlen(kata);
    int udah[1001]= {0};
    int ganjil = 0;
    for(int i =0;i<len;i++){
        if(udah[i]==1) continue;
        int count =0;
        char huruf = kata[i];
        for(int k=0;k<len;k++){
            if(kata[k]==huruf) count++;
        }
        for(int j =i+1;j<len;j++){
            if(kata[j]== huruf){
                udah[i]=1;
                udah[j]= 1;
            }
        }
        if(count %2!=0){
            ganjil ++;
        }
    }
    if(ganjil>1){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return 0;
}