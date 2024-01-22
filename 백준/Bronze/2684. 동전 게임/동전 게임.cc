#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c;
	string str;
	int N, arr[2][2][2] = {0,}, x, y, z;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < 38; j++)
		{
			x = str[j] == 'H' ? 1 : 0;
			y = str[j + 1] == 'H' ? 1 : 0;
			z = str[j + 2] == 'H' ? 1 : 0;
			arr[x][y][z]++;
		}
		for(int x1 = 0; x1 < 2; x1++)
		{
			for(int y1 = 0; y1 < 2; y1++)
			{
				for (int z1 = 0; z1 < 2; z1++)
				{
					cout << arr[x1][y1][z1] << ' ';
					arr[x1][y1][z1] = 0;
				}
			}
		}
		cout << endl;
	}
}