#include <iostream>
using namespace std;

int a, b, c;
int history[101] = {0};

int main() {
    int start, end;
    int sum = 0;

    cin >> a >> b >> c;

    for(int i=0; i<3; i++) {
        cin >> start >> end;
        for(int j=start+1; j<=end; j++) {
            history[j]++;
        }
    }

    for(int i=1; i<101; i++) {
        switch(history[i]) {
        case 1:
            sum += a * history[i];
            break;
        case 2:
            sum += b * history[i];
            break;
        case 3:
            sum += c * history[i];
        default:
            break;
        }
    }

    cout << sum << endl;
}