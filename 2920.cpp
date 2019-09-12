#include <iostream>
using namespace std;

int nums[8];

bool isSame(int a[], int b[], int length) {
    for(int i=0; i<length; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int ascending[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int descending[8] = {8, 7, 6, 5, 4, 3, 2, 1};

    for(int i=0; i<8; i++) {
        cin >> nums[i];
    }

    if(isSame(nums, ascending, 8)) {
        cout << "ascending";
    }
    else if(isSame(nums, descending, 8)) {
        cout << "descending";
    }
    else {
        cout << "mixed";
    }
}