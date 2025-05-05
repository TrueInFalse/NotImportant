#define _CRT_SECURE_NO_WANRNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.1415926
double av(int n, double* arr)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    sum = sum / n;
    return sum;
}
int main()
{
    double t1 = 0.0;
    double t2 = 0.0;
    double m, m1, m2, P0, P1, N1, N2, O;
    double Um, H5, UAh, UBh, Uh, D5, d, UAd, UBd, Ud, P, Up, Up1, Ep, Ep1;
    int n;
    double* p;
    double* l;
    printf("请输入高或直径的个数（一般为5看具体情况）：");
    scanf("%d", &n);
    p = (double*)malloc(n * sizeof(double));
    l = (double*)malloc(n * sizeof(double));
    printf("\n请输入%d组数据：\n", n);
    printf("\n请输入直径D（每个数据用空格隔开！）：");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &p[i]);
    }
    D5 = av(n, p);
    printf("\n请输入n组高H（每个数据用空格隔开！）:", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &l[i]);
    }
    H5 = av(n, l);
    printf("\n请输入圆柱体质量m:");
    scanf("%lf", &m);
    printf("\n不规则物体在空气中质量m1:");
    scanf("%lf", &m1);
    printf("\n不规则物体在水中质量m2:");
    scanf("%lf", &m2);
    printf("\n水在t温度下的密度P0(书本338页，表七):");
    scanf("%lf", &P0);
    printf("\n请输入天平的分度值N1:");
    scanf("%lf", &N1);
    printf("\n请输入千分尺的分度值N1:");
    scanf("%lf", &N2);
    printf("\n请输入千分尺的的零点读数O(有正负！):");
    scanf("%lf", &O);
    Um = N1 / sqrt(3);
    for (int i = 0; i < n - 1; i++)
    {
        t1 += pow(l[i] - H5, 2);
    }
    UAh = sqrt(t1 / n * (n - 1));
    UBh = N2 / sqrt(3);
    Uh = sqrt(pow(UAh, 2) + pow(UBh, 2));
    for (int i = 0; i < n - 1; i++)
    {
        t2 += pow(p[i] - D5, 2);
    }
    UAd = sqrt(t2 / n * (n - 1));
    UBd = N1 / sqrt(3);
    Ud = sqrt(pow(UAd, 2) + pow(UBd, 2));
    P = 4 * m / (pi * pow((D5 - O), 2) * H5);
    Ep = sqrt(pow(Um, 2) / pow(m, 2) + 2 * pow(Ud, 2) / pow(D5 - O, 2) + pow(Uh, 2) / pow(H5, 2));
    Up = P * Ep;
    P1 = P0 * m1 / (m1 - m2);
    Ep1 = sqrt(pow(Um, 2) / pow(m1, 2) + 2 * pow(Um, 2) / pow(m1 - m2, 2) + pow(Um, 2) / pow(m1 - m2, 2));
    Up1 = P1 * Ep1;
    printf("圆柱体的结果：\n");
    printf("Um=%.4lf\n", Um);
    printf("m+-Um=%lf+-%lf\n", m, Um);
    printf("高度H的均值是：%.4lf\n", H5);
    printf("UAh=%.4lf\n", UAh);
    printf("UBh=%.4lf\n", UBh);
    printf("Uh=%.4lf\n", Uh);
    printf("h+-Uh=%.4lf+-%.4lf\n", H5, Uh);
    printf("圆柱体直径的均值：%.4lf\n", D5);
    printf("d(即减去零点读数后的值)=%.4lf", D5 - O);
    printf("d+-Ud=%.4lf+-%.4lf\n", D5 - O, Ud);
    printf("圆柱体的密度P=%.4lf\n", P);
    printf("圆柱体的相对不确定度Ep=%.3lf\n", Ep);
    printf("圆柱体的合成不确定度Up=%.4lf", Up);
 
    printf("不规则的结果：\n");
    printf("Um=%.4lf\n", Um);
    printf("p=%.4lf+-%.4lf", P, Up);
    printf("不规则的密度P=%.4lf\n", P);
    printf("不规则的相对不确定度Ep=%.3lf\n", Ep1);
    printf("不规则的合成不确定度Up=%.4lf\n", Up1);
    printf("p=%.4lf+-%.4lf", P1, Up1);
 
    free(p);
    free(l);
    return 0;
}