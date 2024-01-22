#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INF 987654321
#define endl '\n'
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
typedef pair<char, char> pii;
int N;
vector<pii> tree;

void preorder(char root)
{
	char left, right;
	left = tree[root - 'A'].first;
	right = tree[root - 'A'].second;
	cout << root;

	if(left != '.')
		preorder(left);
	if(right != '.')
		preorder(right);
}

void inorder(char root)
{
	char left, right;
	left = tree[root - 'A'].first;
	right = tree[root - 'A'].second;

	if(left != '.')
		inorder(left);
	cout << root;
	if(right != '.')
		inorder(right);
}

void postorder(char root)
{
	char left, right;
	left = tree[root - 'A'].first;
	right = tree[root - 'A'].second;

	if(left != '.')
		postorder(left);
	if(right != '.')
		postorder(right);
	cout << root;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char root;
	cin >> N;
	tree = vector<pii>(N, {'.', '.'});
	for(int i = 0; i < N; i++)
	{
		cin >> root;
		cin >> tree[root-'A'].first >> tree[root-'A'].second;
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;

}
