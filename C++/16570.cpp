/*
16570 - 앞뒤가 맞는 수열
<TIME OUT>
	숫자를 문자열로 + find()에 0~9의 인덱스 사용
-TEST CASE-
12
1 4 8 4 7 3 4 7 4 8 4 7

4 1

11
2 5 2 5 2 5 2 8 2 5 2

3 3
*/

/*
-EXPLANATION-

1 4 8 4 7 3 4 7 4 8 4 7
최대 개수 : 12 + 11 + 10 + ... + 2 + 1 = sum(0 ~ N)개
이 문제 최대 -> sum(0 ~ 1,000,000) = 500,000,500,000개....
length: contents(cnt(>1))
1: 1, 3, 4(5), 7(3), 8(2)
2: 14, 34, 47, 48, 73, 74, 84
3: 148, 347, 473, 474, 484, 734, 748, 847
4: 1484, 3474, 4734, 4748, 4847(2), 7347, 7484, 8473
5: ...
6: ...

위를 구성하고 cnt가 1 이상인 것들 중 length가 가장 길고 cnt가 가장 많은 것
cnt가 다 1이면 -1
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Block
{
public:
	int surface;
	int cnt = 0;
	vector<int> value;
	//vector<Block*> children;
	//Block* children[10] = { NULL };
	map<int, Block*> children;
	Block(int s) : surface(s){}
	Block(int s, int c) : surface(s), cnt(c) {}
};

typedef vector<int>::const_iterator itr;
typedef map<int, Block*>::iterator mitr;

int N;
vector<int> arr;
//string arr = "";

void initTrieTree(Block* root);
//mitr findBlock(Block b, int target);
//int findBlock(Block b, int target);
pair<int, int> findLongestBlock(Block* root);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	//cin >> N;
	//for(int i = 0; i < N; i++)
	//{
	//	int input; cin >> input;
	//	arr.push_back(input);
	//	//arr += input;
	//}

	N = 200;
	for(int i = 0; i < N; i++)
		arr.push_back(i);
	cout << "inited arr" << endl;
	Block root(0, -1);
	initTrieTree(&root);
	cout << "inited tree" << endl;
	pair<int, int> result = findLongestBlock(&root);

	if(result.first == -1)
		cout << -1;
	else
		cout << result.first << " " << result.second;
}

void initTrieTree(Block* root)
{
	for(int length = 1; length <= N - 1; length++)
	{
		for(int i = N - length; i >=0; i--)
		{
			pair<itr, itr> newB = { arr.begin() + i, arr.begin() + i + length };
			Block* nowB = root;
			bool isCreated = false;

			for(itr j = newB.first; j < newB.second; j++)
			{
				//int f = findBlock(*nowB, *j);
				auto f = nowB->children.find(*j);

				if(/*f == -1*/f == nowB->children.end())
				{
					isCreated = true;
					Block* b = new Block(*j);

					b->value = nowB->value;
					b->value.push_back(*j);

					//nowB->children.push_back(b);
					nowB->children.insert({ *j, b });
					break;
				}
				else
				{
					//nowB = nowB->children[f];
					nowB = f->second;
				}
			}

			if(!isCreated)
				nowB->cnt++;
		}
	}
}

//mitr findBlock(Block b, int target)
//{
//	auto res = b.children.find(target);
//	if(res != b.children.end())
//	{
//		return res;
//	}
//}

//int findBlock(Block b, int target)
//{
//	if(b.children.find(target) != b.children.end())
//	{
//		return 
//	}
//
//
//	for(int i = 0, size = b.children.size(); i < size; i++)
//	{
//		if(b.children[i]->surface == target)
//			return i;
//	}
//	return -1;
//}

pair<int, int> findLongestBlock(Block* root)
{
	for(int i = N - 1; i >= 1; i--)
	{
		pair<itr, itr> newB = { arr.end() - i, arr.end() };
		vector<int> a;
		a.insert(a.end(), newB.first, newB.second);
		Block* nowB = root;

		for(itr j = newB.first; j < newB.second; j++)
		{
			//int f = findBlock(*nowB, *j);
			auto f = nowB->children.find(*j);

			//nowB = nowB->children[f];
			nowB = f->second;
		}

		if(nowB->cnt > 0)
			return { i, nowB->cnt };
	}

	return { -1, -1 };
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N;
//int maxLength = 0, totalCnt = 0;
//vector<int> arr;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
//	
//	cin >> N;
//	for(int i = 0; i < N; i++)
//	{
//		int input; cin >> input;
//		arr.push_back(input);
//	}
//
//	for(int i = N - 1; i >= 1; i--)
//	{
//		if(maxLength != 0)
//			break;
//
//		vector<int> block;
//		block.insert(block.end(), arr.end() - i, arr.end());
//
//		for(int j = 0; j <= N - 1 - i; j++)
//		{
//			if(equal(block.begin(), block.end(), arr.begin() + j))
//			{
//				if(maxLength == 0)
//					maxLength = block.size();
//				totalCnt++;
//			}
//		}
//	}
//
//	if(maxLength == 0)
//		cout << -1;
//	else
//		cout << maxLength << " " << totalCnt;
//}