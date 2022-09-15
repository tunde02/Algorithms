/*
9205 - 맥주 마시면서 걸어가기

-TEST CASE-

2
2
0 0
1000 0
1000 1000
2000 1000
2
0 0
1000 0
2000 1000
2000 2000

happy
sad
*/

/*
-EXPLANATION-

- 모든 점들을 입력받아 따로 저장해둔다
- 이 점들을 정점으로 취급하고, 각각 비교하면서 거리가 1000이하라면
간선으로 취급하여 인접 리스트에 추가한다
- 시작점 : 0번, 목적지 : n + 1번, 나머지 : 1 ~ n번
- 시작점에서 BFS해서 목적지에 도착하면 happy, 아니라면 sad
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n;
int x, y, destX, destY;
vector<pair<int, int>> positions;
vector<vector<int>> adj;

void initAdj();
bool BFS();

int main()
{
	cin >> t;
	while(t-- > 0)
	{
		cin >> n >> x >> y;
		adj = vector<vector<int>>(n + 2, vector<int>());
		positions = vector<pair<int, int>>();

		// add start position
		positions.push_back(make_pair(x, y));

		for(int i = 0; i < n; i++)
		{
			int a, b; cin >> a >> b;
			positions.push_back(make_pair(a, b));
		}

		// add destination position
		cin >> destX >> destY;
		positions.push_back(make_pair(destX, destY));

		initAdj();

		if(BFS())
			cout << "happy\n";
		else
			cout << "sad\n";
	}
}

void initAdj()
{
	for(int i = 0; i < n + 2; i++)
	{
		for(int j = i + 1; j < n + 2; j++)
		{
			int distance = abs(positions[i].first - positions[j].first)
				+ abs(positions[i].second - positions[j].second);

			if(distance <= 1000)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
}

bool BFS()
{
	queue<int> q;
	vector<bool> visited(n + 2, false);
	visited[0] = true;

	q.push(0);
	while(!q.empty())
	{
		int now = q.front();

		for(int around : adj[now])
		{
			if(visited[around]) continue;
			if(around == n + 1) return true;

			visited[around] = true;
			q.push(around);
		}

		q.pop();
	}

	return false;
}