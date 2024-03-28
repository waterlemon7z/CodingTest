#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main()
{
    priority_queue<pii, vector<pii>, greater<pii>> input;
    priority_queue<int, vector<int>, greater<int>> lectures;

    int N, m, rst = 0;
    pii temp;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> m;
        cin >> temp.first >> temp.second;
        input.push(temp);
    }
    while(!input.empty())
    {
        pii top = input.top();
        input.pop();
        if(!lectures.empty() && lectures.top() <= top.first)
        {
            lectures.pop();
        }
        else
        {
            rst++;
        }
        lectures.push(top.second);
    }
    cout <<rst;
}