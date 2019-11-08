/*
17833 - 홍익대학교 지하캠퍼스

-TEST CASE-
9
3 2
3
8 10 7 2
8 20 4 3
5 14 1 3

34

9
3 2
3
8 20 5 6
8 10 2 7
5 14 3 5

38
*/

/*
-EXPLANATION-

- 각 층을 정점으로 본다면, 샘플들을 간선으로 볼 수 있습니다
- 지하 N층까지는 건물을 마음대로 배치할 수 있으므로, 샘플 건물 1개가 나타내는 간선은 여러 개가 있을 수 있습니다
- 샘플 건물들을 generateAdj()를 이용해 간선으로 바꾸어 인접리스트를 형성한 후, 출발지를 기준으로 다익스트라 알고리즘을 사용하면 됩니다
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Building
{
public:
	int height;
	int time;
	int a;
	int b;
	Building(int h, int t, int a, int b) : height(h), time(t), a(a), b(b) {}
};

int N, R, D, M;
vector<Building> buildings;
vector<vector<pair<int, int>>> adj;

void generateAdj();

int main()
{
	cin >> N >> R >> D >> M;
	adj = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for(int i = 0; i < M; i++)
	{
		int h, t, a, b; cin >> h >> t >> a >> b;
		buildings.push_back(Building(h, t, a, b));
	}

	generateAdj();

	priority_queue<pair<int, int>> pq; // {cost, num}
	vector<int> distances(N + 1, INT32_MAX);

	pq.push({ 0, R });
	distances[R] = 0;

	while(!pq.empty())
	{
		pair<int, int> now = pq.top();
		pq.pop();

		if(now.first > distances[now.second]) continue;
		if(now.second == D) break; // ?

		for(pair<int, int> next : adj[now.second])
		{
			if(distances[next.first] > distances[now.second] + next.second)
			{
				distances[next.first] = distances[now.second] + next.second;
				pq.push({ distances[next.first], next.first });
			}
		}
	}

	if(distances[D] == INT32_MAX)
		cout << -1;
	else
		cout << distances[D];
}

void generateAdj()
{
	for(int i = 0, size = buildings.size(); i < size; i++)
	{
		Building building = buildings[i];
		for(int j = 0; j <= (N - building.height); j++)
		{
			adj[building.a + j].push_back({ building.b + j, building.time });
			adj[building.b + j].push_back({ building.a + j, building.time });
		}
	}
}