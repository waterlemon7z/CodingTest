#include <iostream>
#include <map>
#include <cmath>
using namespace std;
long long P, Q;
map<long long, long long> memo;

long long dp(long long n)
{
	long long A, B, Af, Bf;
	if(n == 0)
	{
		memo.insert({n,1});
		return 1;
	}
	Af = floor(n/P);
	Bf = floor(n/Q);
	auto Aiter = memo.find(Af);
	if(Aiter != memo.end())
	{
		A = Aiter->second;
	}
	else
		A =dp(Af);
	auto Biter = memo.find(Bf);
	if(Biter != memo.end())
	{
		B = Biter->second;
	}
	else
		B = dp(Bf);
	memo.insert({n, A + B});
	return A + B;
}

int main()
{
	long long N;
//	memo.push_back(1);
	cin >> N >> P >> Q;
	cout << dp(N);
}
