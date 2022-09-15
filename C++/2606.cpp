/*
2606 - 바이러스

TEST CASE

7
6
1 2
2 3
1 5
5 2
5 6
4 7

4
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int DFS(int v);

int main()
{
	int n, m; cin >> n >> m;
	adj = vector<vector<int>>(n + 1, vector<int>());
	visited = vector<bool>(n + 1, false);

	for(int i = 0; i < m; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << DFS(1) - 1;
}

int DFS(int v)
{
	int count = 1;

	visited[v] = true;

	for(int i = 0, size = adj[v].size(); i < size; i++)
	{
		if(!visited[adj[v][i]])
		{
			count += DFS(adj[v][i]);
		}
	}

	return count;
}