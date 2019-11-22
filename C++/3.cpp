/*
다익스트라 하고 최대거리를 구해야지;
4
1 2 3
2 3 2
2 4 4

7

7
1 2 1
2 3 1
2 4 4
6 4 10000
4 5 3
3 6 50000

60002
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
long long maxDist = 0;
vector<vector<pair<int, int>>> adj;
//int adj[5001][5001];
vector<long long> distances;

int main()
{
	cin >> N;
	distances = vector<long long>(N + 1, 0);
	adj = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for(int i = 0; i < N - 1; i++)
	{
		int a, b, dist; cin >> a >> b >> dist;
		//int a = i + 1, b = i + 2, dist = 1000000000;
		//adj[a][b] = dist;
		//adj[b][a] = dist;
		adj[a].push_back({ b, dist });
		adj[b].push_back({ a, dist });
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, less<pair<long long, int>>> pq;
	pq.push({ 0, 1 }); // {distance, num}
	distances[1] = 0;

	while(!pq.empty())
	{
		int now = pq.top().second, nowDist = pq.top().first;
		pq.pop();

		if(nowDist < distances[now])
			continue;

		//for(int next = 1; next <= N; next++)
		for(pair<int, int> next : adj[now])
		{
			int nextNum = next.first, nextDist = next.second;
			if(distances[nextNum] < distances[now] + nextDist)
			{
				distances[nextNum] = distances[now] + nextDist;
				pq.push({ distances[nextNum], nextNum });
			}
		}
	}

	for(int i = 1; i <= N; i++)
		maxDist = maxDist > distances[i] ? maxDist : distances[i];

	cout << maxDist;
}