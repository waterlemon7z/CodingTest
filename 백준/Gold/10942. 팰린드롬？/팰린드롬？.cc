#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
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

vector<int> input;

int memo[2001][2001] = {0,};

int palin(int f, int l)
{
	if (f >= l)
	{
		return 1;
	}
	if (memo[f][l] == 1)
	{
		return 1;
	}
	else if (input[f] == input[l])
		return memo[f + 1][l - 1] = palin(f + 1, l - 1);
	return memo[f][l] = 0;
}

void solve(int s, int e)
{
	memo[s][e] = palin(s, e);
	if (memo[s][e] == 1)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, temp, T, S, E;
	input.push_back(-1);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> S >> E;
		solve(S, E);
	}


}