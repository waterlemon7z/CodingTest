#include <bits/stdc++.h>

using namespace std;

int get(int n)
{
    int rst = n;
    while (n != 0)
    {
        rst += n % 10;
        n /= 10;
    }
    return rst;

}

int main()
{
    bool check[10001] = {0,};
    int n = 1;
    while(n <= 10000)
    {
        int b= get(n);
        if(b <= 10000)
            check[b] = true;
        n++;
    }
    for (int i = 01; i < 10001; ++i)
    {
        if(!check[i])
            cout << i << '\n';
    }
}