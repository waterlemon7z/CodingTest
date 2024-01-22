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
//typedef long long ll;

void select_sort(vector<int> &arr, int T)
{
	int cnt = 0, temp, key, idx;
	for(int cur = 0; cur < arr.size() - 1; cur++)
	{
		if(cnt == T)
			return;
		idx = -1;
		key = arr[cur];
		for(int i = cur + 1; i < T + cur - cnt + 1 && i < arr.size(); i++)
		{
			if(arr[i] > key)
			{
				idx = i;
				key = arr[i];
			}
		}
		if(idx != -1)
		{
			temp = arr[idx];
			for(int i = idx; i > cur; i--)
			{
				arr[i] = arr[i-1];
			}
			arr[cur] = temp;
			cnt += idx - cur;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	vector<int> A;
	cin >> N;
	A.resize(N);
	for(int i = 0 ; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> T;
	select_sort(A, T);
//	bubble_sort(A, T);
	for(auto iter : A)
	{
		cout << iter << ' ';
	}
}