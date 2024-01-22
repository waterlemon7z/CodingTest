#include <iostream>
#include <algorithm>
//#include <string>
using namespace std;

int main()
{
	int rst = 0;
	string str;
	getline(cin, str);
	for(auto iter : str)
	{
		if(iter == ' ')
			rst++;
	}
    if(str[0] == ' ')
        rst--;
    if(str[str.size()-1] == ' ')
        rst--;
	cout << ++rst;
}