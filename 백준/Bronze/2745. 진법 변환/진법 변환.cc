#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstring>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, cur = 1, size, rst = 0;
	char str[100];
	scanf("%s %d", str, &N);
	size = strlen(str);
	for(int i = size - 1; i >= 0; i--)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			rst += (str[i] - '0') * cur;
		}
		else
		{
			rst += (str[i] - 'A' + 10) * cur;
		}
		cur *= N;
	}
	printf("%d", rst);
}
