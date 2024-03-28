#include <bits/stdc++.h>

#define INF 2000001
using namespace std;
typedef pair<int, int> pii;

int main()
{
    int N, x, cnt;
    long long rst = 0;
    stack<pii> s;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cnt = 1;
        cin >> x;
        while (!s.empty() && s.top().first <= x)
        {
            if (s.top().first == x)
                cnt += s.top().second;
            rst += s.top().second;
            s.pop();
        }
        s.push({x, cnt});
        if (s.size() != 1)
            rst++;

    }
    cout << rst;

}