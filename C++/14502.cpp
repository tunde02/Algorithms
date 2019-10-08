/*
14502 - 연구소

TEST CASE

7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0

27

4 6
0 0 0 0 0 0
1 0 0 0 0 2
1 1 1 0 0 2
0 0 0 0 0 2

9
*/

/*
EXPLANATION

- DFS로 바이러스를 퍼지게 하는 함수 spread, map안의 안전지대를 세는 함수 countSafety를 생성
- 벽 3개를 세울 수 있는 모든 경우를 고려한다.
- spread() 안에서 maxSafety와 바이러스의 개수를 계속 비교해주어 최댓값이 될 가망이 없으면 바로 탈출한다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int maxSafety = -1;
int walls = 0;
vector<vector<int>> map;
vector<pair<int, int>> list;
queue<pair<int, int>> virus;
vector<vector<bool>> visited;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int countSafety(vector<vector<int>>* map, vector<vector<bool>>* visited);
int spread(vector<vector<int>>* map, vector<vector<bool>>* visited);

int main()
{
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(m, 0));
	visited = vector<vector<bool>>(n, vector<bool>(m, false));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int input; cin >> input;
			
			if(input == 0)
				list.push_back(make_pair(i, j));
			else if(input == 2)
			{
				virus.push(make_pair(i, j));
				visited[i][j] = true;
			}
			else
			{
				walls++;
				visited[i][j] = true;
			}

			map[i][j] = input;
		}
	}
	
	for(int i = 0, size = list.size(); i < size - 2; i++)
	{
		for(int j = i + 1; j < size - 1; j++)
		{
			for(int k = j + 1; k < size; k++)
			{
				int x1 = list[i].first, y1 = list[i].second;
				int x2 = list[j].first, y2 = list[j].second;
				int x3 = list[k].first, y3 = list[k].second;

				vector<vector<int>> tempMap = map;
				vector<vector<bool>> tempVisited = visited;

				tempMap[x1][y1] = 1;
				tempMap[x2][y2] = 1;
				tempMap[x3][y3] = 1;

				int tempSafety = countSafety(&tempMap, &tempVisited);

				maxSafety = tempSafety > maxSafety ? tempSafety : maxSafety;
			}
		}
	}

	cout << maxSafety;
}

int countSafety(vector<vector<int>>* map, vector<vector<bool>>* visited)
{
	int count = 0;

	if(spread(map, visited) == -1)
		return 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			count += map->at(i).at(j) == 0 ? 1 : 0;
		}
	}

	return count;
}

int spread(vector<vector<int>>* map, vector<vector<bool>>* visited)
{
	int virusNum = virus.size();
	queue<pair<int, int>> tempVirus = virus;

	while(!tempVirus.empty())
	{
		for(int i = 0; i < 4; i++)
		{
			if(maxSafety >= 0 && maxSafety >= (n * m) - walls - 3 - virusNum)
				return -1;

			int x = tempVirus.front().first + dx[i], y = tempVirus.front().second + dy[i];
			try
			{
				if(!visited->at(x).at(y) && map->at(x).at(y) == 0)
				{
					map->at(x).at(y) = 2;
					visited->at(x).at(y) = true;
					tempVirus.push(make_pair(x, y));
					virusNum++;
				}
			}
			catch(out_of_range e) { continue; }
		}

		tempVirus.pop();
	}

	return 0;
}