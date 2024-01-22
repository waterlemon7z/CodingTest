#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;

typedef unsigned long long ull;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int check[10] = {0,}, temp;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		check[temp]++;
	}
	for (int i = 0; i < 10; i++)
	{
		if(check[i] % 2)
			cout << i;
	}

}
