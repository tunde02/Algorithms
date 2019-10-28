/*
1389 - 케빈 베이컨의 6단계 법칙

-TEST CASE-
5 5
1 3
1 4
4 5
4 3
3 2

3
*/

/*
-EXPLANATION-

BFS로 adj를 돌면서 정점에 step을 갱신함(step이 더 작을 때만)
다 돌면 기준 정점에 대한 케빈 베이컨 수를 구하고, 최솟값을 유지
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int minNum = 1;
vector<int> KBNums;
vector<vector<int>> adj;

int sum(vector<int>* v)
{
	int result = 0;
	for(int i = 0, size = v->size(); i < size; i++)
		result += (*v)[i];
	return result;
}

int main()
{
	cin >> N >> M;
	KBNums = vector<int>(N + 1, 0);
	adj = vector<vector<int>>(N + 1, vector<int>());

	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	for(int i = 1; i < N + 1; i++)
	{
		vector<int> steps(N + 1, 10000);
		vector<bool> visited(N + 1, false);

		steps[i] = 0;
		visited[i] = true;

		q.push(i);
		while(!q.empty())
		{
			int now = q.front();

			for(int next : adj[now])
			{
				if(visited[next]) continue;

				visited[next] = true;
				q.push(next);

				if(steps[next] > steps[now] + 1)
					steps[next] = steps[now] + 1;
			}

			q.pop();
		}

		KBNums[i] = sum(&steps);

		if(KBNums[minNum] > KBNums[i])
			minNum = i;
	}

	cout << minNum;
}