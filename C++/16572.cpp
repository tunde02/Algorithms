/*
16572 - Pixel Triangles

-TEST CASE-

3
1 2 3
3 1 2
5 5 1

9

3
1 2 1
1 2 2
1 2 3

6

3
1 2 3
1 2 2
1 2 1

6
*/


/*
-EXPLANATION-

1. 삼각형 정보의 x, y가 같을 경우 길이가 긴 것만 남기면 된다
2. 픽셀을 셀 때 길이가 긴 것이 나오면 그것으로 유지해야 한다
*/

#include <iostream>
#include <vector>
using namespace std;

int counts = 0;
vector<vector<int>> map(2001, vector<int>(2001, 0));

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int A, B, C; cin >> A >> B >> C;
		if(map[A][B] == 0)
		{
			map[A][B] = C;
			counts++;
		}
		else
		{
			map[A][B] = max(map[A][B], C);
		}
	}

	for(int i = 1; i < 2000; i++)
	{
		for(int j = 1; j < 2000; j++)
		{
			if(map[i][j] <= 1)
				continue;

			if(map[i + 1][j] == 0)
			{
				map[i + 1][j] = map[i][j] - 1;
				counts++;
			}
			else
			{
				map[i + 1][j] = max(map[i][j] - 1, map[i + 1][j]);
			}

			if(map[i][j + 1] == 0)
			{
				map[i][j + 1] = map[i][j] - 1;
				counts++;
			}
			else
			{
				map[i][j + 1] = max(map[i][j] - 1, map[i][j + 1]);
			}
		}
	}

	cout << counts;
}