#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//typedef unsigned long long ull;


void postorder(string str)
{
	int size = str.size();
	char xx;
	vector<char> ss;
	for(int i = 0; i < size; i++)
	{
		xx = str[i];
		if(xx == '(')
		{
			ss.push_back(xx);
		}
		else if (xx == ')')
		{
			while(ss.back() != '(')
			{
				cout << ss.back();
				ss.pop_back();
			}
			ss.pop_back();
		}
		else if(xx == '*' || xx == '/')
		{
			while(!ss.empty() && (ss.back() == '*' || ss.back() == '/'))
			{
				cout << ss.back();
				ss.pop_back();
			}
			ss.push_back(xx);
		}
		else if(xx == '+' || xx == '-')
		{
			while(!ss.empty() && (ss.back() != '('))
			{
				cout << ss.back();
				ss.pop_back();
			}
			ss.push_back(xx);
		}
		else
		{
			cout << xx;
		}
	}
	while(!ss.empty())
	{
		cout << ss.back();
		ss.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	postorder(str);
}
