#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//int MM;
vector<int> arr;
void backT(int N, int M, int cur)
{
	int i = 0;
	if(M == cur)
	{
		for(auto iter : arr)
			cout << iter << ' ';
		cout << '\n';
		return;
	}
	if(cur == 0)
		i = cur;
	else
		i = arr[cur-1];
	for(; i < N; i++)
	{
		arr[cur] = i + 1;
		backT(N, M, cur + 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	arr = vector<int>(m);
	backT(n, m, 0);

}