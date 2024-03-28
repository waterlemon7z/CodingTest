#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M, temp;
    cin >> N >>M;
    cout << max(N + M,N - M) << endl;
    cout << min(N + M,N - M);
}