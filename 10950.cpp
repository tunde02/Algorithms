#include <iostream>
using namespace std;

int n, a, b;

int main() {
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a >> b;
        cout << a + b << endl;
    }

    return 0;
}