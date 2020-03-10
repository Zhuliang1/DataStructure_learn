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
/*静态链表的创建*/

typedef struct
{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];
Status InitList(StaticLinkList space)
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
	{
		space[i].cur = i + 1;

	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}
int Malloc_SLL(StaticLinkList space)
{
	int i = space[0].cur;/*当前数组的第一个元素的cur存的值*/
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;

}
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i<1 || i>ListLength(L) + 1)
		return ERROR;
	j = Malloc_SLL(L);
	if (j)
	{
		L[j].data = e;
		for ( l = 1; l <i; l++)/*往后走i-1次*/
		{
			k = L[k].cur;

		}
		/*此时k从第一个来走到了k的就是第i个元素*/
		L[j].cur = L[k].cur;
		L[k].cur =j ;
		return OK;
	}
	return ERROR;

}
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;

}
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
	{
		k = L[k].cur;
	}
	j = L[k].cur;

	L[k].cur = L[j].cur;/*   k代表i-1个元素   i-1 的指针指向  i的下一个  */
	Free_SSL(L,j);
	return OK;


}