#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	int hh, mm;
	cin >> hh >> mm;
	if(mm - 45 <0)
	{
		hh--;
		mm = mm + 15;
	}
	else
		mm -= 45;
	if(hh < 0)
		hh = 23;
	cout << hh << ' ' << mm;
}