#include <iostream>
#include <vector>
using namespace std;

int R, C;
string a = "|>___/|        /}\n| O < |       / }\n(==0==)------/ }\n| ^  _____    |\n|_|_/     ||__|";
string b = "|>___/|     /}\n| O O |    / }\n( =0= )\"\"\"\"  \\\n| ^  ____    |\n|_|_/    ||__|\n";
vector<vector<int>> afterArr;
vector<vector<int>> beforeArr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	afterArr = vector<vector<int>>(C, vector<int>(R, 0));
	beforeArr = vector<vector<int>>(R, vector<int>(C, 0));

	for(int i = 0; i < C; i++)
	{
		for(int j = 0; j < R; j++)
		{
			int input; cin >> input;
			afterArr[i][j] = input;
		}
	}

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			int input; cin >> input;
			beforeArr[i][j] = input;
		}
	}

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(beforeArr[i][C - 1 - j] != afterArr[j][i])
			{
				cout << b;
				return 0;
			}
		}
	}

	cout << a;
}