#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> arr(8);
	vector<int> cmp1 = {1,2,3,4,5,6,7,8};
	vector<int> cmp2 = {1,2,3,4,5,6,7,8};
	reverse(cmp2.begin(), cmp2.end());

	for(int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	if(arr == cmp1)
	{
		cout << "ascending";
	}
	else if (arr == cmp2)
	{
		cout << "descending";
	}
	else
	{
		cout << "mixed";
	}

}
