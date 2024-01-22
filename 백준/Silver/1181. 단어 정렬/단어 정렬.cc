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

bool comp(string a, string b)
{
	if(a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<string> str;
	int N;
	string temp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		str.push_back(temp);
	}
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());
	sort(str.begin(), str.end(), comp);
	for(string iter : str)
	{
		cout << iter << endl;
	}
}