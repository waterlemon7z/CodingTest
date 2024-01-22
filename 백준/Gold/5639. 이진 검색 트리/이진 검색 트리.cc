#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#define INF 987654321
#define DIV 1000000007
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;
using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
vector<int> arr;

void tree(int fst, int lst)
{
	int i, root = arr[fst];
	if(fst > lst)
		return;
	if(fst == lst)
	{
		cout << root << endl;
		return;
	}

	for(i = fst + 1; i <= lst; i++)
	{
		if(arr[i] > root)
		{
			break;
		}
	}
	if(i == lst + 1)
	{
		tree(fst + 1, lst);
	}
	else
	{
		tree(fst + 1, i - 1);
		tree(i, lst);
	}
	cout << root << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int temp;
	while(scanf("%d", &temp) != EOF)
	{
//		if(temp == -1)
//			break;
		arr.push_back(temp);
	}
	tree(0, arr.size() - 1);
}