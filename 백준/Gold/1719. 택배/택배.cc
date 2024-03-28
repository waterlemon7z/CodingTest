#include <bits/stdc++.h>

#define INF 2000001
using namespace std;


int main()
{
    int N, M, x, y, val;
    int board[201][201] = {0,}, rst[201][201] = {0,};
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            board[i][j] = INF;
            if (i == j)
                board[i][j] = 0;
        }
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y >> val;
        board[x][y] = val;
        board[y][x] = val;
        rst[x][y] = y;
        rst[y][x] = x;
    }
    //fw
    for (int dir = 1; dir <= N; ++dir)
    {
        for (x = 1; x <= N; ++x)
        {
            for (y = 1; y <= N; ++y)
            {
                if(board[x][y] > board[x][dir] + board[dir][y])
                {
                    board[x][y] = board[x][dir] + board[dir][y];
                    rst[x][y] = rst[x][dir];
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                cout << "- ";
            else
                cout << rst[i][j] << ' ';
        }
        cout << '\n';
    }

}