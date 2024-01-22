#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stack>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
//int MM;

int main()
{
	int cursor, cnt = 0;
	string str, key;
	cin >> str >> key;

	vector<char> ss;

	for(int i = str.size() - 1; i >= 0; i--)
	{
		ss.push_back(str[i]);
		if(ss.size() >= key.size())
		{
			cursor = ss.size() - 1;
			for(auto iter : key)
			{
				if(ss[cursor] == iter)
				{
					cnt++;
					cursor--;
				}
				else break;
			}
			if(cnt == key.size())
			{
				for(int ii = 0; ii < key.size(); ii++)
				{
					ss.pop_back();
				}
			}
			cnt = 0;
		}
	}
	if(ss.empty())
		cout << "FRULA";
	else
		for(int i = ss.size() - 1; i >= 0; i--)
		{
			cout << ss[i];
		}
}