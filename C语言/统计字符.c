#include<stdio.h>
int main()
{
	int l=0,b=-1,d=0,o=0,i=0,a;
	a=getchar();
	if((a>=65&&a<=90)||(a>=97&&a<=122)||(a==32)||(a==10)||((a>=48)&&(a<=57)))
	{
	if((a>=65&&a<=90)||(a>=97&&a<=122)){l++;}
	if((a==32)||(a==10)){b++;}
	if((a>=48)&&(a<=57)){d++;}
	}
	else o++;
	for(i=0;i<10;i++){
			a=getchar();
			if((a>=65&&a<=90)||(a>=97&&a<=122)||(a==32)||(a==10)||((a>=48)&&(a<=57)))
			{
			if((a>=65&&a<=90)||(a>=97&&a<=122)){l++;}
			if((a==32)||(a==10)){b++;}
			if((a>=48)&&(a<=57)){d++;}
			}
			else o++;
			}
	printf("letter = %d, blank = %d, digit = %d, other = %d",l,b,d,o);
	return 0;
}
