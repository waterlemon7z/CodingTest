#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//struct for input
typedef struct pair_
{
	float first, second;
} Pair;

//struct for kruskal queue
typedef struct kruskalNode_
{
	float dist;
	Pair node;
} KruskalNode;

KruskalNode sorted[10001]; // temporary array for merge sort
int root[101] = {0,}; // root array for union_find
/*
 * Name        : init
 * Date        : 2023-10-11
 * argument    : none
 * return      : void
 * description : initialize for union_find
*/
void init()
{
	for (int i = 0; i < 101; i++)
	{
		root[i] = i;
	}
}

/*
 * Name        : find_
 * Date        : 2023-10-11
 * argument    : int
 * return      : int
 * description : find each node's root
*/
int find_(int n)
{
	if (n == root[n]) // if finds
		return n;
	return root[n] = find_(root[n]); // this step shrinks find steps next time.
}
/*
 * Name        : union_
 * Date        : 2023-10-11
 * argument    : int, int
 * return      : int
 * description : union nodes. x - y => root[x] == root[y] && if already unioned return 0 else return true.
*/
bool union_(int x, int y)
{
	x = find_(x);
	y = find_(y);
	if (x == y)
		return 0;
	root[y] = x;
	return 1;
}

/*
 * Name        : merge
 * Date        : 2023-10-11
 * argument    : KruskalNode, int, int, int
 * return      : void
 * description : merge nodes which were split.
*/
void merge(KruskalNode *q, int fst, int lst, int mid)
{
	int i = fst;
	int j = mid + 1;
	int cur = fst;
	while (i <= mid && j <= lst)
	{
		if (q[i].dist <= q[j].dist)
			sorted[cur++] = q[i++];
		else
			sorted[cur++] = q[j++];
	}
	if (i > mid)
	{
		while (j <= lst)
			sorted[cur++] = q[j++];
	}
	else
	{
		while (i <= mid)
			sorted[cur++] = q[i++];
	}
	for (int l = fst; l < cur; l++)
	{
		q[l] = sorted[l];
	}
}

/*
 * Name        : sort
 * Date        : 2023-10-11
 * argument    : KruskalNode, int, int
 * return      : void
 * description : Do merge sort
*/
void sort(KruskalNode *q, int fst, int lst)
{
	int mid;
	if (fst < lst)
	{
		mid = (fst + lst) / 2;
		sort(q, mid + 1, lst);
		sort(q, fst, mid);
		merge(q, fst, lst, mid);
	}
}

/*
 * Name        : distance
 * Date        : 2023-10-11
 * argument    : int, Pair*, KruskalNode*
 * return      : int
 * description : calculate nodes distance.
*/
int distance(int N, Pair *input, KruskalNode *qq)
{
	int loc = 0;
	float dist;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			dist = sqrt(pow(input[i].first - input[j].first, 2) + pow(input[i].second - input[j].second, 2));
			qq[loc].dist = dist; // distance of two nodes.
			qq[loc].node.first = i; // i - j node is connected.
			qq[loc].node.second = j;
			loc++;
		}
	}
	return loc;
}

/*
 * Name        : solve
 * Date        : 2023-10-11
 * argument    : int, Pair*
 * return      : float
 * description : Get distance, sort nodes by distance, and do kruskal to get the shortest length.
*/
float solve(int N, Pair *input)
{
	KruskalNode q[10001];
	float dist = 0;
	int x, y, size;
	size = distance(N, input, q); // get distance
	sort(q, 0, size - 1); // merge sort

	for (int i = 0; i < size; i++) // kruskal algorithm
	{
		x = q[i].node.first; // from x node to y
		y = q[i].node.second;
		if (union_(x, y)) // if not connected
			dist += q[i].dist; // add distance
		// else not.
	}
	return dist;
}

int main()
{
	init();
	int N;
	Pair input[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%f %f", &input[i].first, &input[i].second);
	}
	printf("%.2f", solve(N, input));
}