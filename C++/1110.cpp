#include <iostream>
using namespace std;

// 0 <= n <= 99
int n;

int main() {
    cin >> n;
    int cycle = 0;
    int temp = n;

    do {
        temp = (temp%10)*10 + (temp/10 + temp%10)%10;
        cycle++;
    } while(temp != n);

    cout << cycle;
}