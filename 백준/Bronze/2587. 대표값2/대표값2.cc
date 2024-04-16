#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;

int main()
{
	FASTIO
	int temp, mean = 0;
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		mean += temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cout << mean/5 << endl<< v[2];
}
