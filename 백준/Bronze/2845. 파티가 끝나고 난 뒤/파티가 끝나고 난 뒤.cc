#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M, temp;
    cin >> N >>M;
    for (int i = 0; i < 5; ++i)
    {
        cin >> temp;
        cout <<   temp-N *M << ' ';
    }
}