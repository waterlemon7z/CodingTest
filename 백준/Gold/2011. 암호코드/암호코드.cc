#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int memo[5001] = {0,};
	string str, substr_;
	cin >> str;
	if(str[0] == '0')
	{
		cout << 0;
		return 0;
	}
	memo[0] = 1;
	memo[1] = 1;
	for(int i = 2; i <= str.size(); i++)
	{
		substr_ = str.substr(i-2,2);
		if(substr_ == "00")
		{
			cout << 0;
			return 0;
		}
		if(stoi(substr_) >= 30 && stoi(substr_) % 10 == 0)
		{
			cout << 0;
			return 0;
		}
		if(stoi(substr_) >= 11 && stoi(substr_) <= 26 && stoi(substr_) != 20)
		{
			memo[i] = (memo[i - 2] + memo[i - 1]) % 1000000;
		}
		else
		{
			if(stoi(substr_) == 10 || stoi(substr_) == 20)
				memo[i] = memo[i-2] % 1000000;
			else
				memo[i] = memo[i - 1] % 1000000;
		}
	}
	cout << memo[str.size()];
}
