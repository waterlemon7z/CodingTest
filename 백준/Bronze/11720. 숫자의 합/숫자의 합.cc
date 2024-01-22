#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	string str;
	int rst;
	cin >> rst >> str;
	rst = 0;
	for(auto iter : str)
	{
		rst += (iter - '0')%10;
	}
	cout << rst;
}