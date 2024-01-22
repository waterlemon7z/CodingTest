#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int aa, ab, ac ,ca, cb, cc;
	cin >> aa >> ab >> ac >> ca >> cb >>cc;
	cout << abs(ac - ca) << ' ' << (ab > cb? ab/cb : cb/ab) << ' ' << abs(aa - cc);
}