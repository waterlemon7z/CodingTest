#include <stdio.h>

int solve()
{
	int top = -1, cnt= 0;
	char str[100];
	scanf("%s", str);
	while(str[cnt] != '\0')
	{
		if(str[cnt++] == '(')
		{
			top++;
		}
		else
		{
			if(top == -1)
				return 0;
			top--;
		}
	}
	if(top == -1)
		return 1;
	else
		return 0;
}
int main()
{
	int  T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		if(solve() == 1)
			puts("YES");
		else
			puts("NO");
	}
}