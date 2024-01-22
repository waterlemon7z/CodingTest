#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
typedef long long ll;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L = 0, R = 0, rst = INF;
	ll cur, S;
	cin >> N >> S;
	arr.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cur = arr[0];
	while (1)
	{
		if(R != N && L != N)
		{
			if (cur < S)
			{
				cur += arr[++R];
			}
			else if (cur >= S)
			{
				rst = min(rst, R - L + 1);

				if(R == L)
					cur += arr[++R];
				else
					cur -= arr[L++];
			}
		}
		else if(cur >= S)
		{
			if(R == L)
			{
				rst = min(1, rst);
				break;
			}
			else
			{
				cur -= arr[L--];
			}
		}
		else
			break;

	}
	if(rst == INF)
		cout << 0;
	else
		cout << rst;
}