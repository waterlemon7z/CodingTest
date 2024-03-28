#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int > pii;
bool cmp(pii a, pii b)
{
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    char ox;
    int T, N,temp, sc;
    int score[101];
    vector<pii> stscore;
    cin >> T >> N;
    for (int i = 0; i < T; ++i)
    {
        cin >> score[i];
    }
    for (int i = 0; i < N; ++i)
    {
        sc = 0;
        cin >> temp;
        for (int j = 0; j < T; ++j)
        {
            cin >> ox;
            if('O' == ox)
                sc +=score[j];
        }
        stscore.push_back({sc, temp});
    }
    sort(stscore.begin(), stscore.end(), cmp);
    cout << stscore[0].second << ' ' << stscore[0].first;

}