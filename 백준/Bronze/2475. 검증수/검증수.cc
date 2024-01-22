#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int N, rst = 0, temp;
	for(int i = 0; i < 5; i++)
	{
		cin >> temp;
		rst =( rst + temp * temp) % 10;
	}
	cout << rst;
}
