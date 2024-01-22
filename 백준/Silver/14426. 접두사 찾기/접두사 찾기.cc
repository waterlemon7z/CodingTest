#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;

using namespace std;

//clock_t start;
typedef pair<int, int> pii;
typedef unsigned long long ull;

class Trie{
public:
	Trie *node[26];

	Trie()
	{
		for(int i = 0; i < 26; i++)
		{
			node[i] = NULL;
		}
	}
	void insert(string &str, int idx)
	{
		if(str.size() == idx)
		{
			return;
		}
		if(node[str[idx]- 'a'] == NULL)
		{
			node[str[idx]- 'a'] = new Trie();
		}
		node[str[idx]- 'a']->insert(str, idx + 1);
	}
	bool find(string &key, int idx)
	{
		if(key.size() == idx)
			return true;
		else if(node[key[idx] - 'a'] != NULL)
		{
			return node[key[idx] - 'a']->find(key, idx + 1);
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string temp;
	int N, M, rst = 0;
	cin >> N >> M;
	Trie tree;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		tree.insert(temp, 0);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		if(tree.find(temp, 0)) rst++;
	}
	cout << rst;
}