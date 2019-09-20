#include <iostream>
using namespace std;

int t;
string result = "";

int main() {
    cin >> t;

    for(int i=0; i<t; i++) {
        cin >> result;
        int score = 0, temp = 0;
        for(int j=0; j<result.length(); j++) {
            temp = result[j] == 'O' ? temp + 1 : 0;
            score += temp;
        }
        cout << score << "\n";
    }
}