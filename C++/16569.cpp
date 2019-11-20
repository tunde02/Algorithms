/*
16569 - 화산쇄설물

-TEST CASE-

8 8 8
5 8
58 34 30 23 12 44 18 30
4 62 26 42 64 39 44 25
64 34 6 10 0 25 46 34
42 3 62 48 20 25 25 41
35 30 4 33 35 39 41 38
7 43 37 3 0 25 20 23
20 59 18 43 1 14 16 11
17 50 12 19 59 48 7 4
4 5 4
2 6 4
5 1 2
8 8 3
5 6 2
8 2 2
5 2 1
3 5 2

46 3

3 3 2
1 1
0 0 9
0 0 0
0 0 0
2 3 9
3 3 0

0 0

3 3 1
2 1
0 0 0
0 10 0
0 0 0
1 1 0

0 0
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Space
{
public:
	bool available = true;
	bool isHuman = false;
	int x = 0, y = 0;
	int height = 0;
	int time = 0;
	Space() {}
	Space(int x, int y, int h) : x(x), y(y), height(h) {}
};

int M, N, V, X, Y;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
vector<vector<Space>> map;
vector<vector<bool>> visited;
vector<Space> volcanos;

pair<int, int> BFS();

int main()
{
	cin >> M >> N >> V >> X >> Y;
	map = vector<vector<Space>>(M + 1, vector<Space>(N + 1));
	visited = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false));
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			int input; cin >> input;
			map[i][j] = Space(i, j, input);
		}
	}

	for(int i = 0; i < V; i++)
	{
		int x, y, t; cin >> x >> y >> t;
		map[x][y].time = t;
		map[x][y].available = false;
		volcanos.push_back(map[x][y]);
	}

	map[X][Y].isHuman = true;
	pair<int, int> result = BFS();

	cout << result.first << " " << result.second;
}

pair<int, int> BFS()
{
	int maxHeight = map[X][Y].height, times = 0;
	queue<pair<pair<int, int>, int>> q;
	
	for(int i = 0; i < volcanos.size(); i++)
		q.push({ {volcanos[i].x, volcanos[i].y}, 0 });
	q.push({ {X, Y}, 0 });

	while(!q.empty())
	{
		int nowX = q.front().first.first, nowY = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if(map[nowX][nowY].time > time)
		{
			q.push({ {nowX, nowY}, time + 1 });
			continue;
		}

		visited[nowX][nowY] = true;

		for(int i = 0; i < 4; i++)
		{
			int nextX = nowX + dx[i], nextY = nowY + dy[i];

			if(!(1 <= nextX && nextX <= M && 1 <= nextY && nextY <= N)) continue;
			if(visited[nextX][nextY]) continue;

			visited[nextX][nextY] = true;

			if(map[nowX][nowY].isHuman)
			{
				if(map[nextX][nextY].available)
				{
					map[nextX][nextY].isHuman = true;
					q.push({ {nextX, nextY}, time + 1 });

					if(maxHeight < map[nextX][nextY].height)
					{
						maxHeight = map[nextX][nextY].height;
						times = time + 1;
					}
				}
			}
			else
			{
				map[nextX][nextY].isHuman = false;
				map[nextX][nextY].available = false;
				map[nextX][nextY].time = map[nextX][nextY].time < time + 1 ? map[nextX][nextY].time : time + 1;
				q.push({ {nextX, nextY}, time + 1 });
			}
		}
	}

	return { maxHeight, times };
}