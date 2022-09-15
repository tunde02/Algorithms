/*
1753 - 최단경로

-TEST CASE-
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

0
2
3
7
INF
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
constexpr int INF = INT32_MAX;
vector<vector<pair<int, int>>> adj;
vector<int> distances;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E >> K;
	adj = vector<vector<pair<int, int>>>(V + 1, vector<pair<int, int>>());
	distances = vector<int>(V + 1, INF);
	pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();

	for(int i = 0; i < E; i++)
	{
		int from, to, weight; cin >> from >> to >> weight;
		adj[from].push_back({ to, weight });
	}

	pq.push({ 0, K });
	distances[K] = 0;

	while(!pq.empty())
	{
		int now = pq.top().second, nowWeight = pq.top().first;
		pq.pop();

		if(nowWeight > distances[now])
			continue;

		for(pair<int, int> e : adj[now])
		{
			int next = e.first, nextWeight = e.second;

			if(distances[now] + nextWeight < distances[next])
			{
				distances[next] = distances[now] + nextWeight;
				pq.push({ distances[next], next });
			}
		}
	}

	for(int i = 1; i <= V; i++)
	{
		if(distances[i] == INF)
			cout << "INF\n";
		else
			cout << distances[i] << "\n";
	}
}