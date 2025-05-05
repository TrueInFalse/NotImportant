#include<stdio.h>
int main()
{
    int N;
    char x,y;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int l=0;l<4;l++){
            scanf("%c-%c",&x,&y);
                if(x=='A'&&y=='T'){printf("1");}
                if(x=='B'&&y=='T'){printf("2");}
                if(x=='C'&&y=='T'){printf("3");}
                if(x=='D'&&y=='T'){printf("4");}
            }
        }
    return 0;
}

