/*
2174 - 로봇 시뮬레이션

-TEST CASE-
5 4
2 2
1 1 E
5 4 W
1 F 7
2 F 7

Robot 1 crashes into the wall

5 4
2 3
1 1 E
5 4 W
1 F 4
1 L 1
1 F 3

Robot 1 crashes into robot 2
*/

/*
-EXPLANATION-

- 맵이 뒤집혀있기 때문에, dx dy를 반대로 설정해주고, 회전도 반대로 설정
- 로봇을 직접 맵에서 움직이면서 결과를 판정하고, 그에 따른 출력
*/

#include <iostream>
#include <vector>
using namespace std;

class Robot {
public:
	int x, y, direction = 0;
	Robot(int x, int y, char direction) : x(x), y(y)
	{
		switch(direction)
		{
		case 'N':
			this->direction = 0;
			break;
		case 'E':
			this->direction = 1;
			break;
		case 'S':
			this->direction = 2;
			break;
		case 'W':
			this->direction = 3;
			break;
		}
	}
};

int A, B, N, M;
vector<vector<int>> map;
vector<Robot> robots;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

// 0 : no problem, -1 : wall, else : another robot
int operate(int robotIndex, char type, int times);
void left(int index);
void right(int index);
int front(int index);

int main()
{
	cin >> A >> B >> N >> M;
	map = vector<vector<int>>(B + 1, vector<int>(A + 1, 0));

	for(int i = 0; i < N; i++)
	{
		int x, y;
		char dir;
		cin >> y >> x >> dir;
		robots.push_back(Robot(x, y, dir));
		map[x][y] = i + 1;
	}

	for(int i = 0; i < M; i++)
	{
		int index, times;
		char type;
		cin >> index >> type >> times;

		int state = operate(index - 1, type, times);
		switch(state)
		{
		case 0:
			break;
		case -1:
			cout << "Robot " << index << " crashes into the wall";
			return 0;
		default:
			cout << "Robot " << index << " crashes into robot " << state;
			return 0;
		}
	}

	cout << "OK";
}

int operate(int robotIndex, char type, int times)
{
	for(int i = 0; i < times; i++)
	{
		switch(type)
		{
		case 'L':
			left(robotIndex);
			break;
		case 'R':
			right(robotIndex);
			break;
		case 'F':
			int state = front(robotIndex);
			switch(state)
			{
			case 0:
				break;
			case -1: // wall
				return -1;
			default: // another robot
				return state;
			}
		}
	}

	// no problem
	return 0;
}

void left(int index)
{
	robots[index].direction = (robots[index].direction + 3) % 4;
}

void right(int index)
{
	robots[index].direction = (robots[index].direction + 1) % 4;
}

int front(int index)
{
	int nextX = robots[index].x + dx[robots[index].direction];
	int nextY = robots[index].y + dy[robots[index].direction];

	// wall
	if(!(1 <= nextX && nextX <= B && 1 <= nextY && nextY <= A))
		return -1;

	// another robot
	if(map[nextX][nextY] != 0)
		return map[nextX][nextY];

	map[robots[index].x][robots[index].y] = 0;
	robots[index].x = nextX;
	robots[index].y = nextY;
	map[robots[index].x][robots[index].y] = index + 1;

	return 0;
}