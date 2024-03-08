#include <iostream>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef  long long ull;

int main()
{
	FASTIO
	string str;
	cin >> str;
	char  korea[] = {'K', 'O', 'R', 'E', 'A'};
	int rst = 0;
	for(auto iter : str)
	{
		if(iter == korea[rst%5])
			rst++;
	}
	cout << rst;
}

