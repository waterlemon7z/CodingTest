#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, N,  cur = 1, temp;
    cin >> T;
    while(T--)
    {
        cin >> N;
        deque<int>dq;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            dq.push_back(temp);
        }
        while(dq.size() != 2)
        {
            deque<int> cnt;
            while(dq.size() > 1){
                cnt.push_back(dq.front() + dq.back());
                dq.pop_back();
                dq.pop_front();
            }
            if(dq.size() == 1)
            {
                cnt.push_back(dq.front()*2);
            }
            dq = cnt;
        }
        cout << "Case #"<< cur++ << (dq[0] > dq[1] ? ": Alice" : ": Bob") << endl;
    }
}