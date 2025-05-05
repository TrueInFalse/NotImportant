#include<stdio.h>
int main()
{
    int n,x,y,X,Y;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    y=(n-1)/2;
    Y=(n-1)/2;
    x=0;
    X=0;
    a[x][y]=1;
    for(int i=2;i<=n*n;i++){
        if(x==0) X=n-1;
        	else X=x-1;
        if(y==n-1) Y=0;
        	else Y=y+1;
        if(a[X][Y]==0){
            a[X][Y]=i;
            x=X;
            y=Y;
        }
        	else{
            	if(x==n-1) X=0;
            		else X=x+1;
            	a[X][y]=i;
            	x=X;
        	}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}