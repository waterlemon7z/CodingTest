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

class Node
{
public:
	Node *child[10] = {NULL,};
	bool fine = false;

	Node()
	{

	}
};

//bool find(string str, Node &cur, int len)
//{
//	if (len == str.size())
//		return true;
//	if (cur.fine)
//		return false;
//	else if (cur.child.find(str[len]) != cur.child.end())
//		return find(str, cur.child[str[len]], len + 1);
//	return false;
//}

bool insert(string str, Node *cur, int len)
{
	if (len == str.size())
	{
		cur->fine = true;
		return true;
	}
	if (cur->fine)
		return false;
	char key = str[len] - '0';
	if (cur->child[key] == NULL)
	{
		cur->child[key] = new Node();
//		return insert(str, cur.child[key], len+ 1);
	}
	return insert(str, cur->child[key], len + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, N, i;
	string str[10001];
	cin >> T;
	while (T--)
	{
		Node root = Node();
		cin >> N;
		for (i = 0; i < N; i++)
		{
			cin >> str[i];
		}
		sort(str, str + N);
		for (i = 0; i < N; i++)
		{
			if (!insert(str[i], &root, 0))
			{
				cout << "NO" << endl;
				break;
			}
		}
		if (i == N)
			cout << "YES" << endl;
	}
}
