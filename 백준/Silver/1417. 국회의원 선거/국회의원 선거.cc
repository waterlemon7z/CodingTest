#include <iostream>
#include <queue>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;

int main()
{
	FASTIO
	priority_queue<int> pq;
	int N, tar, temp, rst = 0;
	cin >> N >> tar;
	for (int i = 1; i < N; i++)
	{
		cin >> temp;
		pq.push(temp);
	}
	if(pq.empty())
	{
		cout << 0;
		return 0;
	}
	while(pq.top() >= tar)
	{
		int i = pq.top();
		pq.pop();
		pq.push(--i);
		tar ++;
		rst ++;
	}
	cout << rst;
}

