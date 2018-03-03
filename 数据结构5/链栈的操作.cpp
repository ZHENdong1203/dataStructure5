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
}//空栈的建立
Status Push(LStack* &s, ElemType e)
{
	LStack *p;
	p = (LStack*)malloc(sizeof(LStack));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return OK;
}//入栈
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
}//出栈
Status GetTop(LStack* &s, ElemType &e)
{
	LStack *p = s->next;
	if (s->next == NULL)
		return ERROR;
	e = p->data;
	return e;
}//获得栈顶元素
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
}//遍历链栈
int main()
{
	LStack *S;
	int i, e;
	InitStack(S);
	printf("在链栈中插入1-10十个数:\n");
	for (i = 1; i <= 10; i++)
	{
		Push(S, i);
	}
	printf("此时链栈中元素为:\n");
	StackTraverse(S);
	printf("栈顶元素为:");
	printf("%d\n", GetTop(S, e));
	printf("删除栈顶元素\n");
	printf("删除的元素为:");
	printf("%d\n", Pop(S, e));
	printf("此时链栈中元素为:\n");
	StackTraverse(S);
	system("pause");
	return 0;
}