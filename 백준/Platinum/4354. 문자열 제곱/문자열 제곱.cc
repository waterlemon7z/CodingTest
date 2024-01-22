#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#define INF 987654321
#define TIMER_S start = clock();
#define TIMER_F cout << (clock() - start) << "ms" << endl;


using namespace std;
//clock_t start;
//typedef pair<int, int> pii;
vector<int> pi, rst;
void setPI(string P)
{
	int size = P.size(), j = 0;
	pi = vector<int>(P.size(),0);
	for(int i = 1; i < size; i++)
	{
		while(j > 0 && P[i] != P[j])
			j = pi[j-1];
		if(P[i] == P[j])
			pi[i] = ++j;
	}
}

//void kmp(string T, string P)
//{
//	int j = 0, size = T.size(), keysize = P.size();
//	setPI(P);
//	for(int i = 0; i < size; i++)
//	{
//		while(j > 0 && T[i] != P[j])
//			j = pi[j-1];
//		if(T[i] == P[j])
//		{
//			if(j == keysize - 1)
//			{
//				j = pi[j];
//				rst.push_back(i - keysize + 2);
//			}
//			else
//				j++;
//		}
//	}
//}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string P;
	int length;
	while(1)
	{
		getline(cin, P);
		if(P == ".")
			break;
		length = P.size();
		setPI(P);
		cout << ((length%(length - pi[length - 1]) != 0)? 1 : length/(length - pi[length - 1])) << '\n';
	}

}
