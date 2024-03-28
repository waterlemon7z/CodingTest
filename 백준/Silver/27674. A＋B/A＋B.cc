#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int > pii;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int N;
    cin >> N;

    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        sort(str.begin(), str.end(), cmp);
        cout << stoll(str.substr(0,str.size() - 1)) + stoll(str.substr(str.size()-1, str.size())) << endl;
    }

}