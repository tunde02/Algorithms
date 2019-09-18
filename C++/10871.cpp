#include <iostream>
using namespace std;

int n, x;

int main() {
    cin >> n >> x;
    int temp;

    for(int i=0; i<n; i++) {
        cin >> temp;
        
        if(temp < x) {
            cout << temp << " ";
        }
    }
}