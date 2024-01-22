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

priority_queue<int> maxH;
priority_queue<int, vector<int>, greater<int>> minH;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, temp;
    cin >> N;
	while(N--)
	{
		cin >> temp;
		if(maxH.empty())
			maxH.push(temp);
		else if(maxH.top() > temp)
		{
			maxH.push(temp);
		}
		else
			minH.push(temp);
		if(maxH.size() + 1 <= minH.size())
		{
			maxH.push(minH.top());
			minH.pop();
		}
		if(maxH.size() - 1 > minH.size())
		{
			minH.push(maxH.top());
			maxH.pop();
		}
		cout << maxH.top() << endl;
	}
}