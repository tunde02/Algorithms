/*
2211 - 네트워크 복구

-TEST CASE-
4 5
1 2 1
1 4 4
1 3 2
4 2 2
4 3 3

3
1 2
3 1
4 2
*/

/*
      1   2   3   4 
      0  INF INF INF
1:    0  0+1 0+2 0+4
2:    0  0+1 0+2 0+1+2
3:    0  0+1 0+2 0+1+2
4:    0  0+1 0+2 0+1+2
result : 12, 13, 24
*/

/*
-EXPLANATION-

- 다익스트라 알고리즘을 이용했습니다.
- 간선을 이용해 정점으로 가는 최소 거리를 갱신하며, Paths에 그 Edge들을 넣습니다.
- 사용된 간선들을 중복없이 출력해야하기 때문에, isPrinted 변수를 선언하고 Edge의 포인터를 Paths에 저장하였습니다.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public :
	int a, b, weight;
	bool isPrinted = false;
	Edge(int a, int b, int w) : a(a), b(b), weight(w) {}
};

int N, M;
constexpr int INF = 1000000;
vector<vector<Edge>> adj;
vector<Edge> selected;
vector<bool> visited;
vector<pair<int, vector<Edge*>>> paths; // {totalWeight, edges}
priority_queue<int> pq;

int main()
{
	cin >> N >> M;
	adj = vector<vector<Edge>>(N + 1, vector<Edge>());
	visited = vector<bool>(N + 1, false);
	paths = vector<pair<int, vector<Edge*>>>(N + 1, { INF, vector<Edge*>() });

	for(int i = 0; i < M; i++)
	{
		int a, b, weight; cin >> a >> b >> weight;
		adj[a].push_back(Edge(a, b, weight));
		adj[b].push_back(Edge(b, a, weight));
	}

	pq.push(1);
	paths[1] = { 0, vector<Edge*>() };

	while(!pq.empty())
	{
		int now = pq.top();
		int nowCost = paths[now].first;

		pq.pop();

		for(int i = 0, size = adj[now].size(); i < size; i++)
		{
			Edge next = adj[now][i];

			if(paths[next.b].first > paths[now].first + next.weight)
			{
				paths[next.b].first = paths[now].first + next.weight;
				paths[next.b].second = paths[now].second;
				paths[next.b].second.push_back(&adj[now][i]);

				pq.push(next.b);
			}
		}
	}

	cout << N - 1 << "\n";
	for(int i = 1; i < N + 1; i++)
	{
		for(Edge* e : paths[i].second)
		{
			if(!e->isPrinted)
			{
				cout << e->a << " " << e->b << "\n";
				e->isPrinted = true;
			}
		}
	}
}
