#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	int max = 0, temp, idx;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		if(temp > max)
		{
			idx = i + 1;
			max = temp;
		}

	}
	cout <<max << '\n' << idx;
}