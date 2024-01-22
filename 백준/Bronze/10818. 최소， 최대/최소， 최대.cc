#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	for(auto &iter : arr)
	{
		scanf("%d", &iter);
	}
	sort(arr.begin(), arr.end());
	cout << arr[0]<< ' ' << arr[arr.size() - 1];
}