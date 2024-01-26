#include <bits/stdc++.h>

#define INF 2147483647
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
#define FASTIO ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;


int main()
{
	FASTIO
	int i;
	cin >>i;
	string s;
	if(620 <= i && i <= 780) s = "Red";
	else if(590 <= i && i < 620) s = "Orange";
	else if(570 <= i && i < 590) s = "Yellow";
	else if(495 <= i && i < 570) s = "Green";
	else if(450 <= i && i < 495) s = "Blue";
	else if(425 <= i && i < 450) s = "Indigo";
	else if(380 <= i && i < 425) s = "Violet";

	cout << s;
}
