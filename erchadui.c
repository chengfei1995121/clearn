#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
static int m_heap[30];
static int m_capa = 30;
static int m_size = 0;
int get_index(int data)
{
	int i;
	for (i = 0; i < m_size; i++)
	{
		if (data == m_heap[i])
		{
			return i;
			break;
		}
	}
	return -1;
}
static void filper_up(int start)
{
	int c = start;
	int p = (c - 1) / 2;
	int tem = m_heap[c];
	while (c > 0)
	{
		if (m_heap[p] < tem)
			break;
		else
		{
			m_heap[c] = m_heap[p];
			c = p;
			p = (p - 1) / 2;
		}
	}
	m_heap[c] = tem;
}
int insert(int data)
{
	m_heap[m_size] = data;
	filper_up(m_size);
	m_size++;
	return 1;
}
void printfheap(int m_size)
{
	int i;
	for (i = 0; i < m_size; i++)
	{
		printf("%d ", m_heap[i]);
	}
}
void filaredown(int start, int end)//下沉函数
{
	int c = start;
	int l = 2 * c + 1;//左儿子
	int tem = m_heap[c];
	while(l < end)
	{
		if (l<end&&m_heap[l]>m_heap[l + 1])//假如右儿子最小，则将l=右儿子
			l++;
		if (tem < m_heap[l])
			break;
		else
		{
			m_heap[c] = m_heap[l];
			c = l;
			l = l * 2 + 1;
		}
	}
	m_heap[c] = tem;
}
void fildown(int start, int end)
{
	int c = start;
	int p = c * 2 +1;
	int tem = m_heap[c];
	while (p <= end)
	{
		if (p<end&&m_heap[p]>m_heap[p + 1])
			p = p + 1;
		if (tem < m_heap[p])
			break;
		else
		{
			m_heap[c] = m_heap[p];
			c = p;
			p = p * 2 + 1;
		}
	}
}
int delete(int data)
{
	int i;
	i = get_index(data);
	if (i == -1)
		return -1;
	m_heap[i] = m_heap[--m_size];
	filaredown(i, m_size - 1);
	return 0;
}
int main()
{
	int i;
	int a[9] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
	for (i = 0; i < 9; i++)
	{
		insert(a[i]);
	}
	printf("初始化后：\n");
	printfheap(m_size);
	printf("\n");
	i = 15;
	insert(i);
	printf("插入后:\n");
	printfheap(m_size);
	printf("\n");
	i = 90;
	delete(i);
	printf("删除后：\n");
	printfheap(m_size);
	printf("\n");
	system("color 54");
}