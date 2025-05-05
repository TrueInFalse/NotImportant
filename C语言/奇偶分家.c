#include<stdio.h>
int main()
{
	int N,ru,i=0,o=0;
	scanf("%d\n",&N);
    while(i+o!=N)
	{
    	scanf("%d",&ru);
    	switch(ru%2)
		{
			case 1:i++;
				break;
			case 0:o++;
				break;
		}
	}
	printf("%d %d",i,o);	
	return 0;
}
