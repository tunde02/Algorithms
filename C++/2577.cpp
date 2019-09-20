#include <iostream>
#include <string>
using namespace std;

int a, b, c;
int nums[10] = {0};

int main() {
    cin >> a >> b >> c;

    string result = to_string(a * b * c);

    for(int i=0; i<result.length(); i++) {
        nums[result.at(i) - 48]++;
    }

    for(int i=0; i<10; i++) {
        cout << nums[i] << "\n";
    }
}