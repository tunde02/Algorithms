/*
10 10 3
13 2 5 11 7 8 2 4 9 10
1
2
3
8
9
10
11
16
17
49
*/

#include <iostream>
#include <vector>
using namespace std;

int N, M, V, K;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;
	arr = vector<int>(N + 1, 0);
	for(int i = 1; i < N + 1; i++)
	{
		int input; cin >> input;
		arr[i] = input;
	}

	while(M-- > 0)
	{
		cin >> K;

		if(K < V)
		{
			cout << arr[K + 1] << "\n";
		}
		else
		{
			int circleSize = N - V + 1;
			int innerMove = K - V + 1;
			int destIndex = innerMove % circleSize;

			cout << arr[V + destIndex] << "\n";
		}
	}
}