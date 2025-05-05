#include<stdio.h>
int main() 
{
	int n = 0;
	printf("请输入一个整数：");
	scanf("%d", &n);
	if (n == 1||n==2) {
		return 1;
	}else {
		int f1 = 1;
		int f2 = 1;
		int f3 = -1;
		for (int i = 3; i <= n; i++) {
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		printf("该整数的Fib数列是%d", f3);
	}
	return 0;
}