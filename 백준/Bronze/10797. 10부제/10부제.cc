#include <iostream>

using namespace std;

int main()
{
    int N, temp, cnt = 0;
    cin >> N;
    N %= 10;
    for(int i = 0; i < 5; i++)
    {
        cin >> temp;
        if(temp == N)
            cnt++;
    }
    cout << cnt;
}