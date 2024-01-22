#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
typedef long long ll;
map<ll,ll> map_idx;

void idx_mapper(vector<int> *arr)
{
	ll total;
	for(int i = 0; i < arr->size(); i++)
	{
		total = 0;
		for(int j = i; j < arr->size(); j++)
		{
			total += arr->at(j);
			if(map_idx.find(total) == map_idx.end())
			{
				map_idx[total] = 1;
			}
			else
			{
				map_idx[total]++;
			}
		}
	}
}

ll idx_finder(vector<int> *arr, int T)
{
	ll total, temp, rst = 0;
	for(int i = 0; i < arr->size(); i++)
	{
		total = 0;
		for(int j = i; j < arr->size(); j++)
		{
			total += arr->at(j);
			temp = T - total;
			rst += map_idx[temp];
		}
	}
	return rst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, M;
	vector<int> A, B;
	cin >> T >> N;
	A.resize(N);
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> M;
	B.resize(M);
	for(int i = 0; i < M; i++)
	{
		cin >> B[i];
	}
	idx_mapper(&A);
	cout  << idx_finder(&B, T);
}