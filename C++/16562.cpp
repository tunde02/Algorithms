/*
16562 - 친구비

-TEST CASE-
5 3 20
10 10 20 20 30
1 3
2 4
5 4

20

5 3 10
10 10 20 20 30
1 3
2 4
5 4

Oh no
*/

/*
-EXPLANATION-
1. 모든 정점에 대해 탐색으로 visited 갱신
2. 그럴때마다 최소 비용 유지하면서 탐색이 끝나면 합침
3. 다 끝나고 비교해서 알맞은 출력
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, k;
int totalCost = 0;
vector<int> prices;
vector<vector<int>> adj;
vector<bool> visited;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> k;
	prices = vector<int>(N + 1, 0);
	adj = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<bool>(N + 1, false);
	for(int i = 1; i <= N; i++)
	{
		int input; cin >> input;
		prices[i] = input;
	}

	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++)
	{
		if(visited[i])
			continue;

		queue<int> q;
		int minCost = prices[i];

		q.push(i);
		visited[i] = true;

		while(!q.empty())
		{
			int now = q.front();
			q.pop();

			for(int next : adj[now])
			{
				if(visited[next]) continue;

				visited[next] = true;
				q.push(next);

				minCost = minCost < prices[next] ? minCost : prices[next];
			}
		}

		totalCost += minCost;
		if(totalCost > k)
		{
			cout << "Oh no";
			return 0;
		}
	}

	cout << totalCost;
}