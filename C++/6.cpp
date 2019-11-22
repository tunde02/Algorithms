#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
int K;
bool alphaCheck[26];
vector<int> result;

int main()
{
	cin >> str >> K;
	for(int i = 0, size = str.length(); i < size; i++)
	{
		if('A' <= str[i] && str[i] <= 'Z')
			str[i] = tolower(str[i]);
	}

	for(int i = 0, size = str.length(); i < size; i++)
	{
		if(alphaCheck[str[i] - 'a']) continue;

		alphaCheck[str[i] - 'a'] = true;

		int counts = 1, index = 1;
		while(str[i + index] == str[i])
		{
			counts++;
			index++;
		}

		if(counts >= K)
			result.push_back(1);
		else
			result.push_back(0);

		i += index - 1;
	}

	for(int i = 0; i < result.size(); i++)
		cout << result[i];
}