#include<stdio.h>
#include<stdlib.h>
typedef struct huan *node;
struct huan
{
	int number;
	int key;
	node next;
};
node creatlist(int n)
{
	node p, q, l;
	int i;
	l = (node)malloc(sizeof(struct huan));
	if (l == NULL)
	{
		printf("分配失败\n");
		exit(-1);
	}
	l->next = l;
	l->number = 1;
	scanf_s("%d", &(l->key));
	p = l;
	for (i = 1; i < n; i++)
	{
		q = (node)malloc(sizeof(struct huan));
		if (q == NULL)
		{
			printf("分配失败\n");
			exit(-1);
		}
		q->next = p->next;
		q->number = p->number + 1;
		scanf_s("%d", &(q->key));
		p->next = q;
		p = q;
	}
	return p;
}
int main()
{
	node p, q;
	int i, m, n, count;
	printf("几个人参与游戏？\n");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("人数太少\n");
		exit(-1);
	}
	p = creatlist(n);
	q = p->next;
	printf("请任意输入一个数开始游戏!\n");
	scanf_s("%d", &m);
	count = n;
	while (p != q)
	{
		for (i = 1; i <= m; i++)
		{
			if (i == m)
			{
				printf("%3d------%d\n", n - (--count), q->number);
				m = q->key;
				p->next = q->next;
				free(q);
				q = p->next;
				if (p != q)
					i = 0;
				else
					break;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
	}
	printf("%3d------%d\n", n, p->number);
	printf("%d号是胜利者\n", p->number);
	return 0;
}