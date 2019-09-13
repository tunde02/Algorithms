#include <iostream>
using namespace std;

int k;
char binary[2000000];

int main() {
    cin >> k;
    for(int i=0; i<k; i++)
        binary[i] = '1';
    for(int i=k; i<2*k-1; i++)
        binary[i] = '0';
    cout << binary;
}