#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	if (A >0 && B > 0)
	{
		cout << '1';
	}
	else if(A > 0 && B < 0)
		cout << '4';
	else if (A < 0 && B < 0)
		cout << 3;
	else cout << 2;
}