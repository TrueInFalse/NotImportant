#include<stdio.h>
int main()
{
    int n,x,y,i=0,k;
    scanf("%d",&n);
    k=n;
    for(x=1;x<k;x++)
    {

        for(y=0;y<n;y++)
            {
                if(x*x+y*y==n)
                    {
                        printf("%d %d\n",x,y);
                        i++;
                        k=y;
                    }
            }
    }
    if(i==0) printf("No Solution");

    return 0;

}
