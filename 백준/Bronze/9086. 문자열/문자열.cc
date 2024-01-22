#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string str;
	int N;
	cin >> N;
	for(int i = 0 ; i < N; i++)
	{
		cin >> str;
		cout << str[0] << str[str.size() - 1] << endl;
	}
}