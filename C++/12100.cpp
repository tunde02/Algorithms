/*
12100 - 2048 (Easy)

TEST CASE

3
2 2 2
4 4 4
8 8 8

16

9
4 2 0 0 0 0 0 0 0
4 8 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0
8 0 0 0 0 0 0 0 0
8 4 0 0 0 0 0 0 0
8 2 0 0 0 0 0 0 0

64
*/

/*
EXPLANATION

- move()는 이번이 3번째니 잘 알거라 생각
- 최대 5번의 move를 할 수 있는데, 합쳐지지 않는다면 5번보다 적게 움직였을 때 최댓값이 나오더라도
남은 횟수를 아무렇게나 움직여도 결국 최댓값이 같다. 따라서 무조건 5번 움직였다고 가정
- 5번의 움직임을 구하는 방식을 비트패턴으로 하였고, 위 아래 왼쪽 오른쪽 순으로 맨 나중의 움직임이
한 바퀴를 돌면 자동으로 그전 움직임이 다음 움직임으로 바뀌게끔 하였다.
- simulate()에서 그러한 움직임 배열을 전부 돌면서 움직여주고, 최댓값을 갱신
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> matrix;
constexpr int UP = 0b00;
constexpr int DOWN = 0b01;
constexpr int LEFT = 0b10;
constexpr int RIGHT = 0b11;

int n;
matrix nums;
vector<int> list;

void move(matrix* nums, int direction);
int simulate(matrix* nums);
int getMax(matrix* nums);

void print(matrix* nums)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << nums->at(i).at(j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	cin >> n;
	nums = matrix(n, vector<int>(n, 0));

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int input; cin >> input;
			nums[i][j] = input;
		}
	}

	for(int i = 0b0000000000; i <= 0b1111111111; i++)
		list.push_back(i);

	cout << simulate(&nums);
}

void move(matrix* nums, int direction)
{
	switch(direction)
	{
	case UP:
		for(int i = 0; i < n; i++)
		{
			int limit = 0;
			for(int j = 1; j <= n - 1; j++)
			{
				int index = j;

				while(index - 1 >= 0 && nums->at(index - 1).at(i) == 0)
				{
					nums->at(index - 1).at(i) = nums->at(index).at(i);
					nums->at(index).at(i) = 0;
					index--;
				}
				
				if(index > limit && nums->at(index - 1).at(i) == nums->at(index).at(i))
				{
					nums->at(index - 1).at(i) *= 2;
					nums->at(index).at(i) = 0;
					limit = index;
				}
			}
		}
		break;
	case DOWN:
		for(int i = 0; i < n; i++)
		{
			int limit = n - 1;
			for(int j = n - 2; j >= 0; j--)
			{
				int index = j;

				while(index + 1 <= n - 1 && nums->at(index + 1).at(i) == 0)
				{
					nums->at(index + 1).at(i) = nums->at(index).at(i);
					nums->at(index).at(i) = 0;
					index++;
				}

				if(index < limit && nums->at(index + 1).at(i) == nums->at(index).at(i))
				{
					nums->at(index + 1).at(i) *= 2;
					nums->at(index).at(i) = 0;
					limit = index;
				}
			}
		}
		break;
	case LEFT:
		for(int i = 0; i < n; i++)
		{
			int limit = 0;
			for(int j = 1; j <= n - 1; j++)
			{
				int index = j;

				while(index - 1 >= 0 && nums->at(i).at(index - 1) == 0)
				{
					nums->at(i).at(index - 1) = nums->at(i).at(index);
					nums->at(i).at(index) = 0;
					index--;
				}

				if(index > limit&& nums->at(i).at(index - 1) == nums->at(i).at(index))
				{
					nums->at(i).at(index - 1) *= 2;
					nums->at(i).at(index) = 0;
					limit = index;
				}
			}
		}
		break;
	case RIGHT:
		for(int i = 0; i < n; i++)
		{
			int limit = n - 1;
			for(int j = n - 2; j >= 0; j--)
			{
				int index = j;

				while(index + 1 <= n - 1 && nums->at(i).at(index + 1) == 0)
				{
					nums->at(i).at(index + 1) = nums->at(i).at(index);
					nums->at(i).at(index) = 0;
					index++;
				}

				if(index < limit && nums->at(i).at(index + 1) == nums->at(i).at(index))
				{
					nums->at(i).at(index + 1) *= 2;
					nums->at(i).at(index) = 0;
					limit = index;
				}
			}
		}
		break;
	}
}

int simulate(matrix* nums)
{
	int max = 0;

	for(int i = 0, size = list.size(); i < size; i++)
	{
		matrix temp = *nums;
		int tempMax;

		for(int j = 0; j < 5; j++)
		{
			int direction = (list[i] >> (2 * j)) & 0b0000000011;
			move(&temp, direction);
		}

		tempMax = getMax(&temp);
		max = tempMax > max ? tempMax : max;
	}

	return max;
}

int getMax(matrix* nums)
{
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(max < nums->at(i).at(j))
				max = nums->at(i).at(j);
		}
	}
	return max;
}