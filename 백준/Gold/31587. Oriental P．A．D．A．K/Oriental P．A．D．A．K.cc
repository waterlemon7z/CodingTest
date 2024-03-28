#include <bits/stdc++.h>
//#include <iostream>
//#include <queue>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

vector<int> chickCnt;
vector<vector<bool>> board;
int N, M, K, B, Z, x, y;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void bfs(queue<pii> qq)
{
	int xx, yy;
	queue<pii> curq, cls;
	curq = qq;
	while (!curq.empty())
	{
		curq = queue<pii>();

		while (!qq.empty())
		{
			pii cur = qq.front();
			qq.pop();
			for (int i = 0; i < 4; i++)
			{
				xx = cur.first + dx[i];
				yy = cur.second + dy[i];
				if ((xx > 0 && yy > 0 && xx <= N && yy <= M) && !board[xx][yy])
				{
					board[xx][yy] = true;
					curq.push({xx, yy});
				}
			}
		}

		chickCnt.push_back(curq.size());
		qq = curq;
	}
}

int main()
{
	FASTIO
	queue<pii> bfsQ;
	int maxRst = 0, minRst = 0, cur, val;
	cin >> N >> M >> K >> B >> Z;
	board = vector<vector<bool>>(N + 1, vector<bool>(M + 1, 0));
	chickCnt.push_back(K);
	for (int i = 0; i < K; i++)
	{
		cin >> x >> y;
		board[x][y] = true;
		bfsQ.push({x, y});
	}
	bfs(bfsQ);
	chickCnt.pop_back();

	vector<int> minChick = chickCnt;
	vector<int> maxChick = chickCnt;

	cur = maxChick.size() - 1;
	for (int i = 0; i < minChick.size(); i++)
	{
		val = Z;
		minChick[i] = 0;
		while (cur >= 0 &&
			   val != 0)
		{
			if(minChick[cur] == 0)
			{
				cur--;
				continue;
			}
			if (minChick[cur] - val < 0)
			{
				val -= minChick[cur];
				minRst += minChick[cur];
				minChick[cur] = 0;
				cur--;
			} else
			{
				minRst += val;
				minChick[cur] -= val;
				val = 0;
			}
		}
		if(cur == -1)
			break;
	}

	cur = 0;
	for (int i = 0; i < maxChick.size(); i++)
	{
		val = Z;
		maxChick[i] = 0;
		while (cur < maxChick.size() &&
			   val != 0)
		{
			if(maxChick[cur] == 0)
			{
				cur++;
				continue;
			}
			if (maxChick[cur] - val < 0)
			{
				val -= maxChick[cur];
				maxRst += maxChick[cur];
				maxChick[cur] = 0;
				cur++;
			} else
			{
				maxRst += val;
				maxChick[cur] -= val;
				val = 0;
			}
		}
		if(cur == maxChick.size())
			break;
//		if(maxChick[cur] == 0)
//			break;
	}
	cout << minRst << ' ' << maxRst;
}

