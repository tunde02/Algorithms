/*
16567 - 바이너리 왕국

-TEST CASE-
10 9
1 1 0 1 1 0 0 0 1 0
1 0 0 0 1 0 1 0 1 0

5 9
0 0 0 0 0
0
1 4
0
1 4
0
1 2
0
1 3
0

0
1
1
2
1
*/


/*
-EXPLANATION-

- 일단 1 더함
if 앞뒤 다 0 : pass
else if 앞뒤 중 하나만 1 : -1
else if 둘 다 1 : -2
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int flips = 0;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int prev = 0, cur = 0;
	arr.push_back(0);
	for(int i = 0; i < N; i++)
	{
		cin >> cur;
		arr.push_back(cur);

		if(prev != cur)
			flips++;
		prev = cur;
	}

	arr.push_back(0);
	flips = flips % 2 == 0 ? flips / 2 : flips / 2 + 1;

	for(int i = 0; i < M; i++)
	{
		int op; cin >> op;

		if(op == 0)
		{
			cout << flips << "\n";
		}
		else
		{
			int index; cin >> index;
			if(arr[index] == 1)
				continue;

			arr[index] = 1;
			flips++;

			if(arr[index - 1] == 1 && arr[index + 1] == 1)
				flips -= 2;
			else if(arr[index - 1] == 1 || arr[index + 1] == 1)
				flips--;
		}
	}
}