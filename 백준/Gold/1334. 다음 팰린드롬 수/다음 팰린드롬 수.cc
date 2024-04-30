#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	FASTIO
	string input, orig;
	bool only9 = true;
	cin >> input;
	orig = input;
	for (int i = 0; i < input.size() / 2; i++)
	{
		input[input.size() - 1 - i] = input[i];
	}
	for(char iter : orig)
	{
		if(iter != '9') only9 = false;
	}
	int len = input.size();
	if(only9)
	{
		cout << 1;
		for (int i = 0; i < len-1; i++)
		{
			cout << 0;
		}
		cout << 1;
		return 0;
	}
	if (input > orig)
	{
		cout << input;
	}
	else
	{
		int mid =len / 2;
		while(input[mid] == ':' || input <= orig)
		{
			if(input[mid] == ':')
			{
				input[len - 1 - mid] = input[mid] = '0';
				mid--;
				input[len - 1 - mid] = ++input[mid];
			}
			else
			{
				input[len - 1 - mid] = ++input[mid];
			}
		}
		cout << input;
	}
}
