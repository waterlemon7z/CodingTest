#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	stoi(str1) > stoi(str2) ? cout << str1 : cout << str2;
}