#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int check[51] = {0,};

int party(vector<vector<int>> arr, set<int> q)
{
	int rst = 0, cnt, bol = 1 ;
	while(!q.empty())
	{
		auto iter_q = q.begin();
		for(auto iter_arr = arr.begin(); iter_arr != arr.end(); iter_arr += 1 * bol)
		{
			bol = 1;
			for(int i = 0; i < iter_arr->size(); i++)
			{
				if(*iter_q == iter_arr->at(i))
				{
					bol = 0;
					for(int j = 0; j < iter_arr->size(); j++)
					{
						q.insert(iter_arr->at(j));
					}
					arr.erase(iter_arr);
				}
			}
		}
		q.erase(iter_q);
	}
	return arr.size();
}

int main()
{
	int N, M, qq, temp9i, tempii;
	cin >> N >> M >> qq;
	set<int> q;
	vector<vector<int>> arr(M);
	vector<int> temp;
	for(int i = 0; i < qq; i++)
	{
		cin >> tempii;
		q.insert(tempii);
	}
	for(int i = 0; i < M; i++)
	{
		cin >> temp9i;
		for(int j = 0 ; j < temp9i; j++)
		{
			cin >> tempii;
			arr[i].push_back(tempii);
		}
	}
	cout << party(arr, q);
}
