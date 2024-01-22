#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> arr;
	int A, B,N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i + 1 <<": " << A << " + " << B << " = " << A + B << endl;
	}
	}