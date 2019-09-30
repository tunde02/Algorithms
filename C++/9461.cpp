/*
9461 - 파도반 수열

TEST CASE

2
6
12

3
16
*/

/*
EXPLANATION

p[1] ~ p[12] = 1 1 1 2 2 3 4 5 7 9 12 16
p[6] = p[6-1] + p[6-5], p[7] = p[7-1] + p[7-5]  p[8] = p[8-1] + p[8-5]
p[n] = p[n-1] + p[n-5]
or
p[12] = p[12-2] + p[12-3]
p[n] = p[n-2] + p[n-3]

select second explanation to minimize initionalization
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T; cin >> T;
	// p[1], p[2], p[3] = 1
	vector<long long> p; p.push_back(0); p.push_back(1); p.push_back(1); p.push_back(1);

	while(T-- > 0)
	{
		int n; cin >> n;

		if(p.size() - 1 < n)
		{
			for(int i = p.size(); i <= n; i++)
			{
				p.push_back(p[i - 2] + p[i - 3]);
			}
		}

		cout << p[n] << "\n";
	}
}