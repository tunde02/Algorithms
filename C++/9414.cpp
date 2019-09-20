// not yet

#include <iostream>
#include <algorithm>
using namespace std;

int t;

int pow(int a, int b) {
    int result = 1;
    for(int i=0; i<b; i++)
        result *= a;
    return result;
}

int sum(int* arr) {
    int result = 0;
    for(int i=0; i<40; i++)
        result = result + 2 * (pow(arr[i], i+1));
    return result;
}

int main() {
    cin >> t;
    int results[t] = {0};

    for(int i=0; i<t; i++) {
        int index = -1;
        int prices[40] = {0};
        
        do {
            cin >> prices[++index];
        } while(prices[index] != 0);

        sort(prices, prices+40, greater<int>());

        results[i] = sum(prices) <= 5000000 ? sum(prices) : -1;
    }

    for(int i=0; i<t; i++) {
        if(results[i] == -1)
            cout << "Too expensive\n";
        else
            cout << results[i] << "\n";
    }
}
