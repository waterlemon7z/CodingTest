#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char moum[5] = {'a', 'e', 'i', 'o', 'u'};

void backT(vector<char> arr, string str, int L, int cur, int mo, int ja)
{
	if(str.size() == L && mo >= 1 && ja >= 2)
		cout << str << endl;
	if(cur + L - str.size() - 1 >= arr.size())
		return;
	for(int i = cur; i < arr.size(); i++)
	{
		if(arr[i] == moum[0] || arr[i] == moum[1] || arr[i] == moum[2] || arr[i] == moum[3] || arr[i] == moum[4])
			backT(arr, str + arr[i], L, i + 1, mo + 1, ja);
		else
			backT(arr, str + arr[i], L, i + 1, mo, ja + 1);
	}
}

int main()
{
	int L, C;
	cin >> L >> C;
	vector<char> arr(C);
	for(int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	backT(arr, "", L, 0, 0, 0);
}
