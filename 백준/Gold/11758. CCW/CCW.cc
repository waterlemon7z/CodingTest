#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

typedef struct
{
	pii p1,p2;
}Line;


int is_ccw(pii a, pii b, pii c)
{
	long long crossProduct = (a.first * b.second + b.first * c.second + c.first * a.second) -
							 (a.second * b.first + b.second * c.first + c.second * a.first);
	if(crossProduct < 0)
		return -1;
	else if (crossProduct == 0)
		return 0;
	return 1;
}

int main()
{
	FASTIO
	Line l1, l2;
//	cin >> l1.p1.first >> l1.p1.second >> l1.p2.first >> l1.p2.second;
//	cin >> l2.p1.first >> l2.p1.second >> l2.p2.first >> l2.p2.second;

//	if(is_ccw(l1.p1, l1.p2, l2.p1) *
//		is_ccw(l1.p1,l1.p2,l2.p2) <= 0
//	&& is_ccw(l2.p1,l2.p2,l1.p1) *
//		is_ccw(l2.p1,l2.p2,l1.p2) <= 0)
//	{
//		cout << 1;
//	}
//	else
//		cout << 0;
	pii a, b, c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	cout << is_ccw(a,b,c);
}