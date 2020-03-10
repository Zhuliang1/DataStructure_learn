#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*GetElem操作的写法*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int Status;
/*Status是函数的类型，其值是函数结果  状态代码，如OK等*/
/*初始条件：顺序线性表已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/

typedef int ElemType;/*ElemType根据实际情况而定*/

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;/*定义链表*/

/*拿出第i个数据 送给e*/
Status GetElem(LinkList L, int i, ElemType* e)
{
	int j;
	LinkList p;
	p = L->next;/*指向第一个节点*/
	j = 1;
	while (p&&j<i)/*让p下一个站点*/
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;

}

Status ListInsert(LinkList* L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	if (!p||j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	if (s)
	{
		// code ...
		s->data = e;
		s->next = p->next;
		p->next = s;
		return OK;

		//free(p);
	}
	else
	{
		return ERROR;
	}



}

Status ListDelete(LinkList* L, int i, ElemType* e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next&&j<i)
	{
		p = p->next;
		j++;

	}
	if (!(p->next) || j > i)/*i为负情况去除*/
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;




}
/*头插法建立链表*/
void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));/*先建立一个带头节点的单链表*/
	(*L)->next = NULL;
	for ( i = 0; i < n; i++)
	{
		p= (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;

	}
	
}
/*尾插法建立链表*/
void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L= (LinkList)malloc(sizeof(Node)); 
	r = *L;/*指向尾部的节点*/
	for ( i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data=rand()%100+1;
		r->next = p;
		r = p;

	}
	r->next = NULL;
}
/*清空链表，头指针保留*/
Status ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;  /*当前与下一个的方式进行讲解*/
		free(q);
		p = q;

	}
	(*L)->next = NULL;
	return OK;
}

