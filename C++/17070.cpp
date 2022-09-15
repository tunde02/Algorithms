/*
17070 - 파이프 옮기기 1

-TEST CASE-
4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

3

5
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

0
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
vector<vector<vector<int>>> d; // {가로, 세로, 대각선}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n, 0));
	d = vector<vector<vector<int>>>(n, vector<vector<int>>(n, { 0, 0, 0 }));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int input; cin >> input;
			map[i][j] = input;
		}
	}

	d[0][1] = { 1, 0, 0 };

	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(map[i][j] == 1) continue;

			int a = d[i][j][0], b = d[i][j][1], c = d[i][j][2];

			if(0 <= j - 1 && map[i][j - 1] == 0) // 가로 상태에서
			{
				if(j + 1 < n && map[i][j + 1] == 0) // 가로로 가는 경우
					d[i][j + 1][0] += a;
				if(i + 1 < n && j + 1 < n // 대각선으로 가는 경우
					&& map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
					d[i + 1][j + 1][2] += a;
			}
			if(0 <= i - 1 && map[i - 1][j] == 0) // 세로 상태에서
			{
				if(i + 1 < n && map[i + 1][j] == 0) // 세로로 가는 경우
					d[i + 1][j][1] += b;
				if(i + 1 < n && j + 1 < n // 대각선으로 가는 경우
					&& map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
					d[i + 1][j + 1][2] += b;
			}
			if(0 <= i - 1 && 0 <= j - 1 // 대각선 상태에서
				&& map[i - 1][j] == 0 && map[i][j - 1] == 0 && map[i - 1][j - 1] == 0)
			{
				if(j + 1 < n && map[i][j + 1] == 0) // 가로로 가는 경우
					d[i][j + 1][0] += c;
				if(i + 1 < n && map[i + 1][j] == 0) // 세로로 가는 경우
					d[i + 1][j][1] += c;
				if(i + 1 < n && j + 1 < n // 대각선으로 가는 경우
					&& map[i][j + 1] == 0 && map[i + 1][j] == 0 && map[i + 1][j + 1] == 0)
					d[i + 1][j + 1][2] += c;
			}
		}
	}

	cout << (d[n - 1][n - 1][0] + d[n - 1][n - 1][1] + d[n - 1][n - 1][2]);
}