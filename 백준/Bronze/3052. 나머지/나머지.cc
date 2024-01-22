#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> check(42, 0);
	int rst = 0, temp;
	for(int i = 0; i < 10; i ++)
	{
		cin >> temp;
		if(check[temp % 42] == 0)
		{
			check[temp % 42] = 1;
			rst++;
		}
	}
	cout << rst;
}