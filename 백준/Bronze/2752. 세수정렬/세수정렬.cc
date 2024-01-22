#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	int temp;
	for(int i = 0; i < 3; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
}