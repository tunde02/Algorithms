/*
16568 - 엔비스카의 영혼

-TEST CASE-
5 1 2

2

11 3 2

3
*/

/*
-EXPLANATION-

1x + 2y + (x+y) = 5, 2x + 3y = 5, x = 1, y = 1
"N = n + 나머지"라고 하면
-> (a+1)x + (b+1)y = n, T = min(x + y + 나머지)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, a, b;

int main()
{
	cin >> N >> a >> b;
	int minTime = N;
	a++; b++;
	int x = 0, y = 0;

	while(a * x <= N)
	{
		y = (N - a * x) / b;
		minTime = min(minTime, N - a*x - b*y + (x++) + y);
	}

	cout << minTime;
}