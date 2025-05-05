#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void CreateList(LinkNode* L,ElemType a[],int n)//头插法
{
	LinkNode * s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode * )malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

void InitList(LinkNode *L)//初始化线性表
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

int ListLength(LinkNode* L)//单链表长度
{
	int i = 0;
	LinkNode* p = L;
	//printf("这编译了。\n");
	/*if(p->next==NULL) printf("这编译了。\n");
	else printf("这编译了。\n");*/
	while (p->next != NULL)
	{
		i++;
		//printf("%d\n",i);
		p = p->next;
	}
	return(i);
}

bool ListInsert(LinkNode* L, int i, ElemType e)//i位置插入元素
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL) return false;
	else {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode* L, int i, ElemType e)//i位置删除元素
{
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL) return false;
	else {
		q = p->next;
		if (q == NULL) return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}

void DispList(LinkNode *L)//输出单链表
{
	LinkNode* p = L->next;
	while (p != NULL) {
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

bool ListEmpty(LinkNode *L)
{
	return (L->next==NULL);
}

/*void DelMaxNode(LinkNode *&L)//删除单链表元素最大结点
{

}*/

void delmaxnode(LinkNode *L)
{
	LinkNode *p = L->next,*pre = L,*maxp=p,*maxpre=pre;
	while(p!=NULL){
	
	if(maxp->data<p->data){
	maxp = p;
	maxpre = pre;
	}
	pre = p;
	p=p->next;
	}
	maxpre->next=maxp->next;
	free(maxp);
}

void PUT(LinkNode *L)
{
	printf("单链表各项元素为：");
	DispList(L);
}

int main()
{
	int temp=0;
	LinkNode *h;
	ElemType e;
	InitList(*&h);
	int a[11]={1,3,2,3,4,10,5,7,8,5,9};
	
	LinkNode * s;
	h = (LinkNode*)malloc(sizeof(LinkNode));
	h->next = NULL;
	for (int i = 0; i < 11; i++)
	{
		s = (LinkNode * )malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = h->next;
		h->next = s;
	}

/*	ListInsert(h,1,1);
	ListInsert(h,2,3);
	ListInsert(h,3,2);
	ListInsert(h,4,3);
	ListInsert(h,5,4);
	ListInsert(h,6,10);
	ListInsert(h,7,5);
	ListInsert(h,8,7);
	ListInsert(h,9,8);
	ListInsert(h,10,5);
	ListInsert(h,11,9);*/
	
	PUT(h);

	printf("单链表的长度为：%d\n",temp=ListLength(h));
	
	ListDelete(h,5,e);

	PUT(h);
	
	ListInsert(h,7,4);
	
	PUT(h);
	
	delmaxnode(h);
	
	PUT(h);

	return 0;
}