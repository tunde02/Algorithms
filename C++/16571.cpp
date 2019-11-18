/*
16571 - 알파 틱택토
43% Fail
-TEST CASE-
1 2 0
1 1 2
0 0 2

W

1 2 0
0 1 0
0 0 0

L

0 0 1
0 0 0
0 0 0

L

2 1 1
0 1 1
2 0 2

W

0 0 1
0 1 2
0 0 0

L

1 0 2
0 0 0
0 0 0

W

1 0 2
0 1 0
0 0 0

D
*/

#include <iostream>
#include <vector>
using namespace std;

constexpr int wins[8] = {
	0b001010100, // 84  '/'
	0b100010001, // 273 '\'
	0b000111000, // 56  '-'
	0b010010010, // 146 '|'
	0b000000111, // 7   '_'
	0b001001001, // 73  '3|'
	0b100100100, // 292 '1|'
	0b111000000  // 448 '^'
};
constexpr int priorities[9] = {
	0b000010000,
	0b000000001,
	0b000000100,
	0b001000000,
	0b100000000,
	0b000000010,
	0b000001000,
	0b000100000,
	0b010000000
};
int p1 = 0, p2 = 0;
int turn = 1;
int viewpoint = 0;

int findWin(int player, int opponent);
int findDraw(int player, int opponent);
int getCount(int num);
int getDangers(int player, int opponent);
int isFinished(int player1, int player2);

int main()
{
	for(int i = 0; i < 9; i++)
	{
		int input; cin >> input;

		p1 <<= 1;
		p2 <<= 1;

		if(input == 1)
			p1 += 1;
		else if(input == 2)
			p2 += 1;
		else
			turn++;
	}

	// turn이 짝수 -> player 1 차례
	// turn이 홀수 -> player 2 차례
	viewpoint = turn % 2 == 0 ? 1 : 2;
	int player = turn % 2 == 0 ? p1 : p2;
	int opponent = turn % 2 == 0 ? p2 : p1;
	int winner = 0;

	while(turn-- > 1)
	{
		int nextChoice = findWin(player, opponent);

		if(nextChoice != -1)
		{
			player += nextChoice;
			winner = isFinished(player, opponent);

			if(winner != 0)
			{
				winner = (p1 & player) != 0 ? 1 : 2;
				if(winner == viewpoint)
					cout << "W";
				else
					cout << "L";
				return 0;
			}
		}
		else
		{
			nextChoice = findDraw(player, opponent);

			if(nextChoice == -1)
			{
				cout << "D";
				return 0;
			}

			player += nextChoice;
		}

		player = player ^ opponent;
		opponent = player ^ opponent;
		player = player ^ opponent;
	}

	cout << "D";
}

int findWin(int player, int opponent)
{
	for(int i = 0; i < 8; i++)
	{
		if((wins[i] & opponent) != 0)
			continue;

		if(getCount(~player & wins[i]) == 1)
			return ~player & wins[i];
	}

	if(getDangers(player, opponent) >= 1)
		return -1;

	int maxDangers = -1;
	int pos = -1;

	for(int i = 0; i < 9; i++)
	{
		if((priorities[i] & player) != 0 || (priorities[i] & opponent) != 0)
			continue;

		int tempProbs = -1;
		int dangerCnt = getDangers(opponent, player | priorities[i]);
		
		if(maxDangers < dangerCnt)
		{
			maxDangers = dangerCnt;
			pos = priorities[i];
		}

		if(maxDangers >= 2)
			return priorities[i];
	}

	return pos;
}

int getCount(int num)
{
	int cnt = 0;
	while(num > 0)
	{
		cnt = (num & 1) == 1 ? cnt + 1 : cnt;
		num >>= 1;
	}
	return cnt;
}

int findDraw(int player, int opponent)
{
	return findWin(opponent, player);
}

int getDangers(int player, int opponent)
{
	int cnt = 0;
	for(int i = 0; i < 8; i++)
	{
		if((wins[i] & player) != 0)
			continue;

		if(getCount(~opponent & wins[i]) == 1)
			cnt++;
	}

	return cnt;
}

int isFinished(int player1, int player2)
{
	for(int i = 0; i < 8; i++)
	{
		if((player1 & wins[i]) == wins[i])
			return 1;
		if((player2 & wins[i]) == wins[i])
			return 2;
	}

	return 0; // draw or not yet
}

/*=======================================================================*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int wins[8] = {
	0b001010100, // 84  '/'
	0b100010001, // 273 '\'
	0b000111000, // 56  '-'
	0b010010010, // 146 '|'
	0b000000111, // 7   '_'
	0b001001001, // 73  '3|'
	0b100100100, // 292 '1|'
	0b111000000  // 448 '^'
};
int p1 = 0, p2 = 0;
int turn = 1;
int viewpoint = 0;

int findWin(int player, int opponent);
int checkMap(int player1, int player2, int viewpoint);
int getCount(int num);

int main()
{
	for(int i = 0; i < 9; i++)
	{
		int input; cin >> input;

		p1 <<= 1;
		p2 <<= 1;

		if(input == 1)
			p1 += 1;
		else if(input == 2)
			p2 += 1;
		else
			turn++;
	}

	// turn이 짝수 -> player 1 차례
	// turn이 홀수 -> player 2 차례
	viewpoint = turn % 2 == 0 ? p1 : p2;

	int l = 0, d = 0, w = 0;
	int l_d = 10000, d_d = 10000, w_d = 10000;
	queue<pair<pair<int, int>, int>> q;

	if(turn % 2 == 0)
		q.push({ { p1, p2 }, 0 });
	else
		q.push({ { p2, p1 }, 0 });

	while(!q.empty())
	{
		int player1 = q.front().first.first, player2 = q.front().first.second;
		int depth = q.front().second;
		q.pop();

		int result = checkMap(player1, player2, viewpoint);

		switch(result)
		{
		case -1:
			break;
		case 0:
			//cout << player1 << " " << player2 << endl;
			l++;
			l_d = l_d > depth ? depth : l_d;
			continue;
		case 1:
			//cout << player1 << " " << player2 << endl;
			d++;
			d_d = d_d > depth ? depth : d_d;
			continue;
		case 2:
			//cout << player1 << " " << player2 << endl;
			w++;
			w_d = w_d > depth ? depth : w_d;
			continue;
		}

		int state;
		// 1. 이길 수 있는 칸이 있는가?
		state = findWin(player1, player2);
		if(state != -1)
		{
			q.push({ { player2, player1 + state }, depth + 1 });
			continue;
		}
		// 2. 막아야되는 칸이 있는가?
		state = findWin(player2, player1);
		if(state != -1)
		{
			q.push({ { player2, player1 + state }, depth + 1 });
			continue;
		}
		// 3. 나머지 경우 전부
		int nextChoice = 0b1000000000;
		for(int i = 0; i < 9; i++)
		{
			nextChoice >>= 1;
			if((nextChoice & player1) != 0 || (nextChoice & player2) != 0)
				continue;

			int next = player1 + nextChoice;
			q.push({ { player2, next }, depth + 1 });
		}
	}

	//if(l_d == 10000)
	//	l_d = -1;
	//if(d_d == 10000)
	//	d_d = -1;
	//if(w_d == 10000)
	//	w_d = -1;

	//int r = max(l_d, max(d_d, w_d));
	//if(r == w_d)
	//	cout << "W";
	//else if(r == d_d)
	//	cout << "D";
	//else
	//	cout << "L";

	//if(l == 0)
	//	cout << "W";
	//else if(w == 0)
	//	cout << "L";
	//else
	//	cout << "D";

	cout << endl << endl;
	cout << "l : " << l << endl;
	cout << "d : " << d << endl;
	cout << "w : " << w << endl;
	cout << "l_d : " << l_d << endl;
	cout << "d_d : " << d_d << endl;
	cout << "w_d : " << w_d << endl;
}

int findWin(int player, int opponent)
{
	for(int i = 0; i < 8; i++)
	{
		if((wins[i] & opponent) != 0)
			continue;

		if(getCount(~player & wins[i]) == 1)
			return ~player & wins[i];
	}
	return -1;
}

int checkMap(int player1, int player2, int viewpoint)
{
	// -1 : not yet, 0 : viewpoint lose, 1 : draw, 2 : viewpoint win
	for(int i = 0; i < 8; i++)
	{
		if((player1 & wins[i]) == wins[i])
			return (viewpoint & player1) != 0 ? 2 : 0;
		if((player2 & wins[i]) == wins[i])
			return (viewpoint & player2) != 0 ? 2 : 0;
	}

	return (player1 | player2) == 0b111111111 ? 1 : -1;
}

int getCount(int num)
{
	int cnt = 0;
	while(num > 0)
	{
		cnt = (num & 1) == 1 ? cnt + 1 : cnt;
		num >>= 1;
	}
	return cnt;
}