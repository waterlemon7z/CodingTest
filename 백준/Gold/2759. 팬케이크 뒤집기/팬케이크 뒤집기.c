
#include <stdio.h>
#include <string.h>

void reverse(int *arr, int x, int y)
{
	int temp;
	for (int i = x; i < y - i; i++)
	{
		temp = arr[i];
		arr[i] = arr[y - i];
		arr[y - i] = temp;
	}
}

int locRst[100];
int loc = 0;
int push_back(int N)
{
	locRst[loc++] = N;
	return loc;
}
int maxIdx(int *arr, int start, int end)
{
	int val = -1;
	int idx = -1;
	for (int i = start; i <= end; i++)
	{
		if (val < arr[i])
		{
			val = arr[i];
			idx = i;
		}
	}
	return idx;
}

int main()
{
	int arr[31]; // This array for input
	int T, N, start, end;
	scanf("%d", &T);
	while (T--)
	{
		loc = 0;
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}
		loc = 0;
		start = 0;
		end = N - 1;
		while(end)
		{
			int idx = maxIdx(arr, start, end);
			if(idx == start)
			{
				reverse(arr, start,end);
				push_back(end + 1);
			}
			else if(idx != end && idx != start)
			{
				reverse(arr, start,idx);
				push_back(idx + 1);
				reverse(arr, start,end);
				push_back(end + 1);
			}
			end--;
		}
		int rst = push_back(0) - 1;
		printf("%d ", rst);
		for (int i = 0; i < rst; i++)
		{
			printf("%d ",locRst[i]);
		}
		puts("");
	}
}