#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define MaxSize 30

typedef struct
{
	char data[MaxSize];
	int top;
}SqStack;


typedef struct
{
	int data[MaxSize];
	int front;
	int rear;
}SqQueue;


//栈
void initstack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
bool stackempty(SqStack* s)
{
	return(s->top == -1);
}
bool Push(SqStack& S, char x)
{
	if (S.top == (MaxSize - 1))
		return false;
	S.data[++S.top] = x;
	return true;
}
bool Pop(SqStack& S, char& x)
{
	if (S.top == -1)
		return false;
	x = S.data[S.top--];
	return true;
}
bool Ismatch(char str[], int length)
{
	SqStack* S;

	initstack(S);
	for (int i = 0; i < length; i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			Push(*S, str[i]);
		}
		else {
			if ((str[i] == ')' || str[i] == '}' || str[i] == ']') && stackempty(S))return false;

			char topElem;
			Pop(*S, topElem);
			if (str[i] == ')' && topElem != '(')return false;
			if (str[i] == '}' && topElem != '{')return false;
			if (str[i] == ']' && topElem != '[')return false;
		}
	}
	return stackempty(S);

}
//队列
void initqueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;///////////////////////////////////////////
}

bool queueempty(SqQueue* q)
{
	return(q->front == q->rear);
}

bool enqueue(SqQueue*& q, int e)
{
	if((q->rear+1)%MaxSize==q->front) return false;///////////////////////////////////
	q->rear=(q->rear+1)%MaxSize;
	q->data[q->rear] = e;
	return true;
}

bool dequeue(SqQueue*& q, int &e)
{
	if (q->front == q->rear) return false;
	q->front=(q->front+1)%MaxSize;
	e = q->data[q->front];
	return true;
}

void destroyqueue(SqQueue*&q)
{
	free(q);
}

void baoshu(int n)
{
	int i=1;
	int count = 1;
	int j;
	SqQueue* q;
	initqueue(q);
	for (; i <= n;)
	{
		enqueue(q,i);//遍历队列
		i=i+1;
	}
	/*for (i = 1; i <= n;i++)
	{
		int temp;
		dequeue(q,temp);
		printf("%d ",temp);//遍历队列
	}*/
	while (!queueempty(q))//队列非空循环持续执行
	{
		
		dequeue(q,j);//弹出队首元素
		if (count% 2 == 0) enqueue(q, j);//进队尾
	
		else printf("%d",j);
		count++;
		/*if(!queueempty(q))
		{
			dequeue(q,j);
			enqueue(q, j);
		}*/
		
	}
	printf("\n");
	destroyqueue(q);
}

int main()
{
	int i, j=0;
	int judge;
	int code;
	char k[MaxSize];
	printf("-------------------------\n");
	printf("请输入你想进行的操作所对应的编号:\n");
	printf("1:括号匹配检验\n");
	printf("2:队列出列顺序\n");
	printf("-------------------------\n");
	scanf("%d", &code);
	char x;
	switch (code)
	{
	case 1:
	{
		printf("输入你的括号组合:\n若输出完毕则输入！表示终止\n");
		getchar();
		scanf("%c", &x);
		while (x != '!')
		{
			k[j] = x;
			j++;
			scanf(" %c", &x);
		}

		printf("括号组合是否规范:  ");
		if (Ismatch(k, j))
			printf("是\n");
		else 
			printf("否\n");

		return 0;
	}
	case 2:
	{
		int n;
		printf("请输入n位同学: ");
		scanf("%d", &n);
		baoshu(n);
		return 0;
	}
	}
}