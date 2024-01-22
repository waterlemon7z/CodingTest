#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, m;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> m >> str;
		for(int j = 0; j < str.size(); j++)
		{
			for(int ll = 0; ll < m; ll++)
				cout << str[j];
		}
		cout << '\n';
	}
}