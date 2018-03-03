#include<stdio.h>  
#include<stdlib.h> 
#define OK 1  
#define ERROR 0  
typedef int Status;
typedef int ElemType;
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}LStack;
Status InitStack(LStack* &s)
{
	s = (LStack*)malloc(sizeof(LStack));
	s->next = NULL;
	return OK;
}//��ջ�Ľ���
Status Push(LStack* &s, ElemType e)
{
	LStack *p;
	p = (LStack*)malloc(sizeof(LStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return OK;
}//��ջ
Status Pop(LStack* &s, ElemType &e)
{
	LStack *p = s->next;
	if (s->next == NULL)
	{
		return ERROR;
	}
	else
	{
		e = p->data;
		s->next = p->next;
		free(p);
		return e;
	}
}//��ջ
Status GetTop(LStack* &s, ElemType &e)
{
	LStack *p = s->next;
	if (s->next == NULL)
		return ERROR;
	e = p->data;
	return e;
}//���ջ��Ԫ��
Status StackTraverse(LStack* &s)
{
	LStack *p = s->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}//������ջ
int main()
{
	LStack *S;
	int i, e;
	InitStack(S);
	printf("����ջ�в���1-10ʮ����:\n");
	for (i = 1; i <= 10; i++)
	{
		Push(S, i);
	}
	printf("��ʱ��ջ��Ԫ��Ϊ:\n");
	StackTraverse(S);
	printf("ջ��Ԫ��Ϊ:");
	printf("%d\n", GetTop(S, e));
	printf("ɾ��ջ��Ԫ��\n");
	printf("ɾ����Ԫ��Ϊ:");
	printf("%d\n", Pop(S, e));
	printf("��ʱ��ջ��Ԫ��Ϊ:\n");
	StackTraverse(S);
	system("pause");
	return 0;
}