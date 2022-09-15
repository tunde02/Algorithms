/*
16565 - N포커
*/

/*
-EXPLANATION-

1. 포카드를 만족할 카드 4개를 고르고, 나머지 카드를 고릅니다
2. 중복을 고려해야합니다
ex) N = 8일 때,
"3 네 개를 골라두고 나머지 네 개를 고르는 중 2 네 개를 고르는 경우"
"2 네 개를 골라두고 나머지 네 개를 고르는 중 3 네 개를 고르는 경우"
이런 경우가 중복됩니다
3. 중복을 빼주는데, N>=12 일 경우 그냥 빼기만 하면 중복되지 않은
경우의 수까지 제외됩니다. 따라서 그런건 다시 더해줍니다

=> C(13, 1) x C(48, N-4) - Σ { (-1)^i x C(13, i) x C(52-4i, N-4i) }

- 근데 N>=40 이라면, 어떻게 카드를 골라도 포카드가 무조건 나오기 때문에, 이때의 경우의 수는 C(52, N)이 됩니다
*/

#include <iostream>
using namespace std;

long long nCr(int n, int r)
{
	if(r > n) return 0;
	if(r * 2 > n) r = n - r;
	if(r == 0) return 1;

	long long result = n;
	for(int i = 2; i <= r; ++i) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

int main()
{
	int N; cin >> N;

	if(N < 4)
		cout << 0;
	else if(N <= 39)
	{
		long long entire = 13 * nCr(48, N - 4);
		long long overlap = 0;

		for(int i = 2; i <= N / 4; i++)
		{
			if(i%2 == 0)
				overlap += nCr(13, i) * nCr(52 - 4 * i, N - 4 * i);
			else
				overlap -= nCr(13, i) * nCr(52 - 4 * i, N - 4 * i);
		}

		cout << (entire - overlap) % 10007;
	}
	else
		cout << nCr(52, N) % 10007;
}