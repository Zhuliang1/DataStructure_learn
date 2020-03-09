#include <stdio.h>
/*GetElem������д��*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
/*Status�Ǻ��������ͣ���ֵ�Ǻ������  ״̬���룬��OK��*/
/*��ʼ������˳�����Ա��Ѵ��ڣ�1<=i<=ListLength(L)*/
/*�����������e����L�е�i������Ԫ�ص�ֵ*/

typedef int ElemType;/*ElemType����ʵ���������*/
/*���Ա�Ĵ洢�ṹ
�ŵ㣺
	����Ϊ��ʾ����Ԫ��֮����߼���ϵ�����Ӷ���洢�ռ�
	���Կ��ٴ�ȡ���е�Ԫ��
ȱ�㣺
	�����ɾ��������Ҫ�ƶ�����Ԫ��
	���Ա��ȱ仯�ϴ�ʱ������ȷ���洢�ռ������
	�洢�ռ�ġ���Ƭ��*/
typedef struct
{
	ElemType data[MAXSIZE];/*���ݴ洢Ԫ�����ֵMAXSIZE*/
	int length;/*���Ա�ǰ����*/
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
	if (L->length == MAXSIZE|| i<1 || i>L->length + 1)/*˳����Ѿ�����i���ڷ�Χ��*/
		return ERROR;
	if (i<=L->length)/*��������ݵ�λ�ò��ڱ�β��*/
	{
		for ( k = L->length-1; k >=i-1; k--)
		{
			L->data[k + 1] = L->data[k];

		}
	}
	L->data[i -1] = *e;/*������Ԫ�أ�һ��һ��ѽ����*/
	L->length++;
	return OK;

}

Status ListDelete(SqList* L, int i, ElemType* e)
{
	int k;
	if (L->length == 0)/*���Ա�Ϊ��*/
		return ERROR;
	if (i<1 || i>L->length)/*ɾ��λ�ô���*/
		return ERROR;
	if (i<L->length)   /*�ڷ�Χ��*/
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
			ListInsert(La, ++La_Len,&e);/*����Ԫ�أ������*/
		}
	}
	return OK;

}

/*ѭ����ʼ������*/
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

	printf("����%d ", ListLength(&a));
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