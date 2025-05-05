#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d=",n);
    int k = 2;
    while(k <= n){
        if(n%k == 0){
            printf("%d", k);
             if(k<n){printf("*");}
            n /= k;
        }
        else
            k++;
    }
    return 0;
}
