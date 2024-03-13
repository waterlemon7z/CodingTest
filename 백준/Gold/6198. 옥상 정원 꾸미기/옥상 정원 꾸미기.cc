#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	stack<int> s;
	int N, h;
	unsigned long long rst = 0;
	cin >> N;
	while (N--) {
		cin >> h;
		while (!s.empty() && s.top() <= h)
			s.pop();
		rst += s.size();
		s.push(h);
	}
	cout << rst;
}