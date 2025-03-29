int main(){
    int a = 0;
    int b;
    int n;
    scanf("%d",&n);
    for(int  i =1 ; i<=n;i++){
        if (n%i == 0){
            for(int j = 1; j <=i;j++){
                if(j*j==i){
                    a ++;
                }
            }
        }
    }
    printf("%d");
}