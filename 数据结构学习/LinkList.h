#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*GetElem������д��*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000
typedef int Status;
/*Status�Ǻ��������ͣ���ֵ�Ǻ������  ״̬���룬��OK��*/
/*��ʼ������˳�����Ա��Ѵ��ڣ�1<=i<=ListLength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/

typedef int ElemType;/*ElemType����ʵ���������*/

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Node* LinkList;/*��������*/

/*�ó���i������ �͸�e*/
Status GetElem(LinkList L, int i, ElemType* e)
{
	int j;
	LinkList p;
	p = L->next;/*ָ���һ���ڵ�*/
	j = 1;
	while (p&&j<i)/*��p��һ��վ��*/
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
	if (!(p->next) || j > i)/*iΪ�����ȥ��*/
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;




}
/*ͷ�巨��������*/
void CreateListHead(LinkList* L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));/*�Ƚ���һ����ͷ�ڵ�ĵ�����*/
	(*L)->next = NULL;
	for ( i = 0; i < n; i++)
	{
		p= (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;

	}
	
}
/*β�巨��������*/
void CreateListTail(LinkList* L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L= (LinkList)malloc(sizeof(Node)); 
	r = *L;/*ָ��β���Ľڵ�*/
	for ( i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data=rand()%100+1;
		r->next = p;
		r = p;

	}
	r->next = NULL;
}
/*�������ͷָ�뱣��*/
Status ClearList(LinkList* L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;  /*��ǰ����һ���ķ�ʽ���н���*/
		free(q);
		p = q;

	}
	(*L)->next = NULL;
	return OK;
}

