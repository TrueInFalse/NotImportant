#include<stdio.h>
int main()
{
	int h,m;
	scanf("%02d:%02d",&h,&m);
	if((h>12&&h<24)||(h==12&&m!=0)){
		if(m!=0){for(int i=0;i<(h-11);i++){
			printf("Dang");
		}}
		if(m==0){for(int i=0;i<(h-12);i++){
					printf("Dang");
				}}
	}
	if(h<12||h>=24||(h==12&&m==0))printf("Only %02d:%02d.  Too early to Dang.",h,m);
	return 0;
}
