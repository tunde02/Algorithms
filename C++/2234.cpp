/*
TEST CASE

7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

5
9
16

10 10
11 10 10 14 7 3 10 2 2 6
3 2 2 6 5 1 2 0 0 4
1 0 0 4 5 1 0 0 0 4
1 0 0 4 13 9 8 8 8 4
1 0 0 4 7 11 10 10 14 13
1 0 0 4 5 7 3 2 2 6
1 0 0 4 5 5 1 0 0 4
1 0 0 4 13 5 1 0 0 4
1 0 0 4 7 5 1 0 0 4
9 8 8 12 13 13 9 8 8 12

9
36
41
*/
#include <iostream>
#include <vector>
using namespace std;

constexpr auto WEST = 0b0001;
constexpr auto NORTH = 0b0010;
constexpr auto EAST = 0b0100;
constexpr auto SOUTH = 0b1000;

int getRoomSize(vector<vector<int>>* map, vector<vector<bool>>* visited, int x, int y);

int main()
{
	int m, n;
	int roomNumber = 0, biggestSize = 1, a_biggestSize = 0;
	cin >> m >> n;
	vector<vector<int>> map(n, vector<int>(m, -1));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
            // 사방이 벽인 방은 입력받을 때 미리 방의 개수에 더해둔다
			if(input == 0b1111) roomNumber++;
			map[i][j] = input;
		}
	}

	vector<vector<int>> temp1 = map;
	vector<vector<bool>> _visited(n, vector<bool>(m, false));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!_visited[i][j] && temp1[i][j] != 0b1111)
			{
                // 방의 크기를 측정하면서 방의 개수도 더해주고,
                // 가장 큰 방의 크기를 유지해준다
				int size = getRoomSize(&temp1, &_visited, i, j);
				biggestSize = biggestSize < size ? size : biggestSize;
				roomNumber++;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
            // 모든 칸을 탐색하면서 그 칸의 벽을 하나씩 지우고
            // 그 칸이 포함된 방의 크기를 측정한다
			if((map[i][j] & WEST) != 0)
			{
				vector<vector<int>> temp2 = map;
				vector<vector<bool>> visited(n, vector<bool>(m, false));
				temp2[i][j] = temp2[i][j] & (~WEST);
				int size = getRoomSize(&temp2, &visited, i, j);
				a_biggestSize = a_biggestSize < size ? size : a_biggestSize;
			}
			if((map[i][j] & NORTH) != 0)
			{
				vector<vector<int>> temp2 = map;
				vector<vector<bool>> visited(n, vector<bool>(m, false));
				temp2[i][j] = temp2[i][j] & (~NORTH);
				int size = getRoomSize(&temp2, &visited, i, j);
				a_biggestSize = a_biggestSize < size ? size : a_biggestSize;
			}
			if((map[i][j] & EAST) != 0)
			{
				vector<vector<int>> temp2 = map;
				vector<vector<bool>> visited(n, vector<bool>(m, false));
				temp2[i][j] = temp2[i][j] & (~EAST);
				int size = getRoomSize(&temp2, &visited, i, j);
				a_biggestSize = a_biggestSize < size ? size : a_biggestSize;
			}
			if((map[i][j] & SOUTH) != 0)
			{
				vector<vector<int>> temp2 = map;
				vector<vector<bool>> visited(n, vector<bool>(m, false));
				temp2[i][j] = temp2[i][j] & (~SOUTH);
				int size = getRoomSize(&temp2, &visited, i, j);
				a_biggestSize = a_biggestSize < size ? size : a_biggestSize;
			}
		}
	}

	cout << roomNumber << "\n" << biggestSize << "\n" << a_biggestSize;
}

int getRoomSize(vector<vector<int>>* map, vector<vector<bool>>* visited, int x, int y)
{
	int size = 1;

    // 방문여부를 업데이트해준다
	visited->at(x).at(y) = true;

    // std::Vector의 at()이 범위를 넘어가면 out_of_range를 던져줘서 
    // try catch로 전부 묶어줌
    // 벽이 없는 쪽으로 옮겨가며 사이즈를 점점 더해주고,
    // 최종적으로 x, y 칸이 포함된 방의 크기를 반환한다
	try
	{
		if(!visited->at(x).at(y - 1) && (map->at(x).at(y) & WEST) == 0)
		{
			map->at(x).at(y) |= WEST;
			map->at(x).at(y - 1) |= EAST;
			size += getRoomSize(map, visited, x, y - 1);
		}
	}
	catch(out_of_range e) {}
	try
	{
		if(!visited->at(x - 1).at(y) && (map->at(x).at(y) & NORTH) == 0)
		{
			map->at(x).at(y) |= NORTH;
			map->at(x - 1).at(y) |= SOUTH;
			size += getRoomSize(map, visited, x - 1, y);
		}
	}
	catch(out_of_range e) {}
	try
	{
		if(!visited->at(x).at(y + 1) && (map->at(x).at(y) & EAST) == 0)
		{
			map->at(x).at(y) |= EAST;
			map->at(x).at(y + 1) |= WEST;
			size += getRoomSize(map, visited, x, y + 1);
		}
	}
	catch(out_of_range e) {}
	try
	{
		if(!visited->at(x + 1).at(y) && (map->at(x).at(y) & SOUTH) == 0)
		{
			map->at(x).at(y) |= SOUTH;
			map->at(x + 1).at(y) |= NORTH;
			size += getRoomSize(map, visited, x + 1, y);
		}
	}
	catch(out_of_range e) {}

	return size;
}