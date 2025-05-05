#include<stdio.h>
#include<string.h>
int main()
{
    int M=5,N=80;
    char a[M][N],tmp[N];
    int i,j;
    for(i=0;i<M;i++){
    scanf("%s",&a[i]);
    }
    for(i=1;i<M;i++){
        for(j=0;j<M-i;j++){
            if(strcmp(a[j],a[j+1])>0){
                strcpy(tmp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],tmp);
            }
        }
    }
    printf("After sorted:\n");
    for(i=0;i<M;i++){
        printf("%s\n",a[i]);
    }
    return 0;
 } 