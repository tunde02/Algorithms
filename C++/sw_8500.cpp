/*
SW 8500 - 극장 좌석

TEST CASE

2
3
2 3 2
5
5 2 3 1 4

#1 13
#2 25
*/

/*
EXPLANATION

왼쪽부터 가장 작은 수부터 차례대로 배치하면 가장 최소한의 좌석을 사용할 수 있다.
근데 사용한 좌석 개수를 구하는 것이므로 그냥 입력받는 값들 다 더해주고
손님 수 더해주고 맨 오른쪽에 배치해야하는 가장 큰 좌석수 한 번더 더해주면 된다.

답 == 사람 수 + 입력받는 모든 좌석수 + 가장 큰 좌석 수
*/

#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;

	for(int t = 1; t <= T; t++)
	{
		int n; cin >> n;
		int seats = 0, max = 0;

		for(int i = 0; i < n; i++)
		{
			int input; cin >> input;
			seats += input;
			max = input > max ? input : max;
		}

		seats = n + seats + max;

		cout << "#" << t << " " << seats << "\n";
	}
}