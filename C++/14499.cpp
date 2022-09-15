/*
14499 - 주사위 굴리기

-TEST CASE-

4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

0
0
3
0
0
8
6
3
*/

/*
-EXPLANATION-

- 윗면 : dice[0], 바닥면 : dice[5]
- move()에서 이동에 따라 인덱스만 잘 변경해주면 됨
- 밖으로 나가는 경우는 false반환하게 해서 출력하지 않도록
*/

// 동1 서2 북3 남4
// 윗면 [0] 바닥면 [5]
#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
vector<vector<int>> map;
vector<int> dice(6, 0);
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool move(int dir);
void stamp();

int main()
{
	cin >> N >> M >> x >> y >> K;

	map = vector<vector<int>>(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			int input; cin >> input;
			map[i][j] = input;
		}
	}

	for(int i = 0; i < K; i++)
	{
		int direction; cin >> direction;

		if(move(direction))
		{
			stamp();
			cout << dice[0] << "\n";
		}
	}
}

bool move(int dir)
{
	if(!(0 <= x + dx[dir - 1] && x + dx[dir - 1] < N &&
		0 <= y + dy[dir - 1] && y + dy[dir - 1] < M))
		return false;

	vector<int> newDice;

	switch(dir)
	{
	case 1: // EAST
		newDice = { dice[3], dice[1], dice[0], dice[5], dice[4], dice[2] };
		break;
	case 2: // WEST
		newDice = { dice[2], dice[1], dice[5], dice[0], dice[4], dice[3] };
		break;
	case 3: // NORTH
		newDice = { dice[4], dice[0], dice[2], dice[3], dice[5], dice[1] };
		break;
	case 4: // SOUTH
		newDice = { dice[1], dice[5], dice[2], dice[3], dice[0], dice[4] };
		break;
	}

	x += dx[dir - 1];
	y += dy[dir - 1];
	dice = newDice;

	return true;
}

void stamp()
{
	if(map[x][y] == 0)
	{
		map[x][y] = dice[5];
	}
	else
	{
		dice[5] = map[x][y];
		map[x][y] = 0;
	}
}