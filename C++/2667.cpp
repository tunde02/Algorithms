/*
TEST CASE
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

7
0101010
1010101
0101010
1010101
0101010
1010101
0101010
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;

void search(vector<vector<int>>* map, int x, int y, int houseNumber);
int countHouses(vector<vector<int>> map, int houseNumber);

int main()
{
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n, 0));
	
	int houseNumber = 1;
	
    // Input
	for(int i = 0; i < n; i++)
	{
		string line;
		cin >> line;

		for(int j = 0; j < n; j++)
		{
			map[i][j] = line[j] - '1';
		}
	}

    // search houses
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(map[i][j] == 0)
			{
				search(&map, i, j, houseNumber++);
			}
		}
	}

    // save houses number
	vector<int> houses(--houseNumber, 0);
	for(int i = 0; i < houseNumber; i++)
	{
		houses[i] = countHouses(map, i + 1);
	}

	sort(houses.begin(), houses.end());

    // Output
	cout << houseNumber << "\n";

	for(int i = 0; i < houseNumber; i++)
	{
		if(houses[i] != 0)
			cout << houses[i] << "\n";
	}
}

void search(vector<vector<int>>* map, int x, int y, int houseNumber)
{
    // change element to houseNumber
    // and check its near block

	(*map)[x][y] = houseNumber;

	if(x - 1 >= 0 && (*map)[x - 1][y] == 0)
		search(map, x - 1, y, houseNumber);

	if(x + 1 < n && (*map)[x + 1][y] == 0)
		search(map, x + 1, y, houseNumber);

	if(y - 1 >= 0 && (*map)[x][y - 1] == 0)
		search(map, x, y - 1, houseNumber);

	if(y + 1 < n && (*map)[x][y + 1] == 0)
		search(map, x, y + 1, houseNumber);
}

int countHouses(vector<vector<int>> map, int houseNumber)
{
    // count houseNumber by checking map

	int num = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			num = map[i][j] == houseNumber ? num + 1 : num;
		}
	}

	return num;
}