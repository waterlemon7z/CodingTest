#include <bits/stdc++.h>

#define INF 2147483647
using namespace std;
typedef pair<int, int> pii;
int n;
void dijkstra(vector<vector<pii>> adja,priority_queue<pii> pq)
{
    int dist[100001];
    int last = -1, rst = 0;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[pq.top().second] = 0;
    while(!pq.empty())
    {
        int v = pq.top().second;
        int val = -pq.top().first;
        pq.pop();
        for(auto nodes : adja[v])
        {
            int e = nodes.first;
            int w = nodes.second;
            if(dist[e] > val + w)
            {
                dist[e] = val + w;
                pq.push({-dist[e], e});
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] != INF) { rst++;
        last = max(last, dist[i]);
        }
    }
    cout << rst << ' ' << last << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int d, c, x, y, val;
        cin >> n >> d >> c;
        vector<vector<pii>> adja(n+1);
        priority_queue<pii> pq;
        for (int i = 0; i < d; ++i)
        {
            cin >> x >> y >> val;
            adja[y].push_back({x, val});
        }
        pq.push({0, c});
        dijkstra(adja,pq);
    }
}
