/*
16946 - 벽 부수고 이동하기 4

-TEST CASE-
3 3
101
010
101

303
050
303

4 5
11001
00111
01010
10101

46003
00732
06040
50403
*/

/*
-EXPLANATION-

- 각 벽에 대해 BFS를 하는 것이 가장 쉽지만 시간초과
- 따라서 벽이 아닌 공간들에 대해 미리 BFS를 하여 그 방이 총 몇 개의 칸으로 이루어져 있는지 구한 후,
결과를 돌면서 벽을 만나면 상하좌우의 방들의 수들을 다 더하여 출력
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int id = 0;
int dx[4] = { 0, -1, 0 ,1 };
int dy[4] = { -1, 0, 1 ,0 };
vector<vector<int>> map;
vector<vector<pair<int, int>*>> result;

void BFS();
bool notIn(vector<int> temp, int i);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	result = vector<vector<pair<int, int>*>>(N, vector<pair<int, int>*>(M, NULL));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			char input; cin >> input;
			map[i][j] = input - '0';
		}
	}

	BFS();

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(map[i][j] == 0)
				cout << "0";
			else
			{
				int count = 1;
				vector<int> temp;

				for(int k = 0; k < 4; k++)
				{
					if(!(0 <= i + dx[k] && i + dx[k] < N && 0 <= j + dy[k] && j + dy[k] < M))
						continue;
					if(map[i + dx[k]][j + dy[k]] == 1)
						continue;
					if(!notIn(temp, result[i + dx[k]][j + dy[k]]->first))
						continue;

					temp.push_back(result[i + dx[k]][j + dy[k]]->first);
					count += result[i + dx[k]][j + dy[k]]->second;
				}

				cout << count % 10;
			}
		}
		cout << "\n";
	}
}

void BFS()
{
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(map[i][j] == 1) continue;
			if(visited[i][j]) continue;

			pair<int, int>* temp = new pair<int, int>;
			temp->first = id++;
			temp->second = 1;

			q.push({ i, j });
			visited[i][j] = true;
			result[i][j] = temp;

			while(!q.empty())
			{
				pair<int, int> now = q.front();

				for(int i = 0; i < 4; i++)
				{
					pair<int, int> next = { now.first + dx[i], now.second + dy[i] };

					if(!(0 <= next.first && next.first < N && 0 <= next.second && next.second < M))
						continue;
					if(visited[next.first][next.second])
						continue;

					visited[next.first][next.second] = true;

					if(map[next.first][next.second] == 0)
					{
						result[next.first][next.second] = temp;
						temp->second++;
						q.push({ next.first, next.second });
					}
				}

				q.pop();
			}
		}
	}
}

bool notIn(vector<int> temp, int i)
{
	for(int a = 0; a < temp.size(); a++)
	{
		if(temp[a] == i)
			return false;
	}
	return true;
}