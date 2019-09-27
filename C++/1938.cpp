/*
TEST CASE

4
B00E
B00E
B00E
1010

3

5
B0011
B0000
B0000
11000
EEE00

9

7
0001000
0001000
B00100E
B00000E
B00100E
0001000
0001000

8
*/
//#include <tuple>
//#include <iostream>
//#include <vector>
//#include <bitset>
//using namespace std;
//
//constexpr int HORIZONTAL = 0;
//constexpr int VERTICAL	 = 1;
//
//constexpr auto UP	 = 0B00001;
//constexpr auto DOWN  = 0B00010;
//constexpr auto LEFT	 = 0B00100;
//constexpr auto RIGHT = 0B01000;
//constexpr auto TURN  = 0B10000;
//
//void initActs(vector<vector<char>> map, vector<vector<tuple<int, int>>>* acts, int n);
//tuple<int, int, int> toPosInfo(vector<tuple<int, int>> arr);
//bool horizontalTest(vector<vector<char>>* map, int i, int j);
//bool verticalTest(vector<vector<char>>* map, int i, int j);
//bool turnTest(vector<vector<char>>* map, int i, int j);
//void getShortestPath(vector<vector<tuple<int, int>>> acts, tuple<int, int, int> now, tuple<int, int, int>* destination, int* shortestPath, int n);
//void printActList(vector<vector<tuple<int, int>>>* acts, int n);
//
//int main()
//{
//	int n;
//	cin >> n;
//	int shortestPath = 99999;
//	vector<vector<char>> map(n, vector<char>(n, ' '));
//	vector<vector<tuple<int, int>>> acts(n, vector<tuple<int, int>>(n, tuple<int, int>(0, 0)));
//	vector<tuple<int, int>> start;
//	vector<tuple<int, int>> destination;
//
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			char input;
//			cin >> input;
//			if(input == 'B')
//			{
//				start.push_back(tuple<int, int>(i, j));
//				map[i][j] = '0';
//			}
//			else if(input == 'E')
//			{
//				destination.push_back(tuple<int, int>(i, j));
//				map[i][j] = '0';
//			}
//			else
//			{
//				map[i][j] = input;
//			}
//		}
//	}
//
//	initActs(map, &acts, n);
//
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	printActList(&acts, n);
//
//	tuple<int, int, int> s = toPosInfo(start);
//	tuple<int, int, int> d = toPosInfo(destination);
//
//	cout << "start : " << "(" << get<0>(s) << ", " << get<1>(s) << "), " << get<2>(s) << endl;
//	cout << "start : " << "(" << get<0>(d) << ", " << get<1>(d) << "), " << get<2>(d) << endl;
//
//	getShortestPath(acts, s, &d, &shortestPath, 0);
//
//	cout << shortestPath;
//}
//
//void initActs(vector<vector<char>> map, vector<vector<tuple<int, int>>>* acts, int n)
//{
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			int h_availableActs = 0b00000;
//			int v_availableActs = 0b00000;
//			bool isHorizontal = horizontalTest(&map, i, j);
//			bool isVertical = verticalTest(&map, i, j);
//			int turn = turnTest(&map, i, j) ? TURN : 0b0000;
//
//			if(isHorizontal)
//			{
//				int up = horizontalTest(&map, i - 1, j) ? UP : 0b00000;
//				int down = horizontalTest(&map, i + 1, j) ? DOWN : 0b0000;
//				int left = horizontalTest(&map, i, j - 1) ? LEFT : 0b00000;
//				int right = horizontalTest(&map, i, j + 1) ? RIGHT : 0b00000;
//				
//				h_availableActs = up | down | left | right | turn;
//			}
//			if(isVertical)
//			{
//				int up = verticalTest(&map, i - 1, j) ? UP : 0b00000;
//				int down = verticalTest(&map, i + 1, j) ? DOWN : 0b00000;
//				int left = verticalTest(&map, i, j - 1) ? LEFT : 0b00000;
//				int right = verticalTest(&map, i, j + 1) ? RIGHT : 0b00000;
//
//				v_availableActs = up | down | left | right | turn;
//			}
//
//			acts->at(i).at(j) = tuple<int, int>(h_availableActs, v_availableActs);
//		}
//	}
//}
//
//tuple<int, int, int> toPosInfo(vector<tuple<int, int>> arr)
//{
//	int m1 = get<0>(arr[1]), m2 = get<1>(arr[1]);
//	int direction = get<0>(arr[0]) == get<0>(arr[1]) && get<0>(arr[1]) == get<0>(arr[2]) ? HORIZONTAL : VERTICAL;
//
//	return tuple<int, int, int>(m1, m2, direction);
//}
//
//bool horizontalTest(vector<vector<char>>* map, int i, int j)
//{
//	try
//	{
//		return map->at(i).at(j - 1) == '0' && map->at(i).at(j) == '0' && map->at(i).at(j + 1) == '0';
//	}
//	catch(out_of_range e) { return false; }
//}
//
//bool verticalTest(vector<vector<char>>* map, int i, int j)
//{
//	try
//	{
//		return map->at(i - 1).at(j) == '0' && map->at(i).at(j) == '0' && map->at(i + 1).at(j) == '0';
//	}
//	catch(out_of_range e) { return false; }
//}
//
//bool turnTest(vector<vector<char>>* map, int i, int j)
//{
//	try
//	{
//		for(int a = -1; a <= 1; a++)
//		{
//			for(int b = -1; b <= 1; b++)
//			{
//				if(map->at(i + a).at(j + b) != '0')
//					return false;
//			}
//		}
//
//		return true;
//	}
//	catch(out_of_range e) { return false; }
//}
//
//void getShortestPath(vector<vector<tuple<int, int>>> acts, tuple<int, int, int> now, tuple<int, int, int>* destination, int* shortestPath, int n)
//{
//	// acts, actList, now 의 최신정보 문제
//	//printActList(acts, (*acts).size());
//
//	int i = get<0>(now), j = get<1>(now), direction = get<2>(now);
//	tuple<int, int, int> moved;
//	//int actList = direction == HORIZONTAL ? get<0>((*acts)[i][j]) : get<1>((*acts)[i][j]);
//
//	if(now == *destination)
//	{
//		*shortestPath = n < *shortestPath ? n : *shortestPath;
//	}
//
//	if((direction == HORIZONTAL && get<0>(acts[i][j]) == 0b00000) || (direction == VERTICAL && get<1>(acts[i][j]) == 0b00000))
//	{
//		return;
//	}
//	else
//	{
//		if(direction == HORIZONTAL)
//		{
//			if((get<0>(acts[i][j]) & UP) != 0)
//			{
//				get<0>(acts[i][j]) ^= UP;
//				get<0>(acts[i - 1][j]) ^= DOWN;
//				moved = now;
//				get<0>(moved) -= 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<0>(acts[i][j]) & DOWN) != 0)
//			{
//				get<0>(acts[i][j]) ^= DOWN;
//				get<0>(acts[i + 1][j]) ^= UP;
//				moved = now;
//				get<0>(moved) += 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<0>(acts[i][j]) & LEFT) != 0)
//			{
//				get<0>(acts[i][j]) ^= LEFT;
//				get<0>(acts[i][j - 1]) ^= RIGHT;
//				moved = now;
//				get<1>(moved) -= 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<0>(acts[i][j]) & RIGHT) != 0)
//			{
//				get<0>(acts[i][j]) ^= RIGHT;
//				get<0>(acts[i][j + 1]) ^= LEFT;
//				moved = now;
//				get<1>(moved) += 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<0>(acts[i][j]) & TURN) != 0)
//			{
//				get<0>(acts[i][j]) ^= TURN;
//				get<1>(acts[i][j]) ^= TURN;
//				moved = now;
//				get<2>(moved) = VERTICAL;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//		}
//		else
//		{
//			if((get<1>(acts[i][j]) & UP) != 0)
//			{
//				get<1>(acts[i][j]) ^= UP;
//				get<1>(acts[i - 1][j]) ^= DOWN;
//				moved = now;
//				get<0>(moved) -= 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<1>(acts[i][j]) & DOWN) != 0)
//			{
//				get<1>(acts[i][j]) ^= DOWN;
//				get<1>(acts[i + 1][j]) ^= UP;
//				moved = now;
//				get<0>(moved) += 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<1>(acts[i][j]) & LEFT) != 0)
//			{
//				get<1>(acts[i][j]) ^= LEFT;
//				get<1>(acts[i][j - 1]) ^= RIGHT;
//				moved = now;
//				get<1>(moved) -= 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<1>(acts[i][j]) & RIGHT) != 0)
//			{
//				get<1>(acts[i][j]) ^= RIGHT;
//				get<1>(acts[i][j + 1]) ^= LEFT;
//				moved = now;
//				get<1>(moved) += 1;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//			if((get<1>(acts[i][j]) & TURN) != 0)
//			{
//				get<0>(acts[i][j]) ^= TURN;
//				get<1>(acts[i][j]) ^= TURN;
//				moved = now;
//				get<2>(moved) = HORIZONTAL;
//				getShortestPath(acts, moved, destination, shortestPath, n + 1);
//			}
//		}
//	}
//}
//
//void printActList(vector<vector<tuple<int, int>>>* acts, int n)
//{
//	cout << "===========================================================" << endl;
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			cout << "(" << bitset<5>(get<0>((*acts)[i][j])) << ", " << bitset<5>(get<1>((*acts)[i][j])) << ") ";
//		}
//		cout << endl;
//	}
//}
#include <tuple>
#include <iostream>
#include <vector>
using namespace std;

constexpr int HORIZONTAL = 0;
constexpr int VERTICAL = 1;

constexpr auto UP = 0B00001;
constexpr auto DOWN = 0B00010;
constexpr auto LEFT = 0B00100;
constexpr auto RIGHT = 0B01000;
constexpr auto TURN = 0B10000;

void initActs(vector<vector<char>> map, vector<vector<tuple<int, int>>>* acts, int n);
tuple<int, int, int> toPosInfo(vector<tuple<int, int>> arr);
bool horizontalTest(vector<vector<char>>* map, int i, int j);
bool verticalTest(vector<vector<char>>* map, int i, int j);
bool turnTest(vector<vector<char>>* map, int i, int j);
void getShortestPath(vector<vector<tuple<int, int>>> acts, tuple<int, int, int> now, tuple<int, int, int>* destination, int* shortestPath, int n);

int main()
{
	int n;
	cin >> n;
	int shortestPath = 99999;
	vector<vector<char>> map(n, vector<char>(n, ' '));
	vector<vector<tuple<int, int>>> acts(n, vector<tuple<int, int>>(n, tuple<int, int>(0, 0)));
	vector<tuple<int, int>> start;
	vector<tuple<int, int>> destination;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char input;
			cin >> input;
			if(input == 'B')
			{
				start.push_back(tuple<int, int>(i, j));
				map[i][j] = '0';
			}
			else if(input == 'E')
			{
				destination.push_back(tuple<int, int>(i, j));
				map[i][j] = '0';
			}
			else
			{
				map[i][j] = input;
			}
		}
	}

	initActs(map, &acts, n);

	tuple<int, int, int> s = toPosInfo(start);
	tuple<int, int, int> d = toPosInfo(destination);

	getShortestPath(acts, s, &d, &shortestPath, 0);

	cout << shortestPath;
}

void initActs(vector<vector<char>> map, vector<vector<tuple<int, int>>>* acts, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int h_availableActs = 0b00000;
			int v_availableActs = 0b00000;
			bool isHorizontal = horizontalTest(&map, i, j);
			bool isVertical = verticalTest(&map, i, j);
			int turn = turnTest(&map, i, j) ? TURN : 0b0000;

			if(isHorizontal)
			{
				int up = horizontalTest(&map, i - 1, j) ? UP : 0b00000;
				int down = horizontalTest(&map, i + 1, j) ? DOWN : 0b0000;
				int left = horizontalTest(&map, i, j - 1) ? LEFT : 0b00000;
				int right = horizontalTest(&map, i, j + 1) ? RIGHT : 0b00000;

				h_availableActs = up | down | left | right | turn;
			}
			if(isVertical)
			{
				int up = verticalTest(&map, i - 1, j) ? UP : 0b00000;
				int down = verticalTest(&map, i + 1, j) ? DOWN : 0b00000;
				int left = verticalTest(&map, i, j - 1) ? LEFT : 0b00000;
				int right = verticalTest(&map, i, j + 1) ? RIGHT : 0b00000;

				v_availableActs = up | down | left | right | turn;
			}

			acts->at(i).at(j) = tuple<int, int>(h_availableActs, v_availableActs);
		}
	}
}

tuple<int, int, int> toPosInfo(vector<tuple<int, int>> arr)
{
	int m1 = get<0>(arr[1]), m2 = get<1>(arr[1]);
	int direction = get<0>(arr[0]) == get<0>(arr[1]) && get<0>(arr[1]) == get<0>(arr[2]) ? HORIZONTAL : VERTICAL;

	return tuple<int, int, int>(m1, m2, direction);
}

bool horizontalTest(vector<vector<char>>* map, int i, int j)
{
	try
	{
		return map->at(i).at(j - 1) == '0' && map->at(i).at(j) == '0' && map->at(i).at(j + 1) == '0';
	}
	catch(out_of_range e) { return false; }
}

bool verticalTest(vector<vector<char>>* map, int i, int j)
{
	try
	{
		return map->at(i - 1).at(j) == '0' && map->at(i).at(j) == '0' && map->at(i + 1).at(j) == '0';
	}
	catch(out_of_range e) { return false; }
}

bool turnTest(vector<vector<char>>* map, int i, int j)
{
	try
	{
		for(int a = -1; a <= 1; a++)
		{
			for(int b = -1; b <= 1; b++)
			{
				if(map->at(i + a).at(j + b) != '0')
					return false;
			}
		}

		return true;
	}
	catch(out_of_range e) { return false; }
}

void getShortestPath(vector<vector<tuple<int, int>>> acts, tuple<int, int, int> now, tuple<int, int, int>* destination, int* shortestPath, int n)
{
	int i = get<0>(now), j = get<1>(now), direction = get<2>(now);
	tuple<int, int, int> moved;
	vector<vector<tuple<int, int>>> newActs;

	if(now == *destination)
	{
		*shortestPath = n < *shortestPath ? n : *shortestPath;
		cout << *shortestPath << endl;
	}

	if((direction == HORIZONTAL && get<0>(acts[i][j]) == 0b00000) || (direction == VERTICAL && get<1>(acts[i][j]) == 0b00000))
	{
		return;
	}
	else
	{
		if(direction == HORIZONTAL)
		{
			if((get<0>(acts[i][j]) & UP) != 0)
			{
				newActs = acts;
				get<0>(newActs[i][j]) ^= UP;
				get<0>(newActs[i - 1][j]) ^= DOWN;
				moved = now;
				get<0>(moved) -= 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<0>(acts[i][j]) & DOWN) != 0)
			{
				newActs = acts;
				get<0>(newActs[i][j]) ^= DOWN;
				get<0>(newActs[i + 1][j]) ^= UP;
				moved = now;
				get<0>(moved) += 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<0>(acts[i][j]) & LEFT) != 0)
			{
				newActs = acts;
				get<0>(newActs[i][j]) ^= LEFT;
				get<0>(newActs[i][j - 1]) ^= RIGHT;
				moved = now;
				get<1>(moved) -= 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<0>(acts[i][j]) & RIGHT) != 0)
			{
				newActs = acts;
				get<0>(newActs[i][j]) ^= RIGHT;
				get<0>(newActs[i][j + 1]) ^= LEFT;
				moved = now;
				get<1>(moved) += 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<0>(acts[i][j]) & TURN) != 0)
			{
				newActs = acts;
				get<0>(newActs[i][j]) ^= TURN;
				get<1>(newActs[i][j]) ^= TURN;
				moved = now;
				get<2>(moved) = VERTICAL;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
		}
		else
		{
			if((get<1>(acts[i][j]) & UP) != 0)
			{
				newActs = acts;
				get<1>(newActs[i][j]) ^= UP;
				get<1>(newActs[i - 1][j]) ^= DOWN;
				moved = now;
				get<0>(moved) -= 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<1>(acts[i][j]) & DOWN) != 0)
			{
				newActs = acts;
				get<1>(newActs[i][j]) ^= DOWN;
				get<1>(newActs[i + 1][j]) ^= UP;
				moved = now;
				get<0>(moved) += 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<1>(acts[i][j]) & LEFT) != 0)
			{
				newActs = acts;
				get<1>(newActs[i][j]) ^= LEFT;
				get<1>(newActs[i][j - 1]) ^= RIGHT;
				moved = now;
				get<1>(moved) -= 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<1>(acts[i][j]) & RIGHT) != 0)
			{
				newActs = acts;
				get<1>(newActs[i][j]) ^= RIGHT;
				get<1>(newActs[i][j + 1]) ^= LEFT;
				moved = now;
				get<1>(moved) += 1;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
			if((get<1>(acts[i][j]) & TURN) != 0)
			{
				newActs = acts;
				get<0>(newActs[i][j]) ^= TURN;
				get<1>(newActs[i][j]) ^= TURN;
				moved = now;
				get<2>(moved) = HORIZONTAL;
				getShortestPath(newActs, moved, destination, shortestPath, n + 1);
			}
		}
	}
}