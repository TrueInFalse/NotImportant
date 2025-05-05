#include <stdio.h>
int main()
{
    int A,i,j,k,c=0;
    scanf("%d",&A);
    for(i=A; i<=A+3; i++)
    {
        for(j=A; j<=A+3; j++)
        {
            for(k=A; k<=A+3; k++)
            {
                if((i!=j)&&(j!=k)&&(k!=i))
                {
                    c++;
                    printf("%d%d%d",i,j,k);
                    if(c==6)
                    {
                        printf("\n");
                        c=0;
                    }
                    else
                        printf(" ");
                }
            }
        }
    }
    return 0;
}
