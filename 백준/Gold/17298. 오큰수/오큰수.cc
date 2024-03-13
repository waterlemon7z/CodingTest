#include <bits/stdc++.h>
//#include <iostream>
//#include <queue>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	FASTIO

	stack<int> orig, temp;

	int N, input, cur, rst;
	int rstset[1000001]={0,};
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		orig.push(input);
	}

	for (int i = 0; i < N; i++)
	{
		rst = -1;
		cur = orig.top();
		orig.pop();
		while(temp.size() != 0)
		{
			if(temp.top() > cur)
			{
				rst = temp.top();
				break;
			}
			else
				temp.pop();
		}
		temp.push(cur);
		rstset[i] = rst;
	}
	for(int i = N - 1; i >= 0; i--)
	{
		cout << rstset[i] << ' ';
	}
}

