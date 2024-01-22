#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	int check[26] = {0,}, max_ = 0;
	char rst = 0;
	cin >> str;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= 'a')
			str[i] -= 32;
		check[str[i] - 'A']++;
	}
	for(int i = 0; i < 26; i++)
	{
		if(check[i] == max_ && max_ != 0)
			rst = '?';
		else if(check[i] > max_)
		{
			rst = 'A' + i;
			max_ = check[i];
		}
	}
	cout << rst;
}