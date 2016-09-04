#include<stdio.h>
#include<stdlib.h>
typedef struct stack *node;
typedef struct NODE *pnode;
struct stack
{
	int n;
	struct stack *next;
};
typedef struct NODE
{
	node top;
	node bottom;
}STACK;
void creatstack(pnode ps)
{
	ps->top = (node)malloc(sizeof(struct stack));
	if (ps->top == NULL)
	{
		printf("分配失败\n");
		exit(-1);
	}
	ps->top->next = NULL;
	ps->bottom=ps->top;
}
void pop(pnode ps, int n)
{
	node p;
	p = (node)malloc(sizeof(struct stack));
	if (p == NULL)
	{
		printf("分配失败\n");
		exit(-1);
	}
	p->n = n;
	p->next = ps->top;
	ps->top = p;
}
int pop(pnode ps)
{
	node s;
	s = ps->top;
}
void order(pnode ps)
{
	node s;
	s = ps->top;
	while (s != ps->bottom)
	{
		printf("%d ", s->n);
		s = s->next;
	}
}
find(int n, pnode ps)
{
	node s;
	s = ps->top;
	while (s != ps->bottom)
	{
		if (n == s->n)
		{
			printf("查找到的数：%d\n", s->n);
			break;
		}
		else
			s = s->next;
	}
}
int main()
{
	STACK s;
	int n,a;
	creatstack(&s);
	scanf_s("%d", &n);
	while (n-- != 0)
	{
		scanf_s("%d", &a);
		push(a, &s);
	}
	order(&s);
	printf("\n");
	find(5, &s);
	
}