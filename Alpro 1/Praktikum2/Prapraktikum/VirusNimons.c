#include <stdio.h>
#include <math.h>

long long main(){
    long long a;
    long long b;
    long long c;
    scanf("%lld %lld %lld",&a,&b,&c);
    long long awal = a ;
    for(int i=1;i<=b;i++){
        a = a *c;
        a += awal;
    }
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%lld",a,b);
    printf("\n");
    return 0 ;
}