/*
5014 - 스타트링크

TEST CASE

10 1 10 2 1

6

100 2 1 1 0

use the stairs
*/

/*
EXPLANATION

BFS를 사용하여 올라가는 경우 내려가는 경우 각각 큐에 넣어 goal에 도착할 때까지 반복
만약 갈 수 있는 층에 전부 갔는데도 goal에 도착하지 못했다면 use the stairs
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int total, start, goal, up, down;
vector<bool> visited;

int BFS(int start);

int main()
{
	cin >> total >> start >> goal >> up >> down;

	visited = vector<bool>(total + 1, false);

	int count = BFS(start);

	if(count == -1)
		cout << "use the stairs";
	else
		cout << count;
}

int BFS(int start)
{
	int count = 0, current;
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while(!q.empty())
	{
		for(int i = 0, size = q.size(); i < size; i++)
		{
			current = q.front();

			if(current == goal)
				return count;
			
			for(int next : {current + up, current - down})
			{
				if(next < 0 || next >= total + 1)
					continue;

				if(visited[next])
					continue;

				q.push(next);
				visited[next] = true;
			}

			q.pop();
		}

		count++;
	}

	return -1;
}