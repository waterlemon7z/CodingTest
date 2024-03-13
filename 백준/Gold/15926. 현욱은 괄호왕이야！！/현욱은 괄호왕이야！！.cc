#include <bits/stdc++.h>
#define FSIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){
	FSIO
	stack<int> s;
	int N, rst = 0;
	string str;
	char c;
	cin >> N >> str;
	s.push(-1);
	for(int i = 0; i < N; i++){
		c = str[i];
		if(c == '(')
			s.push(i);
		else if(!s.empty())
		{
			s.pop();
			if(!s.empty())
				rst = max(rst, i-s.top());
			else
				s.push(i);
		}
	}
	cout << rst;
}