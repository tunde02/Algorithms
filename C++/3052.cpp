#include <iostream>
using namespace std;

int num;
int dif = 0;
bool rests[42] = {false};

int main() {
    for(int i=0; i<10; i++) {
        cin >> num;
        // if(!rests[num%42]) {
        //     rests[num%42] = true;
        //     dif++;
        // }
        dif += rests[num%42] ? 0 : 1;
        rests[num%42] = true;
    }

    cout << dif;
}