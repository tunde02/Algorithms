/*
-FAIL-

TEST CASE

3
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
3 2
2 1
3 2

YES
NO
YES
*/

#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef vector<vector<tuple<int, int>>> graph;

/* COLOR : 0, 1, 2 */

int main()
{
	int t, points, lineNum;

	cout << "start" << endl;

	//ifstream in("1707.in");

	//if(in.is_open())
	//{
		cout << "hello?" << endl;

		cin >> t;

		for(int i = 0; i < t; i++)
		{
			cin >> points >> lineNum;
			vector<int> pointColors(points + 1, 0);
			graph g(points + 1, vector<tuple<int, int>>());
			bool isBinary = true;

			for(int j = 0; j < lineNum; j++)
			{
				int a, b;
				cin >> a >> b;
				g[a].push_back(tuple<int, int>(a, b));
				g[b].push_back(tuple<int, int>(b, a));
			}

			for(int j = 1; j < points; j++)
			{
				for(int k = 0; k < g[j].size(); k++)
				{
					int point1 = get<0>(g[j][k]), point2 = get<1>(g[j][k]);

					if(pointColors[point1] == 0)
						pointColors[point1] = 1;

					if(pointColors[point1] == pointColors[point2])
					{
						isBinary = false;
						break;
					}

					pointColors[point2] = pointColors[point1] == 1 ? 2 : 1;
				}
			}

			cout << (isBinary ? "YES" : "NO") << endl;
		}
	//}
	//else
	//{
	//	cout << "no file" << endl;
	//}
}