#include <iostream>
using namespace std;

int n;

int main() {
    cin >> n;
    int numbers[n];
    cin >> numbers[0];
    int min = numbers[0], max = numbers[0];
    
    for(int i=1; i<n; i++) {
        cin >> numbers[i];
        min = min > numbers[i] ? numbers[i] : min;
        max = max < numbers[i] ? numbers[i] : max;
    }
    
    cout << min << " " << max;
}
