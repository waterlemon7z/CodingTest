#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int N, x, temp, rst = 0;
	vector<int> arr(31,0);
	for(int i = 1; i < 29; i++)
	{
		cin >> temp;
		arr[temp] = 1;
	}
	for(int i = 1; i < 31; i++)
	{
		if(arr[i] == 0)
			cout << i << '\n';
	}
}