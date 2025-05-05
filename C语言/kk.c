#include<stdio.h>
void ExchangeData1(int a,int b){
 int c;
 c=a;
 a=b;
 b=c;
 printf("%d,%d\n",a,b);
}
void ExchangeData2(int*pa,int*pb){
 int c;
 c=pa[0];
 pa[0]=pb[0];
 pb[0]=c;
}
void ExchangeData3(int pa[],int pb[]){
 int c;
 c=*pa;
 *pa=*pb;
 *pb=c;
}
void ExchangeData4(int &a,int &b){
 int c;
 c=a;
 a=b;
 b=c;
}
int main(){
 int x=5,y=10;
 ExchangeData1(x,y);
 x=5,y=10;
 ExchangeData2(&x,&y);
 printf("%d,%d\n",x,y);
 x=5,y=10;
 ExchangeData3(&x,&y);
 printf("%d,%d\n",x,y);
 x=5,y=10;
 ExchangeData4(x,y);
 printf("%d,%d\n",x,y);
}