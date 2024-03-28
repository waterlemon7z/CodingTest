#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[101][101] = {0,};
    int N,x ,y, rst = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        for (int dx = x; dx < x + 10; ++dx)
            for (int dy = y; dy < y + 10; ++dy)
            {
                if(arr[dx][dy] == 0)
                {
                    arr[dx][dy] = 1;
                    rst++;
                }
            }
    }
    cout << rst;
}