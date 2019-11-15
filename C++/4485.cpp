/*
4485 - 녹색 옷 입은 애가 젤다지?

-TEST CASE-
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
0

Problem 1: 20
Problem 2: 19
Problem 3: 36
*/

/*
-EXPLANATION-
- 2차원 배열에서 인접한 점들을 연결된 정점으로 생각하고 다익스트라 알고리즘 사용
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = INT32_MAX;
typedef pair<int, int> pos;
int n, cnt = 1;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int dijkstra(vector<vector<int>>* map)
{
	vector<vector<int>> distances(n, vector<int>(n, INF));
	priority_queue<pair<int, pos>, vector<pair<int, pos>>, greater<pair<int, pos>>> pq;

	pq.push({ (*map)[0][0], {0, 0} });
	distances[0][0] = (*map)[0][0];

	while(!pq.empty())
	{
		int nowX = pq.top().second.first, nowY = pq.top().second.second;
		int nowWeight = pq.top().first;

		pq.pop();

		if(distances[nowX][nowY] < nowWeight)
			continue;

		for(int i = 0; i < 4; i++)
		{
			int nextX = nowX + dx[i], nextY = nowY + dy[i];
			if(!(0 <= nextX && nextX < n && 0 <= nextY && nextY < n))
				continue;
			int nextWeight = (*map)[nextX][nextY];

			if(distances[nowX][nowY] + nextWeight < distances[nextX][nextY])
			{
				distances[nextX][nextY] = distances[nowX][nowY] + nextWeight;
				pq.push({ distances[nextX][nextY], {nextX, nextY} });
			}
		}
	}

	return distances[n - 1][n - 1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while(n != 0)
	{
		vector<vector<int>> map(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				int input; cin >> input;
				map[i][j] = input;
			}
		}

		cout << "Problem " << cnt++ << ": " << dijkstra(&map) << "\n";

		cin >> n;
	}
}