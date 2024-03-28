#include <bits/stdc++.h>

using namespace std;

int get(int n, int d)
{
    int rst = 0;
    while(n != 0)
    {
        if(n % 10 == d)
            rst++;
        n /= 10;
    }
    return rst;
}

int main()
{
    int n, d, cur = 0;
    int rst = 0;
    cin >> n >> d;

    for (int i = 0; i <= n; ++i)
    {
        rst += get(i ,d);
    }
    cout <<rst;
}