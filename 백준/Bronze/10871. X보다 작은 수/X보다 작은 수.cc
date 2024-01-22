#include <iostream>
using namespace std;

int main()
{
	int N, x, temp;
	cin >> N >> x;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		if(temp < x)
			cout << temp << ' ';
	}
}
