#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	int N, sc = 0, lll = 0;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >>str;
		for(auto iter = str.begin(); iter != str.end(); iter++)
		{
			if(*iter == 'O')
				sc += 1 + lll++;
			else
				lll = 0;
		}
		cout << sc << endl;
		sc = 0;
		lll = 0;
	}
}