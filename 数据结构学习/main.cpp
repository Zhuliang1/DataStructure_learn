#include <stdio.h>
/*GetElem操作的写法*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
/*Status是函数的类型，其值是函数结果  状态代码，如OK等*/
/*初始条件：顺序线性表已存在，1<=i<=ListLength(L)*/
/*操作结果：用e返回L中第i个数据元素的值*/

typedef int ElemType;/*ElemType根据实际情况而定*/
/*线性表的存储结构
优点：
	无须为表示表中元素之间的逻辑关系而增加额外存储空间
	可以快速存取表中的元素
缺点：
	插入和删除操作需要移动大量元素
	线性表长度变化较大时候，难以确定存储空间的容量
	存储空间的“碎片”*/
typedef struct
{
	ElemType data[MAXSIZE];/*数据存储元素最大值MAXSIZE*/
	int length;/*线性表当前长度*/
}SqList;

Status GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

Status ListInsert(SqList* L, int i, ElemType *e)
{
	int k;
	if (L->length == MAXSIZE|| i<1 || i>L->length + 1)/*顺序表已经满，i不在范围内*/
		return ERROR;
	if (i<=L->length)/*插入的数据的位置不在表尾部*/
	{
		for ( k = L->length-1; k >=i-1; k--)
		{
			L->data[k + 1] = L->data[k];

		}
	}
	L->data[i -1] = *e;/*插入新元素，一库一库呀灭嗲*/
	L->length++;
	return OK;

}

Status ListDelete(SqList* L, int i, ElemType* e)
{
	int k;
	if (L->length == 0)/*线性表为空*/
		return ERROR;
	if (i<1 || i>L->length)/*删除位置错误*/
		return ERROR;
	if (i<L->length)   /*在范围内*/
	{
		for (k  = i;  k<L->length; k++)
		{
			L->data[k - 1] = L->data[k];
		}
	}
	L->length--;
	return OK;

}

Status ClearList(SqList* L)
{
	L->length = 0;
	return OK;
}

int ListLength(SqList* L)
{
	return L->length;
}

Status ShowList(SqList* L)
{
	if (L->length==0)
	{
		return ERROR;

	}
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
	return OK;
}
Status LocateElem(SqList* L, ElemType* e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == *e)
			return i;
		
			
	}
	return ERROR;
		

}
Status Union_Test(SqList* La, SqList *Lb)
{
	int La_Len, Lb_Len;
	ElemType e;
	La_Len = ListLength(La);
	Lb_Len = ListLength(Lb);
	for (int i = 1; i <=Lb->length; i++)
	{
		GetElem(*Lb, i, &e);
		if (!LocateElem(La,&e))
		{
			ListInsert(La, ++La_Len,&e);/*插入元素，雅蔑蝶*/
		}
	}
	return OK;

}

/*循环初始化数组*/
Status Init_Sqlist(SqList* L)
{
	L->length = 0;
	int flag, i = 0;
	while (1)
	{
		scanf_s("%d", &flag);

		if (flag == -1)
		{
			return OK;
		}
		else
		{
			L->data[i] = flag;
			i++;
			L->length++;
		}

	}
}

void Test_SqList()
{
	SqList a, b;
	Init_Sqlist(&a);
	Init_Sqlist(&b);
	Union_Test(&a, &b);

	printf("长度%d ", ListLength(&a));
	int e = 999;
	ListInsert(&a, 2, &e);
	ShowList(&a);
	ListDelete(&a, 2, &e);
	ShowList(&a);
}


void main()
{
	
	Test_SqList();
}