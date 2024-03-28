#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N;
    cin >> N;
    int arr[11] = {0,};
    arr [0] = 0;
    for (int i = 1; i < 11; ++i)
    {
        arr[i] = arr[i-1] + i-1;
    }
    cout <<arr[N];
}