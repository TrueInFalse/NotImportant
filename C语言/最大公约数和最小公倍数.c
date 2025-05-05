#include <stdio.h>
int main()
{
    int M,N,a1,m,t,n1,n;
    scanf("%d %d",&M,&N);
    n1=M*N;
    if(M>N){
            a1=M%N;
            t=N;
        while(a1!=0){t=a1;a1=N%a1;N=t;}
            m=t;}
    if(M==N){m=M;}
    if(M<N){
             a1=N%M;
             t=M;
         while(a1!=0){t=a1;a1=M%a1;M=t;}
     m=t;}
    //printf("%d\n",m);
    //printf("%d\n",n);
    n=n1/m;
    printf("%d %d",m,n);
    return 0;
}
