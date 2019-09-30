/*
-FAIL-
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

constexpr int LEFT = 1;
constexpr int RIGHT = 2;

int toDigit(string a)
{
	// C D E F G A B ...
	// 0 1 2 3 4 5 6
	// C0 -> 0
	// C0# -> 1
	// D0 -> 2 ...
	// 숫자차이 -> +12
	// # -> +1
	int digit = 0;

	switch(a.at(0))
	{
	case 'C':
		digit += 0;
		break;
	case 'D':
		digit += 2;
		break;
	case 'E':
		digit += 4;
		break;
	case 'F':
		digit += 5;
		break;
	case 'G':
		digit += 7;
		break;
	case 'A':
		digit += 9;
		break;
	case 'B':
		digit += 11;
		break;
	}

	digit += (a.at(1) - '0') * 12;

	if(a.size() == 3)
		digit += 1;

	return digit;
}

int main()
{
	string s_left, s_right; cin >> s_left >> s_right;
	int left = toDigit(s_left), right = toDigit(s_right);
	int n; cin >> n;
	vector<int> history;
	int total = 0;

	for(int i = 0; i < n; i++)
	{
		string s_now; cin >> s_now;
		int now = toDigit(s_now);

		if(abs(left - now) < abs(right - now))
		{
			total += abs(left - now);
			left = now;
			history.push_back(LEFT);
		}
		else
		{
			total += abs(right - now);
			right = now;
			history.push_back(RIGHT);
		}
	}

	cout << total << "\n";
	for(int i = 0; i < history.size(); i++)
		cout << history[i] << " ";
}