#include <iostream>
#include <array>
using namespace std;

int d_func(int n) {
    // °íÃÄ¾ßµÊ
    if(n < 10) {
        return n * 2;
    }

    int sum = n;
    while(n > 0) {
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

int main() {
    cout << "start" << endl;
    array<bool, 101> numbers;
    for(int i=0; i<numbers.size(); i++) {
        numbers[i] = false;
    }

    for(int i=1; i<numbers.size(); i++) {
        if(numbers[i]) {
            continue;
        }

        int number = i;

        while(number < numbers.size()) {
            numbers[d_func(number)] = true;
            number = d_func(number);
        }
    }

    for(int i=1; i<numbers.size(); i++) {
        if(!numbers[i]) {
            cout << i << endl;
        }
    }

    return 0;
}