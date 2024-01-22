#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;

pii solve(string &str, int cur)
{
	if(str[cur] == ')' || str[cur] == '\0')
		return {0, cur};
	int len = 0;
	pii rtn;
	while(1)
	{
		len++;
		if(str[cur] == '(')
		{
			len--;
			rtn = solve(str, cur + 1);
			len += rtn.first * (str[cur - 1] - '0');
			cur = rtn.second + 1;
		}
		if(str[cur] == ')' || str[cur] == '\0')
		{
			len--;
			return {len, cur};
		}
		cur++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	cout << solve(str, 0).first;
}