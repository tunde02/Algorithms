/*
2688 - 줄어들지 않아
TEST CASE

3
2
3
4

55
220
715
*/

/*
EXPLANATION
d[i] : i자리 수들 중에서 줄어들지 않는 수의 개수

d[1] = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 10
d[2] = 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
d[3] = 1 + 3 + 6 + 10 + 15 + 21 + 28 + 36 + 45 + 55 = 220
d[4] = 1 + 4 + 10 + 20 + 35 + 56 + 84 + 120 + 165 + 220 = 715

num[i][j] = num[i-1][j] + num[i][j-1], num[i][0] = 1

d[i] = num[i-1][0] + (num[i-1][0] + num[i-1][1]) + (num[i-1][0] + num[i-1][1] + num[i-1][2]) + ...

	 = 10*num[i-1][0] + 9*num[i-1][1] + ... 1*num[i-1][9]

	 = n * num[i-1][10-n], n = 10 ~ 1
*/

#include <iostream>
#include <vector>
using namespace std;

long long sum(vector<long long> numbers)
{
	long long s = 0;
	for(int i = 0; i < 10; i++)
		s += numbers[i];
	return s;
}

int main()
{
	int T; cin >> T;
	vector<long long> d;
	// d[i]를 구성하는 숫자 10개를 저장할 배열
	vector<vector<long long>> numbers(65, vector<long long>(10, 1));

	// save d[0], d[1]
	d.push_back(0);
	d.push_back(10);

	while(T-- > 0)
	{
		int n; cin >> n;

		if(d.size() - 1 < n)
		{
			for(int i = d.size() - 1; i <= n; i++)
			{
				for(int j = 1; j < 10; j++)
				{
					numbers[i][j] = numbers[i][j - 1] + numbers[i - 1][j];
				}

				d.push_back(sum(numbers[i]));
			}
		}

		cout << d[n] << "\n";
	}
}