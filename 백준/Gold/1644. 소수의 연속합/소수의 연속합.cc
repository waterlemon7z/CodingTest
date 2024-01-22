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

vector<bool> input = vector<bool>(4000001, true);

vector<int> primes;

void getPrime(int N)
{
	input[0] = false;
	input[1] = false;
	for (int i = 2; i * i <= N; i++)
	{
		if (input[i])
			for (int j = i * i; j <= N; j += i)
			{
				input[j] = false;
			}
	}
	for (int i = 2; i <= N; i++)
	{
		if (input[i])
			primes.push_back(i);
	}
}

void solve(int N)
{
	int cur = 0, f = 0, rst = 0;
	getPrime(N);
	if (N <= 1)
	{
		cout << 0;
		return;
	}
	for (int i = 0; i < primes.size(); i++)
	{
		cur += primes[i];
		while (cur > N)
		{
			cur -= primes[f++];
		}
		if (cur == N)
			rst++;
	}
	cout << rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	solve(N);
}