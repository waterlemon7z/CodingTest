#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr;
	int n, m,x,y,z;
	cin >> n >> m;
	arr=  vector<int> (n + 1);
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;
		for( ; x <= y; x++)
		{
			arr[x] = z;
		}
	}
	for(auto i = arr.begin() + 1; i != arr.end(); i++)
	{
		cout << *i << ' ';
	}
}