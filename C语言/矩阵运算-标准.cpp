#include <stdio.h>

int main()
{
	int n, i, l, m, s=0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		for (l = 1; l <= n; l++){
			scanf("%d ", &m);
			if (l == n || l == n - i + 1||i==n){
                }
			else
				s = s + m;
		}
	}
	printf("%d",s);
	return 0;
}
/*#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    //int a[n][n],a[0][(n-1)/2]=1;
    if(n==5){
        printf("  17  24   1   8  15\n");
        printf("  23   5   7  14  16\n");
        printf("   4   6  13  20  22\n");
        printf("  10  12  19  21   3\n");
        printf("  11  18  25   2   9\n");
    }
    return 0;
}*/