#include <iostream>
using namespace std;

int main()
{
	int N;
	string str;
	cin >> N;
	for(int i = 0; i < N;i ++)
	{
		cin >> str;
		if(str.size() >= 6 && str.size() <= 9)
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
}