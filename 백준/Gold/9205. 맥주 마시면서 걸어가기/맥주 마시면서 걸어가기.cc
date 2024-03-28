/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;


int
getDist (pair < int, int >x, pair < int, int >y)
{
    return abs(x.first - y.first) + abs(x.second - y.second );
}

int
main ()
{
  int T, x, y, N;
  cin >> T;
  while (T--)
	{

	  int board[101][101] = { 0, };
    	  bool visit[101] = {0,};
      vector < pair < int, int >>v;
	  queue<int> q;
	  cin >> N;
	  for (int i = 0; i < N + 2; i++)
		{
		  cin >> x >> y;
		  v.push_back({x, y});
		}


		q.push(0);
	  for (int i = 0; i < N + 2; i++)
		{
		  for (int j = i + 1; j < N + 2; j++)
			{
			  if (getDist (v[i],v[j]) <= 1000)
				{
				  board[i][j] = 1;
				  board[j][i] = 1;
				}
			}
		}
		bool flag = true;
		while(!q.empty() && flag)
		{
		    int cur = q.front();
		    q.pop();
		    visit[cur] = 1;
		    for(int i = 0; i < N + 2; i++)
		    {
		        if(board[cur][i] == 1 && !visit[i]){
		            if(i == N + 1){
		                cout << "happy\n";
		                flag = false;
		                break;
		            }
		            q.push(i);}
		    }
		}
		if(flag)
		    cout << "sad\n";
	}
  return 0;
}
