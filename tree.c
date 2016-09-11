#include<stdio.h>
#include<stdlib.h>
typedef struct tree *node;
typedef node Tree;
Tree creat(int n);
Tree insert(int, Tree);
void destroy(Tree);
Tree find(int, Tree);
void order(Tree);
Tree findmin(Tree);
Tree delete(int, Tree);
struct tree
{
	int zhi;
	Tree left;
	Tree right;
};
int main()
{
	Tree root = creat(11),p;
	int i,a,c;
	printf("要输入几个数？\n");
	scanf_s("%d", &a);
	for (i = 0; i < a; i++)
	{
		scanf_s("%d", &c);
		insert(c, root);//插入
	}
	p=find(8, root);
	printf("查找到的树：%d\n", p->zhi);
	order(root);
	delete(10, root);
	printf("\n");
	order(root);//中序遍历
	destroy(root);//清空树
}
Tree creat(int n)
{
	Tree p;
	p = (Tree)malloc(sizeof(struct tree));
	if (p == NULL)
		return NULL;
	else
	{
		p->zhi = n;
		p->left = p->right = NULL;
		return p;
	}
}
Tree insert(int n, Tree T)
{
	if (T == NULL)
		T = creat(n);
	else
		if (n < T->zhi)
			T->left=insert(n, T->left);
		else
			if (n > T->zhi)
				T->right=insert(n, T->right);
	return T;
}
Tree find(int n, Tree T)
{
	if (T == NULL)
		return NULL;
	if (n < T->zhi)
		return find(n, T->left);
	else
		if (n > T->zhi)
			return find(n, T->right);
		else
			return T;
}
void destroy(Tree T)
{
	if (T)
	{
		if (T->left)
			destroy(T->left);
		if (T->right)
			destroy(T->right);
		free(T);
		T = NULL;
	}
}
void order(Tree T)
{
	if (T == NULL)
		return;
	order(T->left);
	printf("%d ", T->zhi);
	order(T->right);
}
Tree delete(int n, Tree T)
{
	Tree temple;
	if (n < T->zhi)
		T->left = delete(n, T->left);
	else
		if (n > T->zhi)
			T->right = delete(n, T->right);
		else
			if (T->left&&T->right)
			{
				temple = findmin(T->right);
				T->zhi = temple->zhi;
				T->right = delete(T->zhi, T->right);
			}
			else
			{
				temple = T;
				if (T->right == NULL)
					T = T->left;
				else
					if(T->left == NULL)
					  T = T->right;
				free(temple);
			}
	return T;
}Tree findmin(Tree T)
{
	if (T = NULL)
		return NULL;
	else
		if (T->left == NULL)
			return T;
		else
			return findmin(T->left);
}