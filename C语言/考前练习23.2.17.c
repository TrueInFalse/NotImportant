#include<stdio.h>
struct Student{
    int sex;
    char name[9];
}stu[50];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %s",&stu[i].sex,&stu[i].name[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=N-1;j>=i;j--){
            if(stu[i].sex!=stu[j].sex&&stu[j].sex!=3){
                printf("%s %s\n",stu[i].name,stu[j].name);
                stu[j].sex=3;
                break;
            }
        }
    }
    return 0;
}