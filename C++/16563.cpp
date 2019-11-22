/*
16563 - 어려운 소인수분해
<TIME OUT>
-TEST CASE-
5
5 4 45 64 54

5
2 2
3 3 5
2 2 2 2 2 2
2 3 3 3
*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int maxNum = 0;
vector<int> arr;
vector<vector<int>> d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int input; cin >> input;
		arr.push_back(input);
		maxNum = maxNum > input ? maxNum : input;
	}

	d = vector<vector<int>>(maxNum + 1);
	d[2] = { 2 };

	for(int i = 3; i <= maxNum; i++)
	{
		int num = i;
		for(int j = 2; j < i; j++)
		{
			if(num % j == 0)
			{
				d[num].insert(d[num].end(), d[j].begin(), d[j].end());
				num /= j;
				break;
			}
		}

		if(i == num) // prime number
			d[i] = { i };
		else
			d[i].insert(d[i].end(), d[num].begin(), d[num].end());
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0, size = d[arr[i]].size(); j < size; j++)
		{
			cout << d[arr[i]][j] << " ";
		}
		cout << "\n";
	}
}