/*
9517 - 아이 러브 크로아티아

-TEST CASE-

1
5
20 T
50 T
80 T
50 T
30 T

5
*/

#include <iostream>
#include <vector>
using namespace std;

constexpr int TIMELIMIT = 210;
int K, N;
int gage = 0;

int main()
{
	cin >> K >> N;

	for(int i = 0; i < N; i++)
	{
		int temp;
		char answer;
		cin >> temp >> answer;

		gage += temp;

		if(gage > TIMELIMIT)
		{
			cout << K;
			break;
		}

		K = answer == 'T' ? (K == 8 ? 1 : K + 1) : K;
	}
}