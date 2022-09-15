/*
2606 - DFS와 BFS

TEST CASE

4 5 1
1 2
1 3
1 4
2 4
3 4

1 2 4 3
1 2 3 4

5 5 3
5 4
5 2
1 2
3 4
3 1

3 1 2 5 4
3 1 4 2 5
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, start;
vector<bool> visited;
vector<vector<int>> adj;

void DFS(int v);
void BFS(int v);
int min(vector<int>* list);

int main()
{
	cin >> n >> m >> start;
	visited = vector<bool>(n + 1, false);
	adj = vector<vector<int>>(n + 1, vector<int>());

	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	DFS(start);
	visited = vector<bool>(n + 1, false);
	cout << "\n";
	BFS(start);
}

void DFS(int v)
{
	int next = min(&adj[v]);

	cout << v << " ";
	visited[v] = true;

	while(next != -1)
	{
		DFS(next);
		next = min(&adj[v]);
	}
}

void BFS(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while(!q.empty())
	{
		v = q.front();
		q.pop();

		cout << v << " ";
		
		sort(adj[v].begin(), adj[v].end());

		for(int i = 0, size = adj[v].size(); i < size; i++)
		{
			if(!visited[adj[v][i]])
			{
				q.push(adj[v][i]);
				visited[adj[v][i]] = true;
			}
		}
	}
}

int min(vector<int>* list)
{
	int minNum = 1001;
	for(int i = 0, size = list->size(); i < size; i++)
	{
		if(!visited[list->at(i)] && minNum > list->at(i))
			minNum = list->at(i);
	}
	return minNum == 1001 ? -1 : minNum;
}