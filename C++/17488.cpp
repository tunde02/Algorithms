/*
-FAIL-

TEST CASE

3 5
2 1 3 1 2
1 2 3 -1
1 2 -1
-1
4 5 -1
4 -1
1 2 4 -1

1 3 5
1
망했어요
*/

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<bool> confirmed, int m)
{
	for(int j = 1; j < m + 1; j++)
	{
		if(confirmed[j])
			return true;
	}
	
	return false;
}

int main()
{
	int n, m; cin >> n >> m;
	vector<int> classes(m + 1, 0);
	vector<vector<bool>> qs(n, vector<bool>(m + 1, false));;
	vector<vector<bool>> confirmed(n, vector<bool>(m + 1, 0));

	for(int i = 1; i < m + 1; i++)
	{
		int input; cin >> input;
		classes[i] = input;
	}

	for(int k = 0; k < 2; k++)
	{
		for(int i = 0; i < n; i++)
		{
			int input; cin >> input;

			while(input != -1)
			{
				qs[i][input] = true;
				cin >> input;
			}
		}

		for(int i = 1; i < m + 1; i++)
		{
			vector<int> temp;
			int expected = 0;

			for(int j = 0; j < n; j++)
			{
				if(qs[j][i])
				{
					expected++;
					temp.push_back(j);
				}
			}

			if(classes[i] - expected >= 0)
			{
				classes[i] = classes[i] - expected;

				for(int j = 0; j < temp.size(); j++)
				{
					confirmed[temp[j]][i] = true;
				}
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(check(confirmed[i], m))
		{
			for(int j = 1; j < m + 1; j++)
			{
				if(confirmed[i][j])
					cout << j << " ";
			}
		}
		else
		{
			cout << "망했어요";
		}
		
		cout << endl;
	}
}