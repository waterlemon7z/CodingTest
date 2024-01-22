#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INF 987654321
int arr[100000] = {0,};

int main()
{
	int N, turnpoint = -1, r, l, rst = INF, rstR, rstL;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", arr + i);
		if(turnpoint == -1 && arr[i] > 0)
			turnpoint = i;
	}
	if(turnpoint == 0)
	{
		printf("%d %d", arr[0], arr[1]);
		return 0;
	}
	else if(turnpoint == -1)
	{
		printf("%d %d", arr[N - 2], arr[N - 1]);
		return 0;
	}
	l = turnpoint - 1;
	r = turnpoint;
	while(1)
	{
		if(arr[l] + arr[r] == 0)
		{
			printf("%d %d", arr[l], arr[r]);
			return 0;
		}
		if(abs(arr[l] + arr[r]) < rst)
		{
			rst = abs(arr[l] + arr[r]);
			rstL = l;
			rstR = r;
		}

		if(arr[l] + arr[r] < 0)
		{
			if(r == N - 1)
				l--;
			else
				r++;
		}
		else
		{
			if(l == 0)
				r++;
			else
				l--;
		}
		if(l == 0 && r == N - 1)
			break;
	}
	if(arr[l] + arr[r] == 0)
	{
		printf("%d %d", arr[l], arr[r]);
		return 0;
	}
	if(abs(arr[l] + arr[r]) < rst)
	{
		rst = abs(arr[l] + arr[r]);
		rstL = l;
		rstR = r;
	}
	if(turnpoint < N - 2)
	{
		if(arr[turnpoint] + arr[turnpoint + 1] < rst)
		{
			rstL = turnpoint;
			rstR = rstL + 1;
		}
	}
	if(turnpoint > 2)
	{
		if(abs(arr[turnpoint - 1] + arr[turnpoint - 2]) < rst)
		{
			rstL = turnpoint - 2;
			rstR = rstL + 1;
		}
	}
	printf("%d %d", arr[rstL], arr[rstR]);
}