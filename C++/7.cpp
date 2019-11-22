#include <iostream>
#include <vector>
using namespace std;

int N, Q;
int cheapFan;
long long cheapPrice = LLONG_MAX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for(int i = 0; i < N; i++)
	{
		long long start, interval, cost; cin >> start >> interval >> cost;
		long long counts = Q % interval == 0 ? Q / interval - 1 : Q / interval;
		long long tempSum = start + cost * ((counts * (counts + 1)) / 2);

		if(cheapPrice > tempSum)
		{
			cheapPrice = tempSum;
			cheapFan = i + 1;
		}
	}

	cout << cheapFan << " " << cheapPrice;
}