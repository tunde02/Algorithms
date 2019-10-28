/*
1022 - 소용돌이 예쁘게 출력하기

-TEST CASE-
-3 -3 2 0

37 36 35 34
38 17 16 15
39 18  5  4
40 19  6  1
41 20  7  8
42 21 22 23

-4980 -4980 -4950 -4977
*/

/*
-EXPLANATION-

- → ↑ ← ← ↓ ↓ / → → → ↑ ↑ ↑ ← ← ← ← ↓ ↓ ↓ ↓ / .....
- → ↑ : i번 반복, ← ↓ : i+1번 반복, i += 2
- 메모리가 제한적이라 출력에 필요한 배열만 선언하고, fill()함수를 이용해 출력 범위 안에 들어가면 채워줌
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int r1, c1, r2, c2;
int finish, num = 1, maxNum = 0;
int totalSize, curX, curY;
vector<vector<int>> map;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int digit(int num)
{
	int count = 1;
	while(num >= 10)
	{
		num /= 10;
		count++;
	}
	return count;
}

void fill(int x, int y, int n)
{
	if(0 <= x && x <= r2 - r1 &&
		0 <= y && y <= c2 - c1)
	{
		map[x][y] = n;
		maxNum = maxNum > n ? maxNum : n;
	}
}

int main()
{
	cin >> r1 >> c1 >> r2 >> c2;

	curX = -r1; curY = -c1;
	// 최소한으로 필요한 정사각형의 한 변의 길이
	totalSize = max(max(abs(r1), abs(r2)), max(abs(c1), abs(c2))) * 2 + 1;
	// 정사각형 칸의 개수
	finish = totalSize * totalSize;

	map = vector<vector<int>>(r2 - r1 + 1, vector<int>(c2 - c1 + 1));
	fill(curX, curY, num++);

	for(int i = 1; ; i += 2)
	{
		for(int j = 0; j < i && num <= finish; j++)
		{
			curX += dx[0]; curY += dy[0];
			fill(curX, curY, num++);
		}

		if(num > finish) break;

		for(int j = 0; j < i; j++)
		{
			curX += dx[1]; curY += dy[1];
			fill(curX, curY, num++);
		}
		for(int j = 0; j < i + 1; j++)
		{
			curX += dx[2]; curY += dy[2];
			fill(curX, curY, num++);
		}
		for(int j = 0; j < i + 1; j++)
		{
			curX += dx[3]; curY += dy[3];
			fill(curX, curY, num++);
		}
	}

	int d = digit(maxNum);
	for(int i = 0; i <= r2 - r1; i++)
	{
		for(int j = 0; j <= c2 - c1; j++)
			cout << setw(d) << map[i][j] << " ";
		cout << endl;
	}
}