/*
2156 - 포도주 시식

-TEST CASE-
6
6
10
13
9
8
1

33
*/

/*
-EXPLANATION-

- d[n] : n까지의 포도주들 중 마실 수 있는 최대의 양
- d[n+1] : max(d[n], d[n-1] + amounts[n], d[n-2] + amounts[n-1] + amounts[n-2])
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> amounts;
vector<int> d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	d = vector<int>(n, 0);
	for(int i = 0; i < n; i++)
	{
		int input; cin >> input;
		amounts.push_back(input);
	}

	d[0] = amounts[0];
	d[1] = amounts[0] + amounts[1];
	d[2] = max(amounts[0] + amounts[1], max(amounts[0] + amounts[2], amounts[1] + amounts[2]));

	for(int i = 3; i < n; i++)
	{
		d[i] = max(d[i - 3] + amounts[i - 1] + amounts[i], max(d[i - 2] + amounts[i], d[i - 1]));
	}

	cout << d[n - 1];
}