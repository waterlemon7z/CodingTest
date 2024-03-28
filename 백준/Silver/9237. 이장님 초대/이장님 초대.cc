#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int > pii;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
   int N, temp, rst = 0;
   cin >> N;
   vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(), cmp);
    for (int i = 0; i < N; ++i)
    {
        rst = max(v[i] + i, rst);
    }
    cout << rst + 2;
}