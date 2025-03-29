#include <stdio.h>
int main(){
    int a;
    int b;
    int n;
    scanf("%d",&n);
    int temp = n;
    int tengah = n/2 +1 ;
    a = n/2 + 1 ;
    b = n/2 + 1 ;
    while (temp != 0){
        if(temp>tengah){
            if (a==b){
                    for(int i=1;i<=n;i++){
                        if(i!=a){
                            printf(".");
                        }
                        else{
                            printf("*");
                        }
                    }
                    printf("\n");
                    a-=1 ;
                    b += 1 ;
                    temp -= 1 ;
            }

            else {
                    for(int i=1;i<=n;i++){
                        if(i == a){
                            printf("*");
                        }
                        else if(i==b){
                            printf("*");
                        }
                        else{
                            printf(".");
                        }
                        
                    }
                    a -= 1;
                    b += 1 ;
                    temp -= 1 ;
                    printf("\n");
                    
                }
            }
        else{
                if (a==b){
                    for(int i=1;i<=n;i++){
                        if(i!=a){
                            printf(".");
                        }
                        else{
                            printf("*");
                        }
                    }
                    printf("\n");
                    a+=1 ;
                    b -= 1 ;
                    temp -= 1 ;
                }
                else{
                    for(int i=1;i<=n;i++){
                        if(i == a){
                            printf("*");
                        }
                        else if(i==b){
                            printf("*");
                        }
                        else{
                            printf(".");
                        }
                    }
                    a += 1;
                    b -= 1 ;
                    temp -= 1 ;
                    printf("\n");
                }
                
            }
    }
    return 0;
}