#include<stdio.h>
int main()
{
	int N,i,t=1,k=0;
	double r=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++,k++){
		r=r+t*(i*1./(2*k+1));
		t=-t;
	}
	printf("%.3lf",r);
	return 0;
}
