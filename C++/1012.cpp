#include <iostream>
#include <vector>
using namespace std;

int t, r, c, cabbages;

int calcWarms(vector<vector<int>> map);
void erase(vector<vector<int>>* map, int x, int y);
void print(vector<vector<int>> map);

int main() {
	cin >> t;

	for (int tests = 0; tests < t; tests++) {
		cin >> r >> c >> cabbages;
		vector<vector<int>> map(r, vector<int>(c, 0));

		for (int i = 0; i < cabbages; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		print(map);
		cout << calcWarms(map) << "\n";
	}
}

void initMap(vector<vector<int>> map) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = 0;
		}
	}
}

int calcWarms(vector<vector<int>> map) {
	int warms = 0;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 1) {
				erase(&map, i, j);
				warms++;
			}
		}
	}

	return warms;
}

void erase(vector<vector<int>>* map, int x, int y) {
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