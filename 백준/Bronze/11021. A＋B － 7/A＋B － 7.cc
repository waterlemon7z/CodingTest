#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, a, b;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a + b << endl;
	}
}