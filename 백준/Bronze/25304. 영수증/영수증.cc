#include <iostream>
using namespace std;

int main()
{
	int t, n, A, B, r = 0;
	cin >> t >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> A >> B;
		r += A * B;
		if(r > t)
		{
			cout << "No";
			return 0;
		}
	}
	if(r == t)
		cout<< "Yes";
	else
		cout << "No";
}