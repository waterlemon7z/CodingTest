#include <vector>
#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	string star = "****************************************************************************************************";
	string space = "                                                                                                    ;";
	int N;
	cin >> N;
	for (int i = 1; i < N + 1; i++)
	{
		cout << space.substr(0,N-i) << star.substr(0,i) << '\n';
	}
}