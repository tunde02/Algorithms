/*
-EXPLANATION-

- 2x2 배열을 비교하기때문에 길이 4의 1차원 배열 temp를 사용했습니다
- 전체 map을 돌아다니는 밖의 반복문 a, b와 a, b를 왼쪽위로 하는 크기 2x2 배열의 안을 도는 반복문 i, j를 이용하여 temp를 뽑아내고,
두 번째로 큰 값을 newMap의 알맞은 위치에 넣어줍니다.
- newMap을 매 반복마다 map으로 갱신해주고, size또한 갱신해줍니다
- size가 1이 되면 map[0][0]을 출력합니다
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;
vector<int> temp(4, 0);

int twoPooling();

int main()
{
	cin >> N;
	map = vector<vector<int>>(N, vector<int>(N));
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int input; cin >> input;
			map[i][j] = input;
		}
	}

	cout << twoPooling();
}

int twoPooling()
{
	int size = N;
	while(size > 1)
	{
		vector<vector<int>> newMap(size / 2, vector<int>(size / 2));

		for(int a = 0; a < size; a += 2)
		{
			for(int b = 0; b < size; b += 2)
			{
				temp = vector<int>();

				for(int i = a; i < a + 2; i++)
				{
					for(int j = b; j < b + 2; j++)
					{
						temp.push_back(map[i][j]);
					}
				}

				sort(temp.begin(), temp.end());

				newMap[a / 2][b / 2] = temp[2];
			}
		}

		map = vector<vector<int>>(size / 2, vector<int>(size / 2, 0));
		map = newMap;
		size = map[0].size();
	}
	
	return map[0][0];
}