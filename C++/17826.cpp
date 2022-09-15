#include <iostream>
#include <vector>
using namespace std;

int n = 50;
int h_score;
vector<int> scores(n, 0);

int main()
{
	for(int i = 0; i < n; i++)
	{
		int input; cin >> input;
		scores[i] = input;
	}

	cin >> h_score;

	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(h_score == scores[i])
		{
			index = i;
			break;
		}
	}

	if(0 <= index && index <= 4)
	{
		cout << "A+";
	}
	else if(5 <= index && index <= 14)
	{
		cout << "A0";
	}
	else if(15 <= index && index <= 29)
	{
		cout << "B+";
	}
	else if(30 <= index && index <= 34)
	{
		cout << "B0";
	}
	else if(35 <= index && index <= 44)
	{
		cout << "C+";
	}
	else if(45 <= index && index <= 47)
	{
		cout << "C0";
	}
	else
	{
		cout << "F";
	}
}