#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int A, rst = 1;
    cin >> A;
    if (A == 0){
        cout << 1;
    return 0;}
    for(int i = 1; i <= A; i++)
        rst *= i;
    cout << rst;
}