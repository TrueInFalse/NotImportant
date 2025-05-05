#include<stdio.h>
#include<math.h>
double sqr(double x);
double T[11] = {0, 8.99, 2.48, 1.59, 1.24, 1.05, 0.93, 0.84, 0.77, 0.72}; 
int main()
{
	int n;
	double a[101], sum, ave, bessel, sum1, disconfirmA, disconfirmB, result;
	printf("请输入数据个数\n");
	scanf("%d", &n);
	printf("请输入%d组数据\n", n);  
	for(int i = 1;i <= n; i++) scanf("%lf", &a[i]);
	
	// 求平均数 
	for(int i = 1;i <= n; i++)
	{
		sum = sum + a[i];
	}
	ave =  sum / n;
	
	//求解各组数据减去平均数的平方差 
	for(int i = 1;i <= n; i++)
	{
		sum1 = sum1 + sqr(a[i] - ave); 
	}
	bessel = sqrt(sum1 / (n - 1));
	disconfirmA = bessel * T[n]; 
	printf("平均值为：%lf", ave);
	printf("贝塞尔公式的值：%lf\n", bessel);
	printf("A类不确定度为：%lf\n", disconfirmA);
	printf("TIPS:不要忘记单位\n");
}	

double sqr(double x)
{
	return x*x; 
}
