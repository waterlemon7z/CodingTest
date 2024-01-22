#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
typedef pair<int, int> pii;
typedef long long ll;
int N;

double triangle(double x1, double y1, double x2,double y2, double x3, double y3)
{
	return ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3))/2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double pointx, pointy, newx, newy, oldx, oldy;
	double rst = 0;

	cin >> N;
	cin >> pointx >> pointy >> oldx >> oldy;

	for(int i = 0; i < N - 2; i++)
	{
		cin >> newx >> newy;
		rst += triangle(pointx, pointy, oldx, oldy, newx, newy);
		oldx = newx;
		oldy = newy;
	}
	printf("%.1lf", abs(rst));
}