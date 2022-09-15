/*
6359 - 만취한 상범

TEST CASE

2
5
100

2
10
*/

/*
EXPLANATION

답 = n에 루트를 취했을 때 정수부분
아마 방번호가 홀수번 나와야 문이 열려 있는 상태인데, 그럴려면 약수의 개수가 홀수개인 숫자들이 필요하다
약수의 개수가 홀수개인 숫자들 = 제곱수들
*/

#include <iostream>
using namespace std;

int main()
{
	int T; cin >> T;

	while(T-- > 0)
	{
		int n; cin >> n;
		cout << (int)sqrt(n) << "\n";
	}
}