#include <bits/stdc++.h>
using namespace std;
bool arr[10000001] = {0,};
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N, temp;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        if(arr[temp])
        {
            cout << temp;
            break;
        }
        arr[temp] = true;
    }

}