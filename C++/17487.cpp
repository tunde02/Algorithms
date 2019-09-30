/*
-FAIL-

TEST CASE

Konkuk

1 6

Hello World

7 6
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isLeft(char a);
bool isRight(char a);

int main()
{
	char input[100];
	fgets(input, 100, stdin);
	int left = 0, right = 0, special = 0;
	cout << input << endl;
	for(int i = 0; i < 100; i++)
	{
		
		if(isRight(input[i]))
		{
			right++;
		}
		else if(isLeft(input[i]))
		{
			left++;
		}
		else if(input[i] == ' ')
		{
			special++;
		}
		else if('A' <= input[i] && input[i] <= 'Z')
		{
			input[i] = tolower(input[i]);
			special++;
			i -= 1;
		}
	}

	cout << left << " " << right << " " << special << endl;

	if(left < right)
	{
		while(special != 0 && left != right)
		{
			left++;
			special--;
		}
	}
	else
	{
		while(special != 0 && right != left)
		{
			right++;
			special--;
		}
	}

	if(special > 0)
	{
		left += (special - (special / 2));
		right += special / 2;
	}


	cout << left << " " << right;
}

bool isLeft(char a)
{
	switch(a)
	{
	case 'q':
	case 'w':
	case 'e':
	case 'r':
	case 't':
	case 'y':
	case 'a':
	case 's':
	case 'd':
	case 'f':
	case 'g':
	case 'z':
	case 'x':
	case 'c':
	case 'v':
	case 'b':
		return true;
	default:
		return false;
	}
}

bool isRight(char a)
{
	switch(a)
	{
	case 'u':
	case 'i':
	case 'o':
	case 'p':
	case 'h':
	case 'j':
	case 'k':
	case 'l':
	case 'n':
	case 'm':
		return true;
	default:
		return false;
	}
}