#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree *T;
struct tree {
	int number;
	T left,right;
};
T insert(int n, T S)
{
	if (S == NULL)
	{
		S = (T)malloc(sizeof(struct tree));
		if (S == NULL)
		{
			printf("·ÖÅäÊ§°Ü");
		}

		S->number = n;
		S->left = NULL;
		S->right = NULL;
	}
	else
	{
		if (n < S->number)
		{
			S->left = insert(n, S->left);
		}
		else
			if (n > S->number)
			{
				S->right = insert(n, S->right);
			}
	}
	return S;
}
void middleprint(T S) {
	if (S != NULL)
	{
		middleprint(S->left);
		printf("%d\n", S->number);
		middleprint(S->right);
	}
}
int main()
{
	T root=NULL;
	int a,i;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a);
		root = insert(a, root);
	}
	middleprint(root);
}