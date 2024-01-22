#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string str, rst;
	cin >> str;
	if(str[0] == 'A')
	{
		rst += '4';
		if(str[1] == '+')
			rst += ".3";
		else if(str[1] == '0')
			rst += ".0";
		else if(str[1] == '-')
			rst = "3.7";
	}
	else if(str[0] == 'B')
	{
		rst += '3';
		if(str[1] == '+')
			rst += ".3";
		else if(str[1] == '0')
			rst += ".0";
		else if(str[1] == '-')
			rst = "2.7";
	}
	else if(str[0] == 'C')
	{
		rst += '2';
		if(str[1] == '+')
			rst += ".3";
		else if(str[1] == '0')
			rst += ".0";
		else if(str[1] == '-')
			rst = "1.7";
	}
	else if(str[0] == 'D')
	{
		rst += '1';
		if(str[1] == '+')
			rst += ".3";
		else if(str[1] == '0')
			rst += ".0";
		else if(str[1] == '-')
			rst = "0.7";
	}
	else
		rst = "0.0";
		cout << rst;

}