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
int check[8] = {0,};
void backT(int N, int M, int cur)
{
	if(M == cur)
	{
		for(auto iter : arr)
			cout << iter << ' ';
		cout << '\n';
		return;
	}
	for(int i = 0; i < N; i++)
	{
		if(check[i] == 0)
		{
			arr[cur] = input[i];
			check[i]= 1;
			backT(N, M, cur + 1);
			check[i]= 0;
		}
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
	backT(n, m, 0);
}