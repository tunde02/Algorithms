/*
15686 - 드래곤 커브

TEST CASE

3
3 3 0 1
4 2 1 3
4 2 2 1

4

10
5 5 0 0
5 6 0 0
5 7 0 0
5 8 0 0
5 9 0 0
6 5 0 0
6 6 0 0
6 7 0 0
6 8 0 0
6 9 0 0

8
*/

/*
EXPLANATION

1. 좌표(pair)들을 배열에 저장해두고, 그것들을 드래곤 커브하여 생긴 좌표들을 이용해
좌표평면상의 flag를 갱신해준다.
2. 좌표평면의 (0, 0)부터 돌면서 flag가 true이면 그 점을 왼쪽 위 꼭짓점으로 하는
정사각형 좌표들을 확인하여 전부 true이면 count++
3. x=100, y=100까지만 돌고 구한 count 출력

90도 회전 : (x, y) -> (-y, x)
끝에 이어붙이기 : 커브의 끝 좌표를 (x, y)라고 하면 (x + y, y - x)만큼 이동
*/

#include <iostream>
#include <vector>
using namespace std;

// 인자값으로 받은 locations를 드래곤 커브하여 새로운 좌표들의 flag를 바꿔주고, locations에 추가해주는 함수
void dragonCurve(vector<pair<int, int>>* locations, vector<vector<bool>>* map);
// 좌표평면을 돌면서 조건에 맞는 정사각형의 개수를 세는 함수
int countSquare(vector<vector<bool>>* map);

int main()
{
	int N; cin >> N;
	int count = 0;
	vector<vector<bool>> map(101, vector<bool>(101, false));

	for(int i=0; i<N; i++)
	{
		vector<pair<int, int>> curve;
		int x, y, direction, generation;
		cin >> x >> y >> direction >> generation;
		
		curve.push_back(make_pair(x, y));
		switch(direction)
		{
		case 0:
			curve.push_back(make_pair(x + 1, y));
			break;
		case 1:
			curve.push_back(make_pair(x, y - 1));
			break;
		case 2:
			curve.push_back(make_pair(x - 1, y));
			break;
		case 3:
			curve.push_back(make_pair(x, y + 1));
			break;
		}

		map[x][y] = true;
		map[curve[1].first][curve[1].second] = true;

		for(int j = 0; j < generation; j++)
		{
			dragonCurve(&curve, &map);
		}
	}

	count = countSquare(&map);

	cout << count;
}

void dragonCurve(vector<pair<int, int>>* locations, vector<vector<bool>>* map)
{
	vector<pair<int, int>> newCurves;
	pair<int, int> offset = make_pair(locations->back().first + locations->back().second, locations->back().second - locations->back().first);

	for(int i = 0; i < locations->size() - 1; i++)
	{
		pair<int, int> newPos = make_pair(-locations->at(i).second, locations->at(i).first);
		newPos.first += offset.first;
		newPos.second += offset.second;

		map->at(newPos.first).at(newPos.second) = true;

		newCurves.push_back(newPos);
	}

	while(newCurves.size() > 0)
	{
		locations->push_back(newCurves.back());
		newCurves.pop_back();
	}
}

int countSquare(vector<vector<bool>>* map)
{
	int count = 0;

	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			if(map->at(i).at(j))
			{
				count += map->at(i + 1).at(j) && map->at(i).at(j + 1) && map->at(i + 1).at(j + 1) ? 1 : 0;
			}
		}
	}

	return count;
}