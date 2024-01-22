#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string str, rst;
	vector<int> arr(26,-1);
	int i = 0;
	cin >> str;
	for(auto iter = str.begin(); iter != str.end(); iter++, i++)
	{
		if(arr[*iter-'a'] == -1)
			arr[*iter-'a'] = i;
	}
	for(auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		cout << *iter << ' ';
	}
}