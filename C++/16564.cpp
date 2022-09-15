/*
16564 - 히오스 프로게이머

-TEST CASE-
3 10
10
20
15

17
*/

/*
-EXPLANATION-

- 오름차순으로 정렬하고, 앞에서부터 진행합니다
- 다음 플레이어와의 차이를 구하고, 그 차이만큼 최소레벨을 올릴 수 있다면 그렇게 하고 플레이어수를 증가시킵니다
- 올릴 수 없다면 탈출하고 나머지를 균등하게 분배합니다
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, T;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		int input; cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	int players = 1;
	T = arr[0];

	if(N == 1)
	{
		cout << T + K;
	}
	else
	{
		for(int i = 0; i < N - 1; i++)
		{
			int diff = arr[i + 1] - arr[i];

			if(K >= diff * players)
			{
				T += diff;
				K -= diff * players;
				players++;
			}
			else
			{
				break;
			}
		}

		cout << T + (K / players);
	}
}