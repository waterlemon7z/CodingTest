#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cout << N - (int)(N * 0.22) << ' ';
	cout << N - (int)(N * 0.2 * 0.22);
}