#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
typedef long long ull;
map<ull, ull> memo;

ull fibo(ull N)
{
	ull tempA, tempB, result;
	ull m, n;
	if(N == 0)
		return 0;
	if(memo.find(N) != memo.end())
		return memo[N];
//	if(N == 1)
//	{
//		memo[N] = 1;
//		return 1;
//	}
	if(N % 2 == 0)
	{
		m = N/2;
		n = N/2 - 1;
		tempA = fibo(m) % DIV;
		tempB = fibo(n) % DIV;
		result = tempA * ( tempA + 2 * tempB % DIV) % DIV;
	}
	else
	{
		m = N / 2 + 1;
		n = N / 2;
		tempA = fibo(m) % DIV;
		tempB = fibo(n) % DIV;
		result = ((tempA * tempA) % DIV + (tempB*tempB) % DIV) %DIV;
	}
	memo.insert({N, result});
	return result;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull A;
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 1;
	cin >> A;
	cout << fibo(A);
}
