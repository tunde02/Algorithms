#include <iostream>
#include <vector>
using namespace std;

int t, r, c, cabbages;

int calcWarms(vector<vector<int>> map); // 필요한 지렁이의 개수를 구하는 함수
void erase(vector<vector<int>>* map, int x, int y); // 이미 본 배추가 있던 자리를 지워주는 함수
void print(vector<vector<int>> map); // 디버깅용 출력 함수

int main() {
	cin >> t;

	for (int tests = 0; tests < t; tests++) {
		cin >> r >> c >> cabbages;
		vector<vector<int>> map(r, vector<int>(c, 0));

		/* 배추밭을 입력받는 부분 */
		for (int i = 0; i < cabbages; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		// print(map);

		cout << calcWarms(map) << "\n";
	}
}

int calcWarms(vector<vector<int>> map) {
	int warms = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 1) {
				// 배추가 있는 칸을 발견하면 erase를 실행
				erase(&map, i, j);
				warms++;
			}
		}
	}

	return warms;
}

void erase(vector<vector<int>>* map, int x, int y) {
	// 인자값으로 받은 좌표를 먼저 지우고,
	// 상하좌우에 대해서 erase를 재귀적으로 호출
	// 배열 인덱스 범위체크 필요
	(*(map))[x][y] = 0;

	if (x - 1 >= 0 && (*(map))[x - 1][y] == 1) {
		erase(map, x - 1, y);
	}
	if (x + 1 < r && (*(map))[x + 1][y] == 1) {
		erase(map, x + 1, y);
	}
	if (y - 1 >= 0 && (*(map))[x][y - 1] == 1) {
		erase(map, x, y - 1);
	}
	if (y + 1 < c && (*(map))[x][y + 1] == 1) {
		erase(map, x, y + 1);
	}
}

void print(vector<vector<int>> map) {
	cout << "===========================\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}