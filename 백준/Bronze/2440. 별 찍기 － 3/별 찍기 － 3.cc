#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, S;
vector<int> arr;

int main()
{
	cin >> N;
	for(int i = N; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			cout <<'*';
		}
		cout << endl;
	}
}
