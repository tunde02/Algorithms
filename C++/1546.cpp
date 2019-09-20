#include <iostream>
using namespace std;

int n, num, max_num = 0;
float sum = 0.0f;

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> num;
        sum += num;
        max_num = max_num < num ? num : max_num;
    }

    sum = (sum / max_num) * 100;

    cout << sum / n;
}