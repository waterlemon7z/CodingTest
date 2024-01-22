#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, temp, max_ = 0;
	float rst = 0;
	vector<float> arr;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
		max_ = max(max_, temp);
	}
	for(int i = 0; i < N; i++)
	{
		rst += arr[i]/max_ * 100.0;
	}
	printf("%f", (float)rst/N);
}