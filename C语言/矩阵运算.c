#include <stdio.h>
int main()
{
    int n,sum=0,s1=0,s2=0,s3=0,s4=0;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            scanf("%d",&a[i][k]);
        }
    }
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            s1=s1+a[i][k];
        }
    }
    for(int i=0;i<n;i++){
        s2=s2+a[i][n-1];
        s3=s3+a[n-1][i];
    }
    for(int i=0;i<n;i++){
        s4=s4+a[i][n-1-i];
    }
    sum=s1-(s2+s3+s4-(a[0][n-1]+a[n-1][n-1]+a[n-1][0]));
    printf("%d",sum);
    return 0;
}