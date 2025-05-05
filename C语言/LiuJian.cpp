#include<stdio.h>
#include<malloc.h>
#define MaxSize 30
typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;
void InitStack(SqStack*& s);//初始化栈
void DestroyStack(SqStack*& s);//销毁栈
bool StackEmpty(SqStack* s);//判断栈是否为空
bool Push(SqStack*& s, ElemType e);//进栈
bool Ismatch(char exp[], int n);//检验括号匹配

int main()
{
	int n;
	char exp[MaxSize];
	printf("\n请输入字符串字符数：");
	scanf("%d", &n);
	printf("\n请输入字符串：");
	for (int i = 0; i < n; i++) scanf("%c", &exp[i]);
	for (int i = 0; i < n; i++) printf("%c", exp[i]);
	if (Ismatch(exp, n))
		printf("\n括号匹配返回1");
	else printf("\n括号不匹配返回0");
	return 0;
}
void InitStack(SqStack*& s)                       //初始化
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
void DestroyStack(SqStack*& s)                   //销毁栈
{
	free(s);
}
bool StackEmpty(SqStack *s)                      //判断栈是否为空
{
	return(s->top == -1);
}
bool Push(SqStack*& s, ElemType e)               //进栈
{
	if (s->top == MaxSize - 1) return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s, ElemType& e)               //出栈
{
	if (s->top == -1) return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool Ismatch(ElemType exp[], int n)                 //检验括号匹配
{
	int i = 0;
	ElemType e;
	SqStack *s;
	InitStack(s);
	bool same = true;
	while (same && i < n)
	{
		if (exp[i] == '{' || exp[i] == '(')
			Push(s, exp[i]);
		else if (exp[i] == '}' || exp[i] == ')')
		{
			if (StackEmpty(s)) same = false;
			else
			{
				Pop(s, e);
				if (exp[i] == '}' && e == '(') same = false;
				if (exp[i] == ')' && e == '{') same = false;
			}
		}
		i++;
	}
	if (!StackEmpty(s)) same =false;
	DestroyStack(s);
	return same;
}
