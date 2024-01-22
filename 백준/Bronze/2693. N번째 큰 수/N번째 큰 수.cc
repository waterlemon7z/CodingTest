#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr;
	int N, temp;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		cout << arr[7] << endl;
		arr.clear();
	}
}