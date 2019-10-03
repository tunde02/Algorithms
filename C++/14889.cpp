/*
14889 - 스타트와 링크

TEST CASE

4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

0
*/

/*
EXPLANATION

1. 선수 N명에 대해 N/2명을 골라서 팀을 구성하는 모든 경우를
트리로 저장합니다.
2. 트리를 DFS로 탐색하여 팀을 하나하나 구성하며 점수를 구한 뒤,
점수차의 최솟값을 갱신합니다.
3. 트리를 전부 돌면 완료입니다.
*/

#include <iostream>
#include <vector>
using namespace std;

int N;

class Node
{
public:
	int num;
	bool isVisited;
	vector<Node*> children;
	
	Node()
	{
		num = 0;
		isVisited = false;
		children = vector<Node*>();
	}

	Node(int n)
	{
		num = n;
		isVisited = false;
		children = vector<Node*>();
	}

	void addChild(Node* node)
	{
		children.push_back(node);
	}
};

void initTree(int start, int end, Node* node);
vector<vector<int>> generateTeams(Node* root);
void dfs(Node* node, vector<int>* teams);
int getMinDif(vector<vector<int>>* teams, vector<vector<int>>* stats);
vector<int> getReverseTeam(vector<int> team);

int main()
{
	cin >> N;
	vector<vector<int>> stats(N + 1, vector<int>(N + 1, 0));

	for(int i = 1; i < N + 1; i++)
	{
		for(int j = 1; j < N + 1; j++)
		{
			int input; cin >> input;
			stats[i][j] = input;
		}
	}

	Node root;

	initTree(1, N - (N/2 - 1), &root);

	vector<vector<int>> teams = generateTeams(&root);

	int minDif = getMinDif(&teams, &stats);

	cout << minDif;
}

void initTree(int start, int end, Node* node)
{
	for(int i = start; i <= end; i++)
	{
		if(end > N)
			return;
		Node* newNode = new Node(i);
		node->addChild(newNode);
		initTree(i + 1, end + 1, newNode);
	}
}

vector<vector<int>> generateTeams(Node* root)
{
	vector<vector<int>> teams;

	while(!root->isVisited)
	{
		vector<int> team;
		dfs(root, &team);
		if(team.size() == N / 2)
			teams.push_back(team);
	}

	return teams;
}

void dfs(Node* node, vector<int>* team)
{
	if(node->num != 0)
		team->push_back(node->num);

	int size = node->children.size();
	for(int i = 0; i < size; i++)
	{
		if(!node->children[i]->isVisited)
		{
			dfs(node->children[i], team);
			return;
		}
	}

	node->isVisited = true;
}

int getMinDif(vector<vector<int>>* teams, vector<vector<int>>* stats)
{
	int minDif = 99999999;
	int size = teams->size();

	for(int i = 0; i < size; i++)
	{
		int score1 = 0, score2 = 0;
		vector<int> reverseTeam = getReverseTeam(teams->at(i));

		for(int j = 0; j < (N / 2) - 1; j++)
		{
			for(int k = j + 1; k < N / 2; k++)
			{
				score1 += (*stats)[teams->at(i).at(j)][teams->at(i).at(k)];
				score1 += (*stats)[teams->at(i).at(k)][teams->at(i).at(j)];

				score2 += (*stats)[reverseTeam[j]][reverseTeam[k]];
				score2 += (*stats)[reverseTeam[k]][reverseTeam[j]];
			}
		}

		if(minDif > abs(score1 - score2))
			minDif = abs(score1 - score2);
	}

	return minDif;
}

vector<int> getReverseTeam(vector<int> team)
{
	vector<bool> exists(N + 1, true);
	vector<int> reverseTeam;

	for(int i = 0; i < N / 2; i++)
	{
		exists[team[i]] = false;
	}

	for(int i = 1; i <= N; i++)
	{
		if(exists[i])
			reverseTeam.push_back(i);
	}

	return reverseTeam;
}