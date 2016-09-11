#include<stdio.h>
struct chang
{
	int s;
	char name[8];
};
void bi(int n);
int main()
{
	int n;
	scanf_s("%d", &n);
	if (2 <= n <= 9)
		bi(n);
	return 0;
}
void bi(int n)
{
	struct chang t[9];
	int i,j,k, a,b, c,max,min,h=0;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d%d%d", &a, &b, &c);
		gets(t[i].name);
		t[i].s = a * b * c;
	}for (i = 0; i < n; i++)
	{
		h += t[i].s;
	}
	if (h <= 250)
	{
		max = t[0].s;
		for (i = 0; i < n; i++)
		{
			if (t[i].s>max)
			{
				max = t[i].s;
				j = i;
			}
		}
		min = t[0].s;
		for (i = 0; i < n; i++)
		{
			if (min > t[i].s)
			{
				min = t[i].s;
				k = i;
			}
		}
		printf("%s took clay from %s\n", t[j].name, t[k].name);
	}
}