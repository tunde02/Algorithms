/*
-EXPLANATION-

- 그람을 주우면 벽이 없는 것과 같으므로 그람을 줍는 경우의 time은 그람까지BFS + 그람위치와 공주위치의 차이
- BFS로 공주를 발견한 time과 그람을 줍고 벽을 부수며 공주를 발견한 time을 비교하여 최솟값을 출력
- BFS를 돌아도 공주를 발견하지 못한다면 T + 1을 반환하여 실패했음을 알립니다
*/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M, T;
int gx, gy;
vector<vector<int>> map;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int BFS(int destX, int destY);

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

			map[i][j] = input;
		}
	}

	int normalBFS = BFS(N, M);
	int gramBFS = BFS(gx, gy);
	int minTime = min(normalBFS, gramBFS + (N - gx) + (M - gy));

	if(normalBFS == T + 1 && gramBFS == T + 1 || minTime > T)
		cout << "Fail";
	else
		cout << minTime;
}

int BFS(int destX, int destY)
{

	queue<tuple<int, int, int>> q;
	vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

	q.push(make_tuple(0, 1, 1));
	visited[1][1] = true;
	while(!q.empty())
	{
		int nowX = get<1>(q.front()), nowY = get<2>(q.front());
		int time = get<0>(q.front());

		for(int i = 0; i < 4; i++)
		{
			int nextX = nowX + dx[i], nextY = nowY + dy[i];

			if(!(1 <= nextX && nextX < N + 1 && 1 <= nextY && nextY < M + 1))
				continue;
			if(visited[nextX][nextY])
				continue;

			visited[nextX][nextY] = true;

			if(nextX == destX && nextY == destY)
			{
				return time + 1;
			}
			else if(map[nextX][nextY] != 1)
			{
				q.push(make_tuple(time + 1, nextX, nextY));
			}
		}

		q.pop();
	}

	return T + 1;
}