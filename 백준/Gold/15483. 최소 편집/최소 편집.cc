/*202235134 최민석*/
#include <stdio.h>
#include <string.h>

int target, rst = 0; // target : target string's size, rst : result.
char str1[1001], str2[1001];
/*
 * Name        : min
 * Date        : 2023-09-20
 * argument    : int, int
 * return      : int
 * description : returns min value of a, b.
*/
int min(int a, int b)
{
	return a > b ? b : a;
}

/*
 * Name        : levenshteinDist
 * Date        : 2023-09-20
 * argument    : int, int, int **
 * return      : void
 * description : Do Levenshtein Distance for str1, str2.
*/
void levenshteinDist(int size1, int size2, int memo[][1001])
{
	//Initialize for blank
	for (int i = 1; i < size1; i++)
	{
		memo[i][0] = i;
	}
	for (int i = 1; i < size2; i++)
	{
		memo[0][i] = i;
	}

	for (int i = 1; i < size1; i++)
	{
		for (int j = 1; j < size2; j++)
		{
			if(str1[i] != str2[j])
			{
				memo[i][j] = min(min(memo[i-1][j], memo[i][j-1]) + 1, memo[i-1][j-1] + 1);
			}
			else
				memo[i][j] = memo[i-1][j-1];
		}
	}
}

int main()
{
	int T, size1, size2;

//	scanf("%d", &T);
T = 1;
	while(T--)
	{
		int memo[1001][1001] = {0,};
		scanf("%s", str1 + 1);
		scanf("%s", str2 + 1);
		str1[0] = ' '; // blank at first.
		str2[0] = ' ';
		size1 = strlen(str1);
		size2 = strlen(str2);
		target = min(size1, size2) - 2;

		levenshteinDist(size1, size2, memo); // Do Levenshtein Distance
		printf("%d\n", memo[size1 - 1][size2 - 1]);
		rst = 0;
	}
}