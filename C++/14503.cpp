/*
14503 -	로봇 청소기

TEST CASE

11 10
7 4 3
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1

57
*/

/*
EXPLANATION

 - 북 동 남 서
0 1 2 3
(x - 1, y) / (x, y + 1) / (x + 1, y) / (x, y - 1)
왼쪽으로 돈다 -> direction = (direction + 3) % 4
뒤로 돈다 -> direction = (direction + 2) % 4

 - 기본적인 동작들을 함수로 만들었고, 로봇의 위치와 방향은 전역변수로 선언하여 사용했습니다.
 - operate()는 문제에 나와 있는 로봇 청소기의 행동 패턴과 최대한 유사하게 만들었습니다.
 - search()에선 세가지 조건(왼쪽방향에 청소할 공간이 있는가, 왼쪽이 아닌 방향에 청소할 공간이 있는가, 뒤에 벽이 있는가)을
 비트패턴으로 구현하여 코드를 최적화하였고, 문제의 조건에서 외곽은 전부 벽이기 때문에 따로 범위 체크는 하지 않았습니다.
*/

#include <iostream>
#include <vector>
using namespace std;

enum class STEP { SWEEP, SEARCH };

int n, m, x, y, direction;
int sweepCnt = 1;
STEP step = STEP::SWEEP;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> map;

void move(int dir);
void turn();
void sweep();
void operate();
int search();

int main()
{
	cin >> n >> m >> x >> y >> direction;

	map = vector<vector<int>>(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int input; cin >> input;
			map[i][j] = input;
		}
	}

	operate();
	
	cout << sweepCnt - 1;
}

void move(int dir)
{
	x += dx[dir];
	y += dy[dir];
}

void turn()
{
	direction = (direction + 3) % 4;
}

void sweep()
{
	map[x][y] = ++sweepCnt;
}

void operate()
{
	bool powerOn = true;

	while(powerOn)
	{
		switch(step)
		{
		case STEP::SWEEP:
			sweep();
		case STEP::SEARCH:
			int state = search();

			if(state >= 0b100)
			{
				turn();
				move(direction);
				step = STEP::SWEEP;
			}
			else if(state >= 0b010)
			{
				turn();
				step = STEP::SEARCH;
			}
			else if(state >= 0b001)
			{
				move((direction + 2) % 4);
				step = STEP::SEARCH;
			}
			else
			{
				powerOn = false;
			}
		}
	}
}

int search()
{
	// left, room, back
	int result = 0b000;
	int nx = x + dx[(direction + 3) % 4], ny = y + dy[(direction + 3) % 4];

	if(map[nx][ny] == 0)
	{
		result += 0b100;
	}

	for(int i = 0; i < 4; i++)
	{
		if(map[x + dx[i]][y + dy[i]] == 0)
		{
			result += 0b010;
			break;
		}
	}

	if(map[x + dx[(direction + 2) % 4]][y + dy[(direction + 2) % 4]] != 1)
		result += 0b001;

	return result;
}