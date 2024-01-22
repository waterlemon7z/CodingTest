#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
string str1, str2;

void dp()
{
	int size1, size2;
	size1 = str1.size();
	size2 = str2.size();
	vector<vector<int>> memo(size2 + 1, vector<int>(size1 + 1, 0));
	for(int i = 1; i <= size2; i++)
	{
		for(int j = 1; j <= size1; j++)
		{
			memo[i][j] = max(max(memo[i][j - 1], memo[i - 1][j]), memo[i-1][j-1] + (str1[j - 1] == str2[i - 1]));
		}
	}
	cout << memo[size2][size1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;
	dp();
}

