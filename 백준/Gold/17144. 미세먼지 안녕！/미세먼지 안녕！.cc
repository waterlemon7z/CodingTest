#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int N, M, T, upr, aircol, downr, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, rst =0;

vector<vector<vector<int>>> arr(2,vector<vector<int>>(50, vector<int>(50, 0)));
vector<vector<int>> reset(50,vector<int>(50, 0));
bool did = false;

void Aircirculator()
{
	// air circur
	int row, col, val, cnt = 0, k, nextval, temp;
	for(int time = 0; time < T; time++)
	{
		for (row = 0; row < N; row++)
		{
			for (col = 0; col < M; col++)
			{
				if (arr[0][row][col] > 0)
				{
					val = arr[0][row][col];
					k = val / 5;
				}
				else if (arr[0][row][col] == -1)
				{
					arr[1][row][col] = -1;
					continue;
				}
				else
					continue;

				for (int i = 0; i < 4; i++)
				{
					if (row + dx[i] >= 0 && row + dx[i] < N && col + dy[i] >= 0 && col + dy[i] < M)
					{
						if (arr[0][row + dx[i]][col + dy[i]] != -1)
						{
							cnt++;
							arr[1][row + dx[i]][col + dy[i]] += k;
						}
						else
							continue;
					}
				}
				arr[1][row][col] += val - (val / 5) * cnt;
				cnt = 0;
			}
		}
		arr[0] = arr[1];
		arr[1] = reset;
		//up
		nextval = 0;
		for (int i = aircol + 1; i < M; i++)
		{
			temp = arr[0][upr][i];
			arr[0][upr][i] = nextval;
			nextval = temp;
		}
		for (int i = upr - 1; i >= 0; i--)
		{
			temp = arr[0][i][M - 1];
			arr[0][i][M - 1] = nextval;
			nextval = temp;
		}
		for (int i = M - 2; i >= 0; i--)
		{
			temp = arr[0][0][i];
			arr[0][0][i] = nextval;
			nextval = temp;
		}
		for (int i = 1; i <= upr; i++)
		{
			if (arr[0][i][0] == -1)
			{
				break;
			}
			temp = arr[0][i][0];
			arr[0][i][0] = nextval;
			nextval = temp;
		}
		for (int i = 1; i < aircol; i++)
		{
			temp = arr[0][upr][i];
			arr[0][upr][i] = nextval;
			nextval = temp;
		}
		rst -= nextval;
		nextval = 0;

		for (int i = aircol + 1; i < M; i++)
		{
			temp = arr[0][downr][i];
			arr[0][downr][i] = nextval;
			nextval = temp;
		}
		for (int i = downr + 1; i < N; i++)
		{
			temp = arr[0][i][M - 1];
			arr[0][i][M - 1] = nextval;
			nextval = temp;
		}
		for (int i = M - 2; i >= 0; i--)
		{
			temp = arr[0][N - 1][i];
			arr[0][N - 1][i] = nextval;
			nextval = temp;
		}
		for (int i = N - 2; i >= downr; i--)
		{
			if (arr[0][i][0] == -1)
			{
				break;
			}
			temp = arr[0][i][0];
			arr[0][i][0] = nextval;
			nextval = temp;
		}
		for (int i = 1; i < aircol; i++)
		{
			temp = arr[0][downr][i];
			arr[0][downr][i] = nextval;
			nextval = temp;
		}
		rst -= nextval;
	}
	cout << rst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> arr[0][i][j];
			if(arr[0][i][j] == -1 && !did)
			{
				upr = i;
				downr = i + 1;
				aircol = j;
				did = true;
				continue;
			}
			rst += arr[0][i][j];
		}
	}
	rst++;
	Aircirculator();
}