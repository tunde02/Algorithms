#include <iostream>
using namespace std;

int a ,b;

int main() {
    while(cin >> a >> b) {
        if(a + b == 0) {
            break;
        }
        cout << a + b << "\n";
    }
}
