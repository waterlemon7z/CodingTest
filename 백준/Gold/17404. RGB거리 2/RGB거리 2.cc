#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
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
int input[1001][3];
int N;

int solve(int start)
{
	vector<int> solveArr(3,input[0][start]);
	vector<int> temp;
	for(int i = 1; i < N; i++)
	{
		temp = solveArr;
		solveArr[0] = min(temp[1], temp[2]) + input[i][0];
		solveArr[1] = min(temp[0], temp[2]) + input[i][1];
		solveArr[2] = min(temp[0], temp[1]) + input[i][2];
		if(i == 1)
			solveArr[start] = INF;
	}
	solveArr[start] = INF;
	return min(min(solveArr[0],solveArr[1]),solveArr[2]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int rst = INF;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> input[i][j];
	}
	for (int j = 0; j < 3; j++)
		rst = min(rst, solve(j));
	cout << rst;
}