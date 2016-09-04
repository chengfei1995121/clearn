#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, n, k, max;
	char a[1010];
	int b[1010];
	gets_s(a,1010);
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		k = 1;
		for (j = i + 1; j < n; j++)
		{
			if (a[i] == a[j])
			{
				k = k + 1;
				b[i] = k;
			}
		}
	}
	max = b[0];
	for (i = 1; i <n; i++)
	{
		if (max < b[i])
		{
			max = b[i];
		}
	}
	for (j = 0; j <n; j++)
	{
		if (b[j] == max)
			break;
	}
	printf("%c %d\n", a[j], max);

}