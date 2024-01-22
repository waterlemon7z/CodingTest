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
vector<int> input;
void backT(int N, int M, int cur, int i)
{
	if(M == cur)
	{
		for(auto iter : arr)
			cout << iter << ' ';
		cout << '\n';
		return;
	}
	for(;i < N; i++)
	{
		arr[cur] = input[i];
		backT(N, M, cur + 1, i);
	}
}

int main()
{
	int n, m, temp;
	cin >> n >> m;
	arr = vector<int>(m);
	for(int  i = 0; i < n ; i++)
	{
		cin >> temp;
		input.push_back(temp);
	}
	sort(input.begin(), input.end());
	backT(n, m, 0,0);

}