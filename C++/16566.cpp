/*
16566 - 카드 게임
61% FAIL...?
-TEST CASE-
10 7 5
2 5 3 7 8 4 9
4 1 1 3 8

5
2
3
4
9

10 7 7
2 5 3 7 8 4 9
1 1 1 1 1 1 1
*/

/*
-EXPLANATION-
2 5 3 7 8 4 9
(4, 0) (1, 1) (1, 2) (3, 3) (8, 4)
->
2 3 4 5 7 8 9
(1,1) (1, 2) (3, 3) (4, 0) (8, 4)

- 두 배열을 오름차순 정렬 후 철수 배열의 처음부터 비교 시작
- 민수의 숫자가 철수의 숫자보다 커질 때까지 index를 증가시켜주고,
철수의 숫자를 정렬하기 전에 pair로 저장했던 인덱스를 이용해 output배열에 넣습니다
- output배열을 차례대로 출력합니다
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int> arr1;
vector<pair<int, int>> arr2;
vector<int> outputArr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	outputArr = vector<int>(K);
	for(int i = 0; i < M; i++)
	{
		//int input; cin >> input;
		//arr1.push_back(input);
		arr1.push_back(i + 1);
	}

	for(int i = 0; i < K; i++)
	{
		int input; cin >> input;
		arr2.push_back({ input, i });
	}

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	int index = 0;
	for(int i = 0; i < K; i++)
	{
		while(arr1[index] <= arr2[i].first)
			index++;

		outputArr[arr2[i].second] = arr1[index];
		index++;
	}

	string output = "";
	for(int i = 0; i < K; i++)
		//cout << outputArr[i] << "\n";
		output.append(to_string(outputArr[i])).append("\n");

	cout << output;
}