#include<stdio.h>
int main()
{
	int N,M,i=0;
	scanf("%d %d",&N,&M);
	double P[N];
    for(int i=0;i<N;i++){
		scanf("%lf",&P[i]);
		}	
	for(int i=0;i<N;i++){
		if(P[i]<M){
			printf("On Sale! %.1lf\n",P[i]);
		}
		}
	return 0;
}
