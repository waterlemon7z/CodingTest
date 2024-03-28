#include <bits/stdc++.h>
#define FASTIO cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
using namespace std;
int main()
{
    FASTIO
    int N;
    string s;
    double sc, totalH = 0, totalS =0 ,cur ;
    for (int i = 0; i < 20; ++i)
    {
        cin >> s;
        cin >> sc >> s;
        if(s == "P")continue;
        totalH += sc;
        if(s == "A+")
            cur= 4.5;
        else if(s == "A0")
            cur= 4.0;
        else if(s == "B+")
            cur= 3.5;
        else if(s == "B0")
            cur= 3.0;
        else if(s == "C+")
            cur= 2.5;
        else if(s == "C0")
            cur= 2.0;
        else if(s == "D+")
            cur= 1.5;
        else if(s == "D0")
            cur= 1.0;
        else
            cur= 0;
        totalS += cur * sc;
    }
    printf("%.6lf", totalS / totalH);
}