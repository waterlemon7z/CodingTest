#include <iostream>

using namespace std;

int main()
{
    int A, rst = 0;
    for(int i = 0;i < 5; i++)
    {
        cin >> A;
        if(A < 40)
            A = 40;
       rst += A / 5;
        
    }
    cout << rst;
}