/*
3197 - 백조의 호수
-FAILED-

TEST CASE

8 17
...XXXXXX..XX.XXX
....XXXXXXXXX.XXX
...XXXXXXXXXXXX..
..XXXXX.LXXXXXX..
.XXXXXX..XXXXXX..
XXXXXXX...XXXX...
..XXXXX...XXX....
....XXXXX.XXXL...

2
*/

/*
EXPLANATION

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, days = 0;
int name = 2;
int x_1, y_1, x_2, y_2;
vector<vector<char>> map;
vector<vector<bool>> visited;
vector<pair<int, int>> water;
queue<pair<int, int>> q;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void melt();
bool search();

void print()
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin >> r >> c;
	map = vector<vector<char>>(r, vector<char>(c, ' '));
	visited = vector<vector<bool>>(r, vector<bool>(c, false));

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			char input; cin >> input;
			switch(input)
			{
			case 'L':
				q.push(make_pair(i, j));
				input = '.';
			case '.':
				water.push_back(make_pair(i, j));
			default:
				map[i][j] = input;
				break;
			}
		}
	}

	print();

	x_1 = q.front().first;
	y_1 = q.front().second;
	x_2 = q.back().first;
	y_2 = q.back().second;
	
	//cout << x_1 << ", " << y_1 << endl;
	//cout << x_2 << ", " << y_2 << endl;

	q.pop();
	q.pop();

	while(!search())
	{
		melt();
		days++;
	}

	cout << days;
}

void melt()
{
	vector<pair<int, int>> temp;

	for(int i = 0, size = water.size(); i < size; i++)
	{
		int curX = water[i].first, curY = water[i].second;

		for(int j = 0; j < 4; j++)
		{
			int x = curX + dx[j], y = curY + dy[j];

			if(x < 0 || x >= r || y < 0 || y >= c)
				continue;

			if(map[x][y] == 'X')
			{
				map[x][y] = '.';
				temp.push_back(make_pair(x, y));
			}
		}
	}

	water.clear();

	for(int i = 0, size = temp.size(); i < size; i++)
		water.push_back(temp[i]);
}

bool search()
{
	q.push(make_pair(x_1, y_1));

	while(!q.empty())
	{
		for(int i = 0; i < 4; i++)
		{
			int nx = q.front().first + dx[i], ny = q.front().second + dy[i];

			if(nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;

			if(nx == x_2 && ny == y_2)
				return true;

			if(!visited[nx][ny] && map[nx][ny] == '.')
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}

		q.pop();
	}

	return false;
}