#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int N, x, temp, rst = 0;
	vector<int> arr;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> x;
	for(auto iter = arr.begin(); iter != arr.end(); iter++)
	{
		if(*iter == x)
			rst++;
	}
	cout << rst;
}