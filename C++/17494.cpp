/*
-FAIL-

TEST CASE
5 10
5 10
2 6
3 5
4 4
5 4

<배부름 만족도>

9
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int main()
{
	// tuple<만족도, 포만감>
	int n, limit; cin >> n >> limit;
	bool isFull = false;
	vector<tuple<int, int>> list;
	int satisfaction = 0;

	for(int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		list.push_back(tuple<int, int>(b, a));
	}

	sort(list.begin(), list.end());

	for(int i = 0; i < n && !isFull;)
	{
		int index = 0;
		int tempSatis = get<0>(list[i]);
		vector<tuple<int, int>> temp;

		do
		{
			temp.push_back(list[i + index]);
			index++;
		} while(i + index < list.size() && tempSatis == get<0>(list[i + index]));

		for(int j = temp.size() - 1; j >= 0; j--)
		{
			limit -= get<1>(temp[j]);
			satisfaction += get<0>(temp[j]);

			if(limit <= 0)
			{
				isFull = true;
				break;
			}
		}
		
		i += index;
	}

	if(isFull)
		cout << satisfaction;
	else
		cout << "죄송합니다 한승엽 병장님";
}