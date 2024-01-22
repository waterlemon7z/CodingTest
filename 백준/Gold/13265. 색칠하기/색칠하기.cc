#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

typedef pair<int, int> pii;

typedef long long ull;

int N, M;

vector<vector<int>> adja(1001);
vector<int> ncolor(1001);
bool flag;

void backT(int n)
{
	for(auto iter : adja[n])
	{
		if(!ncolor[iter])
		{
			ncolor[iter] = 3 - ncolor[n];
			backT(iter);
		}
		if(ncolor[iter] == ncolor[n]) flag = false;
	}
}

int main()
{
	int T, x, y;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y;
			adja[x].push_back(y);
			adja[y].push_back(x);
		}
		ncolor[1] = 1;
		flag = true;
		backT(1);
		for(int i = 2; i <= N; i++)
		{
            if(!ncolor[i]){
                ncolor[i] = 1;
                backT(i);
            }
		}
		if (flag)
			cout << "possible" << endl;
		else
			cout << "impossible" << endl;

		adja = vector<vector<int>> (1001);
		ncolor = vector<int> (1001);
	}
}