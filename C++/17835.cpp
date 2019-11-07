/*
17835 -	면접보는 승범이네

-TEST CASE-
6 10 2
2 6 2
1 4 1
6 1 5
2 5 1
5 1 4
4 5 6
6 2 3
3 5 1
3 1 1
5 2 2
1 2

4
8

2 2 1
1 2 1
1 2 3
2

*/

/*
-EXPLANATION-

- 간선들의 from과 to를 바꿔서 인접리스트를 형성합니다
- 면접장들을 묶어서 0번 정점이라 가정하고, 이에따라 간선들을 다시 설정해줍니다 - merge()
- 0번 정점을 시작으로 다익스트라 알고리즘을 실행한 뒤, 제일 거리가 먼 도시를 출력합니다
- 53%에서 시간초과가 납니다
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;

int N, M, K;
constexpr long long INF = 12345678912;
vector<vector<pair<int, int>>> adj;
vector<long long> distances;
vector<bool> interviewPlaces;
int smallestInterviewP = 100100;

void merge();
void dijkstra();

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	adj = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	distances = vector<long long>(N + 1, INF);
	interviewPlaces = vector<bool>(N + 1, false);
	for(int i = 0; i < M; i++)
	{
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		adj[to].push_back({ from, weight });
	}

	for(int i = 0; i < K; i++)
	{
		int input;
		scanf("%d", &input);
		interviewPlaces[input] = true;
		distances[input] = 0;
		smallestInterviewP = smallestInterviewP < input ? smallestInterviewP : input;
	}

	merge();

	dijkstra();

	int farthestCity = 1;

	for(int i = 2; i <= N; i++)
	{
		if(distances[farthestCity] < distances[i])
			farthestCity = i;
	}

	printf("%d\n%lld", farthestCity, distances[farthestCity]);
}

void merge()
{
	for(int i = 1; i <= N; i++)
	{
		if(interviewPlaces[i])
		{
			// 면접장들의 인접 간선들의 from을 0으로 바꿔주고, clear()
			for(int j = 0, size = adj[i].size(); j < size; j++)
			{
				if(!interviewPlaces[adj[i][j].first])
					adj[0].push_back({ adj[i][j].first, adj[i][j].second });
			}

			adj[i].clear();
		}
		else
		{
			// 도시들의 to가 어떤 면접장일 경우, 그걸 0으로 바꿔줌
			for(int j = 0, size = adj[i].size(); j < size; j++)
			{
				pair<int, int> temp = adj[i][j];
				if(interviewPlaces[temp.first])
				{
					adj[i][j] = { 0, temp.second };
				}
			}
		}
	}
}

void dijkstra()
{
	int farthestCity = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {weight, num}

	pq.push({ 0, 0 });
	distances[0] = 0;
	while(!pq.empty())
	{
		int now = pq.top().second, nowDistance = pq.top().first;
		pq.pop();

		if(nowDistance > distances[now]) continue;

		for(pair<int, int> next : adj[now])
		{
			int nextNum = next.first, nextDistance = next.second;

			if(distances[now] + nextDistance < distances[nextNum])
			{
				distances[nextNum] = distances[now] + nextDistance;
				pq.push({ nextDistance, nextNum });
			}
		}
	}
}