/*Time OUt*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, M, T;
int gx, gy;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> list;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int normalBFS(int x, int y);
int gramBFS();

int main()
{
	cin >> N >> M >> T;
	map = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	
	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < M + 1; j++)
		{
			int input; cin >> input;

			if(input == 2)
			{
				gx = i;
				gy = j;
			}
			else if(input == 1)
				list.push_back({ i, j });

			map[i][j] = input;
		}
	}

	cout << min(normalBFS(N, M), gramBFS());
}

int normalBFS(int x, int y)
{
	int time = 1;
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));

	q2.push({ 1, 1 });
	q1 = q2;
	visited[1][1] = true;
	while(!q2.empty())
	{
		q1 = q2;

		while(!q1.empty())
		{
			int nowX = q1.front().first, nowY = q1.front().second;

			for(int i = 0; i < 4; i++)
			{
				int nextX = nowX + dx[i], nextY = nowY + dy[i];

				if(!(1 <= nextX && nextX < N + 1 && 1 <= nextY && nextY < M + 1))
					continue;
				if(visited[nextX][nextY])
					continue;

				visited[nextX][nextY] = true;

				if(nextX == x && nextY == y)
				{
					return time;
				}
				else if(map[nextX][nextY] != 1)
				{
					q2.push({ nextX, nextY });
				}
			}

			q1.pop();
		}
		time++;
	}
	
	return -1;
}

int gramBFS()
{
	int baseTime = normalBFS(gx, gy) + 1;
	int minTime = N * M;
	
	for(pair<int, int> p : list)
	{
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;
		visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
		map[p.first][p.second] = 0;
		int time = baseTime;
		bool isFinished = false;
		
		q2.push({ gx, gy });
		q1 = q2;
		visited[1][1] = true;
		while(!q2.empty() && !isFinished)
		{
			q1 = q2;

			while(!q1.empty() && !isFinished)
			{
				int nowX = q1.front().first, nowY = q1.front().second;

				for(int i = 0; i < 4; i++)
				{
					int nextX = nowX + dx[i], nextY = nowY + dy[i];

					if(!(1 <= nextX && nextX < N + 1 && 1 <= nextY && nextY < M + 1))
						continue;
					if(visited[nextX][nextY])
						continue;

					visited[nextX][nextY] = true;

					if(nextX == N && nextY == M)
					{
						minTime = time < minTime ? time : minTime;
						isFinished = true;
					}
					else if(map[nextX][nextY] != 1)
					{
						q2.push({ nextX, nextY });
					}
				}

				q1.pop();
			}
			time++;
		}

		map[p.first][p.second] = 1;
	}

	return minTime;
}