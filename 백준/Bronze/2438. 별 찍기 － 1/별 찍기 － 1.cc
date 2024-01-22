#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, A, B;
	string str("****************************************************************************************************");
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cout << str.substr(0,i) << endl;
	}
}