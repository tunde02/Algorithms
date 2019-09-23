/*
TEST CASE

10
3
2 4
7 8
6 9

3
1
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

void print(vector<int> vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

int main()
{
	int l, n;
	int expectedMaxIndex = 0, realMaxIndex = 0;
	
	cin >> l >> n;

	vector<int> roleCake(l + 1, 0);
	vector<int> expectedCakeNums;
	vector<int> realCakeNums(n, 0);
	vector<tuple<int, int>> papers;
	
	for(int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
        // 시작과 끝이 적힌 종이를 저장
		papers.push_back(tuple<int, int>(start, end));
        // 저장할 때 각 방청객의 기대 롤케이크 개수를 저장
		expectedCakeNums.push_back(end - start + 1);
	}

	for(int i = 0; i < n; i++)
	{
		cout << "(" << get<0>(papers[i]) << ", " << get<1>(papers[i]) << ") ";
	}
	cout << endl;

    // 역순으로 반복
	for(int i = papers.size() - 1; i >= 0; i--)
	{
		int start = get<0>(papers[i]), end = get<1>(papers[i]);
		cout << "start : " << start << ", end : " << end << endl;
		for(int j = start; j <= end; j++)
		{
            // 롤케이크에 방청객의 번호를 새김
            // 역순이라 조건을 확인할 필요 X
			roleCake[j] = i + 1;
		}
	}

	print(roleCake);

    // 실제로 방청객이 받아가는 롤케이크의 개수를 구함
	for(int i = 1; i < roleCake.size(); i++)
	{
		if(roleCake[i] != 0)
			realCakeNums[roleCake[i] - 1]++;
	}

	cout << "=expected=\n";
	print(expectedCakeNums);
	cout << "=real=\n";
	print(realCakeNums);

	int expectedMax = -1, realMax = -1;
	for(int i = 0; i < n; i++)
	{
        // 기댓값과 실제값중 최댓값들의 인덱스를 구함
		if(expectedMax < expectedCakeNums[i])
		{
			expectedMaxIndex = i + 1;
			expectedMax = expectedCakeNums[i];
		}
		if(realMax < realCakeNums[i])
		{
			realMaxIndex = i + 1;
			realMax = realCakeNums[i];
		}
	}
	
	cout << expectedMaxIndex << "\n" << realMaxIndex;
}