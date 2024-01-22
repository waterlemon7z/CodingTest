	#include <iostream>
	#include <vector>
	#include <algorithm>
	#include <queue>
	#define INF 987654321
	#define endl '\n'
	#define TIMER_S start = clock();
	#define TIMER_F cout << (clock() - start) << "ms" << endl;


	using namespace std;
	//clock_t start;
	//typedef pair<int, int> pii;
	typedef unsigned long long ull;

	ull A, B, C;
	ull pow(ull N)
	{
		ull temp;
		if(N == 1)
			return A % C;
		if(N % 2 == 1)
		{
			temp = pow(N/2) % C;
			return ((temp * temp % C) * A) % C;
		}
		else
		{
			temp = pow(N/2) % C;
			return (temp * temp % C);
		}
	}

	int main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cin >> A >> B >> C;

		cout << pow(B);
	}
