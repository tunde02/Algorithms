/*
TEST CASE

5 3 1
0 -1 0 0 0
-1 -1 0 1 1
0 0 0 1 1

-1

5 3 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0

4

4 3 2
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
-1 -1 -1 -1
1 1 1 -1

0
*/

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef vector<vector<vector<int>>> matrix;
typedef tuple<int, int, int> pos;

int m, n, h;

bool spread(matrix* map, vector<pos>* positions);
void addPosition(vector<pos>* positions, int x, int y, int z);
bool checkFarm(matrix map);
void print(matrix map);

int main()
{
	cin >> m >> n >> h;
	matrix map(h, vector<vector<int>>(n, vector<int>(m, 0)));
	vector<pos> positions;
	int days = 0;

	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				int input;
				cin >> input;
				map[i][j][k] = input;
				if(input == 1)
					addPosition(&positions, i, j, k);
			}
		}
	}

	while(spread(&map, &positions))
	{
		days++;
	}

	days = checkFarm(map) ? days : -1;

	cout << days;
}

bool spread(matrix* map, vector<pos>* positions)
{
	// positions에서 좌표를 꺼내 주변의 토마토를 익히는 함수
	// 한 곳이라도 익히면 true, 아니라면 false 반환
	// 익혔다면 그 좌표를 addPosition()하여 다음에 사용할 수 있도록

	bool isSpread = false;
	vector<pos> tempPositions;

	for(int i = 0; i < positions->size(); i++)
	{
		pos temp = positions->at(i);
		int x = get<2>(temp), y = get<1>(temp), z = get<0>(temp);

		if(x - 1 >= 0 && (*map)[z][y][x - 1] == 0)
		{
			(*map)[z][y][x - 1] = 1;
			tempPositions.push_back(pos(z, y, x - 1));
		}
		if(x + 1 < m && (*map)[z][y][x + 1] == 0)
		{
			(*map)[z][y][x + 1] = 1;
			tempPositions.push_back(pos(z, y, x + 1));
		}
		if(y - 1 >= 0 && (*map)[z][y - 1][x] == 0)
		{
			(*map)[z][y - 1][x] = 1;
			tempPositions.push_back(pos(z, y - 1, x));
		}
		if(y + 1 < n && (*map)[z][y + 1][x] == 0)
		{
			(*map)[z][y + 1][x] = 1;
			tempPositions.push_back(pos(z, y + 1, x));
		}
		if(z - 1 >= 0 && (*map)[z - 1][y][x] == 0)
		{
			(*map)[z - 1][y][x] = 1;
			tempPositions.push_back(pos(z - 1, y, x));
		}
		if(z + 1 < h && (*map)[z + 1][y][x] == 0)
		{
			(*map)[z + 1][y][x] = 1;
			tempPositions.push_back(pos(z + 1, y, x));
		}
	}

	positions->clear();
	for(int i = 0; i < tempPositions.size(); i++)
	{
		positions->push_back(tempPositions[i]);
	}

	isSpread = tempPositions.size() != 0;

	return isSpread;
}

void addPosition(vector<pos>* positions, int x, int y, int z)
{
	// 토마토가 있는 좌표를 인자값으로 받아
	// tuple을 생성하여 positions에 추가하는 함수

	pos newPos(x, y, z);

	positions->push_back(newPos);
}

bool checkFarm(matrix map)
{
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if(map[i][j][k] == 0)
				{
					return false;
				}
			}
		}
	}

	return true;
}

void print(matrix map)
{
	cout << "===== Matrix =====" << endl;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				cout << map[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}
