#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M, temp;
    cin >> N >>M >> temp;
    if(N + M <= temp)
        cout << 1;
    else
        cout << 0;
}