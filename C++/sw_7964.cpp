/*
SW 7964 - 부먹왕국의 차원 관문

TEST CASE

3
6 2
1 0 0 0 0 1
10 2
0 0 1 0 1 0 0 0 0 1
10 1
0 0 0 0 0 0 0 0 0 0

#1 2
#2 3
#3 10
*/

/*
EXPLANATION

도시 정보를 배열에 저장.
"왼쪽"부터 배열을 돌면서
 - 0을 만나면 왼쪽으로 m-1칸을 조사하여
관문이 없다면 그 칸을 관문으로 만들고,
있다면 넘어간다.
 - 1을 만나면 오른쪽으로 m칸을 조사하여
관문이 없다면 가장자리를 관문으로 만들고, m칸 만큼 건너뛴다.
*/
#include <iostream>
#include <vector>
using namespace std;

bool isAlone(vector<int>* city, int i, int m)
{
	for(int j = -(m - 1); j < 0; ++j)
	{
		try
		{
			if(city->at(i + j) == 1)
				return false;
		}
		catch(out_of_range e) { return false; }
	}
	return true;
}

bool isConnectecd(vector<int>* city, int i, int m)
{
	for(int j = 1; j <= m; ++j)
	{
		try
		{
			if(city->at(i + j) == 1)
				return true;
		}
		catch(out_of_range e) { return true; }
	}
	return false;
}

int main()
{
	int T; cin >> T;

	for(int t = 1; t <= T; t++)
	{
		int n, m; cin >> n >> m;
		vector<int> city(n, 0);
		int count = 0;

		for(int i = 0; i < n; ++i)
		{
			int input; cin >> input;
			city[i] = input;
		}

		for(int i = 0; i < n; ++i)
		{
			if(city[i] == 0 && isAlone(&city, i, m))
			{
				city[i] = 1;
				count++;
			}
			if(city[i] == 1 && !isConnectecd(&city, i, m))
			{
				city[i + m] = 1;
				count++;
				i += m - 1;
			}
		}

		cout << "#" << t << " " << count << "\n";
	}
}