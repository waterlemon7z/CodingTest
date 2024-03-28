#include <bits/stdc++.h>
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
using namespace std;
int main()
{
    FASTIO
    long long N, rst = 0;
    int arr[40000] = {0,};
    cin >> N;
    for (int i =1; i <= N; ++i)
    {
        cin >> arr[i];
    }
    rst  += 2*N;
    rst += arr[1] + arr[N];
    for (int i = 1; i < N; ++i)
    {
        rst+= 2 * arr[i];
        rst += abs(arr[i]- arr[i+1]);
    }
    rst+= 2 * arr[N];
    cout <<rst;

}