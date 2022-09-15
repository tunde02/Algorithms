/*
17135 - 캐슬 디펜스

-TEST CASE-
6 5 6
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0

9

6 5 2
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0

14

4 15 2
0 0 0 0 1 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1 1
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0

6
*/

/*
-EXPLANATION-

- 브루트포스
- 궁수 3명의 위치를 3중 for문으로 지정해주고, 각각의 경우에 대해 simulate하여 maxKill을 출력
-   7       이러한 순서로 배열을 돌도록 getNearEnemy()를 구현
  6 3 8
5 2 1 4 9
*/

#include <iostream>
#include <vector>
using namespace std;

int N, M, D;
int enemies = 0, maxKill = 0;
vector<vector<int>> map;

int simulate(int i, int j, int k);
pair<int, int> getNearEnemy(pair<int, int> archer, vector<vector<int>>* map);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> D;
	map = vector<vector<int>>(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int input; cin >> input;
			if(input == 1)
				enemies++;
			map[i][j] = input;
		}
	}

	for(int i = 0; i < M - 2; i++)
	{
		for(int j = i + 1; j < M - 1; j++)
		{
			for(int k = j + 1; k < M; k++)
			{
				int temp = simulate(i, j, k);
				maxKill = maxKill > temp ? maxKill : temp;
			}
		}
	}

	cout << maxKill;
}

int simulate(int i, int j, int k)
{
	vector<vector<int>> tempMap = map;
	int tempKill = enemies;

	for(int a = N; a > 0; a--)
	{
		pair<int, int> e_i = getNearEnemy({ a, i }, &tempMap);
		pair<int, int> e_j = getNearEnemy({ a, j }, &tempMap);
		pair<int, int> e_k = getNearEnemy({ a, k }, &tempMap);

		if(e_i.first != -1)
			tempMap[e_i.first][e_i.second] = 0;
		if(e_j.first != -1)
			tempMap[e_j.first][e_j.second] = 0;
		if(e_k.first != -1)
			tempMap[e_k.first][e_k.second] = 0;
	}

	for(int a = 0; a < N; a++)
	{
		for(int b = 0; b < M; b++)
		{
			if(tempMap[a][b] == 1)
				tempKill--;
		}
	}

	return tempKill;
}

pair<int, int> getNearEnemy(pair<int, int> archer, vector<vector<int>>* map)
{
	for(int dis = 0; dis < D; dis++)
	{
		for(int x = -dis; x <= dis; x++)
		{
			int y = dis - abs(x);

			if(!(0 <= archer.first - 1 - y && archer.first - 1 - y < N
				&& 0 <= archer.second + x && archer.second + x < M))
				continue;

			if((*map)[archer.first - 1 - y][archer.second + x] == 1)
				return { archer.first - 1 - y, archer.second + x };
		}
	}

	return { -1, -1 };
}