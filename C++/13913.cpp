/*
13913 - 숨바꼭질 4

TEST CASE

5 17

4
5 10 9 18 17
*/

/*
EXPLANATION

BFS로 돌면서 -1방향, +1방향, 순간이동 방향을 전부 큐에 넣고
동생을 찾을 때까지 카운트를 늘려가며 반복

경로를 찾기 위해 노드를 사용하여 동생을 찾으면 그 노드를 기준으로 root까지 올라가며 배열에 저장
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
	int num;
	Node* parent;
	Node(int num)
	{
		this->num = num;
		this->parent = nullptr;
	}
	Node(int num, Node* parent)
	{
		this->num = num;
		this->parent = parent;
	}
};

int n, k;
vector<bool> visited;
vector<int> route;

int BFS(int start);
void findRoute(Node node);

int main()
{
	cin >> n >> k;
	int size = n > k ? n : k;
	visited = vector<bool>(2 * size + 1, false);
	
	cout << BFS(n) << "\n";

	route.push_back(n);
	for(int i = route.size() - 1; i >= 0; i--)
		cout << route[i] << " ";
}

int BFS(int start)
{
	int count = 0;
	
	queue<Node*> q;

	q.push(new Node(start));
	visited[start] = true;

	while(!q.empty())
	{
		for(int i = 0, size = q.size(); i < size; i++)
		{
			Node* current = q.front();
			if(current->num == k)
			{
				findRoute(*current);
				return count;
			}

			try
			{
				if(!visited.at(current->num - 1))
				{
					q.push(new Node(current->num - 1, current));
					visited.at(current->num - 1) = true;
				}
			}
			catch(out_of_range e) {}
			try
			{
				if(!visited.at(current->num + 1))
				{
					q.push(new Node(current->num + 1, current));
					visited.at(current->num + 1) = true;
				}
			}
			catch(out_of_range e) {}
			try
			{
				if(!visited.at(current->num * 2))
				{
					q.push(new Node(current->num * 2, current));
					visited.at(current->num * 2) = true;
				}
			}
			catch(out_of_range e) {}
			
			q.pop();
		}

		count++;
	}

	return count;
}

void findRoute(Node node)
{
	while(node.parent != nullptr)
	{
		route.push_back(node.num);
		node = *(node.parent);
	}
}