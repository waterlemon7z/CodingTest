#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
int n;
stack<int> memo;
map<int, int> input;

int ans(int key)
{
	while(!memo.empty())
	{
		if(memo.top() > key)
		{
			return input[memo.top()];
		}
		else
		{
			memo.pop();
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;
	cin  >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		input[temp] = i + 1;
		printf("%d ", ans(temp));
		memo.push(temp);
	}
}