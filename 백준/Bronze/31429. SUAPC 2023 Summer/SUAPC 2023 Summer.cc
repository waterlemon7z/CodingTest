#include <bits/stdc++.h>

using namespace std;


int main()
{
    pair<int, int> arr[12] = {{0,0},{12,1600}, {11,894},{11,1327}, {10,1311}
    ,{9,1004},{9,1178},{9,1357},{8,837},{7,1055},{6,556},{6,773}};

    int n;
    cin >> n;
    cout << arr[n].first << ' ' << arr[n].second;
}