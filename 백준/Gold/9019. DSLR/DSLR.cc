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

int T, target, key;

string bfs()
{
	bool check[10000] = {false,};
	queue<pair<int, string>> qq;
	qq.push({target, ""});
	int temp;
	while (!qq.empty())
	{
		int cur = qq.front().first;
		string oper = qq.front().second;
		if (cur == key)
			return oper;
		qq.pop();
		//D
		if (!check[(cur * 2) % 10000])
		{
			check[(cur * 2) % 10000] = true;
			qq.push({(cur * 2) % 10000, oper + "D"});
		}
		//S
		temp = cur - 1;
		if (temp == -1)
		{
			temp = 9999;
		}
		if (!check[temp])
		{
			check[temp] = true;
			qq.push({temp, oper + "S"});
		}
		//L
		temp = cur * 10;
		temp %= 10000;
		temp += cur / 1000;
		if (!check[temp])
		{
			check[temp] = true;
			qq.push({temp, oper + "L"});
		}
		//R
		temp = cur / 10;
		temp += (cur % 10) * 1000;
		if(!check[temp])
		{
			check[temp] = true;
			qq.push({temp, oper + "R"});
		}
	}
	return "";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while (T--)
	{
		cin >> target >> key;
		cout << bfs() << endl;
	}

}