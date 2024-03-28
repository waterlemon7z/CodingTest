#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int > pii;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int N, temp;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    int j = ceil(N / 2.0);
    for(int i= j - 1; i >= 0  ;i--)
    {
        cout << v[i] << ' ';
        if(j < N)
            cout << v[j++] << ' ';
    }
}