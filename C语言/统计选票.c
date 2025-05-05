#include<stdio.h>
int main()
{
	int T=0,J=0,S=0,I=0,i=0;
	while(i>=0){
		scanf("%d",&i);
		switch(i){
			case 1:T++;
			break;
			case 2:J++;
			break;
			case 3:S++;
			break;
			case 0:I++;
			break;
			case 4:I++;
			break;
		}
	}
	if(T<=I&&J<=I&&S<=I){
		printf("Tom = %d Jerry = %d Spike = %d Invalid = %d\nElection invalid!",T,J,S,I);
	}
	else printf("Tom = %d Jerry = %d Spike = %d Invalid = %d",T,J,S,I);
	return 0;
}
