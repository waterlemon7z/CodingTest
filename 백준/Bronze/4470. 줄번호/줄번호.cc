#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	int N;
	cin >> N;
	getline(cin, str);
	for (int i = 1; i <= N ; i++)
	{
		getline(cin, str);
		cout << i << ". " << str << endl;
	}
}