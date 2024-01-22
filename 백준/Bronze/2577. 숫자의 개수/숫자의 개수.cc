#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	int a, b, c, arr[10] = {0,};
	cin >> a >> b >> c;
	string str = to_string(a * b * c);
	for(auto iter : str)
	{
		arr[iter-'0']++;
	}
	for(auto iter : arr)
	{
		cout << iter << '\n';
	}
}