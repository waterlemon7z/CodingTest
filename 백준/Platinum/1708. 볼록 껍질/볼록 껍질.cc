#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<long, long> pii;

typedef long long ull;

int N;

pii cord[100001], minP = {40001, 400001};

long long is_ccw(pii a, pii b, pii c)
{
//	long long crossProduct = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	long long crossProduct = (a.first * b.second + b.first * c.second + c.first * a.second) -
			(a.second * b.first + b.second * c.first + c.second * a.first);
	return crossProduct;
}

bool minccw(pii a, pii b)
{
	long long ccw = is_ccw(cord[0], a, b);
	if (ccw)
		return ccw > 0;
	else if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

void solve()
{
	stack<pii> ss;
	ss.push(cord[0]);
	ss.push(cord[1]);
	for (int i = 2; i < N; i++)
	{
		while (ss.size() >= 2)
		{
			pii second = ss.top();
			ss.pop();
			pii first = ss.top();
			int ccw = is_ccw(first, second, cord[i]);
			if(ccw>0)
			{
				ss.push(second);
				break;
			}
		}
		ss.push(cord[i]);
	}
	cout << ss.size();
}

int main()
{
	FASTIO
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cord[i].first >> cord[i].second;
		if (minP.second > cord[i].second || (minP.second == cord[i].second && minP.first > cord[i].first))
		{
			minP = cord[i];
			pii temp = cord[i];
			cord[i] = cord[0];
			cord[0] = temp;
		}
	}
//	calcAngle();
	sort(cord+1, cord+N, minccw);
	solve();
}