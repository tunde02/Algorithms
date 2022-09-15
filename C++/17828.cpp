/*
-EXPLANATION

- 문자열 money의 뒤에서부터 'Z'보다 가격이 아직 크다면 Z를 넣고, 아니라면 그 수만큼 'A'에서 더해줍니다.
- 자릿수를 N개만큼 채워야하기때문에, 처음에 'A'로 초기화하고, 가격에서 자릿수만큼 숫자를 뺐습니다.
- "!"를 출력하는 경우가 2가지 있다는 것도 주의해야합니다
*/

#include <iostream>
#include <vector>
using namespace std;

int N, X;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> X;

	if(X > 26 * N || N > X)
	{
		cout << "!";
	}
	else
	{
		vector<char> money(N, 'A');
		X -= N;

		for(int i = N - 1; i >= 0; i--)
		{
			if(X >= 25)
			{
				money[i] = 'Z';
				X -= 25;
			}
			else
			{
				money[i] = 'A' + X;
				break;
			}
		}

		for(int i = 0; i < N; i++)
			cout << money[i];
	}
}