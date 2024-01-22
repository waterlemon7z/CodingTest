#include <iostream>
using namespace std;

int main()
{
	float a, b;
	cin >> a >> b;
	cout << (a-a/100*b >= 100 ? 0 : 1);
}
