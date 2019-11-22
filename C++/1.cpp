/*
13

14
*/

/*
-EXPLANATION-

- 1 / 2 / 2 3 / 3 4 6 8 / 7 6 6 8 10 12 14 16 / 15 14 13 12 11 12 14 ...
- 2^k - 1 ~ 2^k+1 인 구간에서, 숫자가 1씩 내려가다가 어느 시점에서 2씩 다시 올라갑니다
큰 사각형들: 2^k - 1 2^k - 2 2^k - 3 2^k - 4 ... 2^k - 1 - i
작은 사각형들: 2 4 6 8 ... 2(i+1)
2(i+1)이 2^k - 1 - i보다 커지는 시점에서 다시 올라가는 듯
- 즉, N보다 작으면서 가장 큰 2의 제곱수를 offset으로, 거기서부터 내려가다가 증가하여
N보다 크거나 같아질 때까지를 index로 하여 offset + index를 출력했습니다
- N = 13
offset = 2^3 = 8,
index : 0 1 2 3  4  5  6  7  / ...
    8 / 7 6 6 8 10 12 14 16 / ...
index -> 2(index + 1) >= N 를 처음 만족하는 값 = 6
answer = 14
*/

#include <iostream>
using namespace std;

long long N;

int main()
{
	cin >> N;
	
	if(N == 1)
	{
		cout << 0;
		return 0;
	}
	else if(N == 2)
	{
		cout << 1;
		return 0;
	}
	
	long long offset = 1;
	long long index = 0;

	while(offset * 2 < N)
		offset *= 2;
	
	index = (N - 1) / 2;
	
	cout << offset + index;
}