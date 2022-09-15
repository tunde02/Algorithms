/*
-NOT YET-
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct man
{
	int x, y, cnt;
	man()
	{
		this->x = 0;
		this->y = 0;
		this->cnt = 0;
	}
};

void search()
{
	queue<tuple<int, int>> q;

    //???
}

int main()
{
	int n; cin >> n;
	vector<vector<bool>> map(n, vector<bool>(n, false));
	man m;

	for(int i = 0; i < n; i++)
	{
		int x, y; cin >> x >> y;
		map[x][y] = true;
	}

	search();

	cout << m.cnt;
}

