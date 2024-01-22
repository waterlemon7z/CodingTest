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
typedef pair<pair<int, int>, int> pii;
vector<int> rst;
int A, B, C;

void bfs()
{
	int a, b, c;
	bool check[201][201][201]= {0,};
	queue<pii> qq;
	qq.push({{0, 0}, C});
	while(!qq.empty())
	{
		a = qq.front().first.first;
		b = qq.front().first.second;
		c = qq.front().second;
		qq.pop();
		if(check[a][b][c])
			continue;
		check[a][b][c] = 1;
		if(a == 0)
			rst.push_back(c);
		//a->b
		if(a + b > B)
			qq.push({{a + b - B, B}, c});
		else
			qq.push({{0, a + b}, c});
		//a->c
		if(a + c > C)
			qq.push({{a + c - C, b}, C});
		else
			qq.push({{0, b}, a + c});
		//b->a
		if(b + a > A)
			qq.push({{A, a + b - A}, c});
		else
			qq.push({{a + b, 0}, c});
		//b->c
		if(b + c > C)
			qq.push({{a, b + c - C}, C});
		else
			qq.push({{a, 0}, b + c});
		//c->a
		if(c + a > A)
			qq.push({{A, b}, c + a - A});
		else
			qq.push({{a + c, b}, 0});
		//c->b
		if(b + c > B)
			qq.push({{a, B}, b + c - B});
		else
			qq.push({{a, b + c}, 0});

	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C;
	bfs();
	sort(rst.begin(), rst.end());
	for(auto iter : rst)
		cout << iter << ' ';
}