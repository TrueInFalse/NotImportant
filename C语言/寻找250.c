#include<stdio.h>
int main()
{
	int x,a;
	a=(x=5,x+2,x++);
	printf("%d",a);
	return 0;
}
