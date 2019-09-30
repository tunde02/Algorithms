/*
-NOT YET-

8 7
1 2
1 3
1 4
4 5
5 6
6 7
4 8

3
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main()
{
	// 전봇대, 길
	int n, m; cin >> n >> m;
	vector<bool> checks(n, false);
	vector<vector<bool>> g(n, vector<bool>(n, false));
	vector<tuple<int, int>> lines(n, tuple<int, int>(0, 0));

	for(int i = 0; i < n; i++)
		get<1>(lines[i]) = i;

	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		g[a][b] = true;
		g[b][a] = true;
		get<0>(lines[i])++;
	}

	sort(lines.begin(), lines.end());
	reverse(lines.begin(), lines.end());

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			
		}
	}
}