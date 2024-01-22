#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cmath>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, revs, error;
	string oper, input, temp;
	cin >> T;
	while(T--)
	{
		revs = 0;
		error= 0;
		deque<int> qq;
		cin >> oper >> N >> input;
		for(auto iter : input)
		{
			if(isdigit(iter))
				temp += iter;
			else
			{
				if(!temp.empty())
				{
					qq.push_back(stoi(temp));
					temp = "";
				}
			}
		}
		for(auto iter : oper)
		{
			if(iter == 'R')
				revs++;
			if(iter == 'D')
			{
				if(qq.empty())
				{
					error = 1;
					cout << "error" << endl;
					break;
				}
				if(revs % 2 == 0)
				{
					qq.pop_front();
				}
				else
					qq.pop_back();
			}
		}
		if(error == 1)
			continue;
		cout << '[';
		if(revs % 2 == 1 && !qq.empty())
		{
			for(auto i = qq.rbegin(); i != qq.rend() - 1; i++)
			{
				cout << *i << ',';
			}
			cout << *(qq.rend() - 1);
		}
		else if(revs % 2 == 0 && !qq.empty())
		{
			for(auto i = qq.begin(); i != qq.end() - 1; i++)
			{
				cout << *i << ',';
			}
			cout << *(qq.end() - 1);
		}
		cout << ']' << endl;
	}

}