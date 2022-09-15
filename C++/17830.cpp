/*
17830 - 이진수씨의 하루 일과

-TEST CASE-
2
4 0?1?
4 ?00?

7 5
8 1
*/

/*
-EXPLANATION-

- N자리의 두 이진수를 곱했을 때, A가 전부 1이므로 특정한 규칙이 생긴다
1. B에 1이 없다 -> A x B = 1자리
2. B에 1이 1개만 있다 -> A x B = N + 첫 1이 나오는 자리 - 1
3. B에 1이 여러 개 있다 -> A x B = N + 첫 1이 나오는 자리
- 위의 규칙을 코드로 구현하면 완료
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;
string A, B;

int measureSize(string str);

int main()
{
	cin >> T;

	while(T-- > 0)
	{
		cin >> N >> B;
		A.resize(N, '1');
		
		string minB = B, maxB = B;
		
		replace(minB.begin(), minB.end(), '?', '0');
		replace(maxB.begin(), maxB.end(), '?', '1');

		cout << measureSize(maxB) << " " << measureSize(minB) << "\n";
	}
}

int measureSize(string str)
{
	int index = str.find_first_of('1'), check = str.find_last_of('1');
	
	if(index == -1)
		return 1;
	else if(index == check)
		return N + (N - index - 1);
	else
		return N + (N - index);
}