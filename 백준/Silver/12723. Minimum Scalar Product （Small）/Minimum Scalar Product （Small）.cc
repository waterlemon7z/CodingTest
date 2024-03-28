#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int > pii;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int N, T, temp, ts = 1;
    cin >> T;
    while(T--)
    {
        cin >>N;
        vector<int> a,b;
        int rst = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            b.push_back(temp);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), cmp);
        for (int i = 0; i < N; ++i)
        {
            rst += a[i] * b[i];
        }
        cout << "Case #" << ts++ <<": " << rst << endl;
    }

}